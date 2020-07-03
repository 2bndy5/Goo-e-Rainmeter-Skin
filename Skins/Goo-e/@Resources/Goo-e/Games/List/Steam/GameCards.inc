
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;Measures~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[mItemID1]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName1]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR1]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript1]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime1]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc1 "/60,1]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc1 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc1 "/1440,2]#CRLF#day(s)"

[mItemTrophies1]
measure=string
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize1]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc1 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc1 "/1048576,1]#CRLF#MB"

[mItemID2]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName2]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR2]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript2]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime2]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc2 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc2 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc2 "/1440,1]#CRLF#day(s)"

[mItemTrophies2]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize2]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc2 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc2 "/1048576,1]#CRLF#MB"

[mItemID3]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName3]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR3]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript3]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime3]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc3 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc3 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc3 "/1440,1]#CRLF#day(s)"

[mItemTrophies3]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize3]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc3 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc3 "/1048576,1]#CRLF#MB"

[mItemID4]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName4]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR4]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript4]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime4]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc4 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc4 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc4 "/1440,1]#CRLF#day(s)"

[mItemTrophies4]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize4]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc4 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc4 "/1048576,1]#CRLF#MB"

[mItemID5]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName5]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR5]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript5]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime5]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc5 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc5 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc5 "/1440,1]#CRLF#day(s)"

[mItemTrophies5]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize5]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc5 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc5 "/1048576,1]#CRLF#MB"

[mItemID6]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName6]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR6]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript6]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime6]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc6 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc6 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc6 "/1440,1]#CRLF#day(s)"

[mItemTrophies6]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize6]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc6 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc6 "/1048576,1]#CRLF#MB"

[mItemID7]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName7]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR7]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript7]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime7]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc7 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc7 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc7 "/1440,1]#CRLF#day(s)"

[mItemTrophies7]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize7]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc7 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc7 "/1048576,1]#CRLF#MB"

[mItemID8]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName8]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR8]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript8]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime8]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc8 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc8 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc8 "/1440,1]#CRLF#day(s)"

[mItemTrophies8]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize8]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc8 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc8 "/1048576,1]#CRLF#MB"

[mItemID9]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName9]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR9]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript9]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime9]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc9 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc9 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc9 "/1440,1]#CRLF#day(s)"

[mItemTrophies9]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize9]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc9 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc9 "/1048576,1]#CRLF#MB"

[mItemID10]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName10]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR10]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript10]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime10]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc10 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc10 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc10 "/1440,1]#CRLF#day(s)"

[mItemTrophies10]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize10]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc10 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc10 "/1048576,1]#CRLF#MB"

[mItemID11]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName11]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR11]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript11]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime11]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc11 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc11 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc11 "/1440,1]#CRLF#day(s)"

[mItemTrophies11]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize11]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc11 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc11 "/1048576,1]#CRLF#MB"

[mItemID12]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemName12]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDIR12]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemDescript12]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemPlayTime12]
measure=calc
dynamicVariables=1
updateDivider=-1
formula=0
group=InfoMeasures
ifConditionMode=1
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc12 "/60,2]#CRLF#hr(s)"
ifFalseAction=!setvariable timecalc12 "/1,0]#CRLF#min(s)"
ifCondition2=#CurrentSection# > 1440
ifTrueAction2=!setvariable timecalc12 "/1440,1]#CRLF#day(s)"

[mItemTrophies12]
measure=String
dynamicVariables=1
updateDivider=-1
group=InfoMeasures

[mItemSize12]
Measure=calc
formula=0
dynamicVariables=1
updateDivider=-1
group=InfoMeasures
ifConditionMode=1
ifcondition=#CurrentSection# > 1073741824
iftrueaction=!setvariable Sizecalc12 "/1073741824,2]#CRLF#GB"
iffalseaction=!setvariable Sizecalc12 "/1048576,1]#CRLF#MB"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;Meters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[1]
meter=image
MeterStyle=IconBG
x=90
y=74
group=item12 | item11 | item10 | item9 | item8 | item7 | item6 | item5 | item4 | item3 | item2 | item1

[infoBG1]
meter=image
meterStyle=infoBG
group=info1

[itemPlaytime1Icon]
meter=image
meterStyle=playtimeStyle
group=info1

[itemPlayTime1]
meter=string
text="[m#CurrentSection#:#timecalc1#"
meterStyle=InfoStyle
group=info1

[itemTrophies1Icon]
meter=image
meterStyle=trophiesStyle
group=info1

[itemTrophies1]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info1

[itemSize1Icon]
meter=image
meterStyle=sizeStyle
group=info1

[itemSize1]
meter=string
text="[m#CurrentSection#:#sizecalc1#"
MeterStyle=InfoStyle
group=info1

[itemDescript1]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info1

[2]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8 | item7 | item6 | item5 | item4 | item3 | item2

[infoBG2]
meter=image
meterStyle=infoBG
group=info2

[itemPlaytime2Icon]
meter=image
meterStyle=playtimeStyle
group=info2

[itemPlayTime2]
meter=string
text="[m#CurrentSection#:#timecalc2#"
meterStyle=InfoStyle
group=info2

[itemTrophies2Icon]
meter=image
meterStyle=trophiesStyle
group=info2

[itemTrophies2]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info2

[itemSize2Icon]
meter=image
meterStyle=sizeStyle
group=info2

[itemSize2]
meter=string
text="[mItemSize2:#sizecalc2#"
MeterStyle=InfoStyle
group=info2

[itemDescript2]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info2

[3]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8 | item7 | item6 | item5 | item4 | item3

[infoBG3]
meter=image
meterStyle=infoBG
group=info3

[itemPlaytime3Icon]
meter=image
meterStyle=playtimeStyle
group=info3

[itemPlayTime3]
meter=string
text="[m#CurrentSection#:#timecalc3#"
meterStyle=InfoStyle
group=info3

[itemTrophies3Icon]
meter=image
meterStyle=trophiesStyle
group=info3

[itemTrophies3]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info3

[itemSize3Icon]
meter=image
meterStyle=sizeStyle
group=info3

[itemSize3]
meter=string
text="[mItemSize3:#sizecalc3#"
MeterStyle=InfoStyle
group=info3

[itemDescript3]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info3

[4]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8 | item7 | item6 | item5 | item4

[infoBG4]
meter=image
meterStyle=infoBG
group=info4

[itemPlaytime4Icon]
meter=image
meterStyle=playtimeStyle
group=info4

[itemPlayTime4]
meter=string
text="[m#CurrentSection#:#timecalc4#"
meterStyle=InfoStyle
group=info4

[itemTrophies4Icon]
meter=image
meterStyle=trophiesStyle
group=info4

[itemTrophies4]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info4

[itemSize4Icon]
meter=image
meterStyle=sizeStyle
group=info4

[itemSize4]
meter=string
text="[mItemSize4:#sizecalc4#"
MeterStyle=InfoStyle
group=info4

[itemDescript4]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info4

[5]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8 | item7 | item6 | item5

[infoBG5]
meter=image
meterStyle=infoBG
group=info5

[itemPlaytime5Icon]
meter=image
meterStyle=playtimeStyle
group=info5

[itemPlayTime5]
meter=string
text="[m#CurrentSection#:#timecalc5#"
meterStyle=InfoStyle
group=info5

[itemTrophies5Icon]
meter=image
meterStyle=trophiesStyle
group=info5

[itemTrophies5]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info5

[itemSize5Icon]
meter=image
meterStyle=sizeStyle
group=info5

[itemSize5]
meter=string
text="[mItemSize5:#sizecalc5#"
MeterStyle=InfoStyle
group=info5

[itemDescript5]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info5

[6]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8 | item7 | item6

[infoBG6]
meter=image
meterStyle=infoBG
group=info6

[itemPlaytime6Icon]
meter=image
meterStyle=playtimeStyle
group=info6

[itemPlayTime6]
meter=string
text="[m#CurrentSection#:#timecalc6#"
meterStyle=InfoStyle
group=info6

[itemTrophies6Icon]
meter=image
meterStyle=trophiesStyle
group=info6

[itemTrophies6]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info6

[itemSize6Icon]
meter=image
meterStyle=sizeStyle
group=info6

[itemSize6]
meter=string
text="[mItemSize6:#sizecalc6#"
MeterStyle=InfoStyle
group=info6

[itemDescript6]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info6

[7]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8 | item7

[infoBG7]
meter=image
meterStyle=infoBG
group=info7

[itemPlaytime7Icon]
meter=image
meterStyle=playtimeStyle
group=info7

[itemPlayTime7]
meter=string
text="[m#CurrentSection#:#timecalc7#"
meterStyle=InfoStyle
group=info7

[itemTrophies7Icon]
meter=image
meterStyle=trophiesStyle
group=info7

[itemTrophies7]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info7

[itemSize7Icon]
meter=image
meterStyle=sizeStyle
group=info7

[itemSize7]
meter=string
text="[mItemSize7:#sizecalc7#"
MeterStyle=InfoStyle
group=info7

[itemDescript7]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info7

[8]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9 | item8

[infoBG8]
meter=image
meterStyle=infoBG
group=info8

[itemPlaytime8Icon]
meter=image
meterStyle=playtimeStyle
group=info8

[itemPlayTime8]
meter=string
text="[m#CurrentSection#:#timecalc8#"
meterStyle=InfoStyle
group=info8

[itemTrophies8Icon]
meter=image
meterStyle=trophiesStyle
group=info8

[itemTrophies8]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info8

[itemSize8Icon]
meter=image
meterStyle=sizeStyle
group=info8

[itemSize8]
meter=string
text="[mItemSize8:#sizecalc8#"
MeterStyle=InfoStyle
group=info8

[itemDescript8]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info8

[9]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10 | item9

[infoBG9]
meter=image
meterStyle=infoBG
group=info9

[itemPlaytime9Icon]
meter=image
meterStyle=playtimeStyle
group=info9

[itemPlayTime9]
meter=string
text="[m#CurrentSection#:#timecalc9#"
meterStyle=InfoStyle
group=info9

[itemTrophies9Icon]
meter=image
meterStyle=trophiesStyle
group=info9

[itemTrophies9]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info9

[itemSize9Icon]
meter=image
meterStyle=sizeStyle
group=info9

[itemSize9]
meter=string
text="[mItemSize9:#sizecalc9#"
MeterStyle=InfoStyle
group=info9

[itemDescript9]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info9

[10]
meter=image
MeterStyle=IconBG
group=item12 | item11 | item10

[infoBG10]
meter=image
meterStyle=infoBG
group=info10

[itemPlaytime10Icon]
meter=image
meterStyle=playtimeStyle
group=info10

[itemPlayTime10]
meter=string
text="[m#CurrentSection#:#timecalc10#"
meterStyle=InfoStyle
group=info10

[itemTrophies10Icon]
meter=image
meterStyle=trophiesStyle
group=info10

[itemTrophies10]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info10

[itemSize10Icon]
meter=image
meterStyle=sizeStyle
group=info10

[itemSize10]
meter=string
text="[mItemSize10:#sizecalc10#"
MeterStyle=InfoStyle
group=info10

[itemDescript10]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info10

[11]
meter=image
MeterStyle=IconBG
group=item12 | item11

[infoBG11]
meter=image
meterStyle=infoBG
group=info11

[itemPlaytime11Icon]
meter=image
meterStyle=playtimeStyle
group=info11

[itemPlayTime11]
meter=string
text="[m#CurrentSection#:#timecalc11#"
meterStyle=InfoStyle
group=info11

[itemTrophies11Icon]
meter=image
meterStyle=trophiesStyle
group=info11

[itemTrophies11]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info11

[itemSize11Icon]
meter=image
meterStyle=sizeStyle
group=info11

[itemSize11]
meter=string
text="[mItemSize11:#sizecalc11#"
MeterStyle=InfoStyle
group=info11

[itemDescript11]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info11

[12]
meter=image
MeterStyle=IconBG
group=item12

[infoBG12]
meter=image
meterStyle=infoBG
group=info12

[itemPlaytime12Icon]
meter=image
meterStyle=playtimeStyle
group=info12

[itemPlayTime12]
meter=string
text="[m#CurrentSection#:#timecalc12#"
meterStyle=InfoStyle
group=info12

[itemTrophies12Icon]
meter=image
meterStyle=trophiesStyle
group=info12

[itemTrophies12]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=InfoStyle
group=info12

[itemSize12Icon]
meter=image
meterStyle=sizeStyle
group=info12

[itemSize12]
meter=string
text="[mItemSize12:#sizecalc12#"
MeterStyle=InfoStyle
group=info12

[itemDescript12]
meter=string
MeasureName=m#CurrentSection#
MeterStyle=descriptStyle
group=info12
