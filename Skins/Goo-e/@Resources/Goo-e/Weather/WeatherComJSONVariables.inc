[Variables]

; If another language or unit(s) of measures are desired the correct code can be found at:

; https://admin.rainmeter.net/LanguageCodes.php

; For example, French as used in France would be Language=fr-FR
; The unit(s) of measure are automatic, based on the language.
; For instance, you cannot have the language be French, but the units be F imperial.

; Note however, that simply changing from imperial F to metric C units of measure while keeping the 
; language as English can be done by using en-GB as the Language.
 
Language=en-US

; How often to update the weather information. Default and recommended is 600, which would be 10 minutes.

UpdateRate=600

; Date and time formats you desire.
; See https://docs.rainmeter.net/manual/measures/time/#FormatCodes 
; For formatting codes to use.

DateFormat=%A, %B %#d, %Y
TimeFormat=%#I:%M %p

; Getting and setting your LocationCode can be done one of several ways.
; 
; The EASIEST and likely BEST way is to right-click the skin and select "Choose Location"
;
; This will allow you to search for and use the weather.com Location ID.
; This uses the database described at https://forum.rainmeter.net/viewtopic.php?f=118&t=34714
; Example : LocationCode=USVA0944
;
; Search for your Country and Location, then just click the Location ID that you want.
; Your LocationCode will be set, and your skin will be refreshed to use it. Done...
; Note: You can click the Location Name, to go to Google Maps and confirm your choice.
; 
; More manual alternatives are:
; 
; Go to https://weather.com/
; Search for your city until you get the location you want.
; Use the long Canonical ID number at the end of the resulting URL, for example:
; https://weather.com/weather/today/l/1665d9e3052c3448be48dafc1587318a27ee85516e97e0b5376043cd41a4f0e8

; Copy and enter that as the value for the LocationCode.
; Example : LocationCode=1665d9e3052c3448be48dafc1587318a27ee85516e97e0b5376043cd41a4f0e8
;
; You can also use your Latitude,Longitude retrieved from https://google.com/maps in this format:
; Example : LocationCode=38.7230934,-77.0690415

; In the USA, you can simply use your ZipCode as the LocationCode.
; Example : LocationCode=22308

LocationCode=94519

; Don't change any below here.

CommonSubstitute='"':"","^null$":"","\\u002F":"/","\\u005C":"\","\\u003C":"<","\\u003E":">"
URLSite=https://weather.com/#Language#/weather/today/l/#LocationCode#
