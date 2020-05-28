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

[scrollPagesBG]
dynamicvariables=1
w=80
h=70
BG=([#CurrentSection#:W]*0.5),0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]) | ArcTo ([#CurrentSection#:W]*0.5),0 | ClosePath 1
shape=Path BG | Extend BGAttributes
group=scrollPages

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Meters~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[indexup]
meter=shape
imagename="#@#images\Steam\arrow.png"
greyscale=#greyscale#
imagetint=#fontColor#
ButtAttributes=Strokewidth 0 | Fill Color #UpWhite# | rotate (-90*#scrollPlane#)
BGAttributes=StrokeWidth 0 | Fill Color #UpBGcolor#,#BgAlpha#
shape=Path BG | Extend BGAttributes
meterStyle=ArrowShape | scrollPagesBG
MouseOverAction=[!SetVariable UpBGcolor "#HighlightColor#"][!SetVariable UpWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable UpBGcolor "#BGcolor#"][!SetVariable UpWhite "#fontColor#"][!redraw]
leftmouseupaction=[!commandmeasure mParseApps "pageUp()"][!redraw]

[indexdown]
meter=shape
meterStyle=ArrowShape | scrollPagesBG
ButtAttributes=Strokewidth 0 | Fill Color #DnWhite# | Scale 1.0,-1.0 | rotate (90*#scrollPlane#)
BGAttributes=StrokeWidth 0 | Fill Color #DnBGcolor#,#BgAlpha#
MouseOverAction=[!SetVariable DnBGcolor "#HighlightColor#"][!SetVariable DnWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable DnBGcolor "#BGcolor#"][!SetVariable DnWhite "#FontColor#"][!redraw]
Leftmouseupaction=[!commandmeasure mParseApps "pageDn()"][!redraw]

[Settings]
meter=shape
dynamicvariables=1
h=90
w=90
meterStyle=SettingsShape
ButtAttributes=Strokewidth ([#CurrentSection#:W]*0.05) | StrokeColor #sizeWhite# | Fill Color 0,0,0,1 | scale 0.8,0.8 | offset ([#CurrentSection#:W]*0.01),([#CurrentSection#:H]*0.01)
BGAttributes=StrokeWidth 0 | Fill Color #sizeBGcolor#,#BgAlpha#
TopCorner=0,([#CurrentSection#:H]) | LineTo 0,([#CurrentSection#:W]*0.2) | CurveTo ([#CurrentSection#:W]*0.2),0,0,0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | ClosePath 1
shape=path TopCorner | Extend BGAttributes
LeftMouseUpAction=[!togglemetergroup settingsMenu][!hideMeterGroup menuSelect][!hidemetergroup rightClickMenu]
MouseOverAction=[!SetVariable sizeBGcolor "#HighlightColor#"][!SetVariable sizeWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable sizeBGcolor "#BGcolor#"][!SetVariable sizeWhite #FontColor#][!redraw]

[Menu]
Meter=shape
x=r
y=90r
w=90
h=90
dynamicvariables=1
meterStyle=hamberger
ButtAttributes=strokeWidth ([#CurrentSection#:H]*0.15) | strokeColor #menuWhite# | StrokeStartCap Round | StrokeEndCap Round
BGAttributes=StrokeWidth 0 | Fill Color #menuBGcolor#,#BgAlpha#
leftmouseupaction=[!togglemetergroup menuSelect][!hidemetergroup rightClickMenu][!hideMeterGroup settingsMenu]
MouseOverAction=[!SetVariable menuBGcolor "#HighlightColor#"][!SetVariable menuWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable menuBGcolor "#BGcolor#"][!SetVariable menuWhite #FontColor#][!redraw]

[CloseSkin]
meter=Shape
dynamicVariables=1
x=r
y=90r
w=90
h=90
meterStyle=Close
ButtAttributes=Strokewidth 0 | Fill Color #xWhite#
BGAttributes=StrokeWidth 0 | Fill Color #xBGcolor#,#BgAlpha#
BottomCorner=0,0 | LineTo 0,([#CurrentSection#:H]-[#CurrentSection#:W]*0.2) | CurveTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]),0,([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]),0 | ClosePath 1
shape=path BottomCorner | Extend BGAttributes
MouseOverAction=[!SetVariable xBGcolor "#HighlightColor#"][!SetVariable xWhite 255,255,255][!redraw]
MouseLeaveAction=[!SetVariable xBGcolor "#BGcolor#"][!SetVariable xWhite #FontColor#][!redraw]
LeftMouseUpAction=[!DeactivateConfig "#CurrentConfig#"]

[loadingScreen]
meter=string
meterStyle=menuStyle
text="Loading data#CRLF#Please Wait"
x=([Settings:X]+270)
y=([Settings:Y]+135)
h=270
w=360
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
stringalign=CenterCenter
fontSize=36
group=none

[menu0]
Meter=string
x=90
y=([Settings:Y]+23)
text="sort by name"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "name" "#@##CurrentConfig#\Variables.inc"][!setVariable sort "name"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect]

[menu1]
Meter=string
text="sort by install date"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "installed" "#@##CurrentConfig#\Variables.inc"][!setVariable sort "installed"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect]

[menu2]
Meter=string
text="sort by size"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "size" "#@##CurrentConfig#\Variables.inc"][!setVariable sort "size"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect]

[menu3]
Meter=string
meterStyle=menuStyle | #revOrder#revOrder
leftmouseupaction=[!WriteKeyValue variables revOrder (#revOrder#=1?0:1) "#@##CurrentConfig#\Variables.inc"][!setVariable revOrder (#revOrder#=1?0:1)][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect]

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

[bgAlphaSettings]
meter=Shape
dynamicVariables=1
x=([Settings:X]+[Settings:W])
y=([Settings:Y])
w=300
h=90
AlphaGrad=180 | #HighlightColor# ; 0 | #HighlightColor# ; (#BgAlpha#/255) | #fontColor# ; (#BgAlpha#/255) | #fontColor# ; 1.0
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color #BgColor#
shape2=Rectangle ([#CurrentSection#:W]*0.05),([#CurrentSection#:H]*0.35),([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.3),([#CurrentSection#:H]*0.15) | StrokeWidth 0 | Fill LinearGradient AlphaGrad
group=settingsMenu
hidden=1
leftmouseupaction=[!setvariable BgAlpha ($MouseX$>[#CurrentSection#:W]*0.95?255:($MouseX$<[#CurrentSection#:W]*0.05?0:round(($MouseX$-[#CurrentSection#:W]*0.05)/([#CurrentSection#:W]*0.9)*255)))][!writeKeyValue variables BgAlpha ($MouseX$>[#CurrentSection#:W]*0.95?255:($MouseX$<[#CurrentSection#:W]*0.05?0:round(($MouseX$-[#CurrentSection#:W]*0.05)/([#CurrentSection#:W]*0.9)*255))) "#@##CurrentConfig#\Variables.inc"][!redraw]

[bgAlphaSettingsLabel]
meter=String
measureName=mAlphaBg
text=%1%
dynamicVariables=1
x=50R
y=([bgAlphaSettings:H]/2)r
h=([bgAlphaSettings:H])
w=100
solidColor=#BGcolor#
clipstring=1
fontface=#fontface#
fontsize=(#fontsize#+8)
stringalign=CenterCenter
fontColor=#fontColor#
group=settingsMenu
hidden=1
leftmouseupaction=[!setvariable BgAlpha 255][!writeKeyValue variables BgAlpha 255 "#@##CurrentConfig#\Variables.inc"][!redraw]

[fullScreenSettings]
meter=String
meterStyle=menuStyle
x=([bgAlphaSettings:X])
y=([bgAlphaSettings:Y]+[bgAlphaSettings:H]+22)
w=400
text="Use Full Screen"
group=settingsMenu
leftMouseUpAction=[!WriteKeyValue variables Maximize (#Maximize#=0?1:0) "#@##CurrentConfig#\Variables.inc"][!SetVariable Maximize (#Maximize#=0?1:0)][!updateMeasure mPoseApps]

[scrollSettings]
meter=String
meterStyle=menuStyle | #scrollPlane##CurrentSection#
w=400
group=settingsMenu
leftMouseUpAction=[!WriteKeyValue variables scrollPlane (#scrollPlane#=0?1:0) "#@##CurrentConfig#\Variables.inc"][!SetVariable scrollPlane (#scrollPlane#=0?1:0)][!updateMeasure mPoseApps]

[imageDimension]
Meter=string
meterStyle=menuStyle | #useBoxArt##CurrentSection#
w=400
group=settingsMenu
leftmouseupaction=[!WriteKeyValue variables useBoxArt (#useBoxArt#=1?0:1) "#@##CurrentConfig#\Variables.inc"][!SetVariable useBoxArt (#useBoxArt#=1?0:1)][!hidemetergroup menuSelect][!updateMeasure mPoseApps]

[filter]
Meter=string
meterStyle=menuStyle | #filter##currentSection#
w=400
group=settingsMenu
