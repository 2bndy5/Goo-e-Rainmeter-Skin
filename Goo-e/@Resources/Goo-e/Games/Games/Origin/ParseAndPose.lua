
-- begin blueprint for apps{} sorting and filtering
apps = {}
BLtable = {}
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

function apps.filter(arg)
	local result = apps.new() --shadow copy
    local filter = SKIN:GetVariable('filter')
    local hiddenList = SKIN:GetVariable('originHiddenList')
    local hidden = {}
	local i = hiddenList:find('"')
    if i == nil then i = hiddenList:len() else i = i + 1 end
    while i < hiddenList:len() do
        local e = hiddenList:find('"', i)
        if e == nil then e = hiddenList:len() end
        if e - i > 2 then
            local temp = hiddenList:sub(i, e - 1)
            print('hList['.. #hidden + 1 .. ']: ' .. temp)
            table.insert(hidden, temp)
        end
        e = hiddenList:find('"', e + 1)
        if e == nil then break else i = e + 1 end
    end
    i = 1
	while i <= #apps do
		local isHidden = false
		for j, k in ipairs(BLtable) do
			if apps[i].id == tonumber(k) then -- blacklisted (my permanent list of non executables)
				isHidden = true
				break
			end
		end
        for j, k in ipairs(hidden) do
			-- print(apps[i].id .. ' = ' .. k)
            if apps[i].id == k then -- user blacklisted (dynamic list based on user input)
				isHidden = true
				break
			end
		end
		if filter:match('hidden')~= nil then isHidden = not isHidden end
        if isHidden == false then table.insert(result, apps[i])	end
		i = i + 1 
	end
	return result
end

function apps.print(self, arg)
    for i, v in ipairs(self) do
		if arg == nil then 
			print(i .. ' = id:' .. v.id .. ', name:' .. v.name .. ', path' .. v.path .. ', dir:' .. v.dir .. ', size:' .. v.size .. ', time:' .. v.tStamp)
		elseif v[arg] ~= nil then
			print(i .. ' = ' .. arg .. ":" .. v[arg])
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
App.prototype = {id = 0, name = '', path = '', dir = '', size = 0 , tStamp = ''}
App.mt.__index = App.prototype	
-- end bueprint for apps{} elements

function Initialize()
	SKIN:Bang('!commandMeasure', 'mListFolders', 'run')
    CURRENTPATH = SKIN:MakePathAbsolute(SKIN:GetVariable('CURRENTPATH'))
	WR2 = tonumber(SKIN:GetVariable('WR2'))
    currentConfig = SKIN:GetVariable('CURRENTCONFIG')
    resources = SKIN:GetVariable('@')
	MAX = 12
	showcase = {}
    page = 0
    size_i = 1
end

function parseApps()
    local str = SKIN:GetMeasure('mListFolders'):GetStringValue()
    local path = ''
    for line in str:gmatch"(.-)\n" do
        if line:match(' Directory of (.*)') ~= nil then
            path = line:match(' Directory of (.*)') .. '\\'
            -- print ('path = ' .. path)
        elseif line:match('<DIR>.*(%w+)') ~= nil then
            local appID = line:match('<DIR>%s+(.*)$')
            if appID ~= '..' and appID ~= '.' then 
                -- print('reading file = ' .. path .. appID)
                local app = parsePath(path, appID)
                local temp = line:match('(.*M)%s+<DIR>')
                app.tStamp = convertTime(temp)
                table.insert(apps, app)
            end
        end
    end
    applyFilter()
    Update()

end

function getSizes()
    SKIN:Bang('!setVariable', 'temp', '"' .. apps[size_i].path .. apps[size_i].dir .. '"')
    SKIN:Bang('!updateMeasure', 'mItemSize')
    SKIN:Bang('!commandMeasure', 'mItemSize', 'run')
end

function takeSize(size)
    -- print('recieved size of ' .. size .. ' bytes')
    if size_i > #apps - 1 then
        apps[size_i].size = tonumber(size)
        size_i = size_i + 1
        if size_i >= #apps then
            SKIN:Bang('!setVariable', 'temp', '"' .. apps[size_i].path .. apps[size_i].dir .. '"')
            SKIN:Bang('!updateMeasure', 'mItemSize')
            SKIN:Bang('!commandMeasure', 'mItemSize', 'run')
        else 
            SKIN:Bang('!disableMeasure', 'mItemSize') 
            -- apps:print('size')
        end
    end
end

function cleanString(str)
	local t = { string.gsub(str, '  ', ' ') }
    t = { string.gsub(t[1], '(%w)%.(%w)', '%1 %2') }
	local patterns = {"%.", '%"', "'"}
	for i,v in ipairs(patterns) do
		t = { string.gsub(t[1], v, "") }
		--print(t[1])
	end
	return t[1]
end

function addHidden(str)
    -- print('adding itemn: ' .. str .. ' to hidden list')
    local hiddenList = SKIN:GetVariable('originHiddenList')
    hiddenList = hiddenList .. ' "' .. str .. '"'
    -- print(hiddenList)
    SKIN:Bang('!setVariable', 'originHiddenList', '"' .. hiddenList .. '"')
    SKIN:Bang('!writeKeyvalue', 'Variables', 'originHiddenList', '"' .. hiddenList .. '"', resources .. currentConfig .. '\\Variables.inc')
    applyFilter()
    Update()
end

function subHidden(str)
    print('subtracting itemn: ' .. str .. ' from hidden list')
    local hiddenList = SKIN:GetVariable('originHiddenList')
    hiddenList = hiddenList:gsub('"' .. str .. '" ', '')
    print(hiddenList)
    SKIN:Bang('!setVariable', 'originHiddenList', '"' .. hiddenList .. '"')
    SKIN:Bang('!writeKeyvalue', 'Variables', 'originHiddenList', '"' .. hiddenList .. '"', resources .. currentConfig .. '\\Variables.inc')
    applyFilter()
    Update()
end

function convertTime(str)
	local hr = tonumber(str:sub(13, 14))
	if str:match("PM") ~= nil then hr = hr + 12 end
	hr = hr * 60
	local mn = tonumber(str:sub(16, 17))
	local mon = tonumber(str:sub(1, 2)) * 43800
	local day = tonumber(str:sub(4, 5)) * 1440
	local yr = tonumber(str:sub(7, 10)) * 525600
	return hr + mn + mon + day + yr 
end


function applySort()
    showcase:sort()
end

function applyFilter()
    apps:sort()
    showcase = apps:filter()
end

function parsePath(path, dir)
	local result = App.new()
    -- parseLog(fileStr, i)
    --print('path + dir=' .. path .. dir)
	result.id = dir
	result.dir = dir
	result.name = cleanString(dir)
    result.path = path
    return result
end

function Update()
    if #apps ~= #showcase then
        SKIN:Bang('!setOption', 'menu4', 'group', 'menuSelect')
    else
        SKIN:Bang('!setOption', 'menu4', 'group', 'none')
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
	if #showcase > 0 then
        for i = start + 1, start + max do
            SKIN:Bang('!SetOption', 'mItemID' .. i - start, 'String', showcase[i].id)
            SKIN:Bang('!SetOption', 'mItemName' .. i - start, 'String', showcase[i].name)
            SKIN:Bang('!SetOption', 'mItemDIR' .. i - start, 'String', showcase[i].path .. showcase[i].dir)
            SKIN:Bang('!SetOption', 'mItemSize' .. i, 'folder', showcase[i].path .. showcase[i].dir)
	        SKIN:Bang('!UpdateMeasure', 'mItemSize' .. i - start)
            local temp = CURRENTPATH .. '\\DownloadFile\\' .. showcase[i].id .. '.jpg'
            local FoundFile = io.open(temp,'r')
            if not FoundFile then
            --print(temp .. ' not found')
                SKIN:Bang('!SetOption', i - start, 'MeterStyle', 'IconBG')
            else
            --print(temp .. ' found')
                io.close(FoundFile)
                SKIN:Bang('!SetOption', i - start, 'MeterStyle', 'GameBanner')
                -- SKIN:Bang('!SetOption', i - start, 'imageName', temp)
			end
		end
		setGrid()
	else 
		SKIN:Bang('!hideMetergroup', 'item12')
		SKIN:Bang('!hideMetergroup', 'scrollpages')
		SKIN:Bang('!SetOptionGroup', 'item12', 'x', 0)
		SKIN:Bang('!SetOptionGroup', 'item12', 'Y', 0)
	end
    SKIN:Bang('!UpdateMeasureGroup', 'StringMeasures')
    return #showcase
end

function switchAxis()
	WR2 = tonumber(SKIN:GetVariable('WR2'))
	if WR2 > 0 then WR2 = 0 else WR2 = 1 end
	SKIN:Bang('!writeKeyvalue', 'variables', 'WR2', WR2, '#@##CurrentConfig#\\Variables.inc')
	SKIN:Bang('!setVariable', 'WR2', WR2)
	setGrid()
end

function setGrid()
	local WorkAreaHeight = tonumber(SKIN:GetVariable('WorkAreaHeight'))
	local WorkAreaWidth = tonumber(SKIN:GetVariable('WorkAreaWidth'))
	local H = 0
	local W = 0
	local X = 0	--Skin center X
	local Y = 0	--Skin center Y
	local cellW = 0
	local cellH = 0
	local Min = tonumber(SKIN:GetVariable('Minimize'))
	-- for hiding/showing scrollpages meter group
	local showPages = 0
	if #showcase > MAX then showPages = 1 else showPages = 0 end
	local max = MAX
    if #showcase < MAX then max = #showcase end
	if WorkAreaWidth > WorkAreaHeight then
		-- print('landscape mode')
		if #showcase <= 2 then
			H = 1
			W = #showcase
		else 
			W = math.ceil(#showcase / 2)
			if W > 6 then W = 6 end
			H = 0
			while W * H < max do H = H + 1 end
		end
	else
		-- print('portrait mode')
		if #showcase < 3 then W = 1 else W = 2 end
		H = 0
		while W * H < max do H = H + 1 end
	end

	if Min < 1 then
		cellH = math.floor(WorkAreaHeight * 3 / 4 / H)
		cellW = math.floor(cellH * 5 / 7)
	else
		cellH = math.floor(WorkAreaHeight / H)
		cellW = math.floor((WorkAreaWidth - 90) / W)
	end

	X = math.floor(cellW * W / 2)
	Y = math.floor(cellH * H / 2)
	-- local layout = { WorkAreaWidth, WorkAreaHeight, cellW, cellH, X, Y, W, H }
	-- print(table.concat(layout, ', '))
	local offset = 0
	for i = 1, 12 do
		if i <= #showcase then
		--ordered from left to right
			if WR2 == 0 then
				if (#showcase - i) < W and (i - 1) % W == 0 and (#showcase % W) > 0 then
					offset = (W - (#showcase % W)) / 2
			-- print(i .. ' offset = ' .. offset)
				end
				SKIN:Bang('!moveMeter', 90 + cellW * (((i - 1) % W) + offset), cellH * math.floor((i - 1) / W), i)

		--ordered from top to bottom
			elseif WR2 == 1 then
				if (#showcase - i) < H and (i - 1) % H == 0 and (#showcase % H) > 0 then
					offset = (H - (#showcase % H)) / 2
		-- print(i .. ' offset = ' .. offset)
				end
				SKIN:Bang('!moveMeter', 90 + cellW * math.floor((i - 1) / H), cellH * (((i - 1) % H) + offset), i)
			end
			SKIN:Bang('!showMeter', i)
		else 
			SKIN:Bang('!hideMeter', i)
			SKIN:Bang('!moveMeter', 0, 0, i)
			SKIN:Bang('!hideMeterGroup', 'info' .. i)
		end
	end
	if #showcase > 12 then
		SKIN:Bang('!MoveMeter', 10, 0, 'indexup')
		SKIN:Bang('!MoveMeter', 10, 2 * Y - 70, 'indexDown')
		SKIN:Bang('!showMeterGroup', 'scrollpages')
	else
		SKIN:Bang('!hideMeterGroup', 'scrollpages')
		SKIN:Bang('!MoveMeter', 0, 0, 'indexup')
		SKIN:Bang('!MoveMeter', 0, 0, 'indexdown')
	end
	local y0 = Y - 135
	if y0 < 0 then y0 = 0 end
	SKIN:Bang('!MoveMeter', 0, y0, 'MinimizeToggle')
	SKIN:Bang('!setVariable', 'iconW', cellW)
	SKIN:Bang('!setVariable', 'iconH', cellH)
end

--Log files have to be encoded to UTF-8 BOM please implement following PS script:
--Get-Content .\test.txt | Set-Content -Encoding utf8 test-utf8.txt
-- all this works if the codepage set to UTF-8 just to get a friendly name and launching shortcut
function parseLog(fileStr, i)
	local result = { nil, nil }
	local filename = fileStr .. '\\__Installer\\InstallLog.txt'
	-- print(filename)
	-- os.execute('Get-Content "' .. filename .. '" | Set-Content -Encoding utf8 "' .. fileStr .. '\\__Installer\\InstallLog_UTF8.txt"')
	filename = fileStr .. '\\__Installer\\InstallLog_UTF8.txt'
	local file = io.open(filename, 'rb')
	if file == nil then 
		filename = fileStr .. '\\__Installer\\InstallLog.txt'
		file = io.open(filename, 'rb')
	end
	local hasShortcut = false
	local foundShortcut = false
	if file ~= nil then
		for line in file:lines() do
			-- if line:find('Install Date: ') ~= nil then
	-- this is not needed
				-- print(string.match(line, 'Install Date: (.*)'))
			-- end
			if line:find('CREATE_STARTMENU_ICON is ') ~= nil then
				if tonumber(string.match(line, 'CREATE_STARTMENU_ICON is (%d+)')) > 0 then
					-- print('created start menu shortcut')
					hasShortcut = true
				end
			elseif line:find('CREATE_DESKTOP_ICON is ') ~= nil then
				if tonumber(string.match(line, 'CREATE_DESKTOP_ICON is (%d+)')) > 0 then
					-- print('created desktop shortcut')
					hasShortcut = true
				end
			end
			if hasShortcut == true and line:find('Successfully created shortcut at') ~= nil then
				local temp = line:match('Successfully created shortcut at..(.*)')
				-- print("shortcut = " .. temp)
				result[2] = temp
				-- foundShortcut = true
				hasShortcut = false
			end
			-- if line:find('%(Config%)Studio: ') ~= nil then
				-- local temp = string.match(line, '%(Config%)Studio: (.*)')
				-- print(temp)
			-- end
			-- if line:find('Install Location: ') ~= nil then
				-- local temp = string.match(line, 'Install Location: (.*)')
				-- print(temp)
				-- SKIN:Bang('!SetOption', 'mItemDIR' .. i, 'String', temp)
				-- SKIN:Bang('!SetOption', 'mItemSize' .. i, 'folder', temp)
				-- SKIN:Bang('!updateMeasure', 'mItemSize' .. i)
			-- end
			if line:find('%(Config%)Game Name: ') ~= nil then
				local temp = string.match(line, 'Game Name: (.*).')
				SKIN:Bang('!SetOption', 'mItemName' .. i, 'String', temp)
				-- print(temp)
				temp = cleanString(temp)
				-- SKIN:Bang('!SetOption', 'mItemID' .. i, 'String', temp)
				result[1] = temp .. '.jpg'
				-- print(temp .. '.jpg')
			end
		end
		file:close()
	else print(filename .. ' is inaccessible!')
	end
	return { result[1], result[2] }
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