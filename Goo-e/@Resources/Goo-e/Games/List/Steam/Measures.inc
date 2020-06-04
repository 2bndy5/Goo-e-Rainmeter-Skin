[mAlphaBg]
measure=calc
dynamicVariables=1
formula=round(#BgAlpha# / 2.55)

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
startTimer=[!commandMeasure mParseApps "startTimer()"]
parseData=[!commandMeasure mListInfoFiles run]

[mListInfoFiles]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter="dir #libList#"
finishAction=[!commandMeasure mParseApps "parseApps()"]

[mParseApps]
Measure=Script
ScriptFile="#@##CurrentConfig#\#Service#\ParseApps.lua"
dynamicVariables=1
updateDivider=-1
onupdateAction=[!updateMeasure mPoseApps]

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

[dirSizeInfo]
measure=plugin
Plugin=folderInfo
dynamicVariables=1
updateDivider=-1
folder=#testDir#
infotype=FolderSize
IncludeSubFolders=1

[activeArtwork]
measure=calc
dynamicVariables=1
formula=#useBoxart#
substitute="0":"_header.jpg","-1":"_logo.png","1":"_library_600x900.jpg"
ifCondition=#useBoxart# = 1
ifTrueAction=[!setOption boxartImages prefix "[\xe73a] "]
ifFalseAction=[!setOption boxartImages prefix "[\xe739] "]
ifCondition2=#useBoxart# = 0
ifTrueAction2=[!setOption BannerImages prefix "[\xe73a] "]
ifFalseAction2=[!setOption BannerImages prefix "[\xe739] "]
ifCondition3=#useBoxart# = -1
ifTrueAction3=[!setOption LogoImages prefix "[\xe73a] "]
ifFalseAction3=[!setOption LogoImages prefix "[\xe739] "]
