function Initialize()
	idList = SKIN:MakePathAbsolute("Library List.txt")
	fin = io.open(idList,'r')
end

function Update()
	local line = fin:read()
	if line == "" then
		SKIN:Bang('!SetOption', 'display', 'text', "downloading finshed")
		fin:close()
		return "done"
	else
		appid = string.sub(line, 1, string.find(line, ' =') - 1)
		appname = string.sub(line, string.find(line, ' =') + 3 )
		SKIN:Bang('!SetVariable', 'appID', appid)
		SKIN:Bang('!CommandMeasure', 'mActionHelper', 'Execute 1')
		SKIN:Bang('!Log', appid, 'Debug')
		return appname
	end
end