
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;Measures~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[mItemCore1]
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
ifTrueAction=!setvariable timecalc1 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc1 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc1 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc1 "/86400,2]#CRLF#day"

[mItemLastPlayed1]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc1 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc1 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc1 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc1 "/1073741824,2]#CRLF#GB"

[mItemCore2]
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
ifTrueAction=!setvariable timecalc2 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc2 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc2 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc2 "/86400,2]#CRLF#day"

[mItemLastPlayed2]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc2 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc2 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc2 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc2 "/1073741824,2]#CRLF#GB"

[mItemCore3]
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
ifTrueAction=!setvariable timecalc3 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc3 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc3 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc3 "/86400,2]#CRLF#day"

[mItemLastPlayed3]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc3 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc3 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc3 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc3 "/1073741824,2]#CRLF#GB"

[mItemCore4]
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
ifTrueAction=!setvariable timecalc4 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc4 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc4 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc4 "/86400,2]#CRLF#day"

[mItemLastPlayed4]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc4 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc4 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc4 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc4 "/1073741824,2]#CRLF#GB"

[mItemCore5]
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
ifTrueAction=!setvariable timecalc5 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc5 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc5 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc5 "/86400,2]#CRLF#day"

[mItemLastPlayed5]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc5 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc5 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc5 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc5 "/1073741824,2]#CRLF#GB"

[mItemCore6]
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
ifTrueAction=!setvariable timecalc6 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc6 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc6 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc6 "/86400,2]#CRLF#day"

[mItemLastPlayed6]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc6 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc6 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc6 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc6 "/1073741824,2]#CRLF#GB"

[mItemCore7]
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
ifTrueAction=!setvariable timecalc7 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc7 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc7 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc7 "/86400,2]#CRLF#day"

[mItemLastPlayed7]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc7 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc7 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc7 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc7 "/1073741824,2]#CRLF#GB"


[mItemCore8]
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
ifTrueAction=!setvariable timecalc8 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc8 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc8 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc8 "/86400,2]#CRLF#day"

[mItemLastPlayed8]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc8 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc8 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc8 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc8 "/1073741824,2]#CRLF#GB"

[mItemCore9]
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
ifTrueAction=!setvariable timecalc9 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc9 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc9 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc9 "/86400,2]#CRLF#day"

[mItemLastPlayed9]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc9 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc9 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc9 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc9 "/1073741824,2]#CRLF#GB"

[mItemCore10]
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
ifTrueAction=!setvariable timecalc10 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc10 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc10 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc10 "/86400,2]#CRLF#day"

[mItemLastPlayed10]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc10 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc10 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc10 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc10 "/1073741824,2]#CRLF#GB"

[mItemCore11]
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
ifCondition=#CurrentSection# > 60
ifTrueAction=!setvariable timecalc11 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc11 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc11 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc11 "/86400,2]#CRLF#day"

[mItemLastPlayed11]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc11 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc11 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc11 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc11 "/1073741824,2]#CRLF#GB"

[mItemCore12]
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
ifTrueAction=!setvariable timecalc12 "/60,0]#CRLF#min"
ifFalseAction=!setvariable timecalc12 "]#CRLF#sec"
ifCondition2=#CurrentSection# > 3600
ifTrueAction2=!setvariable timecalc12 "/3600,1]#CRLF#hr"
ifCondition3=#CurrentSection# > 86400
ifTrueAction3=!setvariable timecalc12 "/86400,2]#CRLF#day"

[mItemLastPlayed12]
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
ifcondition=#CurrentSection# > 1048576
iftrueaction=!setvariable Sizecalc12 "/1048576,1]#CRLF#MB"
iffalseaction=!setvariable Sizecalc12 "/1024,0]#CRLF#KB"
ifcondition2=#CurrentSection# < 1024
iftrueaction2=!setvariable Sizecalc12 "]#CRLF#Bytes"
ifcondition3=#CurrentSection# > 1073741824
iftrueaction3=!setvariable Sizecalc12 "/1073741824,2]#CRLF#GB"

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

[itemLastPlayed1Icon]
meter=image
meterStyle=LastPlayedStyle
group=info1

[itemLastPlayed1]
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

[itemLastPlayed2Icon]
meter=image
meterStyle=LastPlayedStyle
group=info2

[itemLastPlayed2]
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

[itemLastPlayed3Icon]
meter=image
meterStyle=LastPlayedStyle
group=info3

[itemLastPlayed3]
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

[itemLastPlayed4Icon]
meter=image
meterStyle=LastPlayedStyle
group=info4

[itemLastPlayed4]
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

[itemLastPlayed5Icon]
meter=image
meterStyle=LastPlayedStyle
group=info5

[itemLastPlayed5]
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

[itemLastPlayed6Icon]
meter=image
meterStyle=LastPlayedStyle
group=info6

[itemLastPlayed6]
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

[itemLastPlayed7Icon]
meter=image
meterStyle=LastPlayedStyle
group=info7

[itemLastPlayed7]
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

[itemLastPlayed8Icon]
meter=image
meterStyle=LastPlayedStyle
group=info8

[itemLastPlayed8]
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

[itemLastPlayed9Icon]
meter=image
meterStyle=LastPlayedStyle
group=info9

[itemLastPlayed9]
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
group=info10 | gameinfo10

[itemPlaytime10Icon]
meter=image
meterStyle=playtimeStyle
group=info10

[itemPlayTime10]
meter=string
text="[m#CurrentSection#:#timecalc10#"
meterStyle=InfoStyle
group=info10

[itemLastPlayed10Icon]
meter=image
meterStyle=LastPlayedStyle
group=info10

[itemLastPlayed10]
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
group=info10 | gameinfo10

[11]
meter=image
MeterStyle=IconBG
group=item12 | item11

[infoBG11]
meter=image
meterStyle=infoBG
group=info11 | gameinfo11

[itemPlaytime11Icon]
meter=image
meterStyle=playtimeStyle
group=info11

[itemPlayTime11]
meter=string
text="[m#CurrentSection#:#timecalc11#"
meterStyle=InfoStyle
group=info11

[itemLastPlayed11Icon]
meter=image
meterStyle=LastPlayedStyle
group=info11

[itemLastPlayed11]
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
group=info11 | gameinfo11

[12]
meter=image
MeterStyle=IconBG
group=item12

[infoBG12]
meter=image
meterStyle=infoBG
group=info12 | gameinfo12

[itemPlaytime12Icon]
meter=image
meterStyle=playtimeStyle
group=info12

[itemPlayTime12]
meter=string
text="[m#CurrentSection#:#timecalc12#"
meterStyle=InfoStyle
group=info12

[itemLastPlayed12Icon]
meter=image
meterStyle=LastPlayedStyle
group=info12

[itemLastPlayed12]
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
group=info12 | gameinfo12
