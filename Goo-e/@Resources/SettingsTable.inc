[Variables]
cellW=175
cellH=50

[ButtonShape]
w=#cellW#
h=#cellH#
dynamicVariables=1
buttonColor=fill color 255,255,255
shape=Rectangle ([#CurrentSection#:H]*0.05),([#CurrentSection#:H]*0.05),([#CurrentSection#:W]-[#CurrentSection#:H]*0.15),([#CurrentSection#:H]*0.9),([#CurrentSection#:H]/3) | strokeWidth 0 | extend buttonColor

[buttonLabelW]
x=(#CellW#-5)r
y=(#CellH#/2)r
w=(#CellW#*2)
h=(#CellH#)
clipstring=2
stringAlign=CenterCenter
fontSize=#SettingsFontSize#
FontFace=#FontFace#
dynamicVariables=1

[buttonLabel]
x=(#CellW#/2-5)r
y=(#CellH#/2)r
w=(#CellW#)
h=(#CellH#)
clipstring=2
stringAlign=CenterCenter
fontSize=#SettingsFontSize#
FontFace=#FontFace#
dynamicVariables=1

[toggleShape]
dynamicVariables=1
x=r
y=r
h=(#CellH#)
w=(#CellH#)
solidColor=255,255,255
buttonColor=stroke color 255,0,0
shape=Rectangle ([#CurrentSection#:H]*0.25),([#CurrentSection#:H]*0.25),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5) | strokeWidth ([#CurrentSection#:H]*0.08) | fill color 0,0,0,1
shape2=Curve ([#CurrentSection#:H]*0.2),([#CurrentSection#:H]*0.225),([#CurrentSection#:H]*0.8),([#CurrentSection#:H]*0.825),([#CurrentSection#:H]*0.6),([#CurrentSection#:H]*0.5) | strokeWidth ([#CurrentSection#:H]*0.1) | StrokeStartCap Round | StrokeEndCap Round | extend buttonColor
shape3=Curve ([#CurrentSection#:H]*0.85),([#CurrentSection#:H]*0.25),([#CurrentSection#:H]*0.2),([#CurrentSection#:H]*0.8),([#CurrentSection#:H]*0.4),([#CurrentSection#:H]*0.45) | strokeWidth ([#CurrentSection#:H]*0.1) | StrokeStartCap Round | StrokeEndCap Round | extend buttonColor
MouseOverAction=[!SetOption #CURRENTSECTION# solidColor 200,200,200]
MouseLeaveAction=[!SetOption #CURRENTSECTION# solidColor 255,255,255]

[toggleLabel]
x=(#CellH#)r
y=(#CellH#/2)r
w=(#CellW#*2-#CellH#)
h=(#CellH#)
clipstring=2
solidColor=255,255,255
stringAlign=LeftCenter
fontSize=(#SettingsFontSize#-2)
FontFace=#FontFace#
dynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# solidColor 200,200,200][!SetOption #CURRENTSECTION#Checkbox solidColor 200,200,200]
MouseLeaveAction=[!SetOption #CURRENTSECTION# solidColor 255,255,255][!SetOption #CURRENTSECTION#Checkbox solidColor 255,255,255]

[sliderShape]
w=(#CellW#*1.25)
h=(#CellH#)
usedGrad=180 | #ActiveRGB#;((#Alpha#/255-0.05)*1.1) | #ActiveRGB#;((#Alpha#/255-0.05)*1.1+0.05) | 83,83,83;((#Alpha#/255-0.05)*1.1+0.05) | 83,83,83;((#Alpha#/255-0.05)*1.1+0.5)
ButtAttributes=StrokeWidth 0| offset (((#Alpha#/255-0.05)*1.15)*([#CurrentSection#:W]-[#CurrentSection#:H]*1.125)),0
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokeWidth 0 | fill Color 0,0,0,1
shape2=Line ([#CurrentSection#:H]*0.25),([#CurrentSection#:H]/2),([#CurrentSection#:W]-[#CurrentSection#:H]*0.5),([#CurrentSection#:H]/2) | strokeWidth ([#CurrentSection#:H]*0.25) | Stroke LinearGradient usedGrad | StrokeStartCap Round | StrokeEndCap Round
buttonGlare=0,([#CurrentSection#:H]*0.145),*,*,([#CurrentSection#:H]*0.6),([#CurrentSection#:H]*0.425) | 0,0,0,0;0 | 0,0,0,0;1 | 255,255,255,60;1
shape3=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.25) | Fill Color 127,127,127 | Extend ButtAttributes
shape4=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.25) | Fill RadialGradient buttonGlare | Rotate -36.5 | Extend ButtAttributes

[sliderLabel]
x=(#cellW#*0.75)r
y=(#CellH#/2)r
w=(#CellW#)
h=(#CellH#)
clipstring=2
stringAlign=RightCenter
fontSize=#SettingsFontSize#
FontFace=#FontFace#
dynamicVariables=1

[1x1container]
x=r
y=(#CellH#)r
w=(#CellW#)
h=(#CellH#)
dynamicVariables=1

[1x2container]
x=r
y=(#CellH#)r
w=(#CellW#*2)
h=(#CellH#)
dynamicVariables=1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~~~Menu Title~~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[MenuName]
Meter=String
fontSize=#SettingsFontSize#
FontFace=#FontFace#
dynamicVariables=1
fontColor=#activeRGB#
stringAlign=CenterCenter
X=([RGBcolor:X]+[RGBcolor:W]+5+#CellW#)
y=([RGBcolor:Y]+[RGBcolor:H])
w=(#CellW#*2)
h=(#CellH#*2)
text="#CurrentConfig##CRLF##CurrentFile#"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~Container Meters~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[1]
meter=shape
meterStyle=ButtonShape | 1x1container
x=([MenuName:W]/-2)r
y=([MenuName:H]/2)r

[2]
meter=shape
meterStyle=ButtonShape | 1x1container

[3]
meter=shape
meterStyle=ButtonShape | 1x1container

[4]
meter=shape
y=([1:Y]+#cellH#*3)
meterStyle=ButtonShape | 1x1container

[5]
meter=shape
y=([1:Y]+#cellH#*4)
meterStyle=ButtonShape | 1x1container

[6]
meter=shape
y=([1:Y]+#cellH#*5)
meterStyle=ButtonShape | 1x1container

[3w]
meter=shape
y=([1:Y]+#cellH#*2)
meterStyle=ButtonShape | 1x2container

[4w]
meter=shape
y=([1:Y]+#cellH#*3)
meterStyle=ButtonShape | 1x2container

[5w]
meter=shape
y=([1:Y]+#cellH#*4)
meterStyle=ButtonShape | 1x2container

[6w]
meter=shape
y=([1:Y]+#cellH#*5)
meterStyle=ButtonShape | 1x2container

[7]
meter=shape
X=([1:X]+#CellW#+5)
y=([1:Y])
meterStyle=ButtonShape | 1x1container

[8]
meter=shape
y=([1:Y]+#cellH#)
meterStyle=ButtonShape | 1x1container

[9]
meter=shape
y=([1:Y]+#cellH#*2)
meterStyle=ButtonShape | 1x1container

[10]
meter=shape
y=([1:Y]+#cellH#*3)
meterStyle=ButtonShape | 1x1container

[11]
meter=shape
y=([1:Y]+#cellH#*4)
meterStyle=ButtonShape | 1x1container

[12]
meter=shape
y=([1:Y]+#cellH#*5)
meterStyle=ButtonShape | 1x1container

[setOpacity]
meter=string
text="BG Alpha"
SolidColor=255,255,255
meterStyle=sliderLabel
fontSize=(#SettingsFontSize#-2)
container=5w

[adjustAlpha]
meter=shape
dynamicVariables=1
meterStyle=sliderShape | AlphaAction
solidColor=255,255,255
container=5w
x=r
y=(#CellH#/-2)r

[AlphaAction]
; default action for clock alpha vars
LeftMouseUpAction=[!setVariable Alpha (($MouseX:%$)*2.55)][!SetVariable ClockAlpha (($MouseX:%$)*2.55) "#RootConfig#\clocks"][!writeKeyValue Variables ClockAlpha (($MouseX:%$)*2.55) "#RootConfigPath#\Clocks\#CurrentFile#"][!writeKeyValue Variables Alpha (($MouseX:%$)*2.55)][!Redraw "#RootConfig#\clocks"]

[1WinColorsToggleAction]
text="Use Windows Colors"
leftMouseUpAction=[!SetVariable winColors 0][!SetVariable winColors 0 "#RootConfig#\clocks"][!WriteKeyValue Variables WinColors 0][!WriteKeyValue Variables WinColors 0 "#RootConfigPath#\Clocks\#CurrentFile#"][!refresh "#RootConfig#\clocks"]

[0WinColorsToggleAction]
text="Use These Colors"
leftMouseUpAction=[!SetVariable winColors 1][!SetVariable winColors 1 "#RootConfig#\clocks"][!WriteKeyValue Variables WinColors 1][!WriteKeyValue Variables WinColors 1 "#RootConfigPath#\Clocks\#CurrentFile#"][!refresh "#RootConfig#\clocks"]

[WinColorsToggle]
meter=string
meterStyle=buttonLabelW | #winColors##CurrentSection#Action
solidColor=255,255,255
container=6w
MouseOverAction=[!SetOption #CURRENTSECTION# solidColor 200,200,200]
MouseLeaveAction=[!SetOption #CURRENTSECTION# solidColor 255,255,255]
