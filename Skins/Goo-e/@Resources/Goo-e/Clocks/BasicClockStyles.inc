;~~~~~~~~~~~~~~~~~
;MeterStyles;;;;;;
;~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;
;Background;;;;;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersClockBG]
imagename=#@#images\BasicClock\ClockBG.png
greyScale=1
ImageTint=#BGColor#
imageAlpha=#ClockAlpha#
mouseoveraction=[!setOption #CurrentSection# imageAlpha "255"][!setOption DayBG SolidColor "#BGColor#,255"][!redraw]
mouseleaveaction=[!setOption #CurrentSection# imageAlpha "#ClockAlpha#"][!setOption DayBG SolidColor "#BGColor#,#ClockAlpha#"][!redraw]

[NumbersClockBG]
imagename=#@#images\BasicClock\ClockBG.png
greyScale=1
ImageTint=#BGColor#
imageAlpha=#ClockAlpha#
mouseoveraction=[!setOption #CurrentSection# imageAlpha "255"][!setOption DayBG SolidColor "#BGColor#,255"][!redraw]
mouseleaveaction=[!setOption #CurrentSection# imageAlpha "#ClockAlpha#"][!setOption DayBG SolidColor "#BGColor#,#ClockAlpha#"][!redraw]

[MouseClockBG]
imagename=#@#images\BasicClock\MouseBG.png
greyScale=0
ImageTint=255,255,255
SolidColor=#BGColor#,#ClockAlpha#
mouseoveraction=[!setOption #CurrentSection# SolidColor "#BGColor#,255"][!setOption DayBG imageAlpha "#BGColor#,255"][!redraw]
mouseleaveaction=[!setOption #CurrentSection# SolidColor "#BGColor#,#ClockAlpha#"][!setOption DayBG imageAlpha "#ClockAlpha#"][!redraw]

[KermitClockBG]
imagename=#@#images\BasicClock\KermitBG.png
greyScale=0
ImageTint=255,255,255
SolidColor=#BGColor#,#ClockAlpha#
mouseoveraction=[!setOption #CurrentSection# SolidColor "#BGColor#,255"][!setOption DayBG imageAlpha "255"][!redraw]
mouseleaveaction=[!setOption #CurrentSection# SolidColor "#BGColor#,#ClockAlpha#"][!setOption DayBG imageAlpha "#ClockAlpha#"][!redraw]

[AnimalClockBG]
imagename=#@#images\BasicClock\AnimalBG.png
greyScale=0
ImageTint=255,255,255
SolidColor=#BGColor#,#ClockAlpha#
mouseoveraction=[!setOption #CurrentSection# SolidColor "#BGColor#,255"][!setOption DayBG imageAlpha "255"][!redraw]
mouseleaveaction=[!setOption #CurrentSection# SolidColor "#BGColor#,#ClockAlpha#"][!setOption DayBG imageAlpha "#ClockAlpha#"][!redraw]

;;;;;;;;;;;;;;;;;;
;Markers;;;;;;;;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersClockMarkers]
ColoredStuff=StrokeWidth 0 | Fill Color #ClockColor#
shape=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 6
shape2=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 12
shape3=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 18
shape4=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 24
shape5=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape6=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 36
shape7=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 42
shape8=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 48
shape9=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 54
shape10=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 60
shape11=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 66
shape12=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 72
shape13=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 78
shape14=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 84
shape15=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 96
shape16=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 102
shape17=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 108
shape18=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 114
shape19=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 120
shape20=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 126
shape21=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 132
shape22=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 138
shape23=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 144
shape24=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 150
shape25=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 156
shape26=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 162
shape27=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 168
shape28=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 174
shape29=Rectangle ([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.916),([#CurrentSection#:H]*0.916) | Extend ColoredStuff
shape30=Combine shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Union Shape6 | Union Shape7 | Union Shape8 | Union Shape9 | Union Shape10 | Union Shape11 | Union Shape12 | Union Shape13 | Union Shape14 | Union Shape15 | Union Shape16 | Union Shape17 | Union Shape18 | Union Shape19 | Union Shape20 | Union Shape21 | Union Shape22 | Union Shape23 | Union Shape24 | Union Shape25 | Union Shape26 | Union Shape27 | Union Shape28 | Exclude shape29
shape31=Path m3 | Extend ColoredStuff
shape32=Path m9 | Extend ColoredStuff
shape33=Path m6 | Extend ColoredStuff
shape34=Path m12 | Extend ColoredStuff
m3=([#CurrentSection#:H]),([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.49) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.496) | LineTo ([#CurrentSection#:H]),([#CurrentSection#:H]*0.496) | LineTo ([#CurrentSection#:H]),([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.51) | LineTo ([#CurrentSection#:H]),([#CurrentSection#:H]*0.53)
m9=0,([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.49) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.496) | LineTo 0,([#CurrentSection#:H]*0.496) | LineTo 0,([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.51) | LineTo 0,([#CurrentSection#:H]*0.53)
m6=([#CurrentSection#:H]*0.47),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:H]*0.49),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.496),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:H]*0.504),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:H]*0.504),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.51),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.53),([#CurrentSection#:H])
m12=([#CurrentSection#:H]*0.47),0 | LineTo ([#CurrentSection#:H]*0.49),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.496),0 | LineTo ([#CurrentSection#:H]*0.504),0 | LineTo ([#CurrentSection#:H]*0.504),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.51),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.53),0

[NumbersClockMarkers]
ColoredStuff=StrokeWidth 0 | Fill Color #ClockColor#
shape=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 6
shape2=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 12
shape3=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 18
shape4=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 24
shape5=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape6=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 36
shape7=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 42
shape8=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 48
shape9=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 54
shape10=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 60
shape11=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 66
shape12=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 72
shape13=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 78
shape14=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 84
shape15=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 96
shape16=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 102
shape17=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 108
shape18=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 114
shape19=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 120
shape20=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 126
shape21=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 132
shape22=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 138
shape23=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 144
shape24=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 150
shape25=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 156
shape26=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 162
shape27=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 168
shape28=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.008) | Extend ColoredStuff | rotate 174
shape29=Rectangle ([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.916),([#CurrentSection#:H]*0.916) | Extend ColoredStuff
shape30=Combine shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Union Shape6 | Union Shape7 | Union Shape8 | Union Shape9 | Union Shape10 | Union Shape11 | Union Shape12 | Union Shape13 | Union Shape14 | Union Shape15 | Union Shape16 | Union Shape17 | Union Shape18 | Union Shape19 | Union Shape20 | Union Shape21 | Union Shape22 | Union Shape23 | Union Shape24 | Union Shape25 | Union Shape26 | Union Shape27 | Union Shape28 | Exclude shape29
shape31=Path m3 | Extend ColoredStuff
shape32=Path m9 | Extend ColoredStuff
shape33=Path m6 | Extend ColoredStuff
shape34=Path m12 | Extend ColoredStuff
m3=([#CurrentSection#:H]),([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.49) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.496) | LineTo ([#CurrentSection#:H]),([#CurrentSection#:H]*0.496) | LineTo ([#CurrentSection#:H]),([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.926),([#CurrentSection#:H]*0.51) | LineTo ([#CurrentSection#:H]),([#CurrentSection#:H]*0.53)
m9=0,([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.49) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.496) | LineTo 0,([#CurrentSection#:H]*0.496) | LineTo 0,([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.504) | LineTo ([#CurrentSection#:H]*0.074),([#CurrentSection#:H]*0.51) | LineTo 0,([#CurrentSection#:H]*0.53)
m6=([#CurrentSection#:H]*0.47),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:H]*0.49),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.496),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:H]*0.504),([#CurrentSection#:H]) | LineTo ([#CurrentSection#:H]*0.504),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.51),([#CurrentSection#:H]*0.926) | LineTo ([#CurrentSection#:H]*0.53),([#CurrentSection#:H])
m12=([#CurrentSection#:H]*0.47),0 | LineTo ([#CurrentSection#:H]*0.49),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.496),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.496),0 | LineTo ([#CurrentSection#:H]*0.504),0 | LineTo ([#CurrentSection#:H]*0.504),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.51),([#CurrentSection#:H]*0.074) | LineTo ([#CurrentSection#:H]*0.53),0


[MouseClockMarkers]
ColoredStuff=StrokeWidth 0 | Fill Color #SecondsColor#
shape=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff
shape2=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 90
shape3=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape4=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape5=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 60
shape6=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 120
shape7=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 150
shape8=Rectangle ([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.916),([#CurrentSection#:H]*0.916) | Extend ColoredStuff
shape9=Combine shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Union Shape6 | Union Shape7 | Exclude shape8

[KermitClockMarkers]
ColoredStuff=StrokeWidth 0 | Fill Color #SecondsColor#
shape=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff
shape2=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 90
shape3=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape4=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape5=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 60
shape6=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 120
shape7=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 150
shape8=Rectangle ([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.916),([#CurrentSection#:H]*0.916) | Extend ColoredStuff
shape9=Combine shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Union Shape6 | Union Shape7 | Exclude shape8

[AnimalClockMarkers]
ColoredStuff=StrokeWidth 0 | Fill Color #SecondsColor#
shape=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff
shape2=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 90
shape3=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape4=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.02) | Extend ColoredStuff | rotate 30
shape5=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 60
shape6=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 120
shape7=Rectangle ([#CurrentSection#:H]*-0.25),([#CurrentSection#:H]*0.489),([#CurrentSection#:H]*1.5),([#CurrentSection#:H]*0.022) | Extend ColoredStuff | rotate 150
shape8=Rectangle ([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.042),([#CurrentSection#:H]*0.916),([#CurrentSection#:H]*0.916) | Extend ColoredStuff
shape9=Combine shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Union Shape6 | Union Shape7 | Exclude shape8

;;;;;;;;;;;;;;;;;;
;Day BackGround;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersDayBG]
x=(#IconSize#*0.2)
y=(#IconSize#*0.6)
w=(#IconSize#*0.6)
h=(#IconSize#*0.16)
shape=Rectangle ([#CurrentSection#:H]*0.015),([#CurrentSection#:H]*0.015),([#CurrentSection#:W]-([#CurrentSection#:H]*0.03)),([#CurrentSection#:H]*0.97) | StrokeWidth ([#CurrentSection#:H]*0.1) | StrokeColor 140,140,140 | Fill Color #BGColor#
shape2=Rectangle ([#CurrentSection#:H]*0.04),([#CurrentSection#:H]*0.04),([#CurrentSection#:W]-([#CurrentSection#:H]*0.08)),([#CurrentSection#:H]*0.92) | StrokeWidth 0 | Fill Color #Black#,160
shape3=Rectangle ([#CurrentSection#:H]*0.06),([#CurrentSection#:H]*0.06),([#CurrentSection#:W]),([#CurrentSection#:H]) | StrokeWidth 0
shape4=Rectangle 0,0,([#CurrentSection#:W]+([#CurrentSection#:H]*0.03)),([#CurrentSection#:H]*1.03) | StrokeWidth 0 | Fill Color #Black#,160
shape5=Rectangle 0,0,([#CurrentSection#:W]+([#CurrentSection#:H]*0.01)),([#CurrentSection#:H]*1.01) | StrokeWidth 0
shape6=Combine Shape2 | Exclude shape3
shape7=combine shape4 | Exclude shape5
hidden=#ShowDate#

[NumbersDayBG]
x=(#IconSize#*0.2)
y=(#IconSize#*0.6)
w=(#IconSize#*0.6)
h=(#IconSize#*0.16)
shape=Rectangle ([#CurrentSection#:H]*0.015),([#CurrentSection#:H]*0.015),([#CurrentSection#:W]-([#CurrentSection#:H]*0.03)),([#CurrentSection#:H]*0.97) | StrokeWidth ([#CurrentSection#:H]*0.1) | StrokeColor 140,140,140 | Fill Color #BGColor#
shape2=Rectangle ([#CurrentSection#:H]*0.04),([#CurrentSection#:H]*0.04),([#CurrentSection#:W]-([#CurrentSection#:H]*0.08)),([#CurrentSection#:H]*0.92) | StrokeWidth 0 | Fill Color #Black#,160
shape3=Rectangle ([#CurrentSection#:H]*0.06),([#CurrentSection#:H]*0.06),([#CurrentSection#:W]),([#CurrentSection#:H]) | StrokeWidth 0
shape4=Rectangle 0,0,([#CurrentSection#:W]+([#CurrentSection#:H]*0.03)),([#CurrentSection#:H]*1.03) | StrokeWidth 0 | Fill Color #Black#,160
shape5=Rectangle 0,0,([#CurrentSection#:W]+([#CurrentSection#:H]*0.01)),([#CurrentSection#:H]*1.01) | StrokeWidth 0
shape6=Combine Shape2 | Exclude shape3
shape7=combine shape4 | Exclude shape5
hidden=#ShowDate#

[MouseDayBG]
x=(#IconSize#*0.65)
y=(#IconSize#*0.4)
w=(#IconSize#*0.2)
h=(#IconSize#*0.2)
shape=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth 0 | Fill Color #BGColor#
shape2=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth 0 | Fill Color 0,0,0,160
shape3=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | Offset ([#CurrentSection#:H]*0.05),([#CurrentSection#:H]*0.1)
shape4=Combine shape2 | exclude shape3
hidden=#ShowDate#

[KermitDayBG]
x=(#IconSize#*0.4)
y=(#IconSize#*0.65)
w=(#IconSize#*0.2)
h=(#IconSize#*0.2)
shape=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth 0 | Fill Color #BGColor#
shape2=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth 0 | Fill Color 0,0,0,160
shape3=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | Offset ([#CurrentSection#:H]*0.05),([#CurrentSection#:H]*0.1)
shape4=Combine shape2 | exclude shape3
hidden=#ShowDate#

[AnimalDayBG]
x=(#IconSize#*0.65)
y=(#IconSize#*0.4)
w=(#IconSize#*0.2)
h=(#IconSize#*0.2)
shape=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth 0 | Fill Color #BGColor#
shape2=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth 0 | Fill Color 0,0,0,160
shape3=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | Offset ([#CurrentSection#:H]*0.05),([#CurrentSection#:H]*0.1)
shape4=Combine shape2 | exclude shape3
hidden=#ShowDate#

;;;;;;;;;;;;;;;;;;
;Digit Display;;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersDigitalDisplay]
x=(#IconSize#*0.5)
y=(#IconSize#*0.685)
fontface=prototype
fontsize=(#iconSize#*16/152)

[NumbersDigitalDisplay]
x=(#IconSize#*0.5)
y=(#IconSize#*0.685)
fontface=prototype
fontsize=(#iconSize#*18/152)

[MouseDigitalDisplay]
x=(#IconSize#*0.75)
y=(#IconSize#*0.51)
fontface=Arial
fontsize=(#iconSize#*16/152)

[KermitDigitalDisplay]
x=(#IconSize#*0.5)
y=(#IconSize#*0.76)
fontface=Arial
fontsize=(#iconSize#*16/152)

[AnimalDigitalDisplay]
x=(#IconSize#*0.75)
y=(#IconSize#*0.51)
stringalign=Centercenter
fontface=Arial
fontsize=(#iconSize#*16/152)

;;;;;;;;;;;;;;;;;;;
;Day Glare / Shadow
;;;;;;;;;;;;;;;;;;;
[NoNumbersDateGlare]
x=(#IconSize#*0.2)
y=(#IconSize#*0.6)
w=(#IconSize#*0.6)
h=(#IconSize#*0.16)
shape=Rectangle ([#CurrentSection#:H]*0.06),([#CurrentSection#:H]*0.06),([#CurrentSection#:W]-([#CurrentSection#:H]*0.12)),([#CurrentSection#:H]*0.88) | StrokeWidth 0 | Fill LinearGradient Glare
Glare=-90 | 255,255,255,185 ; 0.0 | 255,255,255,0 ; 0.5 | 0,0,0,0 ; 0.5 | 0,0,0,85 ; 1.0
hidden=#ShowDate#

[NumbersDateGlare]
x=(#IconSize#*0.2)
y=(#IconSize#*0.6)
w=(#IconSize#*0.6)
h=(#IconSize#*0.16)
shape=Rectangle ([#CurrentSection#:H]*0.06),([#CurrentSection#:H]*0.06),([#CurrentSection#:W]-([#CurrentSection#:H]*0.12)),([#CurrentSection#:H]*0.88) | StrokeWidth 0 | Fill LinearGradient Glare
Glare=-90 | 255,255,255,195 ; 0.0 | 255,255,255,0 ; 0.5 | 0,0,0,0 ; 0.5 | 0,0,0,85 ; 1.0
hidden=#ShowDate#

[MouseDateGlare]
x=(#IconSize#*0.65)
y=(#IconSize#*0.4)
w=(#IconSize#*0.2)
h=(#IconSize#*0.2)
shape=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth ([#CurrentSection#:H]*0.08) | StrokeColor 161,33,42 | Fill Color 0,0,0,0
hidden=#ShowDate#

[KermitDateGlare]
x=(#IconSize#*0.4)
y=(#IconSize#*0.65)
w=(#IconSize#*0.2)
h=(#IconSize#*0.2)
shape=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth ([#CurrentSection#:H]*0.08) | StrokeColor 161,33,42 | Fill Color 0,0,0,0
hidden=#ShowDate#

[AnimalDateGlare]
x=(#IconSize#*0.65)
y=(#IconSize#*0.4)
w=(#IconSize#*0.2)
h=(#IconSize#*0.2)
shape=Ellipse ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.46) | StrokeWidth ([#CurrentSection#:H]*0.08) | StrokeColor 161,33,42 | Fill Color 0,0,0,0
hidden=#ShowDate#

;;;;;;;;;;;;;;;;;;
;Hours Hand;;;;;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersHoursHand]
x=(round(#IconSize#*0.47))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.34))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #HoursColor# | rotate (([mTime:]%43200/43200)*360-90),([#CurrentSection#:W]*0.12),([#CurrentSection#:H]*0.5)

[NumbersHoursHand]
x=(round(#IconSize#*0.47))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.34))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #HoursColor# | rotate (([mTime:]%43200/43200)*360-90),([#CurrentSection#:W]*0.12),([#CurrentSection#:H]*0.5)

[MouseHoursHand]
shape=Line 0,0,1,0 | strokewidth 0 | fill color 00000000

[KermitHoursHand]
x=(round(#IconSize#*0.47))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.34))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #HoursColor# | rotate (([mTime:]%43200/43200)*360-90),([#CurrentSection#:W]*0.12),([#CurrentSection#:H]*0.5)

[AnimalHoursHand]
x=(round(#IconSize#*0.47))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.34))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #HoursColor# | rotate (([mTime:]%43200/43200)*360-90),([#CurrentSection#:W]*0.12),([#CurrentSection#:H]*0.5)

;;;;;;;;;;;;;;;;;;
;Minutes Hand;;;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersMinutesHand]
x=(round(#IconSize#*0.46))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.54))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #MinutesColor# | rotate (([mTime:]%3600/3600)*360-90),([#CurrentSection#:W]*0.074),([#CurrentSection#:H]*0.5)

[NumbersMinutesHand]
x=(round(#IconSize#*0.46))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.54))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #MinutesColor# | rotate (([mTime:]%3600/3600)*360-90),([#CurrentSection#:W]*0.074),([#CurrentSection#:H]*0.5)

[MouseMinutesHand]
shape=Line 0,0,1,0 | strokewidth 0 | fill color 00000000

[KermitMinutesHand]
x=(round(#IconSize#*0.46))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.54))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #MinutesColor# | rotate (([mTime:]%3600/3600)*360-90),([#CurrentSection#:W]*0.074),([#CurrentSection#:H]*0.5)

[AnimalMinutesHand]
x=(round(#IconSize#*0.46))
y=(round(#IconSize#*0.475))
w=(round(#IconSize#*0.54))
h=(round(#IconSize#*0.05))
Hand=([#CurrentSection#:W]*0.037),0 | ArcTo ([#CurrentSection#:W]*0.037),([#CurrentSection#:H]),*,*,*,1 | LineTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.75) | ArcTo ([#CurrentSection#:W]*0.963),([#CurrentSection#:H]*0.25),*,*,*,1 | ClosePath 1
Shape=path Hand | strokeWidth 0 | fill Color #MinutesColor# | rotate (([mTime:]%3600/3600)*360-90),([#CurrentSection#:W]*0.074),([#CurrentSection#:H]*0.5)

;;;;;;;;;;;;;;;;;;
;Center Dot;;;;;;;
;;;;;;;;;;;;;;;;;;
[NoNumbersClockdot]
x=(#IconSize#*0.487)
y=(#IconSize#*0.487)
w=(#IconSize#*0.026)
h=(#IconSize#*0.026)
shape=Ellipse ([#CurrentSection#:H]/2),([#CurrentSection#:W]/2),[#CurrentSection#:H],[#CurrentSection#:W] | StrokeWidth 0 | Fill Color #BgColor#

[NumbersClockdot]
x=(#IconSize#*0.487)
y=(#IconSize#*0.487)
w=(#IconSize#*0.026)
h=(#IconSize#*0.026)
shape=Ellipse ([#CurrentSection#:H]/2),([#CurrentSection#:W]/2),[#CurrentSection#:H],[#CurrentSection#:W] | StrokeWidth 0 | Fill Color #BgColor#

[Mouseclockdot]
x=(#IconSize#*0.47)
y=(#IconSize#*0.47)
h=(#iconSize#*0.06)
w=(#iconSize#*0.06)
shape=Ellipse ([#CurrentSection#:H]/2),([#CurrentSection#:W]/2),([#CurrentSection#:H]/2) | StrokeWidth ([#CurrentSection#:H]*0.1) | StrokeColor 38,38,38 | Fill Color 138,138,138
shape2=Ellipse ([#CurrentSection#:H]/2),([#CurrentSection#:W]/2),([#CurrentSection#:H]/5) | StrokeWidth ([#CurrentSection#:H]*0.05) | StrokeColor 38,38,38 | Fill Color 179,179,179

[KermitClockdot]
x=(#IconSize#*0.487)
y=(#IconSize#*0.487)
w=(#IconSize#*0.026)
h=(#IconSize#*0.026)
shape=Ellipse ([#CurrentSection#:H]/2),([#CurrentSection#:W]/2),[#CurrentSection#:H],[#CurrentSection#:W] | StrokeWidth 0 | Fill Color #ClockColor#

[AnimalClockdot]
x=(#IconSize#*0.487)
y=(#IconSize#*0.487)
w=(#IconSize#*0.026)
h=(#IconSize#*0.026)
shape=Ellipse ([#CurrentSection#:H]/2),([#CurrentSection#:W]/2),[#CurrentSection#:H],[#CurrentSection#:W] | StrokeWidth 0 | Fill Color #ClockColor#
