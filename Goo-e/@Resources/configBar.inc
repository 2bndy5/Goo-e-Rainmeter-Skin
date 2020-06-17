[Rainmeter]
dynamicwindowsize=1
MouseLeaveAction=[!setvariable hideconfigbar 1][!writekeyvalue variables hideconfigbar 1 "#@##CurrentConfig#\Variables.inc"][!update]
ContextTitle="Color Settings"
ContextAction=[!ToggleConfig "#CurrentConfig#\Settings" "#CURRENTFILE#"][!move "(#WorkAreaWidth#-(#CurrentConfigX#+#CurrentConfigWidth#)>=725?(#CurrentConfigX#+#IconSize#):(#CurrentConfigX#-725))" "(#WorkAreaHeight#-#CurrentConfigY#>=404?(#CurrentConfigY#):(#WorkAreaHeight#-404))" "#CurrentConfig#\Settings"]
ContextTitle2="Set Icon Size"
ContextAction2=[!commandmeasure mInputSize "executebatch 1"]

[configbar]
Meter=shape
x=0
y=(#IconSize#-round(#IconSize#/3))
w=#IconSize#
h=(round(#IconSize#/3))
shape=Rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H]) | strokeWidth 0 | Fill LinearGradient gradient
gradient=90 | 0,0,0,185 ; 1 | [ScriptShade],185 ; 0.8 | [ScriptShade],185 ; 0.2 | 0,0,0,185 ; 0
Hidden=#hideconfigbar#
dynamicvariables=1
Group=configbar

[configNext]
meter=shape
x=(#IconSize#*0.75)
y=([configbar:Y]+#IconSize#*0.05)
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=Strokewidth 0 | Fill Color #ClockColor# | rotate 90
meterStyle=ArrowShape
Hidden=#hideconfigbar#
dynamicvariables=1
Group=configbar

[configBack]
meter=Shape
y=([configbar:Y]+#IconSize#*0.05)
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=Strokewidth 0 | Fill Color #ClockColor# | rotate -90
meterStyle=ArrowShape
Hidden=#hideconfigbar#
dynamicvariables=1
Group=configbar

[settingsbutt]
meter=shape
DynamicVariables=1
x=(#IconSize#*0.25)
y=([configbar:Y]+#IconSize#*0.05)
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=StrokeWidth ([#CurrentSection#:W]*0.065) | StrokeColor #ClockColor# | Fill Color 0,0,0,1
meterStyle=SettingsShape
Hidden=#hideconfigbar#
group=configbar

[setSize]
meter=shape
x=(#IconSize#*0.5)
y=([configbar:Y]+#IconSize#*0.05)
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=StrokeWidth ([#CurrentSection#:W]*0.065) | StrokeColor #ClockColor#
meterStyle=SizeShape
Hidden=#hideconfigbar#
dynamicvariables=1
group=configbar
leftmouseupaction=[!commandmeasure mInputSize "executebatch 1"]
;;Deprecated stopwatch & alarm skins for now. Maybe re-implement in future, so save this code for reference.
;;For switching to StopWatch & Alarm skin
;	[pageclockactiveA]
;	meter=image
;	imagename=#@#images\pageactive.png
;	imagealpha=0
;	UpdateDivider=1
;	x=((#IconSize#/2)-(#IconSize#*0.2))
;	y=(#IconSize#-(#IconSize#*0.1))
;	h=(#IconSize#*0.1)
;	w=(#IconSize#*0.1)
;	hidden=(#hideconfigbar#=0?1:0)
;	dynamicvariables=1
;	group=clockpages
;
;	[pagestopwatchpassiveA]
;	meter=image
;	imagename=#@#images\pagepassive.png
;	imagealpha=0
;	UpdateDivider=1
;	x=((#IconSize#/2)-(#IconSize#*0.05))
;	y=(#IconSize#-(#IconSize#*0.1))
;	h=(#IconSize#*0.1)
;	w=(#IconSize#*0.1)
;	hidden=(#hideconfigbar#=0?1:0)
;	dynamicvariables=1
;	group=clockpages
;	LeftMouseupAction=[!showmetergroup "stopwatch" "#rootconfig#"][!zpos -2][!zpos -1 "#CurrentConfig#"]
;
;	[pagealarmpassiveA]
;	meter=image
;	imagename=#@#images\pagepassive.png
;	imagealpha=0
;	UpdateDivider=1
;	x=((#IconSize#/2)+(#IconSize#*0.1))
;	y=(#IconSize#-(#IconSize#*0.1))
;	h=(#IconSize#*0.1)
;	w=(#IconSize#*0.1)
;	hidden=(#hideconfigbar#=0?1:0)
;	dynamicvariables=1
;	group=clockpages
;	LeftMouseupAction=[!showmetergroup "alarmclock" "#rootconfig#"][!zpos -2][!zpos -1 "#CurrentConfig#"]
