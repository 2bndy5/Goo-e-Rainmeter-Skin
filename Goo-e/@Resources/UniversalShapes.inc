[PlayerPrev]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
Triangle=([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.185) | LineTo ([#CurrentSection#:W]*0.385),([#CurrentSection#:H]/2) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.81) | ClosePath 1
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Line ([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape3=Path Triangle | Extend ButtAttributes

[PlayerNext]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
Triangle=([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.19) | LineTo ([#CurrentSection#:W]*0.5925),([#CurrentSection#:H]/2) | LineTo ([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.8075) | ClosePath 1
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Line ([#CurrentSection#:W]*0.8325),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.8325),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape3=Path Triangle | Extend ButtAttributes

[PlayerPlay]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
Triangle=([#CurrentSection#:W]*0.22),([#CurrentSection#:H]*0.13) | LineTo ([#CurrentSection#:W]*0.75),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.22),([#CurrentSection#:H]*0.87) | ClosePath 1
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Path Triangle | Extend ButtAttributes

[PlayerPause]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Line ([#CurrentSection#:W]*0.3375),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.3375),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape3=Line ([#CurrentSection#:W]*0.6475),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.6475),([#CurrentSection#:H]*0.875) | Extend ButtAttributes

[PlayerShuffle]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1 | offset ([#CurrentSection#:W]*0.015),0
ArrowTop=([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.15) | LineTo ([#CurrentSection#:W]*0.92),([#CurrentSection#:H]*0.2825) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.41) | ClosePath 0
ArrowBottom=([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.595) | LineTo ([#CurrentSection#:W]*0.92),([#CurrentSection#:H]*0.718) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.85) | ClosePath 0
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Curve ([#CurrentSection#:W]*0),([#CurrentSection#:H]*0.28),([#CurrentSection#:W]*0.37),([#CurrentSection#:H]*0.44),([#CurrentSection#:W]*0.23),([#CurrentSection#:H]*0.3) | Extend ButtAttributes
shape3=Curve ([#CurrentSection#:W]*0),([#CurrentSection#:H]*0.72),([#CurrentSection#:W]*0.85),([#CurrentSection#:H]*0.2825),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.74),([#CurrentSection#:W]*0.47),([#CurrentSection#:H]*0.26) | Extend ButtAttributes | StrokeEndCap Triangle
shape4=Curve ([#CurrentSection#:W]*0.49),([#CurrentSection#:H]*0.565),([#CurrentSection#:W]*0.85),([#CurrentSection#:H]*0.718),([#CurrentSection#:W]*0.67),([#CurrentSection#:H]*0.73) | Extend ButtAttributes | StrokeEndCap Triangle
shape5=path ArrowTop | Extend ButtAttributes
shape6=path ArrowBottom | Extend ButtAttributes

[PlayerRepeat]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
CirclePart=([#CurrentSection#:W]*0.615),([#CurrentSection#:H]*0.055) | ArcTo ([#CurrentSection#:W]*0.385),([#CurrentSection#:H]*0.95) | CurveTo ([#CurrentSection#:W]*0.3),([#CurrentSection#:H]*0.0825),([#CurrentSection#:W]*-0.035),([#CurrentSection#:H]*0.835),([#CurrentSection#:W]*-0.095),([#CurrentSection#:H]*0.27)
Arrow=([#CurrentSection#:W]*0.115),([#CurrentSection#:H]*0.0325) | LineTo ([#CurrentSection#:W]*0.3525),([#CurrentSection#:H]*0.0325) | LineTo ([#CurrentSection#:W]*0.3525),([#CurrentSection#:H]*0.26)
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Path CirclePart | Extend ButtAttributes | StrokeEndCap Triangle
shape3=Path Arrow | Extend ButtAttributes

[SettingsShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
Teeth=([#CurrentSection#:W]*0.39),([#CurrentSection#:H]*0.05) | LineTo ([#CurrentSection#:W]*0.46),([#CurrentSection#:H]*0.16) | LineTo ([#CurrentSection#:W]*0.54),([#CurrentSection#:H]*0.16) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.05) | LineTo ([#CurrentSection#:W]*0.75),([#CurrentSection#:H]*0.1) | LineTo ([#CurrentSection#:W]*0.715),([#CurrentSection#:H]*0.24) | LineTo ([#CurrentSection#:W]*0.77),([#CurrentSection#:H]*0.29) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.96),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.54) | LineTo ([#CurrentSection#:W]*0.955),([#CurrentSection#:H]*0.615) | LineTo ([#CurrentSection#:W]*0.89),([#CurrentSection#:H]*0.76) | LineTo ([#CurrentSection#:W]*0.76),([#CurrentSection#:H]*0.72) | LineTo ([#CurrentSection#:W]*0.715),([#CurrentSection#:H]*0.77) | LineTo ([#CurrentSection#:W]*0.745),([#CurrentSection#:H]*0.91) | LineTo ([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.96) | LineTo ([#CurrentSection#:W]*0.53),([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.46),([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.39),([#CurrentSection#:H]*0.96) | LineTo ([#CurrentSection#:W]*0.25),([#CurrentSection#:H]*0.91) | LineTo ([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.77) | LineTo ([#CurrentSection#:W]*0.24),([#CurrentSection#:H]*0.725) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.755) | LineTo ([#CurrentSection#:W]*0.04),([#CurrentSection#:H]*0.615) | LineTo ([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.535) | LineTo ([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.48) | LineTo ([#CurrentSection#:W]*0.04),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.26) | LineTo ([#CurrentSection#:W]*0.23),([#CurrentSection#:H]*0.28) | LineTo ([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.24) | LineTo ([#CurrentSection#:W]*0.25),([#CurrentSection#:H]*0.105) | ClosePath 1
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.15) | Extend ButtAttributes
shape3=Path Teeth | Extend ButtAttributes
shape4=Combine Shape3 | Exclude shape2

[SizeShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
ArrowBottom=([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.62) | LineTo ([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.895) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.895)
ArrowTop=([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.385)
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Line ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.16),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.845) | Extend ButtAttributes | StrokeStartCap Triangle | StrokeEndCap Triangle
shape3=Path ArrowBottom | Extend ButtAttributes
shape4=path ArrowTop | Extend ButtAttributes

[StarShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
Star=([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.1) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.92),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.61) | LineTo ([#CurrentSection#:W]*0.77),([#CurrentSection#:H]*0.94) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.725) | LineTo ([#CurrentSection#:W]*0.235),([#CurrentSection#:H]*0.94) | LineTo ([#CurrentSection#:W]*0.34),([#CurrentSection#:H]*0.61) | LineTo ([#CurrentSection#:W]*0.08),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | ClosePath 1
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Path Star | Extend ButtAttributes

[RightArrow]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
ArrowR=([#CurrentSection#:W]*0.58),([#CurrentSection#:H]*0.3) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.58),([#CurrentSection#:H]*0.7)
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape3=Path ArrowR | Extend ButtAttributes

[LeftArrow]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
ArrowL=([#CurrentSection#:W]*0.42),([#CurrentSection#:H]*0.3) | LineTo ([#CurrentSection#:W]*0.62),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.42),([#CurrentSection#:H]*0.7)
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape3=Path ArrowL | Extend ButtAttributes

[hamberger]
ButtAttributes=strokeWidth ([#CurrentSection#:H]*0.15) | strokeColor #CurrentColor2# | StrokeStartCap Round | StrokeEndCap Round
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=line ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.25),([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.25) | extend ButtAttributes
shape3=line ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.5) | extend ButtAttributes
shape4=line ([#CurrentSection#:W]*0.2),([#CurrentSection#:H]*0.75),([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.75) | extend ButtAttributes

[Close]
ButtAttributes=Strokewidth 0 | Fill Color #CurrentColor2#
BGAttributes=StrokeWidth 0 | Fill Color 0,0,0,1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | extend BGAttributes
shape2=Rectangle 0,([#CurrentSection#:H]*0.47),([#CurrentSection#:W]),([#CurrentSection#:W]*0.12),([#CurrentSection#:W]*0.06) | Extend ButtAttributes | Rotate 45.0
shape3=Rectangle 0,([#CurrentSection#:H]*0.47),([#CurrentSection#:W]),([#CurrentSection#:W]*0.12),([#CurrentSection#:W]*0.06) | Extend ButtAttributes | Rotate -45.0
shape4=Combine Shape2 | Union Shape3
