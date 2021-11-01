function Initialize()
    Path2Var = SKIN:MakePathAbsolute(SKIN:GetVariable('@'))
    CurrentConfig = SKIN:GetVariable('CurrentConfig')
    steamLibs = {}
    return #steamLibs
end

function Update()
    Path2exe = SKIN:GetMeasure('mSteamPath'):GetStringValue()
    Path2exe = Path2exe:sub(2, #Path2exe - 1)
    -- print(Path2exe .. 'SteamApps\\libraryFolders.vdf')
    if Path2exe:len() > 4 then
        -- if #steamLibs == 0 then
        --     table.insert(steamLibs, Path2exe .. 'SteamApps')
        -- end
        parselibrary(SKIN:MakePathAbsolute(Path2exe .. 'SteamApps\\libraryFolders.vdf'))
    end
    SKIN:Bang('!writeKeyValue',  'Variables', 'Dir', Path2exe, Path2Var .. CurrentConfig .. '\\List\\Steam\\specificVars.inc')
    return #steamLibs
end

function parselibrary(str)
    local file = io.open(str, 'r')
    for line in file:lines() do
        if line:match('%".*%".*%".*%:-\\.*%"') ~= nil then
            local temp = line:match('%".*%".*%"(.*%:-\\.*)%"')
            temp = temp:gsub('\\\\', '\\')
            -- print(temp)
            if temp:match('\\$') then
                temp = temp .. 'SteamApps'
            else
                temp = temp .. '\\SteamApps'
            end
            table.insert(steamLibs, temp)
            print(#steamLibs .. ' = ' .. temp)
        end
    end
    if file ~= nil then file:close() end
    if #steamLibs > 0 then
        local libList = ''
        for i,v in ipairs(steamLibs) do
            libList = libList .. '\"' .. v .. '\\\*.acf\" '
            -- print(libList)
        end
        -- print('libList = ' .. libList)
        SKIN:Bang('!writeKeyValue',  'Variables', 'libList', '\"' .. libList .. '\"', Path2Var .. CurrentConfig .. '\\List\\steam\\specificVars.inc')
    end
    return #steamLibs
end

function cleanUp()
    while #steamLibs > 0 do
        table.remove(steamLibs)
    end
end

-- function dumpApps()
    -- local file = nil
    -- if #apps > 0 then
        -- file = io.open(Path2Var .. CurrentConfig .. '\\Games\\Steam\\Apps.xml', 'w')
    -- end
    -- while #apps > 0 do
        -- if #apps[#apps] > 0 then
            -- file:write("<app>")
            -- file:write("\n\t<id>" .. apps[#apps][0] .. "</id>")
            -- file:write("\n\t<name>" .. apps[#apps][1] .. "</name>")
            -- file:write("\n\t<path>" .. apps[#apps][2] .. "</path>")
            -- file:write("\n\t<installDir>" .. apps[#apps][3] .. "</installDir>")
            -- file:write("\n\t<SizeOnDisk>" .. apps[#apps][4] .. "</SizeOnDisk>")
            -- file:write("\n\t<lastModified>" .. apps[#apps][5] .. "</lastModified>")
            -- file:write("\n</app>\n")
            -- while #apps[#apps] > 0 do table.remove(apps[#apps]) end
        -- end
        -- table.remove(apps)
    -- end
    -- if file ~= nil then file:close() end
-- end
