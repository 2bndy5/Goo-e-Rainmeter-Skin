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
	-- move favorites to index 1
	for i = 1, #self do
		if self[i].label == "Favorites" then
			local temp = table.remove(self, i)
			table.insert(self, 1, temp)
			break
		end
	end
end

function apps.filter(self, arg)
	local result = apps.new()
	currConsole = SKIN:GetVariable("console")
	filter = SKIN:GetVariable("filter")
	if currConsole == "Favorites" and filter == "db_name" then
		filter = "favorites"
	end
	for i = 1, #self do
		if filter == "history" then -- assemble showcase of games played
			if self[i].lastPlayed > 0 then
				table.insert(result, self[i])
			end
		elseif filter == "favorites" then -- assemble showcase of favorite games
			if self[i].favorite == true then
				table.insert(result, self[i])
			end
		elseif filter == "db_name" then -- assemble games showcase for a console
			if self[i].db_name == currConsole and not self[i].hidden then
				table.insert(result, self[i])
			end
		else -- assemble consoles/favorites showcase
			if i == 1 then
				local temp = App.new()
				temp.label = "Favorites"
				temp.games = 0
				temp.playtime = 0
				temp.lastPlayed = 0
				temp.size = 0
				table.insert(result, 1, temp) 
			end
			if self[i].favorite then -- update favorites
				result[1].games = result[1].games + 1
				result[1].playtime = result[1].playtime + self[i].playtime
				if self[i].lastPlayed > result[1].lastPlayed then
					result[1].lastPlayed = self[1].lastPlayed
				end
				result[1].size = result[1].size + self[i].size
			end
			local isAlreadyAdded = false
			for r = 1, #result do -- check if console is already added
				if result[r].label == self[i].db_name then -- update console
					isAlreadyAdded = true
					result[r].games = result[r].games + 1
					result[r].playtime = result[r].playtime + self[i].playtime
					if self[i].lastPlayed > result[r].lastPlayed then
						result[r].lastPlayed = self[i].lastPlayed
					end
					result[r].size = result[r].size + self[i].size
				end
			end
			if not isAlreadyAdded then -- add new console
				local temp = App.new()
				temp.games = 1
				temp.label = self[i].db_name
				temp.playtime = self[i].playtime
				temp.lastPlayed = self[i].lastPlayed
				temp.size = self[i].size
				table.insert(result, temp)
			end
		end
	end
	if #result == 0 and filter ~= "none" then
		SKIN:Bang("!setVariable", "filter", "none")
		-- print("showcase has no games in it; switching to consoles")
		return self:filter("none")
	else
		return result
	end
end

function apps.print(self, arg)
	for i, v in ipairs(self) do
		if arg == nil then
			local output = string.format("%d: ", i)
			for key, val in pairs(v) do 
				output = output ..  string.format("%s = %s ", key, tostring(val))
			end
			print(output)
		elseif v[arg] ~= nil then
			if arg ~= "name" then
				print(v.label .. "[" .. arg .. "] = " .. v[arg])
			else
				print(i .. " = " .. arg .. ":" .. v[arg])
			end
		else
			print("wrong keyword passed as arg")
		end
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
	db_name = "",
	favorite = false,
	hidden = false
}
App.mt.__index = App.prototype
-- end bueprint for apps{} elements


function applySort()
	showcase:sort()
end

function applyFilter()
	showcase = games:filter()
	applySort()
end

function Initialize()
	currConsole = SKIN:GetVariable('console')
	filter = SKIN:GetVariable("filter")
	resources = SKIN:GetVariable("@")
	currentConfig = SKIN:GetVariable("CURRENTCONFIG")
	service = SKIN:GetVariable("service")
	DIR = SKIN:GetVariable('DIR')
	if DIR[string.len(DIR) - 1] ~= "\\" then
		-- make DIR look like a path
		DIR = string.format("%s\\", DIR)
	end
	page = tonumber(SKIN:GetVariable("page"))
	games = apps.new() -- stores games
	showcase = {} -- used for filtered & sorted list of items to display
end

function startTimer()
	startTime = os.clock()
end

function parseApps()
	local favorites = parsePlaylist(DIR .. "\\content_favorites.lpl")
	local str = SKIN:GetMeasure("mListInfoFiles"):GetStringValue()
	for line in str:gmatch("(.-)\n") do
		local playlist = ""
		if line:match(".*%.lpl") ~= nil then
			playlist = line:match("(.*)%.lpl")
			local roms = parsePlaylist(DIR .. "\\playlists\\" .. playlist .. ".lpl")
			for i = 1, #roms do -- merge roms into all games table
				for j = 1, #favorites do -- flag favorites
					if roms[i].path == favorites[j].path then
						roms[i].favorite = true
					end
				end
				table.insert(games, roms[i])
			end
		end
	end
	-- all roms imported via retroarch have been discovered
	local playtimes = SKIN:GetMeasure("mListRetroarchHistory"):GetStringValue()
	for line in playtimes:gmatch("(.-)\n") do
		-- print("reading playtimes for " .. line:sub(1, -6))
		local file = io.open(DIR .. "\\playlists\\logs\\" .. line:match(".*"))
		if file ~= nil then
			local gametime = {}
			for l in file:lines() do
				if l:match("\"runtime\":") ~= nil then
					local h, m, s = l:match("\"runtime\":%s+\"(%d+):(%d+):(%d+)\",")
					gametime.ran = tonumber(h) * 60 * 60 + tonumber(m) * 60 + tonumber(s)
				elseif l:match("\"last_played\": ") then
					local y, mo, d, h, mi, s = l:match("\"last_played\": \"(%d+)%-(%d+)%-(%d+) (%d+):(%d+):(%d+)\"")
					gametime.last = os.time{year=y, month=mo, day=d, hour=h, min=mi, sec=s}
				end
			end
			file:close()
			line = line:gsub("%-", "%%-") -- make hyphens arbitrary
			line = line:gsub("%(.-%)", "%%(.-%%)") -- make country code arbitrary
			line = line:gsub("%[.-%]", "%%[.-%%]") -- make version code arbitrary
			for i = 1, #games do
				if games[i].path:match(line:sub(1, -6)) then
					-- print("found " .. line:sub(1, -5) .. ". Inserting playtimes")
					games[i].playtime = gametime.ran
					games[i].lastPlayed = gametime.last
				end
			end
		end
	end
	if #games == 0 then
		SKIN:Bang("!setOption", "loadingScreen", "text", "No gamed found in playlists")
	end
	local endTimer = os.clock()
	SKIN:Bang("!log", "games/apps data loaded in " .. string.format("%.3f", endTimer - startTime) .. " seconds", "Notice")
	SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function parsePlaylist(filename)
	local file = io.open(filename, "r")
	local foundList = false
	local defaultCore = nil
	local roms = apps.new()
	-- print("reading " .. filename)
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
					table.insert(roms, result)
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
	return roms
end

function Update()
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
	elseif useBoxArt == -1 then
		useBoxArt = "Named_Titles"
	end
	if #showcase - start < MAX then
		if #showcase < MAX then
			start = 0
		else
			start = #showcase - MAX
		end
	end
	if #showcase > 0 then 
		for i = start + 1, start + MAX do
			local j = i - start
			if i <= #showcase then
				-- setup generic stats for applicable to all items
				local imageFile = nil
				SKIN:Bang("!setOption", "mItemName" .. j, "string", showcase[i].label)
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
					SKIN:Bang("!setOption", "mItemLastPlayed" .. j, "string", format_t)
				else
					SKIN:Bang("!setOption", "mItemLastPlayed" .. j, "string", "never")
				end
				-- set up stats applicable to concoles or games
				if filter == "none" then -- concerning consoles
					imageFile = DIR .. "assets\\xmb\\" .. theme .. "\\png\\" .. showcase[i].label .. ".png"
					SKIN:Bang("!setOption", j, "imagename", imageFile)
					SKIN:Bang("!setOption", "mItemName" .. j, "string", showcase[i].label)
					local brand, model = showcase[i].label:match("(.-)%s%-%s(.*)$")
					if model == nil then -- for the favorites
						SKIN:Bang("!setOption", "mItemDescript" .. j, "string", "Favorites#CRLF#Games: " .. showcase[i].games .. " in playlist")
					else
						SKIN:Bang("!setOption", "mItemDescript" .. j, "string", "Brand: " .. brand .. "#CRLF#Model: " .. model .. "#CRLF#Games: " .. showcase[i].games .. " in playlist")
					end
					SKIN:Bang("!setOption", j, "meterStyle", "IconBG | ConsoleAction")
					SKIN:Bang("!setoption", "back2Consoles", "meterStyle", "history")
				else -- concerning games about a console
					imageFile = DIR .. "thumbnails\\" .. showcase[i].db_name .. "\\" .. useBoxArt .. "\\" .. showcase[i].label:gsub("&", "_")
					if doesImageExist(imageFile .. ".png") then
						SKIN:Bang("!setOption", j, "imagename", imageFile .. ".png")
					elseif doesImageExist(imageFile .. ".jpg") then
						SKIN:Bang("!setOption", j, "imagename", imageFile .. ".jpg")
					else
						-- print("couldn't find image for " .. showcase[i].label)
						imageFile = DIR .. "assets\\xmb\\" .. theme .. "\\png\\" .. showcase[i].db_name .. "-content.png"
					end
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
					SKIN:Bang("!setOption", "mItemDIR" .. j, "string", showcase[i].path)
					SKIN:Bang("!setOption", "mItemCore" .. j, "string", showcase[i].core_path)
					SKIN:Bang("!setOption", j, "meterStyle", "IconBG | GameAction")
					SKIN:Bang("!setoption", "back2Consoles", "meterStyle", "backButton")
				end
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

function doesImageExist(game_name)
	local FoundFile = io.open(game_name,'r')
	if not FoundFile then
	-- print(game_name .. ' not found')
	return false
	else
	-- print(game_name .. ' found for item# ' .. i - start)
	io.close(FoundFile)
	return true
	end
end

function pageUp()
	page = page + 1
	-- wrap around scrolling
	if page * 12 > #showcase then page = 0 end
	SKIN:Bang('!updateMeasure', 'mParseApps')
end

function pageDn()
	page = page - 1
	-- wrap around scrolling
	if page < 0 then page = math.floor(#showcase / 12) end
	SKIN:Bang('!updateMeasure', 'mParseApps')
end

function cleanUp()
	while #showcase > 0 do
		table.remove(showcase)
	end
	while #games > 0 do
		table.remove(games)
	end
end