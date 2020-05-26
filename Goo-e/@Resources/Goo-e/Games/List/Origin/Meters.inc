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
leftmouseupaction=[""[#shortcut[#CurrentSection#]]""][!deactivateConfig "#CurrentConfig#"]
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
leftmouseupaction=[""[#shortcut#CurrentSection#]""][!deactivateConfig "#CurrentConfig#"]
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
x=#menuX#
y=R
w=#menuW#
h=#NameH#
solidcolor=#BGcolor#
clipstring=2
fontface=#fontface#
fontsize=#fontsize#
stringalign=LeftCenter
fontColor=#fontColor#
dynamicvariables=1
hidden=1
group=rightClickMenu
MouseOverAction=[!setoption #CurrentSection# solidColor #highlightColor#][!redraw]
MouseLeaveAction=[!setoption #CurrentSection# solidColor #BGcolor#][!redraw]

[menuStyle]
solidcolor=#BGcolor#
x=r
y=45r
w=#menuW#
h=45
clipstring=1
fontface=#fontface#
fontsize=#fontsize#
stringalign=leftCenter
fontColor=#fontColor#
dynamicvariables=1
group=menuSelect
hidden=1
MouseOverAction=[!setOption #CurrentSection# solidColor #highlightColor#][!redraw]
MouseLeaveAction=[!setOption #CurrentSection# solidColor #BGcolor#][!redraw]

[1revOrder]
text="descending order"

[0revOrder]
text="ascending order"

[hiddenMenu4]
text="restore showcase"
leftmouseupaction=[!setVariable filter "none"][!commandMeasure parseNpose "applyFilter()"][!hidemetergroup menuSelect][!updateMeasure parseNpose]

[noneMenu4]
text="show hidden"
leftmouseupaction=[!setVariable filter "hidden"][!commandMeasure parseNpose "applyFilter()"][!hidemetergroup menuSelect][!updateMeasure parseNpose]

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
ArrowAttributes=Strokewidth 0 | Fill Color #UpWhite# | rotate (-90*#WR2#)
BGAttributes=StrokeWidth 0 | Fill Color #UpBGcolor#,#BgAlpha#
Arrow=([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.475) | ArcTo ([#CurrentSection#:W]*0.19),([#CurrentSection#:H]*0.39) |  LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.14) | CurveTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.14),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.06) | LineTo ([#CurrentSection#:W]*0.81),([#CurrentSection#:H]*0.39) | ArcTo ([#CurrentSection#:W]*0.72),([#CurrentSection#:H]*0.475) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.315) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.83) | ArcTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.83) | LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.315) | ClosePath 1
BG=([#CurrentSection#:W]*0.5),0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]) | ArcTo ([#CurrentSection#:W]*0.5),0 | ClosePath 1
shape=Path BG | Extend BGAttributes
shape2=Path Arrow | Extend ArrowAttributes
group=scrollPages
MouseOverAction=[!SetVariable UpBGcolor "#HighlightColor#"][!SetVariable UpWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable UpBGcolor "#BGcolor#"][!SetVariable UpWhite "#fontColor#"][!redraw]
leftmouseupaction=[!commandmeasure parseNpose "pageUp()"][!Update]

[indexdown]
meter=shape
dynamicVariables=1
w=80
h=70
ArrowAttributes=Strokewidth 0 | Fill Color #DnWhite# | Scale 1.0,-1.0 | rotate (90*#WR2#)
BGAttributes=StrokeWidth 0 | Fill Color #DnBGcolor#,#BgAlpha#
Arrow=([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.475) | ArcTo ([#CurrentSection#:W]*0.19),([#CurrentSection#:H]*0.39) |  LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.14) | CurveTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.14),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.06) | LineTo ([#CurrentSection#:W]*0.81),([#CurrentSection#:H]*0.39) | ArcTo ([#CurrentSection#:W]*0.72),([#CurrentSection#:H]*0.475) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.315) | LineTo ([#CurrentSection#:W]*0.56),([#CurrentSection#:H]*0.83) | ArcTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.83) | LineTo ([#CurrentSection#:W]*0.44),([#CurrentSection#:H]*0.315) | ClosePath 1
BG=([#CurrentSection#:W]*0.5),0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]) | ArcTo ([#CurrentSection#:W]*0.5),0 | ClosePath 1
shape=Path BG | Extend BGAttributes
shape2=Path Arrow | Extend ArrowAttributes
group=scrollPages
MouseOverAction=[!SetVariable DnBGcolor "#HighlightColor#"][!SetVariable DnWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable DnBGcolor "#BGcolor#"][!SetVariable DnWhite "#FontColor#"][!redraw]
Leftmouseupaction=[!commandmeasure parseNpose "pageDn()"][!Update]

[MinimizeToggle]
meter=shape
dynamicvariables=1
; x=0
; y=(#iconH#/2-135)
h=90
w=90
LineAttributes=Strokewidth ([#CurrentSection#:W]*0.05) | Fill Color 0,0,0,1 | StrokeColor #sizeWhite# | StrokeStartCap Round | StrokeEndCap Round
BGAttributes=StrokeWidth 0 | Fill Color #sizeBGcolor#,#BgAlpha#
TopCorner=0,([#CurrentSection#:H]) | LineTo 0,([#CurrentSection#:W]*0.2) | CurveTo ([#CurrentSection#:W]*0.2),0,0,0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | ClosePath 1
shape=path TopCorner | Extend BGAttributes
shape2=Line ([#CurrentSection#:W]*0.845),([#CurrentSection#:H]*0.15),([#CurrentSection#:W]*0.135),([#CurrentSection#:H]*0.855) | Extend LineAttributes
shape3=Path ArrowBottom | Extend LineAttributes | StrokeLineJoin Round
ArrowBottom=([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.62) | LineTo ([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.895) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.895)
shape4=path ArrowTop | Extend LineAttributes | StrokeLineJoin Round
ArrowTop=([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.385)
shape5=Rectangle -5,-5,90,90 | strokeWidth 0 | fill color 0,0,0,1
LeftMouseUpAction=[!WriteKeyValue variables Minimize (#Minimize#=0?1:0) "#@##CurrentConfig#\Variables.inc][!SetVariable Minimize (#Minimize#=0?1:0)][!commandmeasure parseNpose setGrid()]
MouseOverAction=[!SetVariable sizeBGcolor "#HighlightColor#"][!SetVariable sizeWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable sizeBGcolor "#BGcolor#"][!SetVariable sizeWhite #FontColor#][!redraw]
tooltipHidden=0
tooltipText="Right click to change#CRLF#background Opacity"
RightMouseUpAction=[!togglemetergroup SelectAlpha]
RightMouseDoubleClickAction=[!commandMeasure parseNpose switchAxis()]

[Menu]
Meter=shape
x=r
y=90r
w=90
h=90
dynamicvariables=1
lineAttributes=strokeWidth ([#CurrentSection#:H]*0.15) | strokeColor #menuWhite# | StrokeStartCap Round | StrokeEndCap Round
shape=rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H]) | strokewidth 0 | fill color #menuBGcolor#,#BgAlpha#
shape2=line ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.25),([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.25) | extend lineAttributes
shape3=line ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.5) | extend lineAttributes
shape4=line ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.75),([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.75) | extend lineAttributes
leftmouseupaction=[!togglemetergroup menuSelect][!hidemetergroup rightClickMenu]
MouseOverAction=[!SetVariable menuBGcolor "#HighlightColor#"][!SetVariable menuWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable menuBGcolor "#BGcolor#"][!SetVariable menuWhite #FontColor#][!redraw]

[Close]
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
LeftMouseUpAction=[!DeactivateConfig "#CurrentConfig#"]

[menu0]
Meter=string
x=90
y=([MinimizeToggle:Y]+23)
text="sort by name"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "name" "#@##CurrentConfig#\Variables.inc"][!setVariable sort "name"][!commandMeasure parseNpose "applySort()"][!hidemetergroup menuSelect][!updateMeasure parseNpose]
rightmouseupaction=[!commandmeasure mLibFolder0 "ExecuteBatch 1"]

[menu1]
Meter=string
text="sort by install date"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "tStamp" "#@##CurrentConfig#\Variables.inc"][!setVariable sort "tStamp"][!commandMeasure parseNpose "applySort()"][!hidemetergroup menuSelect][!updateMeasure parseNpose]
rightmouseupaction=[!commandmeasure mLibFolder1 "ExecuteBatch 1"]

; [menu2]
; Meter=string
; text="sort by size"
; meterStyle=menuStyle
; leftmouseupaction=[!WriteKeyValue variables sort "size" "#@##CurrentConfig#\Variables.inc"][!setVariable sort "size"][!commandMeasure parseNpose "applySort()"][!hidemetergroup menuSelect][!updateMeasure parseNpose]
; rightmouseupaction=[!commandmeasure mLibFolder2 "ExecuteBatch 1"]

[menu3]
Meter=string
meterStyle=menuStyle | #revOrder#revOrder
leftmouseupaction=[!WriteKeyValue variables revOrder (#revOrder#=1?0:1) "#@##CurrentConfig#\Variables.inc"][!setVariable revOrder (#revOrder#=1?0:1)][!commandMeasure parseNpose "applySort()"][!hidemetergroup menuSelect][!updateMeasure parseNpose]
rightmouseupaction=[!commandmeasure mLibFolder3 "ExecuteBatch 1"]

[menu4]
Meter=string
meterStyle=menuStyle | #filter##currentSection#
rightmouseupaction=[!commandmeasure mLibFolder4 "ExecuteBatch 1"]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Right Click Menu~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[RightClickMenu1]
meter=string
meterStyle=RCMenuItem
y=#menuY#
text="Search for Image"
leftMouseUpAction=[ "http:////www.google.com/imghp?hl=en&tab=wi&q=[mIconSearch]+boxart" ][!setClip "[mItemID#ActiveItem#]"][!deactivateConfig "#CurrentConfig#"]

[RightClickMenu2]
meter=string
meterStyle=RCMenuItem
text="Search for preReq"
leftMouseUpAction=[ "http:////www.google.com/search?q=[mIconSearch]+pc+system+requirements" ][!setClip "[mItemID#ActiveItem#]"][!deactivateConfig "#CurrentConfig#"]

[RightClickMenu3]
meter=string
meterStyle=RCMenuItem
text="Open Origin"
leftmouseupaction=[!deactivateConfig "#CurrentConfig#"][origin://]

[RightClickMenu4]
meter=string
meterStyle=RCMenuItem
text="Browse in Windows"
leftmouseupaction=[!deactivateConfig "#CurrentConfig#"][!commandmeasure itemSource#ActiveItem# "open"]

[noneRightClickMenu5]
text="Hide This Item"
leftMouseUpAction=[!commandMeasure parseNpose "addHidden('#activeID#')"][!hideMeterGroup rightClickMenu]

[hiddenRightClickMenu5]
text="Show This Item"
leftMouseUpAction=[!commandMeasure parseNpose "subHidden('#activeID#')"][!hideMeterGroup rightClickMenu]

[RightClickMenu5]
meter=string
meterStyle=RCMenuItem | #filter##currentSection#
group=rightClickMenu

[RightClickMenu6]
meter=string
meterStyle=RCMenuItem
text="Uninstall Game"
leftmouseupaction=[!deactivateConfig "#CurrentConfig#"][control appwiz.cpl]

[AlphaBG]
meter=Shape
dynamicVariables=1
x=([MinimizeToggle:X]+[MinimizeToggle:W])
y=([MinimizeToggle:Y])
w=300
h=90
AlphaGrad=180 | #HighlightColor# ; 0 | #HighlightColor# ; (#BgAlpha#/255) | #fontColor# ; (#BgAlpha#/255) | #fontColor# ; 1.0
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color #BgColor#
shape2=Rectangle ([#CurrentSection#:W]*0.05),([#CurrentSection#:H]*0.35),([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.3),([#CurrentSection#:H]*0.15) | StrokeWidth 0 | Fill LinearGradient AlphaGrad
group=SelectAlpha
hidden=1
leftmouseupaction=[!setvariable BgAlpha ($MouseX$>[#CurrentSection#:W]*0.95?255:($MouseX$<[#CurrentSection#:W]*0.05?0:round(($MouseX$-[#CurrentSection#:W]*0.05)/([#CurrentSection#:W]*0.9)*255)))][!writeKeyValue variables BgAlpha ($MouseX$>[#CurrentSection#:W]*0.95?255:($MouseX$<[#CurrentSection#:W]*0.05?0:round(($MouseX$-[#CurrentSection#:W]*0.05)/([#CurrentSection#:W]*0.9)*255))) "#@##CurrentConfig#\Variables.inc"][!redraw]

[AlphaBGLabel]
meter=String
measureName=mAlphaBg
text=%1%
dynamicVariables=1
x=50R
y=([AlphaBG:H]/2)r
h=([AlphaBG:H])
w=100
solidColor=#BGcolor#
clipstring=1
fontface=#fontface#
fontsize=(#fontsize#+8)
stringalign=CenterCenter
fontColor=#fontColor#
group=SelectAlpha
hidden=1