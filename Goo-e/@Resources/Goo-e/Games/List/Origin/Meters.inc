;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;MeterStyles~~~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[IconBG]
h=#IconH#
w=#IconW#
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
preserveAspectratio=#Minimize#
dynamicvariables=1
MouseOverAction=[!showMeterGroup info#CurrentSection#]
MouseLeaveAction=[!hideMeterGroup info#CurrentSection#]
leftmouseupaction=["[&mItemRunLink#CurrentSection#]"][!deactivateConfig "#CurrentConfig#"]
rightMouseUpAction=[!setvariable activeItem "#CurrentSection#"][!hidemetergroup menus][!setVariable menuX ((#WorkareaWidth#-($mouseX$+[#CurrentSection#:X])+#CURRENTCONFIGX#)<#menuW#?(($mouseX$+[#CurrentSection#:X])-#menuW#):($mouseX$+[#CurrentSection#:X]))][!setVariable menuY ((#WorkAreaHeight#-($mouseY$+[#CurrentSection#:Y])+#CURRENTCONFIGY#)<(#menuItemH#*8)?(($mouseY$+[#CurrentSection#:Y])-(#menuItemH#*8)):($mouseY$+[#CurrentSection#:Y]))][!showmetergroup rightClickMenu]

[InfoBG]
x=r
y=r
h=#IconH#
w=#IconW#
; imagetint=#highlightColor#
imagealpha=(255-#BgAlpha#)
PreserveAspectRatio=2
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
dynamicvariables=1
hidden=1

[InfoStyle]
dynamicvariables=1
x=(#useBoxArt#=1?#IconH#/8:#IconW#/8)r
y=((#useBoxArt#=1?#IconH#/8:#IconW#/8)/2)r
w=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
h=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
fontface=#fontface#
fontsize=#fontsize#
fontColor=#fontColor#
stringalign=leftCenter
hidden=1

[sizeStyle]
imageName="#@#images\Games\folders.png"
dynamicvariables=1
x=(#useBoxArt#=1?#IconW#/2-#IconH#/8:5)r
y=(#useBoxArt#=1?5:#IconH#/2-#IconH#/16-5)r
w=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
h=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
hidden=1

[descriptStyle]
x=(#useBoxArt#=1?-1*(#IconH#/4+(#IconW#-(#IconH#/8*4))/2):#IconW#/8+5)r
y=(#useBoxArt#=1?#IconH#/16+5:#IconH#/-2-(#IconH#/16))r
w=(#useBoxArt#=1?#IconW#:#IconW#*3/4-10)
h=(#useBoxArt#=1?#IconH#*3/4-15:#IconH#)
clipstring=2
fontface=#fontface#
fontsize=#fontsize#
fontColor=#fontColor#
dynamicvariables=1
hidden=1

[RCMenuItem]
x=#menuX#
y=R
w=#menuW#
h=#menuItemH#
solidcolor=#BGcolor#
clipstring=2
fontface=#fontface#
fontsize=#fontsize#
stringalign=LeftCenter
fontColor=#fontColor#
dynamicvariables=1
hidden=1
group=rightClickMenu | menus
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
inlineSetting=Face | Segoe MDL2 Assets
inlinePattern=^.\s
group=menuSelect | menus
hidden=1
MouseOverAction=[!setOption #CurrentSection# solidColor #highlightColor#][!redraw]
MouseLeaveAction=[!setOption #CurrentSection# solidColor #BGcolor#][!redraw]

[1revOrder]
text="descending order"

[0revOrder]
text="ascending order"

[0boxartOrBannerImages]
text="use Box Art"

[1boxartOrBannerImages]
text="use Banners"

[0scrollSettings]
text="scroll horizontally"

[1scrollSettings]
text="scroll vertically"

[hiddenFilter]
text="restore showcase"
leftmouseupaction=[!setVariable filter "none"][!updateMeasure mParseApps][!hidemetergroup menuSelect]

[noneFilter]
text="show hidden"
leftmouseupaction=[!setVariable filter "hidden"][!updateMeasure mParseApps][!hidemetergroup menuSelect]

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
BGAttributes=StrokeWidth 0 | Fill Color #sizeBGcolor#
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
BGAttributes=StrokeWidth 0 | Fill Color #menuBGcolor#
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
BGAttributes=StrokeWidth 0 | Fill Color #xBGcolor#
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~~Main Menu~~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[sortname]
Meter=string
x=90
y=([Settings:Y]+23)
text="sort by name"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "name" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable sort "name"][!updateMeasure mParseApps][!hidemetergroup menus]

[sortsize]
Meter=string
text="sort by size"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "size" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable sort "size"][!updateMeasure mParseApps][!hidemetergroup menus]

[revOrder]
Meter=string
meterStyle=menuStyle | #revOrder##CurrentSection#
leftmouseupaction=[!WriteKeyValue variables revOrder (#revOrder#=1?0:1) "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable revOrder (#revOrder#=1?0:1)][!updateMeasure mParseApps][!hidemetergroup menus]

[filter]
Meter=string
meterStyle=menuStyle | #filter##currentSection#

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~Right Click Menu~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[RightClickMenu1]
meter=string
meterStyle=RCMenuItem
y=#menuY#
text="Search for Image"
leftMouseUpAction=[ "http:////www.google.com/imghp?hl=en&tab=wi&q=[mIconSearch]+boxart" ][!setClip "[mItemName#ActiveItem#]"][!deactivateConfig "#CurrentConfig#"]

[RightClickMenu2]
meter=string
meterStyle=RCMenuItem
text="Search for preReq"
leftMouseUpAction=[ "http:////www.google.com/search?q=[mIconSearch]+pc+system+requirements" ][!setClip "[mItemName#ActiveItem#]"][!deactivateConfig "#CurrentConfig#"]

[RightClickMenu3]
meter=string
meterStyle=RCMenuItem
text="Open Origin"
leftmouseupaction=["#OriginPath#"][!deactivateConfig "#CurrentConfig#"]

[RightClickMenu4]
meter=string
meterStyle=RCMenuItem
text="Browse in Windows"
leftmouseupaction=["[&mItemDIR#ActiveItem#]"][!deactivateConfig "#CurrentConfig#"]

[noneRightClickMenu5]
text="Hide This Item"
leftMouseUpAction=[!commandMeasure mParseApps "addHidden('[&mItemID#activeItem#]')"][!hideMeterGroup rightClickMenu]

[hiddenRightClickMenu5]
text="Show This Item"
leftMouseUpAction=[!commandMeasure mParseApps "subHidden('[&mItemID#activeItem#]')"][!hideMeterGroup rightClickMenu]

[RightClickMenu5]
meter=string
meterStyle=RCMenuItem | #filter##currentSection#

[RightClickMenu6]
meter=string
meterStyle=RCMenuItem
text="Uninstall Game"
leftmouseupaction=[!deactivateConfig "#CurrentConfig#"][control appwiz.cpl]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~Settings Menu~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[bgAlphaSettings]
meter=Shape
dynamicVariables=1
x=([Settings:X]+[Settings:W])
y=([Settings:Y])
w=(#menuW#*0.75)
meterStyle=menuStyle
AlphaGrad=180 | #HighlightColor# ; 0 | #HighlightColor# ; (#BgAlpha#/255) | #fontColor# ; (#BgAlpha#/255) | #fontColor# ; 1.0
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color #BgColor#
shape2=Rectangle ([#CurrentSection#:W]*0.05),([#CurrentSection#:H]*0.35),([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.3),([#CurrentSection#:H]*0.15) | StrokeWidth 0 | Fill LinearGradient AlphaGrad
group=settingsMenu | menus
hidden=1
leftmouseupaction=[!setvariable BgAlpha ($MouseX$>[#CurrentSection#:W]*0.95?255:($MouseX$<[#CurrentSection#:W]*0.05?0:round(($MouseX$-[#CurrentSection#:W]*0.05)/([#CurrentSection#:W]*0.9)*255)))][!writeKeyValue variables BgAlpha ($MouseX$>[#CurrentSection#:W]*0.95?255:($MouseX$<[#CurrentSection#:W]*0.05?0:round(($MouseX$-[#CurrentSection#:W]*0.05)/([#CurrentSection#:W]*0.9)*255))) "#@##CurrentConfig#\#service#\SpecificVars.inc"][!redraw]

[bgAlphaSettingsLabel]
meter=String
measureName=mAlphaBg
text="alpha: %1%"
meterStyle=menuStyle
dynamicVariables=1
x=(#menuW#*0.25/2)R
y=([bgAlphaSettings:H]/2)r
w=(#menuW#*0.25)
fontSize=(#fontSize#-1)
stringalign=CenterCenter
group=settingsMenu | menus
hidden=1
leftmouseupaction=[!setvariable BgAlpha 255][!writeKeyValue variables BgAlpha 255 "#@##CurrentConfig#\#service#\SpecificVars.inc"][!redraw]

[fullScreenSettings]
meter=String
meterStyle=menuStyle
x=([bgAlphaSettings:X])
y=([bgAlphaSettings:Y]+[bgAlphaSettings:H]+22)
text="Use Full Screen"
group=settingsMenu | menus
leftMouseUpAction=[!WriteKeyValue variables Maximize (#Maximize#=0?1:0) "#@##CurrentConfig#\Variables.inc"][!SetVariable Maximize (#Maximize#=0?1:0)][!updateMeasure mPoseApps]

[scrollSettings]
meter=String
meterStyle=menuStyle | #scrollPlane##CurrentSection#
group=settingsMenu | menus
leftMouseUpAction=[!WriteKeyValue variables scrollPlane (#scrollPlane#=0?1:0) "#@##CurrentConfig#\#service#\SpecificVars.inc"][!SetVariable scrollPlane (#scrollPlane#=0?1:0)][!updateMeasure mPoseApps]

[boxartOrBannerImages]
Meter=string
meterStyle=menuStyle | #useBoxArt##CurrentSection#
group=settingsMenu | menus
leftmouseupaction=[!WriteKeyValue variables useBoxArt (#useBoxArt#=1?0:1) "#@##CurrentConfig#\#service#\SpecificVars.inc"][!SetVariable useBoxArt (#useBoxArt#=1?0:1)][!hidemetergroup menuSelect][!updateMeasure mPoseApps]

[changeInstalledGamesDIRs]
Meter=string
meterStyle=menuStyle
group=settingsMenu | menus
text="Change Origin Games Folder(s)"
LeftMouseUpAction=["#CONFIGEDITOR#" "#@##CurrentConfig#\#Service#\SpecificVars.inc"][!deactivateConfig #CurrentConfig#]