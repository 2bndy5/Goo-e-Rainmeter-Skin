
[mSpeakHour]
measure=time
format=%#I

[mSpeakMin]
measure=Time
Format=%M
substitute="00":"O clock","01":"O 1","02":"O 2","03":"O 3","04":"O 4","05":"O 5","07":"O 7","08":"O 8","09":"O 9"

[mSpeakAMPM]
measure=time
format=%p
regExpSubstitute=1
substitute="AM":"A. M.","PM":"P. M."

;;For Stopwatch & alarm skin
;;normally always running
;[mAlignpanels]
;measure=calc
;formula=#currentconfigX#+#currentconfigY#
;dynamicvariables=1
;onchangeaction=[!Move #currentconfigX# #currentconfigY# "#rootconfig#"][!update]

[mInputSize]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
SolidColor=255,255,255
FontColor=0,0,0
FontFace=Arial
FontSize=(#IconSize#*16/256)
StringAlign=center
InputNumber=1
X=(#IconSize#-(#IconSize#*0.5))
y=(#IconSize#-(#IconSize#*0.25))
w=(#IconSize#*0.25)
h=(#IconSize#*0.25)
DynamicVariables=1
focusdismiss=1
DefaultValue="#IconSize#"
Command1=[!writekeyvalue variables IconSize "$UserInput$" "#@##ROOTCONFIG#\clocks\ClockVariables.inc"][!refresh]

[WidthHeight]
x=0
y=0
h=#IconSize#
w=#IconSize#
dynamicVariables=1

[ClickClock]
meter=image
solidcolor=0,0,0,1
x=0
y=0
h=#iconSize#
w=#iconSize#
dynamicvariables=1
leftmousedoubleclickaction=["#@#Addons\nircmd.exe" speak text "The time is [mSpeakHour] [mSpeakMin] [mSpeakAMPM]"]
leftMouseUpAction=[!setvariable hideconfigbar (#hideconfigbar#=0?1:0)][!update]
;mouseoveraction=[!setoptiongroup clockpages imagealpha "255"][!redraw]
;mouseleaveaction=[!setoptiongroup clockpages imagealpha "0"][!redraw]
