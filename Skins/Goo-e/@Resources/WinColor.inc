;;windows 7 registry colors are saved under
;;HKCU\Control Panel\Desktop\Colors
;;this method of extraction will NOT work

[GetBaseColor]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\Microsoft\Windows\DWM
RegValue=ColorizationColor
onchangeAction=[!UpdateMeasure ScriptConverter][!UpdateMeasure MeasureWinVar]

;this Measure is NOT actual used
;for historic development insight
[MeasurePaletteRegistry]
Measure=Plugin
Plugin=RunCommand
Parameter=C:\Windows\System32\reg.exe query HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Accent /v AccentPalette
OutputType=ANSI
FinishAction=[!UpdateMeasure ScriptConverter][!UpdateMeasure MeasureWinVar]
RegExpSubstitute=1
Substitute="(?siU).*ARY\s*([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..":"\1 \2 \3 \4 \5 \6 \7 \8"
;;RegEx PATTERN = RR BB GG .. {8}
;; Select a palette entry from
;; "\1\2\3\4\5\6\7\8"
;;\1 = very very bright (Almost white)
;;\2 = very bright
;;\3 = Highlight active menu Selection
;;\4 = Active Window Color
;;\5 = brighter BG
;;\6 = darker BG
;;\7 = much darker BG
;;\8 = Magenta (Bright Purple) Possibly for high contrast theme settings

[ScriptConverter]
measure=script
DynamicVariables=1
ScriptFile="#@#WinColor.lua"
updateDivider=-1

[WindowsDarkMode]
measure=Plugin
plugin=DarkContextMenu
DarkMode=1
Tooltips=1
