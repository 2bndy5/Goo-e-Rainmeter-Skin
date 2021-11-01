function ShadeColor(c)
    local rgb = { ParseColor(c) }
    -- SKIN:Bang('!Log', table.concat(rgb, ','), 'Debug')
    local hsv = { tonumber(getHue(rgb) * 6), tonumber(getSat(rgb)), tonumber(getVal(rgb)) }
    if (hsv[3] < 0.45 and percent < 0.55) or percent > 0.5 then
        hsv[3] = hsv[3] + percent
    else
        hsv[3] = hsv[3] - percent
    end
    return HSVtoRGB(hsv)
end--apply shade

function InvertColor(c)
    local rgb = { ParseColor(c) }
    --	SKIN:Bang('!Log', table.concat(rgb, ','), 'Debug')
    local hsv = { tonumber(getHue(rgb) * 6), tonumber(getSat(rgb)), tonumber(getVal(rgb)) }
    if hsv[3] > 0.25 and hsv[3] < 0.75 then
        if hsv[3] > 0.5 then
            hsv[3] = hsv[3] + (0.5-hsv[3]) - 0.25
        else
            hsv[3] = hsv[3] + (0.5-hsv[3]) + 0.25
        end
    else
        hsv[3] = math.abs(hsv[3]-1)
    end
    return HSVtoRGB(hsv)
end

function ParseColor(c)
--parse color segments from string 'c' then return table of 3 numbers (base 10)
    -- SKIN:Bang('!Log', c, 'Debug')
    local rgb = {}
    if string.find(c, ',') == nil then
        --assumes a 6 digit hex code
        rgb[1] = tonumber(string.sub(c, 1, 2), 16)
        rgb[2] = tonumber(string.sub(c, 3, 4), 16)
        rgb[3] = tonumber(string.sub(c, 5, 6), 16)
    else
        --find comma & extract substring
        local comma = string.find(c, ",")
        rgb[1] = tonumber(string.sub(c, 1, (comma-1)), 10)
        --find 2nd comma & extract substring
        comma = string.find(c, ",", comma)
        rgb[2] = tonumber(string.sub(c, comma+1, string.find(c, ",", comma+1)-1), 10)
        --extract substring from last comma to string.len(c)
        comma = string.find(c, ",", comma+1)
        rgb[3] = tonumber(string.sub(c, comma+1, -1), 10)
    end--end make table of {red, green, blue}
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

function HSVtoRGB(hsv)
    local chroma = hsv[3] * hsv[2]
    local mid = chroma * (1 - math.abs(hsv[1] % 2 - 1))
    local Match = hsv[3] - chroma
--[[for Debug
    SKIN:Bang('!Log', "h = " .. hsv[1], 'Debug')
    SKIN:Bang('!Log', "Chroma = " .. chroma, 'Debug')
    SKIN:Bang('!Log', "mid = " .. mid, 'Debug')
    SKIN:Bang('!Log', "match = " .. Match, 'Debug')
]]--
    local newRGB = {}
    if 0 <= hsv[1] and hsv[1] < 1 then
        newRGB[1] = math.floor((255 * (chroma + Match)) + 0.5)
        newRGB[2] = math.floor((255 * (mid + Match)) + 0.5)
        newRGB[3] = math.floor((255 * (0 + Match)) + 0.5)
    elseif 1 <= hsv[1] and hsv[1] < 2 then
        newRGB[1] = math.floor((255 * (mid + Match)) + 0.5)
        newRGB[2] = math.floor((255 * (chroma + Match)) + 0.5)
        newRGB[3] = math.floor((255 * (0 + Match)) + 0.5)
    elseif 2 <= hsv[1] and hsv[1] < 3 then
        newRGB[1] = math.floor((255 * (0 + Match)) + 0.5)
        newRGB[2] = math.floor((255 * (chroma + Match)) + 0.5)
        newRGB[3] = math.floor((255 * (mid + Match)) + 0.5)
    elseif 3 <= hsv[1] and hsv[1] < 4 then
        newRGB[1] = math.floor((255 * (0 + Match)) + 0.5)
        newRGB[2] = math.floor((255 * (mid + Match)) + 0.5)
        newRGB[3] = math.floor((255 * (chroma + Match)) + 0.5)
    elseif 4 <= hsv[1] and hsv[1] < 5 then
        newRGB[1] = math.floor((255 * (mid + Match)) + 0.5)
        newRGB[2] = math.floor((255 * (0 + Match)) + 0.5)
        newRGB[3] = math.floor((255 * (chroma + Match)) + 0.5)
    elseif 5 <= hsv[1] and hsv[1] <= 6 then
        newRGB[1] = math.floor((255 * (chroma + Match)) + 0.5)
        newRGB[2] = math.floor((255 * (0 + Match)) + 0.5)
        newRGB[3] = math.floor((255 * (mid + Match)) + 0.5)
    end--set newRGB table
    return table.concat(newRGB, ',')
end

function convertAlpha(d)
    --can be used to compensate the alpha value of a color if said color is changed from dec -> hex
    SKIN:Bang('!SetVariable', 'ConvertedAlpha', string.format("%02x", d) )
end

function Update()
    percent = tonumber(SELF:GetOption('Percent'))
    local Colors = {
        tostring(SELF:GetOption('Color1')),
        tostring(SELF:GetOption('Color2')),
        tostring(SELF:GetOption('Color3')),
        tostring(SELF:GetOption('Color4')),
        tostring(SELF:GetOption('Color5')),
        tostring(SELF:GetOption('Color6'))
    }
    for i, c in ipairs(Colors) do
        if c:match("%d-,%d+,%d+") ~= nil then
            SKIN:Bang('!SetVariable', 'ShadedColor' .. i, ShadeColor(Colors[i]))
        end
    end
end
