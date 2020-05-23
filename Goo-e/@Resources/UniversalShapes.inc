[PlayerPrev]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Line ([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape2=Path Triangle | Extend ButtAttributes
Triangle=([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.185) | LineTo ([#CurrentSection#:W]*0.385),([#CurrentSection#:H]/2) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.81) | ClosePath 1
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokeWidth 0 | Fill Color 0,0,0,1

[PlayerNext]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Line ([#CurrentSection#:W]*0.8325),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.8325),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape2=Path Triangle | Extend ButtAttributes
Triangle=([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.19) | LineTo ([#CurrentSection#:W]*0.5925),([#CurrentSection#:H]/2) | LineTo ([#CurrentSection#:W]*0.1575),([#CurrentSection#:H]*0.8075) | ClosePath 1
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokeWidth 0 | Fill Color 0,0,0,1

[PlayerPlay]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Path Triangle | Extend ButtAttributes
Triangle=([#CurrentSection#:W]*0.22),([#CurrentSection#:H]*0.13) | LineTo ([#CurrentSection#:W]*0.75),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.22),([#CurrentSection#:H]*0.87) | ClosePath 1
shape2=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokeWidth 0 | Fill Color 0,0,0,1

[PlayerPause]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Line ([#CurrentSection#:W]*0.3375),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.3375),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape2=Line ([#CurrentSection#:W]*0.6475),([#CurrentSection#:H]*0.125),([#CurrentSection#:W]*0.6475),([#CurrentSection#:H]*0.875) | Extend ButtAttributes
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | strokeWidth 0 | Fill Color 0,0,0,1

[PlayerShuffle]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1 | offset ([#CurrentSection#:W]*0.015),0
shape=Curve ([#CurrentSection#:W]*0),([#CurrentSection#:H]*0.28),([#CurrentSection#:W]*0.37),([#CurrentSection#:H]*0.44),([#CurrentSection#:W]*0.23),([#CurrentSection#:H]*0.3) | Extend ButtAttributes
shape2=Curve ([#CurrentSection#:W]*0),([#CurrentSection#:H]*0.72),([#CurrentSection#:W]*0.85),([#CurrentSection#:H]*0.2825),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.74),([#CurrentSection#:W]*0.47),([#CurrentSection#:H]*0.26) | Extend ButtAttributes | StrokeEndCap Triangle
shape3=Curve ([#CurrentSection#:W]*0.49),([#CurrentSection#:H]*0.565),([#CurrentSection#:W]*0.85),([#CurrentSection#:H]*0.718),([#CurrentSection#:W]*0.67),([#CurrentSection#:H]*0.73) | Extend ButtAttributes | StrokeEndCap Triangle
shape4=path ArrowTop | Extend ButtAttributes
ArrowTop=([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.15) | LineTo ([#CurrentSection#:W]*0.92),([#CurrentSection#:H]*0.2825) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.41) | ClosePath 0
shape5=path ArrowBottom | Extend ButtAttributes
ArrowBottom=([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.595) | LineTo ([#CurrentSection#:W]*0.92),([#CurrentSection#:H]*0.718) | LineTo ([#CurrentSection#:W]*0.8),([#CurrentSection#:H]*0.85) | ClosePath 0
shape6=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[PlayerRepeat]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Path CirclePart | Extend ButtAttributes | StrokeEndCap Triangle
CirclePart=([#CurrentSection#:W]*0.615),([#CurrentSection#:H]*0.055) | ArcTo ([#CurrentSection#:W]*0.385),([#CurrentSection#:H]*0.95) | CurveTo ([#CurrentSection#:W]*0.3),([#CurrentSection#:H]*0.0825),([#CurrentSection#:W]*-0.035),([#CurrentSection#:H]*0.835),([#CurrentSection#:W]*-0.095),([#CurrentSection#:H]*0.27)
shape2=Path Arrow | Extend ButtAttributes
Arrow=([#CurrentSection#:W]*0.115),([#CurrentSection#:H]*0.0325) | LineTo ([#CurrentSection#:W]*0.3525),([#CurrentSection#:H]*0.0325) | LineTo ([#CurrentSection#:W]*0.3525),([#CurrentSection#:H]*0.26)
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[SettingsShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.15) | Extend ButtAttributes
shape2=Path Teeth | Extend ButtAttributes
Teeth=([#CurrentSection#:W]*0.39),([#CurrentSection#:H]*0.05) | LineTo ([#CurrentSection#:W]*0.46),([#CurrentSection#:H]*0.16) | LineTo ([#CurrentSection#:W]*0.54),([#CurrentSection#:H]*0.16) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.05) | LineTo ([#CurrentSection#:W]*0.75),([#CurrentSection#:H]*0.1) | LineTo ([#CurrentSection#:W]*0.715),([#CurrentSection#:H]*0.24) | LineTo ([#CurrentSection#:W]*0.77),([#CurrentSection#:H]*0.29) | LineTo ([#CurrentSection#:W]*0.9),([#CurrentSection#:H]*0.25) | LineTo ([#CurrentSection#:W]*0.96),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.47) | LineTo ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.54) | LineTo ([#CurrentSection#:W]*0.955),([#CurrentSection#:H]*0.615) | LineTo ([#CurrentSection#:W]*0.89),([#CurrentSection#:H]*0.76) | LineTo ([#CurrentSection#:W]*0.76),([#CurrentSection#:H]*0.72) | LineTo ([#CurrentSection#:W]*0.715),([#CurrentSection#:H]*0.77) | LineTo ([#CurrentSection#:W]*0.745),([#CurrentSection#:H]*0.91) | LineTo ([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.96) | LineTo ([#CurrentSection#:W]*0.53),([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.46),([#CurrentSection#:H]*0.85) | LineTo ([#CurrentSection#:W]*0.39),([#CurrentSection#:H]*0.96) | LineTo ([#CurrentSection#:W]*0.25),([#CurrentSection#:H]*0.91) | LineTo ([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.77) | LineTo ([#CurrentSection#:W]*0.24),([#CurrentSection#:H]*0.725) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.755) | LineTo ([#CurrentSection#:W]*0.04),([#CurrentSection#:H]*0.615) | LineTo ([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.535) | LineTo ([#CurrentSection#:W]*0.16),([#CurrentSection#:H]*0.48) | LineTo ([#CurrentSection#:W]*0.04),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.1),([#CurrentSection#:H]*0.26) | LineTo ([#CurrentSection#:W]*0.23),([#CurrentSection#:H]*0.28) | LineTo ([#CurrentSection#:W]*0.28),([#CurrentSection#:H]*0.24) | LineTo ([#CurrentSection#:W]*0.25),([#CurrentSection#:H]*0.105) | ClosePath 1
shape3=Combine Shape2 | Exclude shape
shape4=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[SizeShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Line ([#CurrentSection#:W]*0.835),([#CurrentSection#:H]*0.16),([#CurrentSection#:W]*0.15),([#CurrentSection#:H]*0.845) | Extend ButtAttributes | StrokeStartCap Triangle | StrokeEndCap Triangle
shape2=Path ArrowBottom | Extend ButtAttributes
ArrowBottom=([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.62) | LineTo ([#CurrentSection#:W]*0.095),([#CurrentSection#:H]*0.895) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.895)
shape3=path ArrowTop | Extend ButtAttributes
ArrowTop=([#CurrentSection#:W]*0.61),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.1075) | LineTo ([#CurrentSection#:W]*0.885),([#CurrentSection#:H]*0.385)
shape4=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[StarShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Path Star | Extend ButtAttributes
Star=([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.1) | LineTo ([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.92),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.66),([#CurrentSection#:H]*0.61) | LineTo ([#CurrentSection#:W]*0.77),([#CurrentSection#:H]*0.94) | LineTo ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.725) | LineTo ([#CurrentSection#:W]*0.235),([#CurrentSection#:H]*0.94) | LineTo ([#CurrentSection#:W]*0.34),([#CurrentSection#:H]*0.61) | LineTo ([#CurrentSection#:W]*0.08),([#CurrentSection#:H]*0.4) | LineTo ([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | ClosePath 1

[RoundButtShape]
ButtAttributes=StrokeWidth 0 | Fill Color 139,139,139
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5) | Extend ButtAttributes
shape2=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5) | Fill Color 255,255,255,60 | StrokeWidth 0
shape3=Ellipse ([#CurrentSection#:W]*0.645),([#CurrentSection#:H]*0.645),([#CurrentSection#:W]*0.6),([#CurrentSection#:H]*0.425) | Rotate -36.5
shape4=Combine Shape2 | exclude shape3

[RightArrow]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape2=Path ArrowR | Extend ButtAttributes
ArrowR=([#CurrentSection#:W]*0.58),([#CurrentSection#:H]*0.3) | LineTo ([#CurrentSection#:W]*0.38),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.58),([#CurrentSection#:H]*0.7)
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[LeftArrow]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape2=Path ArrowL | Extend ButtAttributes
ArrowL=([#CurrentSection#:W]*0.42),([#CurrentSection#:H]*0.3) | LineTo ([#CurrentSection#:W]*0.62),([#CurrentSection#:H]*0.5) | LineTo ([#CurrentSection#:W]*0.42),([#CurrentSection#:H]*0.7)
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[PlusShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape2=Line ([#CurrentSection#:W]*0.3225),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.6775),([#CurrentSection#:H]*0.5) | Extend ButtAttributes
shape3=Line ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.3225),([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.6775) | Extend ButtAttributes
shape4=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1

[MinusShape]
ButtAttributes=StrokeWidth ((([#CurrentSection#:W]+[#CurrentSection#:H])/2)*0.065) | StrokeColor #CurrentColor2# | Fill Color 0,0,0,1
shape=Ellipse ([#CurrentSection#:W]*0.5),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.4),([#CurrentSection#:H]*0.4) | Extend ButtAttributes
shape2=Line ([#CurrentSection#:W]*0.3225),([#CurrentSection#:H]*0.5),([#CurrentSection#:W]*0.6775),([#CurrentSection#:H]*0.5) | Extend ButtAttributes
shape3=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 0 | Fill Color 0,0,0,1
