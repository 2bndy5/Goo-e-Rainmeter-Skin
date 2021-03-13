
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~Right Click Menu~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[Rainmeter]
ContextTitle="Browse in Windows"
ContextAction=[!deactivateConfig "#CurrentConfig#"]["[&activePath]"]
ContextTitle2="change Emulator"
ContextAction2=[!deactivateConfig "#CurrentConfig#"]["[&activePath]"]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~Meter Styles~~~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[IconBG]
h=#IconH#
w=#IconW#
solidColor=#highlightColor#,#BgAlpha#
solidColor2=#BGcolor#,#BgAlpha#
GradientAngle=60
dynamicvariables=1
PreserveAspectRatio=1
hidden=1
MouseOverAction=[!ShowMeterGroup info#CurrentSection#][!redraw]
MouseLeaveAction=[!HideMeterGroup info#CurrentSection#][!redraw]
rightMouseUpAction=[!setvariable activeItem "#CurrentSection#"][!setvariable activeFile "[mItemDIR#CurrentSection#:EscapeRegExp]"][!hideMeterGroup menus][!SkinCustomMenu]

[ConsoleAction]
leftMouseUpAction=[!writeKeyValue variables filter "db_name" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable filter "db_name"][!writeKeyValue variables console "[&mItemName#CurrentSection#]" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable console "[&mItemName#CurrentSection#]"][!updateMeasure mParseApps][!hideMeterGroup menus]

[GameAction]
leftmouseupaction=["#DIR#\retroarch.exe" -L "[mItemCore#CurrentSection#]" "[mItemDIR#CurrentSection#]"][!deactivateConfig "#CurrentConfig#"]

[InfoBG]
x=r
y=r
h=#IconH#
w=#IconW#
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

[playtimeStyle]
imageName="#DIR#\assets\xmb\#theme#\png\menu_hourglass.png"
dynamicvariables=1
x=(#useBoxArt#=1?(#IconW#-(#IconH#/8*4))/2-2.5:0)r
y=(#useBoxArt#=1?5:(#IconH#-(#IconW#/8*3))/2)r
w=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
h=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
hidden=1
leftMouseUpAction=[!writeKeyValue variables filter "history" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable filter "history"][!updateMeasure mParseApps]

[LastPlayedStyle]
imageName="#DIR#\assets\xmb\#theme#\png\history.png"
dynamicvariables=1
x=(#useBoxArt#=1?#IconH#/8+5:#IconW#/-8)r
y=(#useBoxArt#=1?-#IconH#/16:#IconW#/16)r
w=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
h=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
hidden=1
leftMouseUpAction=[!writeKeyValue variables filter "history" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable filter "history"][!updateMeasure mParseApps]

[sizeStyle]
imageName="#DIR#\assets\xmb\#theme#\png\file.png"
dynamicvariables=1
x=(#useBoxArt#=1?#IconH#/-8-#IconH#/8:#IconW#/-8)r
y=(#useBoxArt#=1?#IconH#/16+5:#IconW#/16)r
w=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
h=(#useBoxArt#=1?#IconH#/8:#IconW#/8)
hidden=1

[descriptStyle]
x=(#useBoxArt#=1?-1*(#IconH#/4+(#IconW#-(#IconH#/8*4))/2):#IconW#/8+5)r
y=(#useBoxArt#=1?#IconH#/16+5:#IconW#/8*-2.5-(#IconH#-(#IconW#/8*3))/2)r
w=(#useBoxArt#=1?#IconW#:#IconW#*3/4-10)
h=(#useBoxArt#=1?#IconH#*3/4-15:#IconH#)
clipstring=2
fontface=#fontface#
fontsize=#fontsize#
fontColor=#fontColor#
dynamicvariables=1
hidden=1

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

[0scrollSettings]
text="scroll horizontally"

[1scrollSettings]
text="scroll vertically"

[history]
imageName="#DIR#\assets\xmb\#theme#\png\history.png"
leftMouseUpAction=[!writeKeyValue variables filter "history" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable filter "history"][!hideMeterGroup menus][!updateMeasure mParseApps]

[backButton]
imageName="#DIR#\assets\xmb\#theme#\png\core.png"
leftMouseUpAction=[!writeKeyValue variables filter "none" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable filter "none"][!hideMeterGroup menus][!updateMeasure mParseApps]

[scrollPagesBG]
dynamicvariables=1
w=80
h=70
BG=([#CurrentSection#:W]*0.5),0 | LineTo ([#CurrentSection#:W]),0 | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]) | ArcTo ([#CurrentSection#:W]*0.5),0 | ClosePath 1
shape=Path BG | Extend BGAttributes
group=scrollPages

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~~~Meters~~~~~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[indexup]
meter=shape
greyscale=#greyscale#
imagetint=#fontColor#
ButtAttributes=Strokewidth 0 | Fill Color #UpWhite# | rotate (-90*#scrollPlane#)
BGAttributes=StrokeWidth 0 | Fill Color #UpBGcolor#
shape=Path BG | Extend BGAttributes
meterStyle=ArrowShape | scrollPagesBG
MouseOverAction=[!SetVariable UpBGcolor "#HighlightColor#"][!SetVariable UpWhite "255,255,255"][!redraw]
MouseLeaveAction=[!SetVariable UpBGcolor "#BGcolor#"][!SetVariable UpWhite "#fontColor#"][!redraw]
leftmouseupaction=[!commandmeasure mParseApps "pageUp()"][!redraw]

[indexdown]
meter=shape
meterStyle=ArrowShape | scrollPagesBG
ButtAttributes=Strokewidth 0 | Fill Color #DnWhite# | Scale 1.0,-1.0 | rotate (90*#scrollPlane#)
BGAttributes=StrokeWidth 0 | Fill Color #DnBGcolor#
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
LeftMouseUpAction=[!togglemetergroup settingsMenu][!hideMeterGroup menuSelect][!hideMeterGroup rightClickGameMenu][!hideMeterGroup rightClickConsoleMenu]
MouseOverAction=[!SetVariable sizeBGcolor "#HighlightColor#"][!SetVariable sizeWhite 255,255,255]
MouseLeaveAction=[!SetVariable sizeBGcolor "#BGcolor#"][!SetVariable sizeWhite #FontColor#]

[back2Consoles]
meter=image
dynamicvariables=1
meterStyle=history
x=r
y=90r
h=90
w=90
solidColor=#BGcolor#
MouseOverAction=[!setOption #CurrentSection# solidColor "#HighlightColor#"]
MouseLeaveAction=[!setOption #CurrentSection# solidColor "#BGcolor#"]

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
leftmouseupaction=[!togglemetergroup menuSelect][!hideMeterGroup settingsMenu][!hideMeterGroup rightClickGameMenu][!hideMeterGroup rightClickConsoleMenu]
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
y=([Settings:Y]+180)
h=360
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

[sortlabel]
Meter=string
x=90
y=([back2Consoles:Y]+23)
text="sort by label"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "label" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable sort "label"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[sortplaytime]
Meter=string
text="sort by time played"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "playtime" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable sort "playtime"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[sortsize]
Meter=string
text="sort by size"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "size" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable sort "size"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[sortlastPlayed]
Meter=string
text="sort by last played"
meterStyle=menuStyle
leftmouseupaction=[!WriteKeyValue variables sort "lastPlayed" "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable sort "lastPlayed"][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[revOrder]
Meter=string
meterStyle=menuStyle | #revOrder##CurrentSection#
leftmouseupaction=[!WriteKeyValue variables revOrder (#revOrder#=1?0:1) "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable revOrder (#revOrder#=1?0:1)][!commandMeasure mParseApps "applySort()"][!hidemetergroup menuSelect][!updateMeasure mParseApps]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~Settings Menu~~~~~~~~~~~~~;
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
dynamicVariables=1
x=(#menuW#*0.25/2)R
y=([bgAlphaSettings:H]/2)r
w=(#menuW#*0.25)
stringalign=CenterCenter
fontSize=(#fontSize#-2)
clipstring=1
meterStyle=menuStyle
group=settingsMenu | menus
hidden=1
leftmouseupaction=[!setvariable BgAlpha 255][!writeKeyValue variables BgAlpha 255 "#@##CurrentConfig#\#service#\SpecificVars.inc"][!redraw]

[fullScreenSettings]
meter=String
meterStyle=menuStyle
x=([bgAlphaSettings:X])
y=([bgAlphaSettings:Y]+[bgAlphaSettings:H]+22)
text="use full screen"
group=settingsMenu | menus
leftMouseUpAction=[!WriteKeyValue variables Maximize (#Maximize#=0?1:0) "#@##CurrentConfig#\Variables.inc"][!SetVariable Maximize (#Maximize#=0?1:0)][!updateMeasure mPoseApps]

[scrollSettings]
meter=String
meterStyle=menuStyle | #scrollPlane##CurrentSection#
group=settingsMenu | menus
leftMouseUpAction=[!WriteKeyValue variables scrollPlane (#scrollPlane#=0?1:0) "#@##CurrentConfig#\#service#\SpecificVars.inc"][!SetVariable scrollPlane (#scrollPlane#=0?1:0)][!updateMeasure mPoseApps]

[boxartImages]
Meter=string
meterStyle=menuStyle
text="use Boxart"
group=settingsMenu | menus
leftmouseupaction=[!WriteKeyValue variables useBoxArt 1 "#@##CurrentConfig#\#service#\SpecificVars.inc"][!SetVariable useBoxArt 1][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[screenshotImages]
Meter=string
meterStyle=menuStyle
text="use Screenshots"
group=settingsMenu | menus
leftmouseupaction=[!WriteKeyValue variables useBoxArt 0 "#@##CurrentConfig#\#service#\SpecificVars.inc"][!SetVariable useBoxArt 0][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[titleScreensImages]
Meter=string
meterStyle=menuStyle
text="use Title Screens"
group=settingsMenu | menus
leftmouseupaction=[!WriteKeyValue variables useBoxArt -1 "#@##CurrentConfig#\#service#\SpecificVars.inc"][!SetVariable useBoxArt -1][!hidemetergroup menuSelect][!updateMeasure mParseApps]

[themes]
Meter=string
meterStyle=menuStyle
text="select icon theme"
group=settingsMenu | menus
leftMouseUpAction=[!ToggleMeterGroup SelectThemes]

[changeDir]
Meter=string
meterStyle=menuStyle
text="change retroarch path to exe"
group=settingsMenu | menus
leftMouseUpAction=[!commandMeasure mChangePath "executebatch 1"]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;~~~~~~~~~Allowed Themes~~~~~~~~~;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[themeSelectStyle]
text=#CurrentSection#
group=SelectThemes | menus
leftMouseUpAction=[!writeKeyValue variables theme #CurrentSection# "#@##CurrentConfig#\#service#\SpecificVars.inc"][!setVariable theme #CurrentSection#][!hideMeterGroup menus][!UpdateMeasure mParseApps]

[automatic]
meter=string
meterStyle=menuStyle | themeSelectStyle
x=([bgAlphaSettings:X]+#menuW#)
y=([bgAlphaSettings:Y]+23)

[flatui]
meter=string
meterStyle=menuStyle | themeSelectStyle

[monochrome]
meter=string
meterStyle=menuStyle | themeSelectStyle

[neoactive]
meter=string
meterStyle=menuStyle | themeSelectStyle

[retroactive]
meter=string
meterStyle=menuStyle | themeSelectStyle

[retrosystem]
meter=string
meterStyle=menuStyle | themeSelectStyle

[systematic]
meter=string
meterStyle=menuStyle | themeSelectStyle
