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
				"path = " .. v.path ..
				" label = " .. v.label ..
				" size = " .. v.size ..
				" core_path = " .. v.core_path ..
				" playtime = " .. v.playtime ..
				" lastPlayed = " .. v.lastPlayed ..
				" crc = " .. v.crc ..
				" db_name = " .. v.db_name
			)
		elseif v[arg] ~= nil then
			if arg ~= "name" then
				print(v.label .. "[" .. arg .. "] = " .. v[arg])
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
	core_path = "",
	size = 0,
	playtime = 0,
	lastPlayed = 0,
	crc = "",
	db_name = ""
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
	local i = 2
	while i < #consoles do
		-- only sort consoles by name!!
		if consoles[i].name > consoles[i + 1].name then
			local temp = table.remove(consoles, i)
			table.insert(consoles, i + 1, temp)
			i = 2
		else
			i = i + 1
		end
	end
	-- now that consoles are sorted, sort all the games
	local sort = SKIN:GetVariable("sort")
	for i = 1, #consoles do
		consoles[i].games:sort(sort, reverse)
	end
	if history ~= nil then
		history:sort(sort, reverse)
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
	DIR = SKIN:MakePathAbsolute(SKIN:GetVariable('DIR'))
	page = tonumber(SKIN:GetVariable("page"))
	scrollPlane = tonumber(SKIN:GetVariable("scrollPlane"))
	consoles = {} -- stores consoles & games
	showcase = {} -- used for filtered & sorted list of items to display
	history = nil
end

function startTimer()
	startTime = os.clock()
end

function parseApps()
	enableAggHist()
	table.insert(consoles, 1, {})
	consoles[1].name = "favorites"
	consoles[1].games = parsePlaylist(DIR .. "content_favorites.lpl")
	local str = SKIN:GetMeasure("mListInfoFiles"):GetStringValue()
	for line in str:gmatch("(.-)\n") do
		-- print(line)
		local playlist = ""
		if line:match(".*%.lpl") ~= nil then
			playlist = line:match("(.*)%.lpl")
			-- print('reading file = ' .. playlist .. ".lpl")
			table.insert(consoles, {})
			consoles[#consoles].name = playlist
			consoles[#consoles].games = parsePlaylist(DIR .. "playlists\\" .. playlist .. ".lpl")
		end
	end
	-- all roms imported via retroarch have been discovered
	history = apps.new()
	local playtimes = SKIN:GetMeasure("mListRetroarchHistory"):GetStringValue()
	for line in playtimes:gmatch("(.-)\n") do
		-- print("reading playtimes for " .. line:sub(1, -6))
		local file = io.open(DIR .. "playlists\\logs\\" .. line:match(".*"))
		if file ~= nil then
			local gametime = {}
			for l in file:lines() do
				if l:match("\"runtime\":") ~= nil then
					local h, m, s = l:match("\"runtime\":%s+\"(%d+):(%d+):(%d+)\",")
					gametime["ran"] = tonumber(h) * 60 * 60 + tonumber(m) * 60 + tonumber(s)
				elseif l:match("\"last_played\": ") then
					local y, mo, d, h, mi, s = l:match("\"last_played\": \"(%d+)%-(%d+)%-(%d+) (%d+):(%d+):(%d+)\"")
					gametime["last"] = os.time{year=y, month=mo, day=d, hour=h, min=mi, sec=s}
				end
			end
			file:close()
			line = line:gsub("%-", "%%-") -- make hyphens arbitrary
			line = line:gsub("%(.-%)", "%%(.-%%)") -- make country code arbitrary
			line = line:gsub("%[.-%]", "%%[.-%%]") -- make version code arbitrary
			for i = 1, #consoles do
				for k = 1, #consoles[i].games do
					if consoles[i].games[k].path:match(line:sub(1, -6)) then
						-- print("found " .. line:sub(1, -5) .. ". Inserting playtimes")
						consoles[i].games[k].playtime = gametime.ran
						consoles[i].games[k].lastPlayed = gametime.last
						local isInHistory = false
						for j = 1, #history do
							if history[j].path:match(line:sub(1, -6)) ~= nil then
								isInHistory = true
								break
							end
						end
						if isInHistory == false then
							table.insert(history, consoles[i].games[k])
						end
					end -- don't break because favorites contains duplicates
				end
			end
		end
	end
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
	local defaultCore = nil
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
					result.path = line:match('\"path\": \"(.*)\"'):gsub("\\\\", "\\")
					local tempFile = nil
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
				elseif line:match('\"crc32\": ') ~= nil then
					result.crc = line:match('\"crc32\": \"(.*)\"')
				elseif line:match('\"db_name\": ') ~= nil then
					result.db_name = line:match('\"db_name\": \"(.*)%.lpl\"')
				elseif line:match('\"core_path\": ') ~= nil then
					result.core_path = line:match('\"core_path\": \"(.*)\"')
					if result.core_path == "DETECT" and defaultCore ~= nil then
						result.core_path = defaultCore
					end
				end
			elseif line:match("default_core_path\": \".+\",") ~= nil then
				defaultCore = line:match("default_core_path\": \"(.+)\",")
				defaultCore = defaultCore:gsub("\\\\", "\\")
			end
		end
		file:close()
	end
	if defaultCore ~= nil then
		--assign specified core path to favorites
		-- make hyphens arbitrary
		local dbPattern = games[1].db_name:gsub("%-", "%%-")
		for f = 1, #consoles[1].games do
			if consoles[1].games[f].db_name:match(dbPattern) ~= nil then
				-- print("assigning core to " .. consoles[1].games[f].label)
				consoles[1].games[f].core_path = defaultCore
				break
			end
		end
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

function Update()
	currConsole = tonumber(SKIN:GetVariable('console'))
	applyFilter() -- THIS CREATES THE showcase{} USED ON UpdateMeasure ACTIONS
	theme = SKIN:GetVariable("theme")
	if currConsole == -1 then
		if history == nil or #history == 0 then
			showcase = consoles
			currConsole = 0
		else
			showcase = history
		end
	end
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
	if #showcase - start < MAX then
		if #showcase < MAX then
			start = 0
		else
			start = #showcase - MAX
		end
	end
	if currConsole == 0 then --concerning consoles
		for i = start + 1, start + MAX do
			local j = i - start
			if i <= #showcase then
				local imageFile = DIR .. "assets\\xmb\\" .. theme .. "\\png\\" .. showcase[i].name .. ".png"
				SKIN:Bang("!setOption", j, "imagename", imageFile)
				SKIN:Bang("!setOption", "mItemName" .. j, "string", showcase[i].name)
				local brand, model = showcase[i].name:match("(.-)%s%-%s(.*)$")
				if model == nil then -- for the favorites
					SKIN:Bang("!setOption", "mItemDescript" .. j, "string", "Favorites#CRLF#Games: " .. #showcase[i].games .. " in playlist")
				else
					SKIN:Bang("!setOption", "mItemDescript" .. j, "string", "Brand: " .. brand .. "#CRLF#Model: " .. model .. "#CRLF#Games: " .. #showcase[i].games .. " in playlist")
				end
				SKIN:Bang("!setOption", j, "meterStyle", "IconBG | ConsoleAction")
			end
		end
	elseif currConsole <= #consoles then -- concerning games about a console
		if currConsole > 0 and #showcase == #consoles[currConsole].games then
			SKIN:Bang("!setOption", "filter", "group", '""')
		else
			SKIN:Bang("!setOption", "filter", "group", "menuSelect | menus")
		end
		for i = start + 1, start + MAX do
			local j = i - start
			if i <= #showcase then
				local imageFile = nil
				if currConsole <= 1 then -- favorites
					imageFile = DIR .. "thumbnails\\" .. showcase[i].db_name .. "\\" .. useBoxArt .. "\\" .. showcase[i].label:gsub("&", "_") .. ".png"
				else 
					imageFile = DIR .. "thumbnails\\" .. showcase[i].db_name .. "\\" .. useBoxArt .. "\\" .. showcase[i].label:gsub("&", "_") .. ".png"
				end
				local foundFile = io.open(imageFile)
				if foundFile ~= nill then
					foundFile:close()
				else
					-- print("couldn't find image for " .. showcase[i].label)
					imageFile = DIR .. "assets\\xmb\\" .. theme .. "\\png\\" .. showcase[i].db_name .. "-content.png"
				end
				SKIN:Bang("!setOption", j, "imagename", imageFile)
				-- for specificity, parse title from path's filename instead of label
				-- local description = showcase[i].path:match(".*\\(.*)%..+$")
				local description = showcase[i].label
				description = description:gsub("%[.+%]", "") -- lose the version info
				description = description:gsub("%(.+%)", "") -- lose the country code
				description = description .. "#CRLF#"
				if showcase[i].core_path ~= "DETECT" then
					description = description .. showcase[i].core_path:match(".*\\(.*)$")
				else
					description = description .. showcase[i].core_path
				end
				SKIN:Bang("!setOption", "mItemDescript" .. j, "string", description)
				SKIN:Bang("!setOption", "mItemName" .. j, "string", showcase[i].label)
				SKIN:Bang("!setOption", "mItemDIR" .. j, "string", showcase[i].path)
				SKIN:Bang("!setOption", "mItemCore" .. j, "string", showcase[i].core_path)
				SKIN:Bang("!setOption", "mItemSize" .. j, "formula", showcase[i].size)
				SKIN:Bang("!setOption", "mItemPlayTime" .. j, "formula", showcase[i].playtime)
				if showcase[i].lastPlayed > 0 then
					local format_t = nil
					if tonumber(os.date("%Y", os.time())) - tonumber(os.date("%Y", showcase[i].lastPlayed)) > 1 then -- if less than a year ago
						format_t = os.date('%b %d#CRLF#%I:%M', showcase[i].lastPlayed)
						format_t = format_t:gsub("#0", "#") .. string.lower(os.date("%p", showcase[i].lastPlayed))
					else
						format_t = os.date('%b \'%y#CRLF#%a, %d', showcase[i].lastPlayed)
					end
					format_t = format_t:gsub("%s0", "%s")
					-- print(format_t)
					SKIN:Bang("!setOption", "mItemLastPlayed" .. j, "string", format_t)
				else
					SKIN:Bang("!setOption", "mItemLastPlayed" .. j, "string", "never")
				end
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
	SKIN:Bang("!writeKeyValue", "Variables", "page", page, 
		string.format("%s%s\\%s\\SpecificVars.inc", resources, currentConfig, service))
	SKIN:Bang("!UpdateMeasureGroup", "InfoMeasures")
	return #showcase
end

function enableAggHist()
	local conf = io.open(DIR .. "retroarch.cfg", "r+")
	if conf ~= nil then
		local lines = conf:read("*all")
		conf:seek("set", 0)
		if lines:match("content_runtime_log_aggregate = \"false\"") ~= nil then
			-- print("found history option")
			local newcontent, altered = lines:gsub(
				"content_runtime_log_aggregate = \"false\"",
				"content_runtime_log_aggregate = \"true\"")
			-- print(string.format("altered %d line", altered))
			conf:write(newcontent)
		end
		conf:close()
	end
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