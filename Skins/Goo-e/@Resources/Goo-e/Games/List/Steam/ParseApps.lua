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
    if arg == nil then
        arg = SKIN:GetVariable("sort")
    end
    local reverse = tonumber(SKIN:GetVariable("revOrder"))
    while i < #self do
        -- print('total = ' .. #self .. ' iter = ' .. i .. ' value = ' .. self[i].id .. ' > ' .. self[i + 1].id)
        if self[i][arg] > self[i + 1][arg] then
            local temp = table.remove(self, i)
            table.insert(self, i + 1, temp)
            i = 1
        else
            i = i + 1
        end
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
    id = 0,
    name = "",
    path = "",
    dir = "",
    size = 0,
    playtime = 0,
    trophies = {0, 0},
    desc = "No Description",
    lastPlayed = 0
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
        resources .. currentConfig .. "\\" .. service .. "\\SpecificVars.inc")
    SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function subHidden(str)
    -- print("subtracting " .. str)
    local hiddenList = SKIN:GetVariable("hiddenList")
    hiddenList = hiddenList:gsub(str .. "%|", "")
    SKIN:Bang("!setVariable", "hiddenList", hiddenList)
    SKIN:Bang(
        "!writeKeyvalue", "Variables", "hiddenList", hiddenList,
        resources .. currentConfig .. "\\" .. service .. "\\SpecificVars.inc")
    SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function applySort()
    showcase:sort()
    SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function applyFilter()
    apps:sort()
    showcase = apps:filter()
end

function startTimer()
    startTime = os.clock()
end

function parseApps()
    local str = SKIN:GetMeasure("mListInfoFiles"):GetStringValue()
    local path = ""
    local userID = SKIN:GetVariable("lastActiveUser")
    for line in str:gmatch "(.-)\n" do
        -- print(line)
        local appmanifest = "228980.acf" --use steamworks appID as sentinal
        if line:match(" Directory of (.*)") ~= nil then
            path = line:match(" Directory of (.*)") .. "\\"
        elseif line:match(".*appmanifest_(.*).acf") ~= nil then
            appmanifest = line:match(".*(appmanifest_.*.acf)")
            if appmanifest:match("228980.acf") == nil then --ignore the "Steamworks" appmanifest
                -- print('reading file = ' .. path .. appmanifest)
                local app = parseLog(path, appmanifest)
                app.path = path .. "common\\"
                app.playtime = 0
                if tonumber(userID) > 0 then --requires a valid userID number
                    parseJSON(app, userID)
                end
                table.insert(apps, app)
            end
        end
    end
    -- all apps have been discovered; now get user-specific data from
    -- Path2exe .. "userdata\\" .. userID .. "\\config\\localconfig.vdf"
    local file = io.open(Path2exe .. "userdata\\" .. userID .. "\\config\\localconfig.vdf")
    if file ~= nil then
        local foundApps = false
        local isInstalled = 0
        for line in file:lines() do
            if line:match("Software\"") then
                foundApps = true
            elseif foundApps == true then
                if line:match('^%s+"%d+"$') ~= nil then
                    local id = tonumber(line:match('^%s+"(%d+)"$'))
                    -- found an app id; now detirmine if it is installed using the apps table
                    for i, v in ipairs(apps) do
                        if v.id == id then
                            -- save the index pointing to the specific app whose data will follow
                            isInstalled = i
                            break
                        end
                    end
                elseif isInstalled > 0 then
                    if line:match("LastPlayed\"") ~= nil then
                        apps[isInstalled].lastPlayed = line:match("LastPlayed.*\"(%d+)\"")
                    elseif line:match("Playtime\"") ~= nil then
                        apps[isInstalled].playtime = line:match("Playtime.*\"(%d+)\"")
                    elseif line:match("^%s+}$") then
                        isInstalled = 0 -- leaving section about a specific app
                    end
                elseif line:match("LastPlayedTimesSyncTime") ~= nil then
                    foundApps = false -- leaving the only section we care about
                end
            end
        end
        file:close()
    end
    if #apps == 0 then
        SKIN:Bang("!setOption", "loadingScreen", "text", "No games or#CRLF#apps found!")
    end
    local endTimer = os.clock()
    SKIN:Bang("!log", #apps .. " games/apps data loaded in " .. string.format("%.3f", endTimer - startTime) .. " seconds", "Notice")
    SKIN:Bang("!updateMeasure", "mParseApps")
end

function parseLog(dirPath, filename)
    local file = io.open(dirPath .. filename, "r")
    local result = App.new()
    if file ~= nil then
        for line in file:lines() do
            if line:match('"appid"') ~= nil then
                local temp = line:match('appid"%s+"(.*)"')
                result.id = tonumber(temp)
            elseif line:match("name") ~= nil then
                local temp = line:match('name"%s+"(.*)"')
                result.name = temp
            elseif line:match("installdir") ~= nil then
                local temp = line:match('installdir"%s+"(.*)"')
                result.dir = temp
                SKIN:Bang("!setVariable", "testDir", dirPath .. "common\\" .. temp)
                SKIN:Bang("!updateMeasure", "dirSizeInfo")
                local actualSize = tonumber(SKIN:GetMeasure("dirSizeInfo"):GetValue())
                if actualSize > 0 then result.size = actualSize end
            end
        end
        file:close()
    end
    return result
end

function parseJSON(obj, id)
    local path2json = Path2exe .. "userdata\\" .. id .. "\\config\\librarycache\\" .. obj.id .. ".json"
    -- print(path2json)
    local file = io.open(path2json, "r")
    if file ~= nil then
        -- path2json files are 1 super long line in length (minified json)
        for line in file:lines() do
            if line:match('"nTotal":.*,"nAchieved":.*}') ~= nil then
                local total, unlocked = line:match('"nTotal":(%d+),"nAchieved":(%d+)}')
                -- print(obj.id .. ' = ' .. tonumber(total) .. ', ' .. tonumber(unlocked))
                obj.trophies = {tonumber(total), tonumber(unlocked)}
            end
            if line:match('"strSnippet":') ~= nil then
                local temp = line:match('"strSnippet":"(.*)"}}')
                -- print(temp)
                obj.desc = temp
            end
        end
    end
end

function Initialize()
    CURRENTPATH = SKIN:MakePathAbsolute(SKIN:GetVariable("CURRENTPATH"))
    currentConfig = SKIN:GetVariable("CURRENTCONFIG")
    Path2exe = SKIN:GetVariable("Dir")
    resources = SKIN:GetVariable("@")
    service = SKIN:GetVariable("service")
    scrollPlane = tonumber(SKIN:GetVariable("scrollPlane"))
    MAX = 12
    showcase = {}
    page = tonumber(SKIN:GetVariable("page"))
end

function Update()
    applyFilter()
    if #apps ~= #showcase then
        SKIN:Bang("!setOption", "filter", "group", "menuSelect | menus")
    else
        SKIN:Bang("!setOption", "filter", "group", "none")
    end
    local useBoxArt = tonumber(SKIN:GetVariable("useBoxArt"))
    if useBoxArt == 1 then
        useBoxArt = "_library_600x900.jpg"
    elseif useBoxArt == 0 then
        useBoxArt = "_header.jpg"
    elseif useBoxArt == -1 then
        useBoxArt = "_logo.png"
    end
    MAX = 12
    local start = page * MAX
    if #showcase - start < MAX then
        if #showcase < MAX then
            start = 0
        else
            start = #showcase - MAX
        end
    end

    if #showcase > 0 then
        SKIN:Bang("!hidemeter", "loadingScreen")
        if #showcase < MAX then
            MAX = #showcase
        end
        for i = start + 1, start + MAX do
            SKIN:Bang("!SetOption", "mItemID" .. i - start, "String", showcase[i].id)
            SKIN:Bang("!SetOption", "mItemName" .. i - start, "String", showcase[i].name)
            SKIN:Bang("!SetOption", "mItemDIR" .. i - start, "String", showcase[i].path .. showcase[i].dir)
            SKIN:Bang("!SetOption", "mItemDescript" .. i - start, "string", showcase[i].desc)
            SKIN:Bang("!SetOption", "mItemPlayTime" .. i - start, "formula", showcase[i].playtime)
            SKIN:Bang("!SetOption", "mItemSize" .. i - start, "formula", showcase[i].size)
            local achievPercent = "N/A"
            if showcase[i].trophies[1] > 0 then
                achievPercent = math.floor(showcase[i].trophies[2] / showcase[i].trophies[1] * 100) .. "%"
            end
            SKIN:Bang(
                "!SetOption",
                "mItemTrophies" .. i - start,
                "string",
                showcase[i].trophies[2] .. " / " .. showcase[i].trophies[1] .. "#CRLF#" .. achievPercent
            )
            local useDefault = false
            local idleBg = Path2exe .. "appcache\\librarycache\\" .. showcase[i].id .. useBoxArt
            if doesImageExist(idleBg) then
                usedefault = false
            else
                -- use header img as fallback when missing logo img
                usedefault = true
            end
            local blurBg = Path2exe .. "appcache\\librarycache\\" .. showcase[i].id .. "_library_hero_blur.jpg"
            if doesImageExist(blurBg) then -- if blur exists
                if usedefault then
                    SKIN:Bang("!SetOption", i - start, "meterStyle", "IconBg | MouseOverIconDefault")
                else
                    SKIN:Bang("!SetOption", i - start, "meterStyle", "IconBg | MouseOverIcon")
                end
            else -- blur no does not exit
                if usedefault then
                    SKIN:Bang("!SetOption", i - start, "meterStyle", "IconBg | MouseOverIconNoBlurBgDefault")
                else
                    SKIN:Bang("!SetOption", i - start, "meterStyle", "IconBg | MouseOverIconNoBlurBg")
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
    SKIN:Bang("!writeKeyValue", "Variables", "page", page, resources .. currentConfig .. "\\" .. service .. "\\SpecificVars.inc")
    SKIN:Bang("!UpdateMeasureGroup", "InfoMeasures")
return #showcase
end

function doesImageExist(game_name)
    -- print("looking for img " .. game_name)
    local FoundFile = io.open(game_name, 'r')
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
    if page * MAX > #showcase then
        page = 0
    end
    SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function pageDn()
    page = page - 1
    -- wrap around scrolling
    if page < 0 then
        page = math.floor(#showcase / MAX)
    end
    SKIN:Bang("!UpdateMeasure", "mParseApps")
end

function cleanUp()
    while #showcase > 0 do
        table.remove(showcase)
    end
    while #apps > 0 do
        table.remove(apps)
    end
end
-- Generating an AppID for a non-Steam game (why I didn't brute force it myself)
-- # Original approach
--
--   hash = crc32(path .. title)
--   hash = hash | 0x80000000
--   hash = hash << 32
--   hash = hash | 0x02000000
--
-- # Issues
-- Left-shifting by 32 is not feasible since it results in 0.
-- This is because Lua uses the underlying C double datatype to represent all numbers.
-- Converting numbers larger than 2^56 into strings causes the number to be altered.
--
-- # Workaround
-- The workaround is to generate the CRC32 hash and bitwise OR the hash as usual.
-- Then the hash is turned into a string containing the binary version of the hash.
-- The binary hash is then left-shifted by appending 0x02000000 in binary as a string.
-- The binary is then turned back into a string containing the decimal version of the hash.
--
-- OR just add the non-steam shortcut, then run it from within steam once.
-- This makes steam do the crc calc and saves the non-steam appID to the "shortcutnames"
-- field in C:\Program Files (x86)\Steam\userdata\<userID#>\760\screenshots.vdf
