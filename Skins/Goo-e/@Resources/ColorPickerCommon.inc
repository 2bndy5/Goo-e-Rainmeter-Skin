
[Variables]
ActiveRGB=187,82,0
ActiveHex=F05822
Hue=0.16644558326176
sat=0.79
val=0.60667
HueColor=
SettingsFontSize=20

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Measures~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[mCalcRGB]
Measure=Script
dynamicVariables=1
ScriptFile="#@#CalcRGB.lua"
updateDivider=-1
onUpdateAction=[!updatemeter SatAndVal]
ifconditionMode=1
ifCondition=#Val# > 0.45
ifTrueAction=[!setVariable FontColor "000000"]
ifFalseAction=[!setVariable FontColor #HueColor#]

[mtypeRGB]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
solidcolor=#ActiveRGB#
FontColor=#FontColor#
FontFace=Seqoe UI
FontSize=#SettingsFontSize#
stringalign=center
X=[RGBcolor:X]
Y=[RGBcolor:Y]
H=[RGBcolor:H]
W=[RGBcolor:W]
DefaultValue="#ActiveRGB#"
Command1=[!Setvariable ActiveRGB $userinput$][!commandMeasure mCalcRGB "RGBtoHex('[#CurrentSection#]')"][!updateMeasure mCalcRGB][!Redraw]

[mtypeHex]
Measure=Plugin
Plugin=InputText
dynamicvariables=1
solidcolor=#ActiveHex#
FontColor=#FontColor#
FontFace=Seqoe UI
FontSize=#SettingsFontSize#
stringalign=center
X=[HexColor:X]
Y=[HexColor:Y]
H=[HexColor:H]
W=[HexColor:W]
DefaultValue="#ActiveHex#"
Command1=[!Setvariable ActiveHex $userinput$][!commandMeasure mCalcRGB "HexToRGB('[#CurrentSection#]')"][!updateMeasure mCalcRGB][!Redraw]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Meters~~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[CloseButton]
meter=shape
x=0
y=0
h=([HexColor:H])
w=([HexColor:H])
dynamicvariables=1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | Fill Color ff0000 | strokeWidth 0
shape2=Line 0,([#CurrentSection#:H]*0.5),[#CurrentSection#:W],([#CurrentSection#:H]*0.5) | strokeWidth (([#CurrentSection#:W]+[#CurrentSection#:H])/2*0.05)
shape3=Line ([#CurrentSection#:W]*0.5),0,([#CurrentSection#:W]*0.5),[#CurrentSection#:H]
shape4=Combine shape2 | union shape3 | rotate 45
toolTipHidden=0
ToolTipText="Close Settings"
leftmouseupaction=[!DeactivateConfig "#CurrentConfig#"]

[RGBcolor]
meter=string
X=215
Y=25
H=50
W=300
solidcolor=#ActiveRGB#
text=#ActiveRGB#
dynamicvariables=1
FontColor=#FontColor#
FontFace=Seqoe UI
FontSize=#SettingsFontSize#
stringalign=CenterCenter
leftmouseupaction=[!commandmeasure "mtypeRGB" "executebatch 1"]

[HexColor]
meter=string
X=r
Y=([RGBcolor:H])r
H=[RGBcolor:H]
W=[RGBcolor:W]
solidcolor=#ActiveHex#
text=#ActiveHex#
dynamicvariables=1
FontColor=#FontColor#
FontFace=Seqoe UI
FontSize=#SettingsFontSize#
stringalign=CenterCenter
leftmouseupaction=[!commandmeasure "mtypeHex" "executebatch 1"]

[Hue]
meter=shape
x=0
y=29r
h=([HexColor:W])
w=60
dynamicvariables=1
rainbow=-90 | ff0000 ; 0 | ffff00 ; 0.1667 | 00ff00 ; 0.3333 | 00ffff ; 0.5 | 0000ff ; 0.6667 | ff00ff ; 0.8333 | ff0000 ; 1
shape=rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokewidth 0 | fill LinearGradient rainbow
shape2=Line 0,(#Hue#*[#CurrentSection#:H]),[#CurrentSection#:W],(#Hue#*[#CurrentSection#:H]) | strokeWidth 3 | strokeColor 000000
leftmouseupaction=[!setvariable Hue ($MouseY$/[#CurrentSection#:H])][!writeKeyValue variables Hue ($MouseY$/[#CurrentSection#:H]) "#@#ColorPickerCommon.inc"][!updateMeasure mCalcRGB][!commandMeasure mCalcRGB "HSVtoRGB()"]

[SatAndVal]
meter=shape
x=([HexColor:X])
y=([HexColor:Y]+[HexColor:H]+4)
w=([HexColor:W])
h=([HexColor:W])
dynamicvariables=1
Black=180 | 000000 ; 0.0 | 00000000 ; 0.99
White=90 | ffffff ; 0 | FFFFFF00 ; 0.99
selector=180 | #FontColor# ; 0 | #fontColor# ; 0.5 | 000000 ; 0.5 | 000000 ; 1
shape=rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokewidth 0 | fill Color #HueColor#
shape2=rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokewidth 0 | fill LinearGradient White
shape3=rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokewidth 0 | fill LinearGradient Black
shape4=ellipse (#Val#*[#CurrentSection#:W]),((1-#Sat#)*[#CurrentSection#:H]),([#CurrentSection#:W]*0.025),([#CurrentSection#:H]*0.025)
shape5=rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H])
shape6=Line 0,((1-#Sat#)*[#CurrentSection#:H]),([#CurrentSection#:W]),((1-#Sat#)*[#CurrentSection#:H]) | fill color 00000000 | strokeWidth (([#CurrentSection#:W]+[#CurrentSection#:W])/2*0.0075) | Stroke linearGradient selector
shape7=Line (#Val#*[#CurrentSection#:W]),0,(#Val#*[#CurrentSection#:W]),([#CurrentSection#:H])
shape8=Combine shape6 | Union shape7 | Exclude shape4 | union shape4 | Intersect shape5
LeftMouseUpAction=[!setVariable val ($MouseX$/[#CurrentSection#:W])][!setVariable sat (1-$MouseY$/[#CurrentSection#:H])][!writeKeyValue Variables val ($MouseX$/[#CurrentSection#:W]) "#@#ColorPickerCommon.inc"][!writeKeyValue Variables sat (1-$MouseY$/[#CurrentSection#:H]) "#@#ColorPickerCommon.inc"][!updateMeasure mCalcRGB][!commandMeasure mCalcRGB "HSVtoRGB()"]

@includeMenuUI="#@#SettingsTable.inc"
