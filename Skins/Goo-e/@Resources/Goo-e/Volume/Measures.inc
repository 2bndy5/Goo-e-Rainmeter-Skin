
[mAudio]
Measure=Plugin
Plugin=Win7AudioPlugin

[mInputSize]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*18/256)
StringAlign=center
X=([setSize:X]+[setSize:W]/2)
y=([setSize:Y])
w=(#IconSize#*0.25)
h=(#IconSize#*0.25)
DynamicVariables=1
focusdismiss=1
DefaultValue="#IconSize#"
InputNumber=1
Command1=[!writekeyvalue variables IconSize "$UserInput$" "#@##CurrentConfig#\Variables.inc"][!refresh]

[ScriptShade]
measure=script
DynamicVariables=1
ScriptFile="#@#CalcShadows.lua"
Percent=0.45
Color1=#ButtonColor#
Color2=#knobColor#
;disabled=(#WinColors#=1?0:1)
;updateDivider=-1
