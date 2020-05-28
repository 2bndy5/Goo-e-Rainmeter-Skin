function Update()
	-- sets up the grid of listed apps
	showcase = tonumber(SKIN:GetMeasure("mParseApps"):GetValue())
	MAX = 12
	scrollPlane = tonumber(SKIN:GetVariable("scrollPlane"))
	currConsole = tonumber(SKIN:GetVariable('console'))
	local WorkAreaHeight = tonumber(SKIN:GetVariable("WorkAreaHeight"))
    local WorkAreaWidth = tonumber(SKIN:GetVariable("WorkAreaWidth"))
    showcase = tonumber(SKIN:GetMeasure("mParseApps"):GetValue())
	if showcase < MAX then MAX = showcase end
	local H = 0
	local W = 0
	local X = 0 --Skin center X init to 0
	local Y = 0 --Skin center Y init to 0
	local cellW = 0
	local cellH = 0
	local Maximize = tonumber(SKIN:GetVariable("Maximize"))
	local useBoxArt = tonumber(SKIN:GetVariable("useBoxArt"))
	if useBoxArt > 1 then useBoxArt = 0 end-- compensate for title/gameplay screenshots
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
		if i <= showcase then
			--ordered from left to right
			if scrollPlane == 0 then
				--ordered from top to bottom
				if (showcase - i) < W and (i - 1) % W == 0 and (showcase % W) > 0 then
					offset = (W - (showcase % W)) / 2
				-- print(i .. ' offset = ' .. offset)
				end
				SKIN:Bang("!moveMeter", 90 + cellW * (((i - 1) % W) + offset), cellH * math.floor((i - 1) / W), i)
			elseif scrollPlane == 1 then
				if (showcase - i) < H and (i - 1) % H == 0 and (showcase % H) > 0 then
					offset = (H - (showcase % H)) / 2
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
	if showcase > MAX then
		SKIN:Bang("!MoveMeter", 10, 0, "indexup")
		SKIN:Bang("!MoveMeter", 10, 2 * Y - 70, "indexDown")
		SKIN:Bang("!showMeterGroup", "scrollpages")
	else
		SKIN:Bang("!hideMeterGroup", "scrollpages")
		SKIN:Bang("!MoveMeter", 0, 0, "indexup")
		SKIN:Bang("!MoveMeter", 0, 0, "indexdown")
	end
	local menuCtrl_H = 90 * 2
	if currConsole == 0 then --concerning consoles
		SKIN:Bang("!hidemeter", "back2Consoles")
		SKIN:Bang("!hidemeter", "menu")
	else -- concerning games about a console
		menuCtrl_H = menuCtrl_H * 2
		SKIN:Bang("!showmeter", "back2Consoles")
		SKIN:Bang("!showmeter", "menu")
	end
	local y0 = Y - menuCtrl_H / 2
	if y0 < 0 then
		y0 = 0
	end -- don't clip the controls
	SKIN:Bang("!MoveMeter", 0, y0, "Settings")
	SKIN:Bang("!MoveMeter", 0, y0 + menuCtrl_H - 90, "CloseSkin")
	SKIN:Bang("!setVariable", "iconW", cellW)
	SKIN:Bang("!setVariable", "iconH", cellH)
end
