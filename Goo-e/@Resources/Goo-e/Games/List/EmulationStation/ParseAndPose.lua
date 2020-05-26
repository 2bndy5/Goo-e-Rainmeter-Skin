function Initialize()
	CURRENTPATH = SKIN:MakePathAbsolute(SKIN:GetVariable('CURRENTPATH'))
	Service = SKIN:GetVariable('Service')
	ServiceDir = SKIN:MakePathAbsolute(SKIN:GetVariable('ActiveES'))
	skinName = SKIN:GetMeasure('MeasureConfigName'):GetStringValue()
	menuName = SKIN:GetMeasure('mSubConfigName'):GetStringValue()
	rootConfig = SKIN:GetVariable('RootConfig')
	consoles = {}
	games = {}
	parseSystems()
	displayCons()
	displayGames()

end

function subHomepath(str)
	local result = { str:gsub('%/', '\\') }
	result = { result[1]:gsub('%%HOMEPATH%%', ServiceDir) }
	result = { result[1]:gsub('~\\', ServiceDir .. '\\') }
	return result[1]
end

function parseSystems()
-- print(ServiceDir .. '\\.emulationstation\\es_systems.cfg')
	local file = assert(io.open(ServiceDir .. '\\.emulationstation\\es_systems.cfg', 'r'))
	if file ~= nil then
		for line in file:lines() do
			if line:match('<system>') ~= nil then 
				if #consoles > 0 then 
					parseGames(consoles[#consoles][4], consoles[#consoles][2])
					if #games[#consoles] == 0 then --remove console & games for empty lists
			print('removing ' .. consoles[#consoles][1])
						table.remove(consoles)
						table.remove(games)
					end
				end
				table.insert(consoles, {})
			elseif line:match('<fullname>') ~= nil then
				local temp = line:match('<fullname>(.*)</fullname>')
				table.insert(consoles[#consoles], 1, temp)
			elseif line:match('<path>') ~= nil then
				local temp = line:match('<path>(.*)</path>')
				if temp[temp:len()] == '\\' then temp = temp:sub(1, temp:len() - 1) end
				table.insert(consoles[#consoles], 2, temp)
			elseif line:match('<command>') ~= nil then
				local temp = line:match('<command>(.*)</command>')
				temp = subHomepath(temp)
				table.insert(consoles[#consoles], 3, temp)
			elseif line:match('<platform>') ~= nil then
				local temp = line:match('<platform>(.*)</platform>')
				table.insert(consoles[#consoles], 4, temp)
			elseif line:match('<extension>') ~= nil then
				local temp = line:match('<extension>(.*)</extension>')
				temp = temp:gsub(' ', ';')
				temp = { temp:gsub('%.', '') }
				table.insert(consoles[#consoles], 5, temp[1])
			end
		end
		file:close()
	end
end

function parseGames(platform, romPath)
	table.insert(games, {})
	-- print(ServiceDir .. '\\.emulationstation\\gamelists\\' .. platform .. '\\gamelist.xml')
	local file = assert(io.open(ServiceDir .. '\\.emulationstation\\gamelists\\' .. platform .. '\\gamelist.xml', 'r'))
	if file == nil then
		file = assert(io.open(romPath .. '\\gamelist.xml', 'r'))
	end
	if fil ~= nil then
		local capture = false
		for line in file:lines() do
			if line:match('</game>') ~= nil then 
				capture = false
			elseif line:match('<game>') ~= nil then 
				capture = true
				if #games[#games] > 0 then
					local file = io.open(romPath .. '\\' .. games[#games][#games[#games]][2], 'r')
					if file == nil then	
			-- print('removing dead link to ' .. games[#games][#games[#games]][1])
						table.remove(games[#games]) 
					else file:close() end
				end
				table.insert(games[#games], {})
			elseif capture == true and line:match('<name>') ~= nil then
				local temp = line:match('<name>(.*)</name>')
				table.insert(games[#games][#games[#games]], 1, temp)
			elseif capture == true and line:match('<path>') ~= nil then
				local temp = line:match('<path>(.*)</path>')
				if temp:find('\./') ~= nil then temp = temp:sub(temp:find('\./') + 2) end
				temp = subHomepath(temp)
				table.insert(games[#games][#games[#games]], 2, temp)
			elseif capture == true and line:match('<image>') ~= nil then
				local temp = line:match('<image>(.*)</image>')
				temp = subHomepath(temp)
				-- print('image = ' .. temp)
				table.insert(games[#games][#games[#games]], 3, temp)
			end
		end
	-- print(str .. ' has ' .. #games[#games] .. ' games')
		file:close()
	end
end

function getConName(c)
	if c <= #consoles then return consoles[c][1]
	else return 'error' end
end

function getConPath(c)
	if c <= #consoles then return consoles[c][2]
	else return 'error' end
end

function getConCommand(c)
	if c <= #consoles then return consoles[c][3]
	else return 'error' end
end

function getConPlatform(c)
	if c <= #consoles then return consoles[c][4]
	else return 'error' end
end

function getConExt(c)
	if c <= #consoles then return consoles[c][5]
	else return '' end
end

function getGameName(c, i)
	if c <= #consoles and i <= #games[c] then 
		return games[c][i][1]
	else return 'error' end
end

function getGamePath(c, i)
	if c <= #consoles and i <= #games[c] then 
		return consoles[c][2] .. '\\' .. games[c][i][2]
	else return 'error' end
end

function getGameImage(c, i)
	if c <= #consoles and i <= #games[c] then 
		return games[c][i][3]
	else return 'error' end
end

function getGameImagePath(c, i)
	c = tonumber(c)
	i = tonumber(i) + pgBegin - 1
	return getGameImage(c, i)
end

function displayCons()
	local sum = 0
	for i, v in ipairs(consoles) do
		-- print('consoles[' .. i .. '][1] = ' .. v[1])
		-- for j, k in ipairs(v) do
			-- -- print('consoles[' .. i .. '][' .. j .. '] = ' .. k)
		-- end
		sum = sum + 1
	end
	print('found '.. sum .. ' consoles')
end

function displayGames(c)
	local sum = 0
	for i, v in ipairs(games) do
		if c == nil or c == i then 
			for j, k in ipairs(v) do
				-- print('games[' .. i .. '][' .. j .. '][' .. 1 .. '] = ' .. k[1])
				sum = sum + 1
			end
		end
	end
	print('found '.. sum .. ' games')
end

function Update()
	currCon = tonumber(SKIN:GetVariable('console'))
	currGame = tonumber(SKIN:GetVariable('Game'))
	pgBegin = 0
	pgEnd = 0
	if currCon <= 0 then --display consoles
		local temp = currCon * -1 -- restore previous console
		if temp > #consoles then temp = #consoles
		elseif temp == 0 then temp = 1 end -- bounds checking
		if #consoles < 12 then
			pgBegin = 1
			pgEnd = #consoles
		elseif temp >= (#consoles - 12) then 
			pgBegin = (#consoles - 12)
			pgEnd = #consoles
		else
			pgBegin = temp
			pgEnd = temp + 12
		end
		for i = pgBegin, pgEnd - 1 do
			SKIN:Bang('!SetOption', 'mItemName' .. i - pgBegin + 1, 'String', consoles[i][1])
			SKIN:Bang('!SetOption', 'mItemDIR' .. i - pgBegin + 1, 'string', consoles[i][2])
			local currImage = CURRENTPATH .. 'DownloadFile\\' .. consoles[i][4] .. 'Logo.png'
	-- print(i - pgBegin + 1 .. ' = ' .. currImage)
			local FoundFile = io.open(currImage,'r')
			if not FoundFile then
	-- print('currImage .. not found')
				SKIN:Bang('!SetOption', i - pgBegin + 1, 'MeterStyle', 'IconBG')
			else
	-- print('currImage .. found')
				io.close(FoundFile)
				SKIN:Bang('!SetOption', i - pgBegin + 1, 'MeterStyle', 'ConsoleBanner')
				SKIN:Bang('!SetOption', i - pgBegin + 1, 'imageName', currImage)
			end
		end
	elseif currCon > 0 and currCon < #consoles and currGame < #games[currCon] then -- display games
	-- print('Console = ' .. consoles[currCon][1] .. '; Game = ' .. games[currCon][currGame][1])
		-- displayGames(currCon)
		if #games[currCon] < 12 then
			pgBegin = 1
			pgEnd = #games[currCon]
		elseif currGame >= (#games[currCon] - 12) then 
			pgBegin = (#games[currCon] - 12)
			pgEnd = #games[currCon]
		else
			pgBegin = currGame
			pgEnd = currGame + 12
		end
	-- print('pgBegin - pgEnd = ' .. pgBegin .. ' - ' .. pgEnd)
		SKIN:Bang('!SetOption', 'mConName', 'String', consoles[currCon][1])
		for i = pgBegin, pgEnd - 1 do
			if #games[currCon][i] > 0 then	
	-- print('Something was saved')
				SKIN:Bang('!SetOption', 'mItemName' .. i - pgBegin + 1, 'String', games[currCon][i][1])
				local temp = consoles[currCon][2] .. '\\' .. games[currCon][i][2]
	-- print('rom = ' .. temp)
				SKIN:Bang('!SetOption', 'mItemDIR' .. i - pgBegin + 1, 'string', temp)
	-- print('index=' .. i - pgBegin + 1)
			end
			if #games[currCon][i] < 3 then
	-- print('no image saved')
					SKIN:Bang('!SetOption', i - pgBegin + 1, 'MeterStyle', 'IconBG')
			else
				local currImage = games[currCon][i][3]
	-- print(i - pgBegin + 1 .. ' = ' .. currImage)
				local FoundFile = io.open(currImage,'r')
				if not FoundFile then
	-- print(currImage .. ' not found')
					SKIN:Bang('!SetOption', i - pgBegin + 1, 'MeterStyle', 'IconBG')
				else
	-- print(currImage .. ' found')
					io.close(FoundFile)
					SKIN:Bang('!SetOption', i - pgBegin + 1, 'MeterStyle', 'GameBanner')
					SKIN:Bang('!SetOption', i - pgBegin + 1, 'imageName', currImage)
				end
			end
		end
	end
	SKIN:Bang('!UpdateMeasureGroup', 'StringMeasures')
	setGrid()
	return pgEnd - pgBegin
end

function setGrid()
	local totalItems = pgEnd - pgBegin 
	local WorkAreaHeight = tonumber(SKIN:GetVariable('WorkAreaHeight'))
	local WorkAreaWidth = tonumber(SKIN:GetVariable('WorkAreaWidth'))
	H = 0
	W = 0
	local X = 0	--Skin center X
	local Y = 0	--Skin center Y
	local cellW = 0
	local cellH = 0
	local Min = tonumber(SKIN:GetVariable('Minimize'))
	if WorkAreaWidth > WorkAreaHeight then
		--print('landscape mode')
		if totalItems > 4 then
			H = 3
			while W * H < totalItems do W = W + 1 end
		else 
			W = 4
			H = 0
			while W * H < totalItems do H = H + 1 end
		end
		if Min < 1 then
			cellH = math.floor(WorkAreaHeight / 3)
			cellW = math.floor((WorkAreaWidth  * 3 / 4 - 135) / 4 + 0.5)
		else
			cellH = math.floor((WorkAreaHeight - (WorkAreaHeight % H)) / H + 0.5)
			cellW = math.floor((WorkAreaWidth - 35 - ((WorkAreaWidth - 35) % W)) / W + 0.5)
		end
	else
		--print('portrait mode')
		W = 3
		H = 0
		while W * H < totalItems do H = H + 1 end
		if Min < 1 then
			cellW = math.floor((WorkAreaWidth * 3 / 4 - 135) / 3 + 0.5)
			cellH = math.floor(WorkAreaHeight / 4)
		else
			cellH = math.floor((WorkAreaHeight - (WorkAreaHeight % H)) / H + 0.5)
			cellW = math.floor((WorkAreaWidth - 35 - ((WorkAreaWidth - 35) % W)) / W + 0.5)
		end
	end
	
	X = math.floor(cellW * W / 2)
	Y = math.floor(cellH * H / 2)
--local layout = { cellW, cellH, X, Y, W, H }
--print(table.concat(layout, ', '))
	local maxRange = 0
	if currCon <= 0 then maxRange = #consoles else maxRange = #games[currCon] end
	for i = 1, 12 do
		if i + pgBegin - 1 <= maxRange then
			SKIN:Bang('!moveMeter', 90 + cellW * math.floor((i - 1) % W), cellH * math.floor((i - 1) % H), i)
--print('game' .. i .. ' ' .. (i-1) % W  .. ', ' .. math.floor((i-((i-1) % W)) / W)  )
			SKIN:Bang('!showMeter', i)
		else 
			SKIN:Bang('!hideMeter', i)
			SKIN:Bang('!moveMeter', 0, 0, i)
			SKIN:Bang('!hideMeterGroup', 'info' .. i)
		end
	end
	if maxRange > totalItems  then
		SKIN:Bang('!MoveMeter', 10, 0, 'indexup')
		SKIN:Bang('!MoveMeter', 10, 2 * Y - 70, 'indexDown')
		SKIN:Bang('!showMeterGroup', 'scrollpages')
	else
		SKIN:Bang('!hideMeterGroup', 'scrollpages')
		SKIN:Bang('!MoveMeter', 0, 0, 'indexup')
		SKIN:Bang('!MoveMeter', 0, 0, 'indexdown')
	end
	SKIN:Bang('!MoveMeter', 0, Y - 135, 'MinimizeToggle')
	SKIN:Bang('!setVariable', 'iconW', cellW)
	SKIN:Bang('!setVariable', 'iconH', cellH)
end

function shortcut(c, g)
	c = tonumber(c)
	g = tonumber(g) + pgBegin - 1
	local result = 0
	if c <= 0 then
		if #games[g] < currGame then 
			SKIN:Bang('!setVariable', 'game', #games[g] - 1 )
		end
		SKIN:Bang('!setVariable', 'console', g)
		-- SKIN:Bang('!updateMeasure', 'parseNpose')
		result = '[!setVariable console ' .. g ..']'
	else
		local temp = getConCommand(c)
		local rom = { nil, nil }
		local patterns = {'ROM', 'rom', 'Rom'}
		for i, v in ipairs(patterns) do
			if rom[1] ~= nil then 
				-- print(rom[1] .. ' ;' .. temp)
				break
			else
				rom[1] = temp:find(v) - 1
			end
		end
		local s = temp:find('%%')
		while temp:find('%%', s + 1, rom[1]) ~= nil do 
			s =  temp:find('%%', s + 1, rom[1])
		end
		rom[2] = temp:find('%%', s + 1)
		local placeholder = temp:sub(rom[1], rom[2])
		placeholder = placeholder:gsub('%%', '%%%%')
		-- print(placeholder)
		local replacement = getGamePath(c, g)
		local result = temp:gsub(placeholder, replacement)
		-- print(result)
	end
	return result
end

function PgUp()
	if currCon > 0 then
		if currGame - 12 > 0 then
			SKIN:Bang('!setVariable', 'game', currGame - 12)
		else 
			SKIN:Bang('!setVariable', 'game', #games[currCon])
		end
	else
		local temp = currCon * -1 -- restore previous console
		if temp > #consoles then temp = #consoles
		elseif temp == 0 then temp = 1 end -- bounds checking
		if temp - 12 > 0 then
			SKIN:Bang('!setVariable', 'Console', (temp - 12) * -1)
		else 
			SKIN:Bang('!setVariable', 'Console', (#consoles - 12) * -1)
		end
	end
	SKIN:Bang('!updateMeasure', 'parseNpose')
end

function PgDown()
	if currCon > 0 then
		if currGame + 12 < #games[currCon] then
			SKIN:Bang('!setVariable', 'game', currGame + 12)
		else 
			SKIN:Bang('!setVariable', 'game', 1)
		end
	else
		local temp = currCon * -1 -- restore previous console
		if temp > #consoles then temp = #consoles
		elseif temp == 0 then temp = 1 end -- bounds checking
		if temp + 12 < #consoles then
			SKIN:Bang('!setVariable', 'Console', (temp + 12) * -1)
		else 
			SKIN:Bang('!setVariable', 'Console', -1)
		end
	end
	SKIN:Bang('!updateMeasure', 'parseNpose')
end

function IndexUp()
	if currCon > 0 then
		if currGame - W > 0 then
			SKIN:Bang('!setVariable', 'game', currGame - W)
		else 
			SKIN:Bang('!setVariable', 'game', #games[currCon])
		end
	else
		local temp = currCon * -1 -- restore previous console
		if temp > #consoles then temp = #consoles
		elseif temp == 0 then temp = 1 end -- bounds checking
		if temp - W > 0 then
			SKIN:Bang('!setVariable', 'Console', (temp - W) * -1)
		else 
			SKIN:Bang('!setVariable', 'Console', (#consoles - W) * -1)
		end
	end
	SKIN:Bang('!updateMeasure', 'parseNpose')
end

function IndexDown()
	if currCon > 0 then
		if currGame + W < #games[currCon] then
			SKIN:Bang('!setVariable', 'game', currGame + W)
		else 
			SKIN:Bang('!setVariable', 'game', 1)
		end
	else
		local temp = currCon * -1 -- restore previous console
		if temp > #consoles then temp = #consoles
		elseif temp == 0 then temp = 1 end -- bounds checking
		if temp + W < #consoles then
			SKIN:Bang('!setVariable', 'Console', (temp + W) * -1)
		else 
			SKIN:Bang('!setVariable', 'Console', W * -1)
		end
	end
	SKIN:Bang('!updateMeasure', 'parseNpose')
end
