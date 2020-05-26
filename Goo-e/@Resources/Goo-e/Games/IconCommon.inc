[Rainmeter]
update=100
defaultUpdateDivider=10
dynamicWindowSize=1

[Variables]
SizeAlpha=0
controllerAlpha=0
playerAlpha=0
InvertLoop=0
@includeVars="#@##CurrentConfig#\List\Variables.inc"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~~Measures~~~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[mInputSize]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=center
X=(#IconSize#-(#IconSize#*0.25))
y=(#IconSize#-(#IconSize#*0.25))
w=(#IconSize#*0.25)
h=(#IconSize#*0.25)
DynamicVariables=1
focusdismiss=1
DefaultValue="#IconSize#"
InputNumber=1
Command1=[!writekeyvalue variables IconSize "$UserInput$" "#@##CurrentConfig#\List\Variables.inc"][!setVariable IconSize [#CurrentSection#]][!redraw]

[mSteamPath]
Measure=Registry
dynamicvariables=1
UpdateDivider=-1
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\Valve\Steam
RegValue=SteamPath
RegExpSubstitute=1
Substitute="^(.*)$$":'"\1\"',"/":"\"

[mOriginPath]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Classes\origin2\shell\open\command
UpdateDivider=-1
RegExpSubstitute=1
Substitute='(?siU)(.*)\s+"\%1"$':"\1"
onUpdateAction=[!setVariable OriginDir [#CurrentSection#]][!writekeyvalue Variables OriginDir [#CurrentSection#] "#@##CurrentConfig#\List\Variables.inc"]

[currAppId]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Software\Valve\Steam
RegValue=RunningAppID
disabled=1
dynamicVariables=1
ifAboveValue=0
ifAboveAction=[!pauseMeasure mAnimLoop]
ifEqualValue=0
ifEqualAction=[!unpauseMeasure mAnimLoop]

[currActiveUser]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Software\Valve\Steam\ActiveProcess
RegValue=ActiveUser
dynamicVariables=1
ifCondition=[#CurrentSection#] <> 0
ifTrueAction=[!writekeyvalue variables lastActiveUser [#CurrentSection#] "#@##CurrentConfig#\List\Variables.inc"]

[ParseSteamLibs]
measure=script
scriptFile="#@##CurrentConfig#\Parse Steam.lua"
dynamicVariables=1
updateDivider=-1

[mAnimLoop]
measure=loop
startValue=1
endValue=95
increment=4
updateDivider=1
DynamicVariables=1
; LoopCount=1

[calcBodyAlpha]
measure=calc
dynamicVariables=1
updateDivider=1
formula=abs((([mAnimLoop] + 40) > 100 ? ([mAnimLoop] - 60) : ([mAnimLoop] + 40)) - 50) / 50

[mSwitchLoop]
measure=loop
startValue=30
endValue=100
increment=10
updateDivider=1
DynamicVariables=1
invertMeasure=#InvertLoop#
LoopCount=1
ifequalValue=100
ifEqualAction=[!EnableMeasure ServiceChangeTrig]

[mPrevService]
measure=string
dynamicVariables=1
string=#CurrentFile#
regExpSubstitute=1
substitute="(.*)\-.*$":"\1"

[ServiceChangeTrig]
measure=String
dynamicVariables=1
disabled=1
string=#Service#
ifmatchmode=1
ifMatch=(?i)[&mPrevService]
ifNotMatchAction=[!ActivateConfig "#CurrentConfig#" "#service#-[&mPrevService].ini"]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;MeterStyles
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[SteamIconShape]
; common predefined properties
strokeDash=StrokeWidth ([#CurrentSection#:W]*0.0157) | strokeDashCap round
pivotGlow=fill color 97,162,233,([calcBodyAlpha] * 255)
; predefined scalar paths
LeftLeg=0,([#CurrentSection#:H]*0.455) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.612) | ArcTo ([#CurrentSection#:W]*0.316),([#CurrentSection#:H]*0.75) | LineTo 0,([#CurrentSection#:H]*0.62) | ClosePath 1
RightLeg=([#CurrentSection#:W]*0.347),([#CurrentSection#:H]*0.56) | LineTo ([#CurrentSection#:W]*0.49),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.675),([#CurrentSection#:H]*0.54) | LineTo ([#CurrentSection#:W]*0.469),([#CurrentSection#:H]*0.69) | ClosePath 1
; predefined gradients
SteamBgGradient=-90 | 19,132,181,([calcBodyAlpha] * 150) ; 1.0 | 20,60,111,([calcBodyAlpha] * 150) ; 0.6 | 15,32,79,([calcBodyAlpha] * 150) ; 0.4
snakeGradient=([mAnimLoop] * -3.6) | 52,169,250 ; 1.0 | 52,169,250,127 ; 0.5
; shapes for building the image
shape=Ellipse ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.372),([#CurrentSection#:W]*0.092)
shape2=Ellipse ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.372),([#CurrentSection#:W]*0.125) | StrokeWidth 0 | extend pivotGlow
shape3=Ellipse ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.372),([#CurrentSection#:W]*0.186)
shape4=Ellipse ([#CurrentSection#:W]*0.35),([#CurrentSection#:H]*0.682),([#CurrentSection#:W]*0.104) | StrokeWidth 0 | extend pivotGlow
shape5=Ellipse ([#CurrentSection#:W]*0.35),([#CurrentSection#:H]*0.682),([#CurrentSection#:W]*0.14)
shape6=path LeftLeg
shape7=Path RightLeg
Shape8=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.48) | fill LinearGradient SteamBgGradient | extend strokeDash | strokeDashes 160,160 | strokeDashOffset ([mAnimLoop] * 3.2) | stroke LinearGradient snakeGradient
; rotating three-dash stroke
shape9=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.492) | fill LinearGradient SteamBgGradient | extend strokeDash | strokeDashes 31.875,31.875 | strokeDashOffset ([mAnimLoop] * 1.275) | strokeColor 61a2e9
; glowing small pivot
shape10=Combine shape4 | exclude shape6
; glowing big pivot
shape11=Combine shape2 | exclude shape
; the whole outline including wrench and circle
shape12=Combine shape8 | exclude shape7 | exclude shape5 | exclude shape6 | exclude shape3
Group=Icons

[OriginIconShape]
RadGrad=([#CurrentSection#:W]*-0.1),([#CurrentSection#:H]*-0.25),0,0,([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | 255,153,0 ; 0.5 | 240,90,34 ; 1.0
PointUp=([#CurrentSection#:W]*0.52),([#CurrentSection#:H]*0.25) | CurveTo ([#CurrentSection#:W]*0.52),0,([#CurrentSection#:W]*0.37),([#CurrentSection#:H]*0.18) | CurveTo ([#CurrentSection#:W]*0.14),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.14),([#CurrentSection#:H]*0.22) | ClosePath 1
PointDown=([#CurrentSection#:W]*0.48),([#CurrentSection#:H]*0.75) | CurveTo ([#CurrentSection#:W]*0.48),[#CurrentSection#:H],([#CurrentSection#:W]*0.63),([#CurrentSection#:H]*0.82) | CurveTo ([#CurrentSection#:W]*0.86),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.86),([#CurrentSection#:H]*0.78) | ClosePath 1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.5) | StrokeWidth 0 | Fill Color 0,0,0,1
shape2=Path PointUp
shape3=Path PointDown
shape4=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.367) | StrokeWidth ([#CurrentSection#:W]*0.015) | stroke RadialGradient RadGrad | fill color 0,0,0,([calcBodyAlpha:]*255)
; | strokeDashes ([#CurrentSection#:W]*0.015*5.9),([#CurrentSection#:W]*0.015*5.9) | strokeDashOffset ([#CurrentSection#:W]*0.015*11.6*[mAnimLoop:/100])
shape5=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.15)
shape6=Combine Shape4 | Exclude shape5 | Union shape2 | Union shape3 | offset ([#CurrentSection#:W]*0.005),([#CurrentSection#:H]*0.005) | rotate (-3.6*[mAnimLoop:]),([#CurrentSection#:W]*0.3745),([#CurrentSection#:H]*0.53) | scale 0.9,0.9
Group=Icons

[RetroarchIconShape]
bodyGradient=90 | 0,0,0,(round([calcBodyAlpha:]*255)) ; 0 | 2,128,24,(round([calcBodyAlpha:]*255)) ; 1
eyeliner=90 | 255,213,0,(round([calcBodyAlpha:]*255)) ; 0 | 196,158,7,(round([calcBodyAlpha:]*255)) ; 1
eyelinerAttributes=stroke LinearGradient eyeliner | strokeWidth ([#CurrentSection#:H]*0.022) | fill color 0,0,0,0
starWipe=0,0,*,*,([#CurrentSection#:W]),([#CurrentSection#:W]*0.6) | 196,158,7,(round([mAnimLoop:]*2.55));0 | 0,0,0,0;(0.01+[mAnimLoop:]*0.99/100) | 255,213,0;(0.01+[mAnimLoop:]*0.99/100) | 255,213,0;(0.1+[mAnimLoop:]*0.9/100) | 196,158,7,1;(0.1+[mAnimLoop:]*0.9/100) | 196,158,7,255;1
outlineAttributes=stroke RadialGradient starWipe | strokeWidth ([#CurrentSection#:H]*0.022) | fill color 0,0,0,0
body=([#CurrentSection#:W]*0.225),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.775),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.853),([#CurrentSection#:H]*0.636) | LineTo ([#CurrentSection#:W]*0.147),([#CurrentSection#:H]*0.636)
xShape=([#CurrentSection#:W]*0.29),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.374),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.39) | LineTo ([#CurrentSection#:W]*0.626),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.71),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.55),([#CurrentSection#:H]*0.444) | LineTo ([#CurrentSection#:W]*0.815),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.703),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.51) | LineTo ([#CurrentSection#:W]*0.297),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.185),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.45),([#CurrentSection#:H]*0.444)
arms=([#CurrentSection#:W]*0.07),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.12),([#CurrentSection#:H]*0.442) | LineTo ([#CurrentSection#:W]*0.881),([#CurrentSection#:H]*0.442) | LineTo ([#CurrentSection#:W]*0.851),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.93),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.988),([#CurrentSection#:H]*0.5585) | LineTo ([#CurrentSection#:W]*0.012),([#CurrentSection#:H]*0.5585)
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | fill color 0,0,0,1 | strokewidth 0
shape2=path body | Fill LinearGradient bodyGradient | strokeWidth 0
shape3=path xShape | fill color 0,0,0,0 | extend outlineAttributes
shape4=path arms
shape5=Rectangle ([#CurrentSection#:W]*0.298),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083)
shape6=Rectangle ([#CurrentSection#:W]*0.621),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083)
shape7=combine shape2 | union shape3 | union shape4 | exclude shape5 | exclude shape6
shape8=combine shape3 | union shape2 | union shape4
shape9=Rectangle ([#CurrentSection#:W]*0.621),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083) | extend eyelinerAttributes
shape10=Rectangle ([#CurrentSection#:W]*0.298),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083) | extend eyelinerAttributes
Group=Icons

[controllerShape]
outline=([#CurrentSection#:W]*0.7625),([#CurrentSection#:H]*0.225) | SetRoundJoin 1 | CurveTo ([#CurrentSection#:W]*0.97),([#CurrentSection#:H]*0.49),([#CurrentSection#:W]*0.9475),([#CurrentSection#:H]*0.26) | SetRoundJoin 1 | CurveTo ([#CurrentSection#:W]*0.65),([#CurrentSection#:H]*0.66),([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*1.04),([#CurrentSection#:W]*0.702),([#CurrentSection#:H]*0.65) | SetRoundJoin 1 | LineTo ([#CurrentSection#:W]*0.35),([#CurrentSection#:H]*0.66) | SetRoundJoin 1 | CurveTo ([#CurrentSection#:W]*0.03),([#CurrentSection#:H]*0.49),([#CurrentSection#:W]*0.298),([#CurrentSection#:H]*0.65),([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*1.04) | SetRoundJoin 1 | CurveTo ([#CurrentSection#:W]*0.24),([#CurrentSection#:H]*0.225),([#CurrentSection#:W]*0.0525),([#CurrentSection#:H]*0.26) | ClosePath 1
AButton=strokewidth 0 | Fill Color 255,255,255,#controllerAlpha#
Strokes=StrokeWidth (([#CurrentSection#:W]+[#CurrentSection#:H])/2*0.06) | StrokeColor 255,255,255,#controllerAlpha#
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 00000001
shape2=ellipse ([#CurrentSection#:W]*0.6875),([#CurrentSection#:H]*0.4425),([#CurrentSection#:W]*0.065)| Extend AButton
shape3=ellipse ([#CurrentSection#:W]*0.81),([#CurrentSection#:H]*0.5675),([#CurrentSection#:W]*0.065)| Extend AButton
shape4=Line ([#CurrentSection#:W]*0.223),([#CurrentSection#:H]*0.375),([#CurrentSection#:W]*0.223),([#CurrentSection#:H]*0.565) | Extend Strokes
shape5=Line ([#CurrentSection#:W]*0.125),([#CurrentSection#:H]*0.474),([#CurrentSection#:W]*0.313),([#CurrentSection#:H]*0.474) | Extend Strokes
shape6=path outline | Extend Strokes | Extend offset1 | Fill Color 00000000

[musicNoteShape]
lineAttri=strokeWidth ([#CurrentSection#:W]*0.0625) | strokeColor 255,255,255,#playerAlpha#
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
shape2=ellipse ([#CurrentSection#:W]*0.377),([#CurrentSection#:H]*0.8438),([#CurrentSection#:W]*0.1582),([#CurrentSection#:H]*0.125) | extend lineAttri | Fill Color 0,0,0,0
shape3=Line ([#CurrentSection#:W]*0.5352),([#CurrentSection#:H]*0.8633),([#CurrentSection#:W]*0.5352),0
shape4=Curve ([#CurrentSection#:W]*0.5352),0,([#CurrentSection#:W]*0.7227),([#CurrentSection#:H]*0.3711),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.1641),([#CurrentSection#:W]*0.7422),([#CurrentSection#:H]*0.2227) | extend lineAttri | strokeEndCap Round
shape5=combine shape2 | union shape3

[resizeShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor 255,255,255,#SizeAlpha# | Fill Color 0,0,0,1
ArrowBottom=([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.62) | LineTo ([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.895) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.895)
ArrowTop=([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.385)
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
shape2=Line ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.16),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.845) | Extend ButtAttributes | StrokeStartCap Triangle | StrokeEndCap Triangle
shape3=Path ArrowBottom | Extend ButtAttributes
shape4=path ArrowTop | Extend ButtAttributes

; this shape is archived until emulationStation gets updated (development has been stale for years)
[emulationStationIconShape]
bgBlue=0,([#CurrentSection#:H]/4) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.15) | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]*0.15) | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.85) | LineTo 0,([#CurrentSection#:H]*0.85) | ClosePath 1
E=([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.35) | SetRoundJoin 1 | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.65) | closepath 1
S=([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.35) | SetRoundJoin 1 | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.45) | closepath 1
shadeE=0,([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.3),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.3),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.85) | LineTo 0,([#CurrentSection#:H]*0.85) | closepath 1
shadeS=0,([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.7),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.7),([#CurrentSection#:H]*0.85) | closepath 1
shape=path bgBlue | StrokeWidth 0 | Fill Color 0,78,115
shape2=path shadeE | StrokeWidth 0 | Fill Color 0,0,0,85
shape3=path shadeS | StrokeWidth 0 | Fill Color 0,0,0,85
shape4=path E | StrokeColor 255,255,255 | StrokeWidth ([#CurrentSection#:H]*0.005) | Fill Color 255,255,255
shape5=path S | StrokeColor 255,255,255 | StrokeWidth ([#CurrentSection#:H]*0.005) | Fill Color 255,255,255
; blue=0,78,115
; letterH=([#CurrentSection#:H]/2)
; letterW=([#CurrentSection#:H]*0.8)
; bgH=([#CurrentSection#:H]*0.7)
; RounedJoints=([#CurrentSection#:H]*0.025)
