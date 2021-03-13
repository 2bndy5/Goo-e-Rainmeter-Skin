function Initialize()
    DIR = SKIN:GetVariable("DIR")
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