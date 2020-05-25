-- begin blueprint for apps{} sorting and filtering
apps = {}
apps.mt = {}
function apps.new(o)
	o = o or {}
	setmetatable(o, apps.mt)
	o.print = apps.print
	o.sort = apps.sort
	return o
end

function apps.sort(self, arg)
	local i = 1
	if arg == nil then
		arg = SKIN:GetVariable("sort")
	end
	local reverse = tonumber(SKIN:GetVariable("revOrder"))
	while i < #self do
		-- print('total = ' .. #self .. ' iter = ' .. i .. ' value = ' .. self[i].id .. ' > ' .. self[i + 1].id)
		if self[i][arg] > self[i + 1][arg] then
			local temp = table.remove(self, i)
			table.insert(self, i + 1, temp)
			i = 1
		else
			i = i + 1
		end
	end
	if reverse > 0 then
		for j = 1, math.floor(#self / 2) do
			local temp = self[j]
			self[j] = self[#self - j + 1]
			self[#self - j + 1] = temp
		end
	end
end

function apps.filter(arg)
	local result = apps.new()
	local hiddenList = SKIN:GetVariable("steamHiddenList")
	local hidden = {}
	local showHidden = false
	if SKIN:GetVariable("filter"):match("hidden") ~= nil then
		showHidden = true
	end
	local i = 1
	while i < hiddenList:len() do --assenble a table from the comma separated list
		local e = hiddenList:find(",", i)
		if e == nil then
			e = hiddenList:len()
		end
		if e - i > 2 then
			local temp = tonumber(hiddenList:sub(i, e - 1))
			table.insert(hidden, temp)
		end
		i = e + 1
	end
	i = 1
	while i <= #apps do
		local isHidden = false
		for j, k in ipairs(hidden) do
			if apps[i].id == k then -- user blacklisted (dynamic list based on user input)
				isHidden = true
				break
			end
		end
		if isHidden == showHidden then
			table.insert(result, apps[i])
		end
		i = i + 1
	end
	return result
end

function apps.print(self, arg)
	for i, v in ipairs(self) do
		if arg == nil then
			print(
				i .. " = id:" .. v.id ..
					", name:" .. v.name ..
						", path" .. v.path ..
							", dir:" .. v.dir ..
								", size:" .. v.size ..
									", playtime:" .. v.playtime ..
										", achievments:" .. v.trophies[2] .. "/" .. v.trophies[1] ..
											", desc:" .. v.desc
			)
		elseif v[arg] ~= nil then
			if arg ~= "name" then
				print(v.name .. "[" .. arg .. "] = " .. v[arg])
			else
				print(i .. " = " .. arg .. ":" .. v[arg])
			end
		else
			print("wrong keyword passed as arg")
		end
		-- while #apps[#apps] > 0 do table.remove(apps[#apps]) end
		-- table.remove(apps)
	end
end
-- end blueprint for app{} sorting and filtering

-- begin bueprint for apps{} elements
App = {}
App.mt = {}
function App.new(o)
	o = o or {}
	setmetatable(o, App.mt)
	return o
end
App.prototype = {
	id = 0,
	name = "",
	path = "",
	dir = "",
	size = 0,
	playtime = 0,
	trophies = {0, 0},
	desc = "No Description",
	lastPlayed = 0
}
App.mt.__index = App.prototype
-- end bueprint for apps{} elements

function addHidden(str)
	local hiddenList = SKIN:GetVariable("steamHiddenList")
	if hiddenList[hiddenList:len()] ~= " " then
		hiddenList = hiddenList .. " "
	end
	hiddenList = hiddenList .. str .. ","
	-- print(hiddenList)
	SKIN:Bang("!setVariable", "steamHiddenList", hiddenList)
	SKIN:Bang(
		"!writeKeyvalue",
		"Variables",
		"steamHiddenList",
		hiddenList,
		resources .. currentConfig .. "\\Variables.inc"
	)
	applyFilter()
	Update()
end

function subHidden(str)
	print("subtracting " .. str)
	local hiddenList = SKIN:GetVariable("steamHiddenList")
	hiddenList = hiddenList:gsub(str .. ",", "")
	SKIN:Bang("!setVariable", "steamHiddenList", hiddenList)
	SKIN:Bang(
		"!writeKeyvalue",
		"Variables",
		"steamHiddenList",
		hiddenList,
		resources .. currentConfig .. "\\Variables.inc"
	)
	applyFilter()
	Update()
end

function applySort()
	showcase:sort()
end

function applyFilter()
	apps:sort()
	showcase = apps:filter()
end
function startTimer()
	startTime = os.clock()
end

function parseApps()
	local str = SKIN:GetMeasure("mListSteamFiles"):GetStringValue()
	local path = ""
	local userID = SKIN:GetVariable("lastActiveUser")
	for line in str:gmatch "(.-)\n" do
		-- print(line)
		local appmanifest = "228980.acf" --use steamworks appID as sentinal
		if line:match(" Directory of (.*)") ~= nil then
			path = line:match(" Directory of (.*)") .. "\\"
		elseif line:match(".*appmanifest_(.*).acf") ~= nil then
			appmanifest = line:match(".*(appmanifest_.*.acf)")
			if appmanifest:match("228980.acf") == nil then --ignore the "Steamworks" appmanifest
				-- print('reading file = ' .. path .. appmanifest)
				local app = parseLog(path, appmanifest)
				app.path = path .. "common\\"
				app.playtime = 0
				if tonumber(userID) > 0 then --requires a valid userID number
					parseJSON(app, userID)
				end
				table.insert(apps, app)
			end
		end
	end
	-- all apps have been discovered; now get user-specific data from
	-- Path2exe .. "userdata\\" .. userID .. "\\config\\localconfig.vdf"
	local file = io.open(Path2exe .. "userdata\\" .. userID .. "\\config\\localconfig.vdf")
	if file ~= nil then
		local foundApps = false
		local isInstalled = 0
		for line in file:lines() do
			if line:match("Software\"") then
				foundApps = true
			elseif foundApps == true then
				if line:match('^%s+"%d+"$') ~= nil then
					local id = tonumber(line:match('^%s+"(%d+)"$'))
					-- found an app id; now detirmine if it is installed using the apps table
					for i, v in ipairs(apps) do
						if v.id == id then
							-- save the index pointing to the specific app whose data will follow
							isInstalled = i
							break
						end
					end
				elseif isInstalled > 0 then
					if line:match("LastPlayed\"") ~= nil then
						apps[isInstalled].lastPlayed = line:match("LastPlayed.*\"(%d+)\"")
					elseif line:match("Playtime\"") ~= nil then
						apps[isInstalled].playtime = line:match("Playtime.*\"(%d+)\"")
					elseif line:match("^%s+}$") then
						isInstalled = 0 -- leaving section about a specific app
					end
				elseif line:match("LastPlayedTimesSyncTime") ~= nil then
					foundApps = false -- leaving the only section we care about
				end
			end
		end
		file:close()
	end
	-- apps.print(apps)
	local endTimer = os.clock()
	SKIN:Bang("!log", "games/apps data loaded in " .. string.format("%.3f", endTimer - startTime) .. " seconds", "Notice")
	applyFilter()
	Update()
end

function parseLog(dirPath, filename)
	local file = io.open(dirPath .. filename, "r")
	local result = App.new()
	if file ~= nil then
		for line in file:lines() do
			if line:match('"appid"') ~= nil then
				local temp = line:match('appid"%s+"(.*)"')
				result.id = tonumber(temp)
			elseif line:match("name") ~= nil then
				local temp = line:match('name"%s+"(.*)"')
				result.name = temp
			elseif line:match("installdir") ~= nil then
				local temp = line:match('installdir"%s+"(.*)"')
				result.dir = temp
				SKIN:Bang("!setVariable", "testDir", dirPath .. "common\\" .. temp)
				SKIN:Bang("!updateMeasure", "dirSizeInfo")
				local actualSize = tonumber(SKIN:GetMeasure("dirSizeInfo"):GetValue())
				if actualSize > 0 then result.size = actualSize end
			end
		end
		file:close()
	end
	return result
end

function parseJSON(obj, id)
	local path2json = Path2exe .. "userdata\\" .. id .. "\\config\\librarycache\\" .. obj.id .. ".json"
	-- print(path2json)
	local file = io.open(path2json, "r")
	if file ~= nil then
		-- path2json files are 1 super long line in length (minified json)
		for line in file:lines() do
			if line:match('"nTotal":.*,"nAchieved":.*}') ~= nil then
				local total, unlocked = line:match('"nTotal":(%d+),"nAchieved":(%d+)}')
				-- print(obj.id .. ' = ' .. tonumber(total) .. ', ' .. tonumber(unlocked))
				obj.trophies = {tonumber(total), tonumber(unlocked)}
			end
			if line:match('"strSnippet":') ~= nil then
				local temp = line:match('"strSnippet":"(.*)"}}')
				-- print(temp)
				obj.desc = temp
			end
		end
	end
end

function Initialize()
	CURRENTPATH = SKIN:MakePathAbsolute(SKIN:GetVariable("CURRENTPATH"))
	currentConfig = SKIN:GetVariable("CURRENTCONFIG")
	Path2exe = SKIN:GetVariable("SteamDir")
	resources = SKIN:GetVariable("@")
	orientation = tonumber(SKIN:GetVariable("orientation"))
	useAccurateDirSize = tonumber(SKIN:GetVariable("useAccurateDirSize"))
	MAX = 12
	showcase = {}
	page = 0
end

function Update()
	-- apps:print('name')
	if #apps ~= #showcase then
		SKIN:Bang("!setOption", "menu5", "group", "menuSelect")
	else
		SKIN:Bang("!setOption", "menu5", "group", "none")
	end
	MAX = 12
	local start = page * MAX
	if #showcase - start < MAX then
		if #showcase < MAX then
			start = 0
		else
			start = #showcase - MAX
		end
	end
	-- print('start = '.. start)
	if #showcase > 0 then
		-- showcase:print('size')
		SKIN:Bang("!hidemeter", "loadingScreen")
		if #showcase < MAX then
			MAX = #showcase
		end
		for i = start + 1, start + MAX do
			SKIN:Bang("!SetOption", "mItemID" .. i - start, "String", showcase[i].id)
			SKIN:Bang("!SetOption", "mItemName" .. i - start, "String", showcase[i].name)
			SKIN:Bang("!SetOption", "mItemDIR" .. i - start, "String", showcase[i].path .. showcase[i].dir)
			SKIN:Bang("!SetOption", "mItemDescript" .. i - start, "string", showcase[i].desc)
			SKIN:Bang("!SetOption", "mItemPlayTime" .. i - start, "formula", showcase[i].playtime)
			SKIN:Bang("!SetOption", "mItemSize" .. i - start, "formula", showcase[i].size)
			local achievPercent = "N/A"
			if showcase[i].trophies[1] > 0 then
				achievPercent = math.floor(showcase[i].trophies[2] / showcase[i].trophies[1] * 100) .. "%"
			end
			SKIN:Bang(
				"!SetOption",
				"mItemTrophies" .. i - start,
				"string",
				showcase[i].trophies[2] .. " / " .. showcase[i].trophies[1] .. "#CRLF#" .. achievPercent
			)
			local temp = Path2exe .. "appcache\\librarycache\\" .. showcase[i].id .. "_header.jpg"
			-- print(temp)
			local FoundFile = io.open(temp, "r")
			if not FoundFile then
				--print('Found Not File for appID ' .. showcase[i].id)
				SKIN:Bang("!SetOption", i - start, "MeterStyle", "IconBG")
			else
				-- print('Found File for appID ' .. showcase[i].id)
				io.close(FoundFile)
				SKIN:Bang("!SetOption", i - start, "MeterStyle", "IconBG | GameBanner")
			end
		end
		setGrid()
	else
		SKIN:Bang("!hideMetergroup", "item12")
		SKIN:Bang("!hideMetergroup", "scrollpages")
		SKIN:Bang("!SetOptionGroup", "item12", "x", 0)
		SKIN:Bang("!SetOptionGroup", "item12", "Y", 0)
		SKIN:Bang("!showmeter", "loadingScreen")
	end
	SKIN:Bang("!UpdateMeasureGroup", "InfoMeasures")
	return #showcase
end

function switchAxis()
	orientation = tonumber(SKIN:GetVariable("orientation"))
	if orientation > 0 then
		orientation = 0 -- scroll vertically
	else
		orientation = 1 -- scroll horizontally
	end
	SKIN:Bang("!writeKeyvalue", "variables", "orientation", orientation, resources .. currentConfig .. "\\Variables.inc")
	SKIN:Bang("!setVariable", "orientation", orientation)
	setGrid()
end

function setGrid()
	local WorkAreaHeight = tonumber(SKIN:GetVariable("WorkAreaHeight"))
	local WorkAreaWidth = tonumber(SKIN:GetVariable("WorkAreaWidth"))
	local H = 0
	local W = 0
	local X = 0 --Skin center X init to 0
	local Y = 0 --Skin center Y init to 0
	local cellW = 0
	local cellH = 0
	local Maximize = tonumber(SKIN:GetVariable("Maximize"))
	local useBoxArt = tonumber(SKIN:GetVariable("useBoxArt"))
	if WorkAreaWidth > WorkAreaHeight then
		-- print('landscape mode')
		local capH = 2 + (1 - useBoxArt) * 2
		W = MAX % capH
		H = 0
		if W == 0 then
			H = capH
			while H * W < MAX do W = W + 1 end
		elseif W <= capH then
			H = capH
			W = 0
			while H * W < MAX do W = W + 1 end
		else
			while H * W < MAX do H = H + 1 end
		end
		cellH = math.floor((WorkAreaHeight * 3 / 4) / H + 0.5)
		if useBoxArt == 1 then
			cellW = math.floor(cellH * 2 / 3)
		else
			cellW = math.floor(cellH * 2.2326)
		end
	else
		-- print('portrait mode')
		local capH = 6 - (useBoxArt * 2)
		W = MAX % capH
		H = 0
		if W == 0 then
			H = capH
			while H * W < MAX do W = W + 1 end
		elseif MAX <= capH then
			H = MAX
			W = 0
			while H * W < MAX do W = W + 1 end
		else
			while H * W < MAX do H = H + 1 end
		end
		cellW = math.floor((WorkAreaWidth * 3 / 4 - 90) / W + 0.5)
		if useBoxArt == 1 then
			cellH = math.floor(cellW * 1.5)
		else
			cellH = math.floor(cellW * 0.467391)
		end
	end
	if Maximize ~= 0 then
		cellH = math.floor(WorkAreaHeight / H)
		cellW = math.floor((WorkAreaWidth - 90 - ((WorkAreaWidth - 90) % W)) / W + 0.5)
	end

	X = math.floor(cellW * W / 2)
	Y = math.floor(cellH * H / 2)
	
	-- FOR DEBUGGING
	-- local layout = { WorkAreaWidth, WorkAreaHeight, cellW, cellH, X, Y, W, H }
	-- print(table.concat(layout, ', '))
	
	local offset = 0
	for i = 1, 12 do
		if i <= #showcase then
			--ordered from left to right
			if orientation == 0 then
				--ordered from top to bottom
				if (#showcase - i) < W and (i - 1) % W == 0 and (#showcase % W) > 0 then
					offset = (W - (#showcase % W)) / 2
				-- print(i .. ' offset = ' .. offset)
				end
				SKIN:Bang("!moveMeter", 90 + cellW * (((i - 1) % W) + offset), cellH * math.floor((i - 1) / W), i)
			elseif orientation == 1 then
				if (#showcase - i) < H and (i - 1) % H == 0 and (#showcase % H) > 0 then
					offset = (H - (#showcase % H)) / 2
				-- print(i .. ' offset = ' .. offset)
				end
				SKIN:Bang("!moveMeter", 90 + cellW * math.floor((i - 1) / H), cellH * (((i - 1) % H) + offset), i)
			end
			SKIN:Bang("!showMeter", i)
		else
			SKIN:Bang("!hideMeter", i)
			SKIN:Bang("!moveMeter", 0, 0, i)
			SKIN:Bang("!hideMeterGroup", "info" .. i)
		end
	end
	if #showcase > MAX then
		SKIN:Bang("!MoveMeter", 10, 0, "indexup")
		SKIN:Bang("!MoveMeter", 10, 2 * Y - 70, "indexDown")
		SKIN:Bang("!showMeterGroup", "scrollpages")
	else
		SKIN:Bang("!hideMeterGroup", "scrollpages")
		SKIN:Bang("!MoveMeter", 0, 0, "indexup")
		SKIN:Bang("!MoveMeter", 0, 0, "indexdown")
	end
	local y0 = Y - 135
	if y0 < 0 then
		y0 = 0
	end -- don't clip the controls
	SKIN:Bang("!MoveMeter", 0, y0, "Settings")
	SKIN:Bang("!setVariable", "iconW", cellW)
	SKIN:Bang("!setVariable", "iconH", cellH)
end

function pageUp()
	page = page + 1
	-- wrap around scrolling
	if page * MAX > #showcase then
		page = 0
	end
	Update()
	-- print('pg = ' .. page)
end

function pageDn()
	page = page - 1
	-- wrap around scrolling
	if page < 0 then
		page = math.floor(#showcase / MAX)
	end
	Update()
	-- print('pg = ' .. page)
end

function cleanUp()
	while #showcase > 0 do
		table.remove(showcase)
	end
	while #apps > 0 do
		table.remove(apps)
	end
end
-- Generating an AppID for a non-Steam game (why I didn't brute force it myself)
-- # Original approach
--
--   hash = crc32(path .. title)
--   hash = hash | 0x80000000
--   hash = hash << 32
--   hash = hash | 0x02000000
--
-- # Issues
-- Left-shifting by 32 is not feasible since it results in 0.
-- This is because Lua uses the underlying C double datatype to represent all numbers.
-- Converting numbers larger than 2^56 into strings causes the number to be altered.
--
-- # Workaround
-- The workaround is to generate the CRC32 hash and bitwise OR the hash as usual.
-- Then the hash is turned into a string containing the binary version of the hash.
-- The binary hash is then left-shifted by appending 0x02000000 in binary as a string.
-- The binary is then turned back into a string containing the decimal version of the hash.
--
-- OR just add the non-steam shortcut, then run it from within steam once.
-- This makes steam do the crc calc and saves the non-steam appID to the "shortcutnames"
-- field in C:\Program Files (x86)\Steam\userdata\<userID#>\760\screenshots.vdf
