
[SteamIconShape]
strokeDash=StrokeWidth ([#CurrentSection#:W]*0.0157) | strokeDashCap round
pivotGlow=fill color #SteamHighlightGrad2#,([calcBodyAlpha] * 255)
; predefined scalar paths
LeftLeg=0,([#CurrentSection#:H]*0.455) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.612) | ArcTo ([#CurrentSection#:W]*0.316),([#CurrentSection#:H]*0.75) | LineTo 0,([#CurrentSection#:H]*0.62) | ClosePath 1
RightLeg=([#CurrentSection#:W]*0.347),([#CurrentSection#:H]*0.56) | LineTo ([#CurrentSection#:W]*0.49),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.675),([#CurrentSection#:H]*0.54) | LineTo ([#CurrentSection#:W]*0.469),([#CurrentSection#:H]*0.69) | ClosePath 1
; predefined gradients
SteamBgGradient=-90 | #SteamBGgrad2#,([calcBodyAlpha] * #SteamBGAlpha# / 2) ; 1.0 | #SteamBGgrad1#,([calcBodyAlpha] * #SteamBGAlpha# / 2) ; 0.4
snakeGradient=([mAnimLoop] * -3.6) | #SteamHighlightGrad1# ; 1.0 | #SteamHighlightGrad1#,127 ; 0.5
; shapes for building the image
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.5) | strokeWidth 0 | fill color 0,0,0,1
shape2=Ellipse ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.372),([#CurrentSection#:W]*0.092)
shape3=Ellipse ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.372),([#CurrentSection#:W]*0.125) | StrokeWidth 0 | extend pivotGlow
shape4=Ellipse ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.372),([#CurrentSection#:W]*0.186)
shape5=Ellipse ([#CurrentSection#:W]*0.35),([#CurrentSection#:H]*0.682),([#CurrentSection#:W]*0.104) | StrokeWidth 0 | extend pivotGlow
shape6=Ellipse ([#CurrentSection#:W]*0.35),([#CurrentSection#:H]*0.682),([#CurrentSection#:W]*0.14)
shape7=path LeftLeg
shape8=Path RightLeg
Shape9=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.48) | fill LinearGradient SteamBgGradient | extend strokeDash | strokeDashes 160,160 | strokeDashOffset ([mAnimLoop] * 3.2) | stroke LinearGradient snakeGradient
; rotating three-dash stroke
shape10=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.492) | fill LinearGradient SteamBgGradient | extend strokeDash | strokeDashes 31.875,31.875 | strokeDashOffset ([mAnimLoop] * 1.275) | strokeColor #SteamHighlightGrad2#
; glowing small pivot
shape11=Combine shape5 | exclude shape7
; glowing big pivot
shape12=Combine shape3 | exclude shape2
; the whole outline including wrench and circle
shape13=Combine shape9 | exclude shape8 | exclude shape6 | exclude shape7 | exclude shape4
Group=Icons

[OriginIconShape]
RadGrad=([#CurrentSection#:W]*-0.1),([#CurrentSection#:H]*-0.25),0,0,([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | #originHighlightGrad1# ; 0.5 | #originHighlightGrad2# ; 1.0
PointUp=([#CurrentSection#:W]*0.52),([#CurrentSection#:H]*0.25) | CurveTo ([#CurrentSection#:W]*0.52),0,([#CurrentSection#:W]*0.37),([#CurrentSection#:H]*0.18) | CurveTo ([#CurrentSection#:W]*0.14),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.14),([#CurrentSection#:H]*0.22) | ClosePath 1
PointDown=([#CurrentSection#:W]*0.48),([#CurrentSection#:H]*0.75) | CurveTo ([#CurrentSection#:W]*0.48),[#CurrentSection#:H],([#CurrentSection#:W]*0.63),([#CurrentSection#:H]*0.82) | CurveTo ([#CurrentSection#:W]*0.86),([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.86),([#CurrentSection#:H]*0.78) | ClosePath 1
raindropWave=0,0,*,*,([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | #originBGgrad1#,#originBGAlpha#;(([mAnimLoop]-50)*2/100+1) | #originBGgrad1#,0;(([mAnimLoop]-50)*2/100+0.75) | #originBGgrad2#,255;(([mAnimLoop]-50)*2/100+0.5) | #originBGgrad1#,#originBGAlpha#;(([mAnimLoop]-50)*2/100+0.25) | #originBGgrad1#,#originBGAlpha#;(([mAnimLoop]-50)*2/100-1.25) | #originBGgrad1#,#originBGAlpha#;(([mAnimLoop]-50)*2/100-1)
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.5) | StrokeWidth 0 | Fill Color 0,0,0,1
shape2=Path PointUp
shape3=Path PointDown
shape4=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.367) | StrokeWidth ([#CurrentSection#:W]*0.015) | stroke RadialGradient RadGrad | fill RadialGradient raindropWave
; | strokeDashes ([#CurrentSection#:W]*0.015*5.9),([#CurrentSection#:W]*0.015*5.9) | strokeDashOffset ([#CurrentSection#:W]*0.015*11.6*[mAnimLoop:/100])
shape5=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.15)
shape6=Combine Shape4 | Exclude shape5 | Union shape2 | Union shape3 | offset ([#CurrentSection#:W]*0.005),([#CurrentSection#:H]*0.005) | rotate (-3.6*[mAnimLoop:]),([#CurrentSection#:W]*0.3745),([#CurrentSection#:H]*0.53) | scale 0.9,0.9
Group=Icons

[RetroarchIconShape]
bodyGradient=-90 | #retroarchBGgrad2#,#retroarchBGAlpha#;0.25 | #retroarchBGgrad2#,#retroarchBGAlpha#;0.3 | #retroarchBGgrad1#,#retroarchBGAlpha#;0.47 | #retroarchBGgrad1#,#retroarchBGAlpha#;0.725 | #retroarchBGgrad2#,#retroarchBGAlpha#;0.85 | #retroarchBGgrad1#,#retroarchBGAlpha#;0.95
eyeShadow=45 | #retroarchHighlightGrad1#,(#retroarchBGAlpha#>127?#retroarchBGAlpha#:127+abs(#retroarchBGAlpha#-127));0 | #retroarchHighlightGrad2#,(#retroarchBGAlpha#>127?#retroarchBGAlpha#:127+abs(#retroarchBGAlpha#-127));1
eyeShadowAttributes=stroke LinearGradient eyeShadow | strokeWidth ([#CurrentSection#:H]*0.015) | fill color 0,0,0,0
glimmerWave=#retroarchWaveAngle# | 255,255,255,0;(([mAnimLoop]-50)*2/100+1) | 255,255,255,0;(([mAnimLoop]-50)*2/100+0.75) | 255,255,255,185;(([mAnimLoop]-50)*2/100+0.5) | 255,255,255,0;(([mAnimLoop]-50)*2/100+0.25) | 255,255,255,0;(([mAnimLoop]-50)*2/100-1.25) | 255,255,255,0;(([mAnimLoop]-50)*2/100-1)
body=([#CurrentSection#:W]*0.225),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.775),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.853),([#CurrentSection#:H]*0.636) | LineTo ([#CurrentSection#:W]*0.147),([#CurrentSection#:H]*0.636)
xShape=([#CurrentSection#:W]*0.29),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.374),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.39) | LineTo ([#CurrentSection#:W]*0.626),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.71),([#CurrentSection#:H]*0.246) | LineTo ([#CurrentSection#:W]*0.55),([#CurrentSection#:H]*0.444) | LineTo ([#CurrentSection#:W]*0.815),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.703),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.51) | LineTo ([#CurrentSection#:W]*0.297),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.185),([#CurrentSection#:H]*0.753) | LineTo ([#CurrentSection#:W]*0.45),([#CurrentSection#:H]*0.444)
arms=([#CurrentSection#:W]*0.07),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.12),([#CurrentSection#:H]*0.442) | LineTo ([#CurrentSection#:W]*0.881),([#CurrentSection#:H]*0.442) | LineTo ([#CurrentSection#:W]*0.851),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.93),([#CurrentSection#:H]*0.325) | LineTo ([#CurrentSection#:W]*0.988),([#CurrentSection#:H]*0.5585) | LineTo ([#CurrentSection#:W]*0.012),([#CurrentSection#:H]*0.5585)
shape=Rectangle 0,([#CurrentSection#:H]*0.25),([#CurrentSection#:W]),([#CurrentSection#:H]*0.5) | fill color 0,0,0,1 | strokewidth 0
shape2=path body | Fill LinearGradient bodyGradient | strokeWidth 0
shape3=path xShape | strokeWidth ([#CurrentSection#:H]*0.022) | fill LinearGradient glimmerWave | stroke LinearGradient glimmerWave
shape4=path arms | strokeWidth ([#CurrentSection#:H]*0.015) | Fill color 0,0,0,0 | strokeColor #retroarchHighlightGrad2#,(#retroarchBGAlpha#>127?#retroarchBGAlpha#:127+abs(#retroarchBGAlpha#-127))
shape5=Rectangle ([#CurrentSection#:W]*0.298),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083)
shape6=Rectangle ([#CurrentSection#:W]*0.621),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083)
shape7=combine shape2 | union shape3 | union shape4 | exclude shape5 | exclude shape6
shape8=Rectangle ([#CurrentSection#:W]*0.621),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083) | extend eyeShadowAttributes
shape9=Rectangle ([#CurrentSection#:W]*0.298),([#CurrentSection#:H]*0.3995),([#CurrentSection#:W]*0.083),([#CurrentSection#:H]*0.083) | extend eyeShadowAttributes
shape10=combine shape4 | union shape2 | union shape3
shape11=path arms | strokeWidth ([#CurrentSection#:H]*0.015) | Fill color 0,0,0,0 | StrokeDashCap Triangle | strokeDashes 4,64 | strokeColor #retroarchHighlightGrad1# | strokeDashOffset (68*[mAnimLoop:/100])
shape12=combine shape11 | union shape2 | union shape3
shape13=combine shape3 | union shape2 | union shape4 | exclude shape5 | exclude shape6
Group=Icons

[emulationStationIconShape]
bgBlue=0,([#CurrentSection#:H]/4) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.15) | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]*0.15) | LineTo ([#CurrentSection#:W]),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.85) | LineTo 0,([#CurrentSection#:H]*0.85) | ClosePath 1
E=([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.35) | SetRoundJoin 1 | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.65) | closepath 1
S=([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.35) | SetRoundJoin 1 | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.35) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.45) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.75) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.65) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.55) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.45) | closepath 1
flagWaveOutline=#emulationstationWaveAngle# | #emulationstationBGgrad2#,255;(([mAnimLoop]-50)*2/100+1) | #emulationstationBGgrad2#,0;(([mAnimLoop]-50)*2/100+0.75) | #emulationstationBGgrad1#,255;(([mAnimLoop]-50)*2/100+0.5) | #emulationstationBGgrad2#,255;(([mAnimLoop]-50)*2/100+0.25) | #emulationstationBGgrad2#,255;(([mAnimLoop]-50)*2/100-1.25) | #emulationstationBGgrad2#,255;(([mAnimLoop]-50)*2/100-1)
flagWaveBg=#emulationstationWaveAngle# | #emulationstationBGgrad1#,#emulationstationBGAlpha#;(([mAnimLoop]-50)*2/100+1) | #emulationstationBGgrad1#,0;(([mAnimLoop]-50)*2/100+0.75) | #emulationstationBGgrad2#,255;(([mAnimLoop]-50)*2/100+0.5) | #emulationstationBGgrad1#,#emulationstationBGAlpha#;(([mAnimLoop]-50)*2/100+0.25) | #emulationstationBGgrad1#,#emulationstationBGAlpha#;(([mAnimLoop]-50)*2/100-1.25) | #emulationstationBGgrad1#,#emulationstationBGAlpha#;(([mAnimLoop]-50)*2/100-1)
shadow=StrokeColor #emulationstationHighlightGrad2#,((1-[calcBodyAlpha:])*255) | StrokeWidth ([#CurrentSection#:H]*0.005) | Fill Color #emulationstationHighlightGrad2#,(round([calcBodyAlpha:]*85)) | offset ([#CurrentSection#:H]*-0.05),([#CurrentSection#:H]*0.0625)
shape=path bgBlue | StrokeWidth 0 | Fill color 0,0,0,1
shape2=path bgBlue | StrokeWidth ([#CurrentSection#:H]*0.005) | stroke LinearGradient flagWaveOutline | Fill LinearGradient flagWaveBg
shape3=path E | extend shadow
shape4=path S | extend shadow
shape5=path E | StrokeColor #emulationstationHighlightGrad1#,((1-[calcBodyAlpha:])*255) | StrokeWidth ([#CurrentSection#:H]*0.005) | Fill Color #emulationstationHighlightGrad1#,(round([calcBodyAlpha:]*255))
shape6=path S | StrokeColor #emulationstationHighlightGrad1#,((1-[calcBodyAlpha:])*255) | StrokeWidth ([#CurrentSection#:H]*0.005) | Fill Color #emulationstationHighlightGrad1#,(round([calcBodyAlpha:]*255))
; letterH=([#CurrentSection#:H]/2)
; letterW=([#CurrentSection#:H]*0.8)
; bgH=([#CurrentSection#:H]*0.7)

[pirateIconShape]
skull=([#CurrentSection#:W]*0.215),([#CurrentSection#:H]*0.4) | ArcTo ([#CurrentSection#:W]*0.785),([#CurrentSection#:H]*0.4),*,([#CurrentSection#:H]*0.23) | SetRoundJoin 1 | lineTo ([#CurrentSection#:W]*0.735),([#CurrentSection#:H]*0.69) | SetRoundJoin 1 | arcTo ([#CurrentSection#:W]*0.67),([#CurrentSection#:H]*0.735),([#CurrentSection#:W]*0.05),([#CurrentSection#:H]*0.05) | SetRoundJoin 1 | curveTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.835),([#CurrentSection#:W]*0.6),([#CurrentSection#:W]*0.735) | SetRoundJoin 1 | curveTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.835),([#CurrentSection#:W]*0.5),([#CurrentSection#:W]*0.85) | SetRoundJoin 1 | curveTo ([#CurrentSection#:W]*0.33),([#CurrentSection#:H]*0.735),([#CurrentSection#:W]*0.4),([#CurrentSection#:W]*0.735) | SetRoundJoin 1 | arcTo ([#CurrentSection#:W]*0.265),([#CurrentSection#:H]*0.69),([#CurrentSection#:W]*0.05),([#CurrentSection#:H]*0.05) | closepath 1
nose=([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.6) | curveTo ([#CurrentSection#:H]*0.57),([#CurrentSection#:H]*0.72),([#CurrentSection#:H]*0.57),([#CurrentSection#:H]*0.62) | SetRoundJoin 1 | arcTo ([#CurrentSection#:W]*0.43),([#CurrentSection#:H]*0.72),([#CurrentSection#:W]*0.03),([#CurrentSection#:W]*0.02) | SetRoundJoin 1 | curveTo ([#CurrentSection#:H]*0.5),([#CurrentSection#:H]*0.6),([#CurrentSection#:H]*0.43),([#CurrentSection#:H]*0.62) | SetRoundJoin 1 | closepath 1
flagWaveSkullOutline=(#pirateWaveAngle#+[calcBodyAlpha]*38) | #pirateHighlightGrad2#,255;(([mAnimLoop]-50)*2/100+1) | #pirateHighlightGrad2#,0;(([mAnimLoop]-50)*2/100+0.75) | #pirateHighlightGrad1#,255;(([mAnimLoop]-50)*2/100+0.5) | #pirateHighlightGrad2#,255;(([mAnimLoop]-50)*2/100+0.25) | #pirateHighlightGrad2#,255;(([mAnimLoop]-50)*2/100-1.25) | #pirateHighlightGrad2#,255;(([mAnimLoop]-50)*2/100-1)
flagWaveBonesOutline=(#pirateWaveAngle#+[calcBodyAlpha]*38) | #pirateHighlightGrad1#,255;(([mAnimLoop]-50)*2/100+1) | #pirateHighlightGrad1#,0;(([mAnimLoop]-50)*2/100+0.75) | #pirateHighlightGrad2#,255;(([mAnimLoop]-50)*2/100+0.5) | #pirateHighlightGrad1#,255;(([mAnimLoop]-50)*2/100+0.25) | #pirateHighlightGrad1#,255;(([mAnimLoop]-50)*2/100-1.25) | #pirateHighlightGrad1#,255;(([mAnimLoop]-50)*2/100-1)
flagWaveSkullBg=(#pirateWaveAngle#+[calcBodyAlpha]*38) | #pirateBGgrad2#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100+1) | #pirateBGgrad2#,0;(([mAnimLoop]-50)*2/100+0.75) | #pirateBGgrad1#,255;(([mAnimLoop]-50)*2/100+0.5) | #pirateBGgrad2#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100+0.25) | #pirateBGgrad2#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100-1.25) | #pirateBGgrad2#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100-1)
flagWaveBonesBg=(#pirateWaveAngle#+[calcBodyAlpha]*38) | #pirateBGgrad1#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100+1) | #pirateBGgrad1#,0;(([mAnimLoop]-50)*2/100+0.75) | #pirateBGgrad2#,255;(([mAnimLoop]-50)*2/100+0.5) | #pirateBGgrad1#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100+0.25) | #pirateBGgrad1#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100-1.25) | #pirateBGgrad1#,#pirateBGAlpha#;(([mAnimLoop]-50)*2/100-1)
shape=Rectangle 0,0,([#CurrentSection#:H]),([#CurrentSection#:W]) | strokewidth 0 | fill color 0,0,0,1
shape2=Rectangle ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.45),([#CurrentSection#:W]*0.475),([#CurrentSection#:H]*0.09) | strokewidth 0 | fill color 0,255,0,83
shape3=Rectangle ([#CurrentSection#:H]*0.9),([#CurrentSection#:H]*0.45),([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.1),([#CurrentSection#:H]*0.05) | strokewidth 0 | fill color 0,0,255,83 | rotate 52,([#CurrentSection#:H]*0.05),([#CurrentSection#:H]*0.05)
shape4=Rectangle ([#CurrentSection#:H]*0.9),([#CurrentSection#:H]*0.45),([#CurrentSection#:W]*0.175),([#CurrentSection#:H]*0.1),([#CurrentSection#:H]*0.05) | strokewidth 0 | fill color 0,0,255,83 | rotate -52,([#CurrentSection#:H]*0.05),([#CurrentSection#:H]*0.05)
shape5=combine shape3 | union shape4 | union shape2 | rotate -38,([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.495)
shape6=combine shape3 | union shape4 | union shape2 | rotate 38,([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.495)
shape7=combine shape3 | union shape4 | union shape2 | rotate -142,([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.495)
shape8=combine shape3 | union shape4 | union shape2 | rotate 142,([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.495)
shape9=path skull | scale 1.1,1.1
; Bones outline
shape10=path skull | stroke LinearGradient flagWaveBonesOutline | strokewidth ([#CurrentSection#:W]*0.01) | fill LinearGradient flagWaveBonesBg | strokeDashes ([#CurrentSection#:H]/3.14*0.0075),([#CurrentSection#:H]/3.14*0.0125) | StrokeDashCap Round | strokeDashOffset ([#CurrentSection#:H]*[mAnimLoop:/100])
shape11=combine shape10 | union shape5 | union shape6 | union shape7 | union shape8 | exclude shape9
shape12=path skull | strokewidth 0 | fill LinearGradient flagWaveSkullBG
; eyes (right then left)
shape13=Ellipse ([#CurrentSection#:H]*0.62),([#CurrentSection#:H]*0.55),([#CurrentSection#:H]*0.103),([#CurrentSection#:H]*0.085) | fill color 0,0,0,0 | rotate 22 | strokewidth ([#CurrentSection#:W]*0.01) | strokeColor #pirateHighlightGrad2#
shape14=Ellipse ([#CurrentSection#:H]*0.38),([#CurrentSection#:H]*0.55),([#CurrentSection#:H]*0.103),([#CurrentSection#:H]*0.085) | rotate -22
; nose
shape15=path nose
; Skull BG
shape16=combine shape12 | exclude shape13 | exclude shape14 | exclude shape15
; skull outline
shape17=path skull | stroke LinearGradient flagWaveSkullOutline | strokewidth ([#CurrentSection#:W]*0.01) | fill color 0,0,0,0 | strokeDashes ([#CurrentSection#:H]/3.14*0.0075),([#CurrentSection#:H]/3.14*0.0125) | StrokeDashCap Round | strokeDashOffset ([#CurrentSection#:H]*[mAnimLoop:/100])
shape18=combine shape17 | exclude shape13 | exclude shape14 | exclude shape15
