[mAlphaBg]
measure=calc
dynamicVariables=1
formula=round(#BgAlpha# / 2.55)

[imgOrientAlias]
measure=calc
dynamicVariables=1
formula=#useBoxArt#
substitute="0":"_header","1":"_library_600x900"

[currAppId]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Software\Valve\Steam
RegValue=RunningAppID

[displayLoading]
measure=plugin
Plugin=ActionTimer
dynamicVariables=1
ActionList1=wait 250 | startTimer | parseData
startTimer=[!commandMeasure parseNpose "startTimer()"]
parseData=[!commandMeasure mListSteamFiles run]

[mListSteamFiles]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter="dir #libList#"
finishAction=[!commandMeasure parseNpose "parseApps()"]

[mIconSearch]
measure=string
dynamicVariables=1
string="[mItemName#activeItem#]"
substitute=" ":"+"

[parseNpose]
Measure=Script
ScriptFile="#@##CurrentConfig#\#Service#\ParseAndPose.lua"
dynamicVariables=1
updateDivider=-1

[activeSort]
measure=string
string=#sort#
dynamicVariables=1
ifMatch=name
ifMatchAction=[!setOption menu0 prefix "[\xe73a] "]
ifNotMatchAction=[!setOption menu0 prefix "[\xe739] "]
ifMatch2=playtime
ifMatchAction2=[!setOption menu1 prefix "[\xe73a] "]
ifNotMatchAction2=[!setOption menu1 prefix "[\xe739] "]
ifMatch3=size
ifMatchAction3=[!setOption menu2 prefix "[\xe73a] "]
ifNotMatchAction3=[!setOption menu2 prefix "[\xe739] "]
ifMatch4=lastPlayed
ifMatchAction4=[!setOption menu3 prefix "[\xe73a] "]
ifNotMatchAction4=[!setOption menu3 prefix "[\xe739] "]

[activeFullScreen]
measure=calc
dynamicVariables=1
formula=#Maximize#
ifEqualValue=1
ifEqualAction=[!setOption fullScreenSettings prefix "[\xe73a] "]
ifBelowValue=1
ifBelowAction=[!setOption fullScreenSettings prefix "[\xe739] "]


[dirSizeInfo]
measure=plugin
Plugin=folderInfo
dynamicVariables=1
updateDivider=-1
folder=#testDir#
infotype=FolderSize
IncludeSubFolders=1
