[mAlphaBg]
measure=calc
dynamicVariables=1
formula=round(#BgAlpha# / 2.55)

[mLibFolder]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=left
x=([menu0:X])
y=([menu0:Y])
w=([menu0:W])
h=([menu0:H])
DynamicVariables=1
DefaultValue="#OriginDir0#"
Command1=[!SetVariable OriginDir "$userinput$"][!writekeyvalue Variables OriginDir0 "[#CURRENTSECTION#]" "#@##CurrentConfig#\Variables.inc"]

[mLibFolder0]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=left
x=([menu0:X])
y=([menu0:Y])
w=([menu0:W])
h=([menu0:H])
DynamicVariables=1
DefaultValue="#OriginDir0#"
Command1=[!SetVariable OriginDir0 "$userinput$"][!writekeyvalue Variables OriginDir0 "[#CURRENTSECTION#]" "#@##CurrentConfig#\Variables.inc"]

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
Command1=[!SetVariable OriginDir1 "$userinput$"][!writekeyvalue Variables OriginDir1 "[#CURRENTSECTION#]" "#@##CurrentConfig#\Variables.inc"]

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
Command1=[!SetVariable OriginDir2 "$userinput$"][!writekeyvalue Variables OriginDir2 "[#CURRENTSECTION#]" "#@##CurrentConfig#\Variables.inc"]

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
Command1=[!SetVariable OriginDir3 "$userinput$"][!writekeyvalue Variables OriginDir3 "[#CURRENTSECTION#]" "#@##CurrentConfig#\Variables.inc"]

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
Command1=[!SetVariable OriginDir4 "$userinput$"][!writekeyvalue Variables OriginDir4 "[#CURRENTSECTION#]" "#@##CurrentConfig#\Variables.inc"]

[mListFolders]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter="dir #libList# /A:D "
finishAction=[!commandMeasure parseNpose "parseApps()"]

[mItemSize]
measure=Plugin
Plugin=RunCommand
dynamicVariables=1
Parameter="dir #temp# /s"
regexpsubstitute=1
substitute="(?siU).*Total Files Listed.*File\(s\)\s*(.*) bytes.*$":"\1"
finishAction=[!commandMeasure parseNpose "parseApps()"]
onupdateAction=[!CommandMeasure parseNpose takeSize([#currentSection#])]

[mIconSearch]
measure=string
dynamicVariables=1
string="[mItemID#activeItem#]"
substitute=" ":"+"

[parseNpose]
Measure=Script
ScriptFile="#@##CurrentConfig#\#Service#\ParseAndPose.lua"
dynamicVariables=1
updateDivider=-1
