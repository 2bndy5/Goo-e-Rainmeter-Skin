function Initialize()
	StyleVar = SKIN:GetVariable('Preset', 'n/a')
end

function Update()
	CurrentBGcolor = SKIN:GetVariable('BGcolor', 'n/a')
	CurrentClockColor = SKIN:GetVariable('ClockColor', 'n/a')
	CurrentSecondsColor = SKIN:GetVariable('SecondsColor', 'n/a')
	CurrentClockAlpha = SKIN:GetVariable('ClockAlpha', 'n/a')
	CurrentShowDate = SKIN:GetVariable('ShowDate', 'n/a')

	ConfigFile = SKIN:Get
	file = io.open (ConfigFile, r+)

end