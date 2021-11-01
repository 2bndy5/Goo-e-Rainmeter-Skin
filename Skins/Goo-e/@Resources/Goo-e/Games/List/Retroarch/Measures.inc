[mAlphaBg]
measure=calc
dynamicVariables=1
formula=round(#BgAlpha# / 2.55)

[mChangePath]
Measure=Plugin
Plugin=InputText
SolidColor=#BgColor#
FontColor=#FontColor#
FontSize=#FontSize#
X=([changeDir:X])
Y=([changeDir:Y])
H=([changeDir:H])
W=([changeDir:W]*2)
DefaultValue="#DIR#"
regexpsubstitute=1
substitute="^(.*)\\":"\1"
Command1=[!WriteKeyValue Variables DIR "$userInput$" "#@##CurrentConfig#\#Service#\SpecificVars.inc"][!refresh]

[mListInfoFiles]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter=""dir "#Dir#\playlists" /B""
finishaction=[!commandMeasure mListCoreFiles "run"]

[mListCoreFiles]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter=""dir "#Dir#\cores" /B""
finishaction=[!commandMeasure mListRetroarchHistory "run"]

[mListRetroarchHistory]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter=""dir "#Dir#\playlists\logs\*.lrtl" /B""
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
ifMatch=label
ifMatchAction=[!setOption sortlabel prefix "[\xe73a] "]
ifNotMatchAction=[!setOption sortlabel prefix "[\xe739] "]
ifMatch2=playtime
ifMatchAction2=[!setOption sortplaytime prefix "[\xe73a] "]
ifNotMatchAction2=[!setOption sortplaytime prefix "[\xe739] "]
ifMatch3=size
ifMatchAction3=[!setOption sortsize prefix "[\xe73a] "]
ifNotMatchAction3=[!setOption sortsize prefix "[\xe739] "]
ifMatch4=lastPlayed
ifMatchAction4=[!setOption sortlastPlayed prefix "[\xe73a] "]
ifNotMatchAction4=[!setOption sortlastPlayed prefix "[\xe739] "]

[activeFullScreen]
measure=calc
dynamicVariables=1
formula=#Maximize#
ifEqualValue=1
ifEqualAction=[!setOption fullScreenSettings prefix "[\xe73a] "]
ifBelowValue=1
ifBelowAction=[!setOption fullScreenSettings prefix "[\xe739] "]

[activeTheme]
measure=string
dynamicVariables=1
string=#theme#
onUpdateAction=[!setOptiongroup SelectThemes prefix "[\xe739] "][!setOption #theme# prefix "[\xe73a] "]

[activeArtwork]
measure=calc
dynamicVariables=1
formula=#useBoxart#
ifCondition=#useBoxart# = 1
ifTrueAction=[!setOption boxartImages prefix "[\xe73a] "]
ifFalseAction=[!setOption boxartImages prefix "[\xe739] "]
ifCondition2=#useBoxart# = 0
ifTrueAction2=[!setOption screenshotImages prefix "[\xe73a] "]
ifFalseAction2=[!setOption screenshotImages prefix "[\xe739] "]
ifCondition3=#useBoxart# = -1
ifTrueAction3=[!setOption titleScreensImages prefix "[\xe73a] "]
ifFalseAction3=[!setOption titleScreensImages prefix "[\xe739] "]

[scriptedActiveFile]
measure=string
dynamicVariables=1
string=#activeFile#
substitute="'":"\'"

[activePath]
measure=string
string=[mItemDIR#activeItem#]
dynamicVariables=1
regexpsubstitute=1
substitute="(.*\\).*\.\w+":"\1"

[activeCore]
measure=string
string=[mItemCore#activeItem#]
dynamicVariables=1
regexpsubstitute=1
substitute="(.*\\).*\.\w+":"\1"
