;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;MeterStyles~~~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[IconBG]
imagename=downloadfile\NoImagefound.png
h=#IconH#
w=#IconW#
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
dynamicvariables=1
leftmouseupaction=[[&parseNpose:shortcut(#console#,#CurrentSection#)]][!writeKeyValue Variables console #console# "#@##CurrentConfig#\#Service#\Measures.inc"][!writeKeyValue Variables game #game# "#@##CurrentConfig#\#Service#\Measures.inc"]
rightMouseUpAction=[!setvariable activeItem "#CurrentSection#"][!setvariable activeId "[mItemID#CurrentSection#]"][!hidemetergroup rightClickMenu][!setVariable menuX ((#WorkareaWidth#-($mouseX$+[#CurrentSection#:X])+#CURRENTCONFIGX#)<#menuW#?(($mouseX$+[#CurrentSection#:X])-#menuW#):($mouseX$+[#CurrentSection#:X]))][!setVariable menuY ((#WorkAreaHeight#-($mouseY$+[#CurrentSection#:Y])+#CURRENTCONFIGY#)<(#NameH#*8)?(($mouseY$+[#CurrentSection#:Y])-(#NameH#*8)):($mouseY$+[#CurrentSection#:Y]))][!showmetergroup rightClickMenu]

[GameBanner]
imageName="downloadFile\[mItemID#CurrentSection#].jpg"
h=#IconH#
w=#IconW#
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
preserveAspectratio=#Minimize#
dynamicvariables=1
leftmouseupaction=[[&parseNpose:shortcut(#console#,#CurrentSection#)]][!writeKeyValue Variables console #console# "#@##CurrentConfig#\#Service#\Measures.inc"][!writeKeyValue Variables game #game# "#@##CurrentConfig#\#Service#\Measures.inc"]
rightMouseUpAction=[!setvariable activeItem "#CurrentSection#"][!setvariable activeId "[mItemID#CurrentSection#]"][!hidemetergroup rightClickMenu][!setVariable menuX ((#WorkareaWidth#-($mouseX$+[#CurrentSection#:X])+#CURRENTCONFIGX#)<#menuW#?(($mouseX$+[#CurrentSection#:X])-#menuW#):($mouseX$+[#CurrentSection#:X]))][!setVariable menuY ((#WorkAreaHeight#-($mouseY$+[#CurrentSection#:Y])+#CURRENTCONFIGY#)<(#NameH#*8)?(($mouseY$+[#CurrentSection#:Y])-(#NameH#*8)):($mouseY$+[#CurrentSection#:Y]))][!showmetergroup rightClickMenu]

[ConsoleBanner]
imageName="downloadFile\[mItemID#CurrentSection#].jpg"
h=#IconH#
w=#IconW#
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
preserveAspectratio=1
dynamicvariables=1
leftmouseupaction=[&parseNpose:shortcut(#console#,#CurrentSection#)][!updateMeasure parseNpose]
rightMouseUpAction=[!setvariable activeItem "#CurrentSection#"][!setvariable activeId "[mItemID#CurrentSection#]"][!hidemetergroup rightClickMenu][!setVariable menuX ((#WorkareaWidth#-($mouseX$+[#CurrentSection#:X])+#CURRENTCONFIGX#)<#menuW#?(($mouseX$+[#CurrentSection#:X])-#menuW#):($mouseX$+[#CurrentSection#:X]))][!setVariable menuY ((#WorkAreaHeight#-($mouseY$+[#CurrentSection#:Y])+#CURRENTCONFIGY#)<(#NameH#*8)?(($mouseY$+[#CurrentSection#:Y])-(#NameH#*8)):($mouseY$+[#CurrentSection#:Y]))][!showmetergroup rightClickMenu]

[NameStyle]
solidcolor=#BGcolor#,#BgAlpha#
x=(#IconW#/2)r
y=(#IconH#-#NameH#-#NameH#*(#Minimize#=0?1:0))r
w=#IconW#
h=(#NameH#+#NameH#*(#Minimize#=0?1:0))
clipstring=2
fontface=#fontface#
fontsize=#fontsize#
stringalign=CenterTop
fontColor=#fontColor#
dynamicvariables=1

[InfoStyle]
solidcolor=#BGcolor#,#BgAlpha#
x=(#IconW#/2)r
y=r
fontface=#fontface#
fontsize=#fontsize#
stringalign=RightBottom
fontColor=#fontColor#
dynamicvariables=1

[RCMenuItem]
solidcolor=#BGcolor#
w=#menuW#
h=#NameH#
clipstring=2
fontface=#fontface#
fontsize=#fontsize#
stringalign=LeftCenter
fontColor=#fontColor#
dynamicvariables=1
MouseOverAction=[!setoption #CurrentSection# solidColor #highlightColor#][!redraw]
MouseLeaveAction=[!setoption #CurrentSection# solidColor #BGcolor#][!redraw]

[LibraryStyle]
solidcolor=#BGcolor#
x=r
y=45r
w=400
h=45
clipstring=1
fontface=#fontface#
fontsize=#fontsize#
stringalign=leftCenter
fontColor=#fontColor#
dynamicvariables=1
group=LibrarySelect
hidden=1
MouseOverAction=[!setOption #CurrentSection# solidColor #highlightColor#][!redraw]
MouseLeaveAction=[!setOption #CurrentSection# solidColor #BGcolor#][!redraw]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Meters~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[indexup]
meter=shape
imagename="#@#images\Steam\arrow.png"
greyscale=#greyscale#
imagetint=#fontColor#
dynamicvariables=1
w=80
h=70
ArrowAttributes=Strokewidth 0 | Fill Color #UpWhite#
BGAttributes=StrokeWidth 0 | Fill Color #UpBGcolor#,#BgAlpha#
Arrow=([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.475) | ArcTo ([#CurrentSection#:W]*0.19),([#CurrentSection#:H]*0.39) |  LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.14) | CurveTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.14),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.06) | LineTo ([#CurrentSection#:W]*0.81),([#CurrentSection#:H]*0.39) | ArcTo ([#CurrentSection#:W]*0.72),([#CurrentSection#:H]*0.475) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.315) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.83) | ArcTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.83) | LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.315) | ClosePath 1
BG=([#CurrentSection#:W]*0.5),0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]) | ArcTo ([#CurrentSection#:W]*0.5),0 | ClosePath 1
shape=Path BG | Extend BGAttributes
shape2=Path Arrow | Extend ArrowAttributes
group=scrollPages
MouseOverAction=[!SetVariable UpBGcolor "#HighlightColor#"][!SetVariable UpWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable UpBGcolor "#BGcolor#"][!SetVariable UpWhite "#fontColor#"][!redraw]
leftmouseupaction=[!commandMeasure parseNpose PgUp()]

[indexdown]
meter=shape
dynamicVariables=1
w=80
h=70
ArrowAttributes=Strokewidth 0 | Fill Color #DnWhite# | Scale 1.0,-1.0
BGAttributes=StrokeWidth 0 | Fill Color #DnBGcolor#,#BgAlpha#
Arrow=([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.475) | ArcTo ([#CurrentSection#:W]*0.19),([#CurrentSection#:H]*0.39) |  LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.14) | CurveTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.14),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.06) | LineTo ([#CurrentSection#:W]*0.81),([#CurrentSection#:H]*0.39) | ArcTo ([#CurrentSection#:W]*0.72),([#CurrentSection#:H]*0.475) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.315) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.83) | ArcTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.83) | LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.315) | ClosePath 1
BG=([#CurrentSection#:W]*0.5),0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]) | ArcTo ([#CurrentSection#:W]*0.5),0 | ClosePath 1
shape=Path BG | Extend BGAttributes
shape2=Path Arrow | Extend ArrowAttributes
group=scrollPages
MouseOverAction=[!SetVariable DnBGcolor "#HighlightColor#"][!SetVariable DnWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable DnBGcolor "#BGcolor#"][!SetVariable DnWhite "#FontColor#"][!redraw]
leftmouseupaction=[!commandMeasure parseNpose PgDown()]

[MinimizeToggle]
meter=shape
dynamicvariables=1
x=0
y=(#iconH#/2-135)
h=90
w=90
LineAttributes=Strokewidth ([#CurrentSection#:W]*0.05) | Fill Color 0,0,0,1 | StrokeColor #sizeWhite#
BGAttributes=StrokeWidth 0 | Fill Color #sizeBGcolor#,#BgAlpha#
TopCorner=0,([#CurrentSection#:H]) | LineTo 0,([#CurrentSection#:W]*0.2) | CurveTo ([#CurrentSection#:W]*0.2),0,0,0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | ClosePath 1
shape=path TopCorner | Extend BGAttributes
shape2=Line ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.16),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.845) | Extend LineAttributes | StrokeStartCap Triangle | StrokeEndCap Triangle
shape3=Path ArrowBottom | Extend LineAttributes
ArrowBottom=([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.62) | LineTo ([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.895) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.895)
shape4=path ArrowTop | Extend LineAttributes
ArrowTop=([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.385)
shape5=Rectangle -5,-5,90,90 | strokeWidth 0 | fill color 0,0,0,1
LeftMouseUpAction=[!WriteKeyValue variables Minimize (#Minimize#=0?1:0) "#@##CurrentConfig#\Variables.inc][!SetVariable Minimize (#Minimize#=0?1:0)][!commandmeasure parseNpose setGrid()]
MouseOverAction=[!SetVariable sizeBGcolor "#HighlightColor#"][!SetVariable sizeWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable sizeBGcolor "#BGcolor#"][!SetVariable sizeWhite #FontColor#][!redraw]
tooltipHidden=0
tooltipText="Right click to change#CRLF#background Opacity"
RightMouseUpAction=[!togglemetergroup SelectAlpha]

[SwitchLibraryFolder]
Meter=image
imagename="#@#images\Games\HDD.png"
x=r
y=90r
w=90
h=90
dynamicvariables=1
solidcolor=#BGcolor#,#BgAlpha#
leftmouseupaction=[!SetVariable console (-1*#console#)][!updatemeasure parseNpose]
MouseOverAction=[!setOption #CurrentSection# solidColor #HighlightColor#,#BgAlpha#][!redraw]
MouseLeaveAction=[!setOption #CurrentSection# solidColor #BGcolor#,#BgAlpha#][!redraw]

[CloseBG]
meter=Shape
dynamicVariables=1
x=r
y=90r
w=90
h=90
xAttributes=Strokewidth 0 | Fill Color #xWhite#
BGAttributes=StrokeWidth 0 | Fill Color #xBGcolor#,#BgAlpha#
BottomCorner=0,0 | LineTo 0,([#CurrentSection#:H]-[#CurrentSection#:W]*0.2) | CurveTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]),0,([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]),0 | ClosePath 1
shape=path BottomCorner | Extend BGAttributes
shape2=Rectangle 0,([#CurrentSection#:H]*0.47),([#CurrentSection#:W]),([#CurrentSection#:W]*0.12),([#CurrentSection#:W]*0.06) | Extend xAttributes | Rotate 45.0
shape3=Rectangle 0,([#CurrentSection#:H]*0.47),([#CurrentSection#:W]),([#CurrentSection#:W]*0.12),([#CurrentSection#:W]*0.06) | Extend xAttributes | Rotate -45.0
shape4=Combine Shape2 | Union Shape3
MouseOverAction=[!SetVariable xBGcolor "#HighlightColor#"][!SetVariable xWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable xBGcolor "#BGcolor#"][!SetVariable xWhite #FontColor#][!redraw]
LeftMouseUpAction=[!DeactivateConfig "#CurrentConfig#"][!writeKeyValue Variables console #console# "#@##CurrentConfig#\#Service#\Measures.inc"][!writeKeyValue Variables game #game# "#@##CurrentConfig#\#Service#\Measures.inc"]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Right Click Menu~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[RightClickMenu1]
meter=string
meterStyle=RCMenuItem
y=#menuY#
text="Open Image"
leftMouseUpAction=["[&parseNpose:getGameImagePath(#console#, #activeItem#)]"][!hideMeterGroup rightClickMenu]

[RightClickMenu2]
meter=string
meterStyle=RCMenuItem
text="Go to Rom Folder"
leftmouseupaction=[explorer.exe "[&parseNpose:getConPath(#console#)]\"][!deactivateConfig "#CurrentConfig#"]

; [RightClickMenu3]
; meter=string
; meterStyle=RCMenuItem
; text="Browse in Steam"
; leftMouseUpAction=[!setVariable invertMenu 1 "#rootConfig#\Games"][!SetOption MeasureAnimateMenu StartValue 0 "*"][!deactivateConfig "#CurrentConfig#"][steam://nav/games/detsils/#activeID#]

; [RightClickMenu4]
; meter=string
; meterStyle=RCMenuItem
; text="Open Store Page"
; leftmouseupaction=[!setVariable invertMenu 1 "#rootConfig#\Games"][!SetOption MeasureAnimateMenu StartValue 0 "*"][!deactivateConfig "#CurrentConfig#"][steam://store/#activeID#]

[BgOpacity]
meter=shape
dynamicVariables=1
x=([MinimizeToggle:W])
y=([MinimizeToggle:Y])
w=360
h=(#NameH#*2)
hidden=1
group=bgAlpha
shape=Rectangle ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.1),([#CurrentSection#:W]*0.7),([#CurrentSection#:H]*0.8) | strokeWidth 0 | Fill LinearGradient OpacityMeter
OpacityMeter= 180.0 | #MinBGcolor#,1 ; 0 | #MinBGcolor#,255 ; 1 
shape2=Rectangle ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.1),([#CurrentSection#:W]*0.7),([#CurrentSection#:H]*0.8)
shape3=Rectangle ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.1),([#CurrentSection#:W]*0.7),([#CurrentSection#:H]*0.8)
Shape4=Combine shape2 | exclude shape3
;LeftMouseUpAction=[!SetVariable BgAlpha 150]