[mAlphaBg]
measure=calc
dynamicVariables=1
formula=round(#BgAlpha# / 2.55)

[mLibFolder1]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=left
x=([menu1:X])
y=([menu1:Y])
w=([menu1:W])
h=([menu1:H])
DynamicVariables=1
focusdismiss=1
DefaultValue="#OriginDir1#"
Command1=[!SetVariable OriginDir1 "$userinput$"][!writekeyvalue Variables OriginDir1 "[#CURRENTSECTION#]" "#@##CurrentConfig#\#Service#\SpecificVars.inc"]

[mLibFolder2]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=left
x=([menu2:X])
y=([menu2:Y])
w=([menu2:W])
h=([menu2:H])
DynamicVariables=1
focusdismiss=1
DefaultValue="#OriginDir2#"
Command1=[!SetVariable OriginDir2 "$userinput$"][!writekeyvalue Variables OriginDir2 "[#CURRENTSECTION#]" "#@##CurrentConfig#\#Service#\SpecificVars.inc"]

[mLibFolder3]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=left
x=([menu3:X])
y=([menu3:Y])
w=([menu3:W])
h=([menu3:H])
DynamicVariables=1
focusdismiss=1
DefaultValue="#OriginDir3#"
Command1=[!SetVariable OriginDir3 "$userinput$"][!writekeyvalue Variables OriginDir3 "[#CURRENTSECTION#]" "#@##CurrentConfig#\#Service#\SpecificVars.inc"]

[mLibFolder4]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=left
x=([menu4:X])
y=([menu4:Y])
w=([menu4:W])
h=([menu4:H])
DynamicVariables=1
focusdismiss=1
DefaultValue="#OriginDir4#"
Command1=[!SetVariable OriginDir4 "$userinput$"][!writekeyvalue Variables OriginDir4 "[#CURRENTSECTION#]" "#@##CurrentConfig#\#Service#\SpecificVars.inc"]

[mLibList]
measure=string
dynamicVariables=1
string=""#OriginDir1#\__Installer", "#OriginDir2#\__Installer", "#OriginDir3#\__Installer", "#OriginDir4#\__Installer""
; regexpSubstitute=1
substitute=', "\__Installer"':""

[dirSizeInfo]
measure=plugin
Plugin=folderInfo
dynamicVariables=1
updateDivider=-1
folder=#testDir#
infotype=FolderSize
IncludeSubFolders=1

[convert2utf8]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
OutputType=ANSI
Parameter="#PSCMD#"

[mIconSearch]
measure=string
dynamicVariables=1
string="[&mItemName#activeItem#]"
substitute=" ":"+"

[mListInfoFiles]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter="dir [&mLibList] /S /B"
regexpSubstitute=1
substitute="(?sU)Directory of (.*)\n.*bytes\n":"\1\\_Installer"
finishAction=[!commandMeasure mParseApps "parseApps()"]

[displayLoading]
measure=plugin
Plugin=ActionTimer
dynamicVariables=1
ActionList1=wait 250 | startTimer | parseData
startTimer=[!commandMeasure mParseApps "startTimer()"]
parseData=[!commandMeasure mListInfoFiles run]

[mParseApps]
Measure=Script
ScriptFile="#@##CurrentConfig#\#Service#\ParseApps.lua"
dynamicVariables=1
updateDivider=-1
onUpdateAction=[!updateMeasure mPoseApps]

[mPoseApps]
Measure=Script
ScriptFile="#@##CurrentConfig#\PoseApps.lua"
dynamicVariables=1
updateDivider=-1

[activeSort]
measure=string
string=#sort#
dynamicVariables=1
ifMatch=name
ifMatchAction=[!setOption sortname prefix "[\xe73a] "]
ifNotMatchAction=[!setOption sortname prefix "[\xe739] "]
ifMatch2=size
ifMatchAction2=[!setOption sortsize prefix "[\xe73a] "]
ifNotMatchAction2=[!setOption sortsize prefix "[\xe739] "]

[activeFullScreen]
measure=calc
dynamicVariables=1
formula=#Maximize#
ifEqualValue=1
ifEqualAction=[!setOption fullScreenSettings prefix "[\xe73a] "]
ifBelowValue=1
ifBelowAction=[!setOption fullScreenSettings prefix "[\xe739] "]
