[Rainmeter]
update=100
defaultUpdateDivider=10
onCloseAction=[!commandMeasure ParseSteamLibs "cleanUp()"]
ContextTitle="Pause/Unpause Animation"
ContextAction=[!setvariable endvalue (#endValue#<95?95:#pauseValue#)][!setoption mAnimLoop loopCount (#endValue#<95?0:1)]
ContextTitle2="Steam Controller Settings"
ContextAction2=[steam://settings/controller]
ContextTitle3="Windows Controller Settings"
ContextAction3=[!commandMeasure runWinJoy_cpl "run"]

[Variables]
SizeAlpha=0
settingsAlpha=0
playerAlpha=0
InvertLoop=0
endValue=95
pauseValue=44
@includeVars="#@##CurrentConfig#\List\Variables.inc"
@includeRetroarchVars="#@##CurrentConfig#\list\retroarch\specificVars.inc"
@includeShapes="#@#UniversalShapes.inc"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~~Measures~~~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[runWinJoy_cpl]
measure=Plugin
Plugin=RunCommand
Parameter="joy.cpl"

[retroCFG]
measure=script
scriptFile="#@##CurrentConfig#\retrocfg.lua"
updateDivider=-1

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
onUpdateAction=[!setVariable OriginPath [#CurrentSection#]][!writekeyvalue Variables OriginPath [#CurrentSection#] "#@##CurrentConfig#\List\Origin\SpecificVars.inc"]

[currAppId]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Software\Valve\Steam
RegValue=RunningAppID
disabled=1
dynamicVariables=1
ifAboveValue=0
ifAboveAction=[!setvariable endvalue 65][!setoption mAnimLoop loopCount 1]
ifEqualValue=0
ifEqualAction=[!setvariable endvalue 95)][!setoption mAnimLoop loopCount 0]

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
endValue=#endValue#
increment=4
updateDivider=1
DynamicVariables=1
LoopCount=0

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
;~~~~~~~~~~Meter Styles~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@includeLogos="#@##RootConfig#\Games\LogoShapes.inc"

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

[SetServiceSteam]
LeftMouseUpAction=[!writeKeyValue Variables Service Steam "#@##CurrentConfig#\List\Variables.inc"][!setVariable Service Steam][!SetVariable Service Steam "#CurrentConfig#\Settings"]
rightmouseupaction=[steam://open/musicplayer/]

[SetServiceRetroarch]
hidden=#ShowRetroarch#
leftMouseUpAction=[!writeKeyValue Variables Service Retroarch "#@##CurrentConfig#\List\Variables.inc"][!SetVariable Service Retroarch][!SetVariable Service Retroarch "#CurrentConfig#\Settings"]

[SetServiceOrigin]
hidden=#ShowOrigin#
leftMouseUpAction=[!writeKeyValue Variables Service Origin "#@##CurrentConfig#\List\Variables.inc"][!setVariable Service Origin][!SetVariable Service Origin "#CurrentConfig#\Settings"]

[LaunchSteamExe]
LeftMouseDoubleClickAction=[ Steam://open/largegameslist ]

[LaunchOriginExe]
LeftMouseDoubleClickAction=[[&mOriginPath]]

[LaunchRetroarchExe]
LeftMouseDoubleClickAction=["#DIR#\Retroarch.exe"]

[SetSize]
meter=shape
DynamicVariables=1
X=(#IconSize#*0.75)
y=(#IconSize#*0.75)
w=(#IconSize#*0.25)
h=(#IconSize#*0.25)
meterStyle=sizeShape
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor 255,255,255,#SizeAlpha# | Fill Color 0,0,0,1
MouseOverAction=[!setVariable SizeAlpha 255][!redraw]
MouseLeaveAction=[!setVariable SizeAlpha 0][!redraw]
tooltiphidden=0
tooltiptext="Resize Logo"
leftmouseupaction=[!commandmeasure mInputSize "executebatch 1"]

[settingsbutt]
meter=shape
DynamicVariables=1
y=r
h=(#IconSize#*0.25)
w=(#IconSize#*0.25)
meterStyle=SettingsShape
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor 255,255,255,#SettingsAlpha# | Fill Color 0,0,0,1
MouseOverAction=[!setVariable SettingsAlpha 255][!redraw]
MouseLeaveAction=[!setVariable SettingsAlpha 0][!redraw]
leftMouseUpAction=[!ToggleConfig  "#CurrentConfig#\Settings" "LogoSettings.ini"][!move "(#WorkAreaWidth#-(#CurrentConfigX#+#CurrentConfigWidth#)>=725?(#CurrentConfigX#+#IconSize#):(#CurrentConfigX#-725))" "(#WorkAreaHeight#-#CurrentConfigY#>=404?(#CurrentConfigY#):(#WorkAreaHeight#-404))" "#CurrentConfig#\Settings"]
