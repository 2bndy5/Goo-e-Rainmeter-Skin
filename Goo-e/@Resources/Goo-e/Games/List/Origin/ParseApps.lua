
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

function apps.sort(self, arg)
	local i = 1
	if arg == nil then arg = SKIN:GetVariable('sort') end
	local reverse = SKIN:GetVariable('revOrder')
    while i < #self and self[i + 1][arg] ~= nil do
        if self[i][arg] > self[i + 1][arg] then
            local temp = table.remove(self, i)
            table.insert(self, i + 1, temp)
            i = 1
        else
            i = i + 1
        end
    end
    if tonumber(reverse) > 0 then 
		for i = 1, #self / 2 do
			local temp = self[i]
			self[i] = self[#self-i+1]
			self[#self-i+1] = temp
		end
	end
end

function apps.filter(self, arg)
	local result = apps.new()
	local hiddenList = SKIN:GetVariable("hiddenList")
	local hidden = {}
	for str in string.gmatch(hiddenList, '(%d+)|') do
		table.insert(hidden, tonumber(str))
	end
	-- print(table.concat(hidden, ","))
	local showHidden = false
	if SKIN:GetVariable("filter"):match("hidden") ~= nil then
		showHidden = true
	end
	local i = 1
	while i <= #self do
		local isHidden = false
		for j, k in ipairs(hidden) do
			if self[i].id == k then -- user blacklisted (dynamic list based on user input)
				isHidden = true
				break
			end
		end
		if isHidden == showHidden then
			table.insert(result, self[i])
		end
		i = i + 1
	end
	if #result == 0 and showHidden == true then
		SKIN:Bang("!setVariable", "filter", "none")
		-- print("showcase has nothing in it; switching to different filter")
		return self:filter("none")
	else
		return result
	end
	return result
end

function apps.print(self, arg)
    for i, v in ipairs(self) do
		if arg == nil then 
			local output = tostring(i)
			for key, val in pairs(v) do
				output = output .. string.format(" %s = %s", key, tostring(val))
			end
			print(output)
		elseif v[arg] ~= nil then
			print(i .. ' = ' .. arg .. ":" .. v[arg])
		else
			print("wrong keyword passed as arg")
		end
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
	name = '',
	path = '',
	shortcut = '',
	size = 0 ,
	id = 0,
	-- tStamp = 0
}
App.mt.__index = App.prototype	
-- end bueprint for apps{} elements

function addHidden(str)
	local hiddenList = SKIN:GetVariable("hiddenList")
	hiddenList = hiddenList .. str .. "|"
	-- print(hiddenList)
	SKIN:Bang("!setVariable", "hiddenList", hiddenList)
	SKIN:Bang(
		"!writeKeyvalue", "Variables", "hiddenList", hiddenList,
		resources .. currentConfig .. "\\Origin\\SpecificVars.inc")
	SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function subHidden(str)
	-- print("subtracting " .. str)
	local hiddenList = SKIN:GetVariable("hiddenList")
	hiddenList = hiddenList:gsub(str .. '%|', '')
	-- print(hiddenList)
	SKIN:Bang("!setVariable", "hiddenList", hiddenList)
	SKIN:Bang(
		"!writeKeyvalue", "Variables", "hiddenList", hiddenList,
		resources .. currentConfig .. "\\Origin\\SpecificVars.inc")
	SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function applyFilter()
    apps:sort()
    showcase = apps:filter()
end

function Initialize()
	filter = SKIN:GetVariable("filter")
	resources = SKIN:GetVariable("@")
	currentConfig = SKIN:GetVariable("CURRENTCONFIG")
	page = tonumber(SKIN:GetVariable("page"))
	MAX = 12
	showcase = {}
end

function startTimer()
	startTime = os.clock()
end

function parseApps()
    local str = SKIN:GetMeasure('mListInfoFiles'):GetStringValue()
    local path = ''
    for line in str:gmatch"(.-)\n" do
        if line:match('\\__Installer') ~= nil then
            path = line:match('(.*)\\__Installer')
			-- convert Origin's install log to utf-8 & output to a temp file
			local tempOutput = resources .. currentConfig .. '\\Origin\\UTF8.txt'
			local psCmd = 'powershell "Get-Content \'' .. line .. '\' | Set-Content -Encoding utf8 \'' .. tempOutput .. '\'"'
			SKIN:Bang("!SetVariable", "PSCMD", psCmd)
			SKIN:Bang("!commandMeasure", "convert2utf8", "run")
			SKIN:Bang("!UpdateMeasure", "convert2utf8")
			while SKIN:GetMeasure("convert2utf8"):GetValue() < 1 do
				SKIN:Bang("!UpdateMeasure", "convert2utf8")
			end
			local app = parseLog(tempOutput)
			--now get the "content ID" from intalldata.xml
			psCmd = 'powershell "Get-Content \'' .. line:gsub("InstallLog.txt", "installerdata.xml") .. '\' | Set-Content -Encoding utf8 \'' .. tempOutput .. '\'"'
			SKIN:Bang("!SetVariable", "PSCMD", psCmd)
			SKIN:Bang("!commandMeasure", "convert2utf8", "run")
			SKIN:Bang("!UpdateMeasure", "convert2utf8")
			while SKIN:GetMeasure("convert2utf8"):GetValue() < 1 do
				SKIN:Bang("!UpdateMeasure", "convert2utf8")
			end
			local file = io.open(tempOutput, "r")
			if file ~= nil then
				contentID = file:read("*all"):match(".-<contentID>(%d-)</contentID>")
				file:close()
				app.id = tonumber(contentID)
			end
			-- Ilost an unrelated file with this implemented; use at your own risk!
			-- os.remove(tempOutput) -- delete temp file converted to utf-8
			app.path = path
			SKIN:Bang("!setVariable", "testDir", path)
			SKIN:Bang("!updateMeasure", "dirSizeInfo")
			local actualSize = tonumber(SKIN:GetMeasure("dirSizeInfo"):GetValue())
			app.size = actualSize
			if string.len(app.name) == 0  then
				app.name = path:match(".*\\(.*)$")
			end
			table.insert(apps, app)
        end
    end
	local endTimer = os.clock()
	SKIN:Bang("!log", "games/apps data loaded in " .. string.format("%.3f", endTimer - startTime) .. " seconds", "Notice")
	-- apps:print()
	SKIN:Bang("!UpdateMeasure", "mParseApps")
end

--Log files have to be encoded to UTF-8; lua doesn't recognize UTF-16 LE (Origin's default encoding scheme)
function parseLog(fileStr)
	-- print('reading file = ' .. fileStr)
	local result = App.new()
	local hasShortcut = false
	local foundShortcut = false
	local file = io.open(fileStr, 'r')
	if file ~= nil then
		for line in file:lines() do
			-- install date is not needed
			-- if line:find('Install Date: ') ~= nil then
				-- print(string.match(line, 'Install Date: (.*)'))
			-- end
			if not foundShortcut then
				if line:find('CREATE_STARTMENU_ICON is ') ~= nil then
					if tonumber(string.match(line, 'CREATE_STARTMENU_ICON is (%d+)')) > 0 then
						hasShortcut = true
					end
				elseif line:find('CREATE_DESKTOP_ICON is ') ~= nil then
					if tonumber(string.match(line, 'CREATE_DESKTOP_ICON is (%d+)')) > 0 then
						hasShortcut = true
					end
				end
				if hasShortcut and line:find('Successfully created shortcut at') ~= nil  then
					local temp = line:match('Successfully created shortcut at..(.*)')
					result.shortcut = temp
					foundShortcut = true
					hasShortcut = false
				end
			end
			if line:match("%(Config%)Game Name: ") ~= nil then
				result.name = line:match("%(Config%)Game Name: (.*)")
			end
		end
		file:close()
	else
		print(fileStr .. ' is inaccessible!')
	end
	return result
end

function Update()
	applyFilter()
    if #apps ~= #showcase then
        SKIN:Bang('!setOption', 'filter', 'group', 'menuSelect')
    else
        SKIN:Bang('!setOption', 'filter', 'group', 'none')
    end
	start = page * MAX
    if #showcase - start < MAX then 
        if #showcase < MAX then 
            start = 0
        else start = #showcase - MAX end
    end
    -- print('start = '.. start)
    local max = MAX
	if #showcase < MAX then max = #showcase end
	local SkinsPath = SKIN:GetVariable("SkinsPath")
	if #showcase > 0 then
		SKIN:Bang('!hideMeter', 'loadingScreen')
        for i = start + 1, start + max do
            SKIN:Bang('!SetOption', 'mItemName' .. i - start, 'String', showcase[i].name)
			SKIN:Bang('!SetOption', 'mItemDIR' .. i - start, 'String', showcase[i].path)
            SKIN:Bang('!SetOption', 'mItemSize' .. i - start, 'formula', showcase[i].size)
			SKIN:Bang("!SetOption", 'mItemDescript' .. i - start, 'string', showcase[i].name)
			SKIN:Bang("!SetOption", 'mItemRunLink' .. i - start, 'string', showcase[i].shortcut)
			SKIN:Bang("!SetOption", 'mItemId' .. i - start, 'string', showcase[i].id)
			local temp = SkinsPath .. currentConfig .. '\\User Obtained Boxart\\' .. showcase[i].name
			-- print(temp)
			if doesImageExist(temp .. '.jpg') then
				SKIN:Bang('!SetOption', i - start, 'imageName', temp .. '.jpg')
			elseif doesImageExist(temp .. ".png") then
				SKIN:Bang('!SetOption', i - start, 'imageName', temp .. ".png")
			else
				SKIN:Bang('!SetOption', i - start, 'imageName', '""')
			end
		end
	else
		SKIN:Bang('!showMeter', 'loadingScreen')
		SKIN:Bang('!hideMetergroup', 'item12')
		SKIN:Bang('!hideMetergroup', 'scrollpages')
		SKIN:Bang('!SetOptionGroup', 'item12', 'x', 0)
		SKIN:Bang('!SetOptionGroup', 'item12', 'Y', 0)
	end
    SKIN:Bang('!UpdateMeasureGroup', 'InfoMeasures')
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
    if page * MAX > #showcase then page = 0 end
    Update()
    -- print('pg = ' .. page)
end

function pageDn()
    page = page - 1
    -- wrap around scrolling
    if page < 0 then page = math.floor(#showcase / MAX) end
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