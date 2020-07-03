
function getHueColor()
	local h = Hue * 6
	local chroma = 1
	local mid = chroma * (1 - math.abs(h % 2 - 1))
	local Match = 0
	local rgb = {}
	if 0 <= h and h < 1 then
		rgb[1] = math.floor(255 * (chroma + Match) + 0.5)
		rgb[2] = math.floor(255 * (mid + Match) + 0.5)
		rgb[3] = math.floor(255 * (0 + Match) + 0.5)
	elseif 1 <= h and h < 2 then
		rgb[1] = math.floor(255 * (mid + Match) + 0.5)
		rgb[2] = math.floor(255 * (chroma + Match) + 0.5)
		rgb[3] = math.floor(255 * (0 + Match) + 0.5)
	elseif 2 <= h and h < 3 then
		rgb[1] = math.floor(255 * (0 + Match) + 0.5)
		rgb[2] = math.floor(255 * (chroma + Match) + 0.5)
		rgb[3] = math.floor(255 * (mid + Match) + 0.5)
	elseif 3 <= h and h < 4 then
		rgb[1] = math.floor(255 * (0 + Match) + 0.5)
		rgb[2] = math.floor(255 * (mid + Match) + 0.5)
		rgb[3] = math.floor(255 * (chroma + Match) + 0.5)
	elseif 4 <= h and h < 5 then
		rgb[1] = math.floor(255 * (mid + Match) + 0.5)
		rgb[2] = math.floor(255 * (0 + Match) + 0.5)
		rgb[3] = math.floor(255 * (chroma + Match) + 0.5)
	elseif 5 <= h and h <= 6 then
		rgb[1] = math.floor(255 * (chroma + Match) + 0.5)
		rgb[2] = math.floor(255 * (0 + Match) + 0.5)
		rgb[3] = math.floor(255 * (mid + Match) + 0.5)
	end--set rgb table
--[[for Debug
		SKIN:Bang('!Log', table.concat(rgb, ','), 'Debug')
]]--
	SKIN:Bang('!SetVariable', 'HueColor', table.concat(rgb, ',') )
	return rgb
end

function ParseColor(c)
--parse color segments from string 'c' then return table of 3 numbers (base 10)
	local rgb = { nil, nil, nil }
	-- print("recv-ing: " .. c)
	-- print("hexMatch: " .. c:match('(%x+)$S'))
	-- print("rgbMatch: " .. c:match('(%d+)'))
	if c:match('^(%x+)$') ~= nil then
		-- print(c .. " is a hex color code")
		--assumes a 6 digit hex code
		rgb[1] = tonumber(string.sub(c, 1, 2), 16)
		rgb[2] = tonumber(string.sub(c, 3, 4), 16)
		rgb[3] = tonumber(string.sub(c, 5, 6), 16)
	elseif c:match("(%d+)") ~= nil then
		-- print(c .. " is a rgb color code")
		rgb[1] = tonumber(c:match("^(%d-),%d+,%d+$"))
		rgb[2] = tonumber(c:match("^%d-,(%d+),%d+$"))
		rgb[3] = tonumber(c:match("^%d-,%d+,(%d+)$"))
	end--end make table of {red, green, blue}
	-- print(table.concat(rgb,  ","))
	return rgb[1], rgb[2], rgb[3]
end--end parse color

function getHue(rgb)
	local hue
	if (2*rgb[1]-rgb[2]-rgb[3]) == 0 then
		hue = 0
	else
		hue = math.atan2((math.sqrt(3)*(rgb[2]-rgb[3])), (2*rgb[1]-rgb[2]-rgb[3]))
	end

	if hue < 0.0 then
		hue = hue + 6
	end
	return hue / 6
end

function getSat(rgb)
	local Min = math.min(tonumber(rgb[1]), tonumber(rgb[2]), tonumber(rgb[3])) / 255
	local Max = math.max(tonumber(rgb[1]), tonumber(rgb[2]), tonumber(rgb[3])) / 255
	--chroma = max - min unles max == 0
	if Max == 0 then
		return 0
	else
		return (Max - Min) / Max
	end
end

function getVal(rgb)
	local Max = math.max(tonumber(rgb[1]), tonumber(rgb[2]), tonumber(rgb[3])) / 255
	return Max
end

function RGBtoHex(color) 
--[[ 
Converts RGB colors to HEX. Code snippet from rainmeter.net
Modified to set variables 'Hue' & 'ActiveHex'
]]--
	local hex = {}
	local rgb = {}
	for seg in color:gmatch('%d+') do
		table.insert(hex, ('%02X'):format(tonumber(seg)))
		table.insert(rgb, tonumber(seg))
	end
--[[for debug
	for i = 1, 3, 1 do
		SKIN:Bang('!Log', i .. " = " .. rgb[i], 'Debug')
	end--debug result
]]--
	Hue = getHue(rgb)
	Sat = getSat(rgb)
	Val = getVal(rgb)
	SKIN:Bang('!SetVariable', 'ActiveHex', table.concat(hex) )
	SKIN:Bang('!SetVariable', 'Hue', Hue)
	SKIN:Bang('!SetVariable', 'Sat', Sat)
	SKIN:Bang('!SetVariable', 'Val', Val)
	SKIN:Bang('!writeKeyValue', 'Variables', 'ActiveHex', table.concat(hex), ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Hue', Hue, ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Sat', Sat, ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Val', Val, ColorPickerCommon)
end

function HexToRGB(color)
--[[ 
Converts HEX colors to RGB. Code snippet from rainmeter.net
Modified to set variables 'Hue' & 'ActiveRGB'
]]--
	local rgb = {}
	for seg in color:gmatch('..') do
		table.insert(rgb, tonumber(seg, 16))
	end
--[[for debug
	for i = 1, 3, 1 do
		SKIN:Bang('!Log', i .. " = " .. rgb[i], 'Debug')
	end--debug result
]]--
	Hue = getHue(rgb)
	Sat = getSat(rgb)
	Val = getVal(rgb)
	SKIN:Bang('!SetVariable', 'ActiveRGB', table.concat(rgb, ',') )
	SKIN:Bang('!SetVariable', 'Hue', Hue)
	SKIN:Bang('!SetVariable', 'Sat', Sat)
	SKIN:Bang('!SetVariable', 'Val', Val)
	SKIN:Bang('!writeKeyValue', 'Variables', 'ActiveRGB', table.concat(rgb, ','), ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Hue', Hue, ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Sat', Sat, ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Val', Val, ColorPickerCommon)
end

function HSVtoRGB()
	local h = Hue * 6
	local chroma = Val * Sat
	local mid = chroma * (1 - math.abs(h % 2 - 1))
	local Match = Val - chroma
--[[for Debug
	SKIN:Bang('!Log', "h = " .. h, 'Debug')
	SKIN:Bang('!Log', "Chroma = " .. chroma, 'Debug')
	SKIN:Bang('!Log', "mid = " .. mid, 'Debug')
	SKIN:Bang('!Log', "match = " .. Match, 'Debug')
]]--
	local rgb = {}
	if 0 <= h and h < 1 then
		rgb[1] = 255 * (chroma + Match)
		rgb[2] = 255 * (mid + Match)
		rgb[3] = 255 * (0 + Match)
	elseif 1 <= h and h < 2 then
		rgb[1] = 255 * (mid + Match)
		rgb[2] = 255 * (chroma + Match)
		rgb[3] = 255 * (0 + Match)
	elseif 2 <= h and h < 3 then
		rgb[1] = 255 * (0 + Match)
		rgb[2] = 255 * (chroma + Match)
		rgb[3] = 255 * (mid + Match)
	elseif 3 <= h and h < 4 then
		rgb[1] = 255 * (0 + Match)
		rgb[2] = 255 * (mid + Match)
		rgb[3] = 255 * (chroma + Match)
	elseif 4 <= h and h < 5 then
		rgb[1] = 255 * (mid + Match)
		rgb[2] = 255 * (0 + Match)
		rgb[3] = 255 * (chroma + Match)
	elseif 5 <= h and h <= 6 then
		rgb[1] = 255 * (chroma + Match)
		rgb[2] = 255 * (0 + Match)
		rgb[3] = 255 * (mid + Match)
	end--set rgb table
	local hex = {}
	for i = 1, 3, 1 do
		table.insert(hex, ('%02X'):format(math.floor(rgb[i] + 0.5)))
		rgb[i] = math.floor(rgb[i] + 0.5)
	end
	SKIN:Bang('!SetVariable', 'ActiveRGB', table.concat(rgb, ',') )
	SKIN:Bang('!SetVariable', 'ActiveHex', table.concat(hex) )
end

function ShadeColor(c, p)
	local rgb = { ParseColor(c) }
--	SKIN:Bang('!Log', table.concat(rgb, ','), 'Debug')
	local hsv = { tonumber(getHue(rgb) * 6), tonumber(getSat(rgb)), tonumber(getVal(rgb)) }
	if hsv[3] < 0.45 then
		hsv[3] = hsv[3] + p
	else
		hsv[3] = hsv[3] - p
	end
	return HSVtoRGB(hsv)
end--apply shaded 

function RGBtoHSV(color)
	local rgb = { ParseColor(color) }
	-- SKIN:Bang('!Log', color, 'Debug')
	-- SKIN:Bang('!Log', table.concat(rgb, ','), 'Debug')
	Hue = getHue(rgb)
	Sat = getSat(rgb)
	Val = getVal(rgb)
	SKIN:Bang('!SetVariable', 'Hue', Hue)
	SKIN:Bang('!SetVariable', 'Sat', Sat)
	SKIN:Bang('!SetVariable', 'Val', Val)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Hue', Hue, ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Sat', Sat, ColorPickerCommon)
	SKIN:Bang('!writeKeyValue', 'Variables', 'Val', Val, ColorPickerCommon)
	HSVtoRGB()
end

function Initialize()
	ColorPickerCommon = SKIN:MakePathAbsolute(SKIN:GetVariable('@')..'ColorPickerCommon.inc')
end

function Update()
	--hue, saturation, annd value must be a percentage in range 0.0 - 1.0
	Hue = tonumber(SKIN:GetVariable('Hue'))
	Sat = tonumber(SKIN:GetVariable('Sat'))
	Val = tonumber(SKIN:GetVariable('Val'))
	-- getHueColor() also write variable HueColor to ColorPickerCommon.inc file
	return table.concat(getHueColor(), ',')
end