-- begin blueprint for apps{} sorting and filtering
apps = {}
apps.mt = {}
function apps.new(o)
	o = o or {}
	setmetatable(o, apps.mt)
	o.print = apps.print
	o.sort = apps.sort
	o.filter = apps.filter
	return o
end

function apps.sort(self, arg, reverse)
	local i = 1
	if arg == nil then
		arg = SKIN:GetVariable("sort")
	end
	while i < #self do
		if self[i][arg] > self[i + 1][arg] then
			local temp = table.remove(self, i)
			table.insert(self, i + 1, temp)
			i = 1
		else
			i = i + 1
		end
	end
	if reverse == nil then
		reverse = tonumber(SKIN:GetVariable("revOrder"))
	end
	if reverse > 0 then
		for j = 1, math.floor(#self / 2) do
			local temp = self[j]
			self[j] = self[#self - j + 1]
			self[#self - j + 1] = temp
		end
	end
end

function apps.filter(self, arg)
	local result = apps.new()
	local hiddenList = SKIN:GetVariable("hiddenList")
	local hidden = {}
	for str in string.gmatch(hiddenList, '(.-)|') do
		table.insert(hidden, str) -- assemble blacklist from delimited string
	end
	-- print(table.concat(hidden, ","))
	local showHidden = false
	if SKIN:GetVariable("filter"):match("hidden") ~= nil then
		showHidden = true
	end
	for i = 1, #self do
		local isHidden = false
		for j = 1, #hidden do
			if self[i].path == hidden[j] then -- is game blacklisted
				-- print("flagging "..self[i].label .. " as hidden")
				isHidden = true
				break
			end
		end
		if isHidden == showHidden then
			table.insert(result, self[i])
		end
	end
	if #result == 0 and showHidden == true then
		SKIN:Bang("!setVariable", "filter", "none")
		-- print("showcase has nothing in it; switching to different filter")
		return self:filter("none")
	else
		return result
	end
end

function apps.print(self, arg)
	for i, v in ipairs(self) do
		if arg == nil then
			print(
				"path = " .. path ..
				"label = " .. label ..
				"size = " .. size ..
				"core_name = " .. core_name ..
				"playtime = " .. playtime ..
				"lastPlayed = " .. lastPlayed
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
-- end blueprint for apps{} sorting and filtering

-- begin bueprint for apps{} elements
App = {}
App.mt = {}
function App.new(o)
	o = o or {}
	setmetatable(o, App.mt)
	return o
end
App.prototype = {
	path = "",
	label = "",
	core_name = "",
	size = 0,
	playtime = 0,
	lastPlayed = "never"
}
App.mt.__index = App.prototype
-- end bueprint for apps{} elements

function addHidden(str)
	local hiddenList = SKIN:GetVariable("hiddenList")
	-- print("hiding " .. str)
	hiddenList = hiddenList .. str .. "|"
	SKIN:Bang("!setVariable", "hiddenList", hiddenList)
	SKIN:Bang(
		"!writeKeyvalue", "Variables", "hiddenList", hiddenList,
		resources .. currentConfig .. "\\" .. service .. "\\SpecificVars.inc")
	SKIN:Bang("!updateMeasure", "mParseApps")
end

function subHidden(str)
	local hiddenList = SKIN:GetVariable("hiddenList")
	str = str:gsub("%-", "%%-") -- make hyphens arbitrary
	str = str:gsub("%(.-%)", "%%(.-%%)") -- make country code arbitrary
	str = str:gsub("%[.-%]", "%%[.-%%]") -- make version code arbitrary
	-- print("showing " .. str)
	hiddenList = hiddenList:gsub(str .. ".-%|", "", 1)
	SKIN:Bang("!setVariable", "hiddenList", hiddenList)
	SKIN:Bang(
		"!writeKeyvalue", "Variables", "hiddenList", hiddenList,
		resources .. currentConfig .. "\\" .. service .. "\\SpecificVars.inc")
	SKIN:Bang("!updateMeasure", "mParseApps")
end

function applySort()
	local reverse = tonumber(SKIN:GetVariable("revOrder"))
	local i = 1
	while i < #consoles do
		-- only sort consoles by name!!
		if consoles[i].name > consoles[i + 1].name then
			local temp = table.remove(consoles, i)
			table.insert(consoles, i + 1, temp)
			i = 1
		else
			i = i + 1
		end
	end
	-- now that consoles are sorted, sort all the games
	local sort = SKIN:GetVariable("sort")
	for i = 1, #consoles do
		consoles[i].games:sort(sort, reverse)
	end
end

function applyFilter()
	applySort()
	if currConsole <= 0 then
		showcase = consoles -- do not hide consoles
	elseif currConsole <= #consoles then
		showcase = consoles[currConsole].games:filter()
	end
end

function Initialize()
	currConsole = tonumber(SKIN:GetVariable('console'))
	resources = SKIN:GetVariable("@")
	currentConfig = SKIN:GetVariable("CURRENTCONFIG")
	service = SKIN:GetVariable("service")
	retroarchDIR = SKIN:MakePathAbsolute(SKIN:GetVariable('DIR'))
	page = tonumber(SKIN:GetVariable("page"))
	scrollPlane = tonumber(SKIN:GetVariable("scrollPlane"))
	consoles = {} -- stores consoles & games
	showcase = {} -- used for filtered & sorted list of items to display
end

function startTimer()
	startTime = os.clock()
end

function parseApps()
	local str = SKIN:GetMeasure("mListInfoFiles"):GetStringValue()
	for line in str:gmatch "(.-)\n" do
		-- print(line)
		local playlist = ""
		if line:match(".*%.lpl") ~= nil then
			playlist = line:match("(.*)%.lpl")
			-- print('reading file = ' .. playlist .. ".lpl")
			table.insert(consoles, {})
			consoles[#consoles].name = playlist
			consoles[#consoles].games = parsePlaylist(retroarchDIR .. "playlists\\" .. playlist .. ".lpl")
		end
	end
	-- all roms imported via retroarch have been discovered
	--[[ get history for each game from mListRetroarchHistory measure output ]]
	if currConsole <=0 or currConsole > #consoles then
		if #consoles == 0 then
			SKIN:Bang("!setOption", "loadingScreen", "text", "No console#CRLF#playlists found!")
		end
	elseif #consoles[currConsole].games == 0 then
		SKIN:Bang("!setOption", "loadingScreen", "text", "No Roms#CRLF#imported for#CRLF#" .. #consoles[currConsole].name .. "!")
	end
	local endTimer = os.clock()
	SKIN:Bang("!log", "games/apps data loaded in " .. string.format("%.3f", endTimer - startTime) .. " seconds", "Notice")
	-- printConsoles()
	-- printGames()
	SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function parsePlaylist(filename)
	local file = io.open(filename, "r")
	local foundList = false
	local defaultCore = ""
	local games = apps.new()
	if file ~= nil then
		local result = nil
		for line in file:lines() do
			if foundList == false and line:find("\"items\".*%[") ~= nil then
				foundList = true
			end
			if foundList == true then
				if line:match("{") ~= nil then
					result = App.new()
				elseif line:match("}") ~= nil and result ~= nil then
					table.insert(games, result)
					result = nil
					-- print("saving " .. result.label)
				elseif line:match('\"path\": ') ~= nil then
					result.path = string.gsub(line:match('\"path\": \"(.*)\"'), "\\\\", "\\")
					local tempFile
					if result.path:find("%.cue") ~= nil then
						tempFile = io.open(result.path:gsub("%.cue", ".iso"), "r")
						if tempFile == nil then
							tempFile = io.open(result.path:gsub("%.cue", ".bin"), "r")
						end
					elseif result.path:find("%.zip#") ~= nil then
						result.path = result.path:match("^(.*%.zip)#.*$")
						tempFile = io.open(result.path, "r")
					else
						tempFile = io.open(result.path, "r")
					end
					if tempFile ~= nil then
						result.size = tempFile:seek("end")
						tempFile:close()
					end
				elseif line:match('\"label\": ') ~= nil then
					result.label = line:match('\"label\": \"(.*)\"')
				elseif line:match('\"core_name\": ') ~= nil then
					result.core_name = line:match('\"core_name\": \"(.*)\"')
					if result.core_name == "DETECT" and defaultCore:len() > 0 then
						result.core_name = defaultCore
					end
				end
			elseif line:match("default_core_path\": \".+\",") ~= nil then
				defaultCore = line:match("default_core_path\": \"(.+)\",")
				defaultCore = defaultCore:gsub("\\\\", "\\")
			end
		end
		file:close()
	end
	return games
end

function printConsoles()
	local sum = 0
	for i, v in ipairs(consoles) do -- for each console
		print(v.name .. ' console has ' .. #v.games .. ' games')
		sum = sum + #v.games
	end
	print('found '.. sum .. ' games for ' .. #consoles .. ' consoles')
end

function printGames(c)
	if c == nil then
		for i, v in ipairs(consoles) do -- for each console
			printGames(v.name) -- print every game
		end
	else
		local index = 0
		for i = 1, #consoles do
			if c == consoles[i].name then
				index = i
				break
			end
		end
		if index == 0 then
			print(c .. " has no imported games")
		else
			for i, v in ipairs(consoles[index].games) do -- for a spcefied console
				print("(" .. c .. ")[" .. i .. '].label = ' .. v.label)
			end
			print(c .. ' console has ' .. #consoles[index].games .. ' games')
		end
	end
end

function Update()
	currConsole = tonumber(SKIN:GetVariable('console'))
	applyFilter() -- THIS CREATES THE showcase{} USED ON UpdateMeasure ACTIONS
	theme = SKIN:GetVariable("theme")
	if #showcase > 0 then
		SKIN:Bang("!hidemeter", "loadingScreen")
	end
	local MAX = 12
	local start = page * MAX + 1
	local useBoxArt = tonumber(SKIN:GetVariable("useBoxArt"))
	if useBoxArt == 1 then
		useBoxArt = "Named_Boxarts"
	elseif useBoxArt == 0 then
		useBoxArt = "Named_Snaps"
	elseif useBoxArt == 2 then
		useBoxArt = "Named_Titles"
	end
	if currConsole == 0 then --concerning consoles
		if #showcase - start < MAX then
			if #showcase < MAX then
				start = 0
			else
				start = #showcase - MAX
			end
		end
		for i = start + 1, start + MAX do
			local j = i - start
			if i <= #showcase then
				local imageFile = retroarchDIR .. "assets\\xmb\\" .. theme .. "\\png\\" .. showcase[i].name .. ".png"
				SKIN:Bang("!setOption", j, "imagename", imageFile)
				SKIN:Bang("!setOption", "mItemName" .. j, "string", showcase[i].name)
				local brand, model = showcase[i].name:match("(.-)%s%-%s(.*)$")
				SKIN:Bang("!setOption", "mItemDescript" .. j, "string", "Brand: " .. brand .. "#CRLF#Model: " .. model .. "#CRLF#Games: " .. #showcase[i].games .. " in playlist")
				SKIN:Bang("!setOption", j, "meterStyle", "IconBG | ConsoleAction")
			end
		end
	elseif consoles[currConsole] ~= nil then -- concerning games about a console
		SKIN:Bang("!showmeter", "back2Consoles")
		SKIN:Bang("!setOption", "back2Consoles", "y", "([settings:Y]+90)")
		if #showcase == #consoles[currConsole].games then
			SKIN:Bang("!setOption", "filter", "group", '""')
		else
			SKIN:Bang("!setOption", "filter", "group", "menuSelect | menus")
		end
		if #showcase - start < MAX then
			if #showcase < MAX then
				start = 0
			else
				start = #showcase - MAX
			end
		end
		for i = start + 1, start + MAX do
			local j = i - start
			if i <= #showcase then
				local imageFile = retroarchDIR .. "thumbnails\\" .. consoles[currConsole].name .. "\\" .. useBoxArt .. "\\" .. showcase[i].label:gsub("&", "_") .. ".png"
				local foundFile = io.open(imageFile)
				if foundFile ~= nill then
					foundFile:close()
				else
					-- print("couldn't find image for " .. showcase[i].label)
					imageFile = retroarchDIR .. "assets\\xmb\\" .. theme .. "\\png\\" .. consoles[currConsole].name .. "-content.png"
				end
				SKIN:Bang("!setOption", j, "imagename", imageFile)
				-- for specificity, parse title from path's filename instead of label
				-- local description = showcase[i].path:match(".*\\(.*)%..+$")
				local description = showcase[i].label
				description = description:gsub("%[.+%]", "") -- lose the version info
				description = description:gsub("%(.+%)", "") -- lose the country code
				description = description .. "#CRLF##CRLF#using core: "
				if showcase[i].core_name ~= "DETECT" then
					description = description .. showcase[i].core_name:match(".*\\(.*)%....$")
				else
					description = description .. showcase[i].core_name
				end
				SKIN:Bang("!setOption", "mItemDescript" .. j, "string", description)
				SKIN:Bang("!setOption", "mItemName" .. j, "string", showcase[i].label)
				SKIN:Bang("!setOption", "mItemDIR" .. j, "string", showcase[i].path)
				SKIN:Bang("!setOption", "mItemCore" .. j, "string", showcase[i].core_name)
				SKIN:Bang("!setOption", "mItemSize" .. j, "formula", showcase[i].size)
				SKIN:Bang("!setOption", "mItemPlayTime" .. j, "formula", showcase[i].playtime)
				SKIN:Bang("!setOption", "mItemLastPlayed" .. j, "string", showcase[i].lastPlayed)
				SKIN:Bang("!setOption", j, "meterStyle", "IconBG | GameAction")
			end
		end
	else
		SKIN:Bang("!hideMetergroup", "item12")
		SKIN:Bang("!hideMetergroup", "scrollpages")
		SKIN:Bang("!SetOptionGroup", "item12", "x", 0)
		SKIN:Bang("!SetOptionGroup", "item12", "Y", 0)
		SKIN:Bang("!showmeter", "loadingScreen")
	end
	SKIN:Bang("!SetVariable", "page", page)
	SKIN:Bang("!writeKeyValue", "Variables", "page", page, resources .. currentConfig .. "\\" .. service .. "\\SpecificVars.inc")
	SKIN:Bang("!UpdateMeasureGroup", "InfoMeasures")
	return #showcase
end

function pageUp()
	page = page + 1
	local tempMax = 0
	if currConsole == 0 then
		tempMax = #consoles
	else
		tempMax = #consoles[currConsole].games
	end
	-- wrap around scrolling
	if page * 12 > tempMax then page = 0 end
	SKIN:Bang('!updateMeasure', 'mParseApps')
end

function pageDn()
	page = page - 1
	local tempMax = 0
	if currConsole == 0 then
		tempMax = #consoles
	else
		tempMax = #consoles[currConsole].games
	end
	-- wrap around scrolling
	if page < 0 then page = math.floor(tempMax / 12) end
	SKIN:Bang('!updateMeasure', 'mParseApps')
end

function cleanUp()
	while #showcase > 0 do
		table.remove(showcase)
	end
	while #consoles > 0 do
		table.remove(consoles)
	end
end