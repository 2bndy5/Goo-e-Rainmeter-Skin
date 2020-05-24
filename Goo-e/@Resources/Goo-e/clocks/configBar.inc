
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

[confignext]
meter=shape
x=(#iconSize#*0.75)
y=(#IconSize#*0.05)r
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #ClockColor# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape2=Path ArrowL | Extend ButtAttributes
ArrowL=([#CurrentSection#:W]*0.42),([#CurrentSection#:H]*0.3) | LineTo ([#CurrentSection#:W]*0.62),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.42),([#CurrentSection#:H]*0.7)
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
Hidden=#hideconfigbar#
meterStyle=StyleNext
dynamicvariables=1
Group=configbar

[configback]
meter=Shape
x=0
y=r
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #ClockColor# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape2=Path ArrowR | Extend ButtAttributes
ArrowR=([#CurrentSection#:W]*0.58),([#CurrentSection#:H]*0.3) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.58),([#CurrentSection#:H]*0.7)
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
Hidden=#hideconfigbar#
meterStyle=StyleBack
dynamicvariables=1
Group=configbar

[settingsbutt]
meter=shape
DynamicVariables=1
x=(#IconSize#*0.25)
y=r
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #ClockColor# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.15) | Extend ButtAttributes
shape2=Path Teeth | Extend ButtAttributes
Teeth=([#CurrentSection#:W]*0.39),([#CurrentSection#:H]*0.05) | LineTo ([#CurrentSection#:W]*0.46),([#CurrentSection#:H]*0.16) | LineTo ([#CurrentSection#:W]*0.54),([#CurrentSection#:H]*0.16) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.05) | LineTo ([#CurrentSection#:W]*0.75),([#CurrentSection#:H]*0.1) | LineTo ([#CurrentSection#:W]*0.715),([#CurrentSection#:H]*0.24) | LineTo ([#CurrentSection#:W]*0.77),([#CurrentSection#:H]*0.29) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.96),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.54) | LineTo ([#CurrentSection#:W]*0.955),([#CurrentSection#:H]*0.615) | LineTo ([#CurrentSection#:W]*0.89),([#CurrentSection#:H]*0.76) | LineTo ([#CurrentSection#:W]*0.76),([#CurrentSection#:H]*0.72) | LineTo ([#CurrentSection#:W]*0.715),([#CurrentSection#:H]*0.77) | LineTo ([#CurrentSection#:W]*0.745),([#CurrentSection#:H]*0.91) | LineTo ([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.96) | LineTo ([#CurrentSection#:W]*0.53),([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.46),([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.39),([#CurrentSection#:H]*0.96) | LineTo ([#CurrentSection#:W]*0.25),([#CurrentSection#:H]*0.91) | LineTo ([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.77) | LineTo ([#CurrentSection#:W]*0.24),([#CurrentSection#:H]*0.725) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.755) | LineTo ([#CurrentSection#:W]*0.04),([#CurrentSection#:H]*0.615) | LineTo ([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.535) | LineTo ([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.48) | LineTo ([#CurrentSection#:W]*0.04),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.26) | LineTo ([#CurrentSection#:W]*0.23),([#CurrentSection#:H]*0.28) | LineTo ([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.24) | LineTo ([#CurrentSection#:W]*0.25),([#CurrentSection#:H]*0.105) | ClosePath 1
shape3=Combine Shape2 | Exclude shape
shape4=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
Hidden=#hideconfigbar#
group=configbar
leftMouseUpAction=[!toggleConfig  "#RootConfig#\Clock\Settings" "#CURRENTFILE#"][!move "(#WorkAreaWidth#-(#CurrentConfigX#+#CurrentConfigWidth#)>=520?(#CurrentConfigX#+#IconSize#):(#CurrentConfigX#-520))" "(#WorkAreaHeight#-#CurrentConfigY#>=404?(#CurrentConfigY#):(#WorkAreaHeight#-404))" "#RootConfig#\Clock\Settings"]

[setSize]
meter=shape
x=(#IconSize#*0.5)
y=r
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #ClockColor# | Fill Color 0,0,0,1
shape=Line ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.16),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.845) | Extend ButtAttributes | StrokeStartCap Triangle | StrokeEndCap Triangle
shape2=Path ArrowBottom | Extend ButtAttributes
ArrowBottom=([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.62) | LineTo ([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.895) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.895)
shape3=path ArrowTop | Extend ButtAttributes
ArrowTop=([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.385)
shape4=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
Hidden=#hideconfigbar#
dynamicvariables=1
group=configbar
LeftMouseUpAction=[!Commandmeasure minputSize "ExecuteBatch 1"]
;;StopWatch & Alarm skin is normally always running as Root Config
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
