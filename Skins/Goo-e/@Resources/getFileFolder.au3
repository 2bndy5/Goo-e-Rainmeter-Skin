#NoTrayIcon
#include <FileConstants.au3>
#include <MsgBoxConstants.au3>

;$CmdLine[1] = type of dialog to use
;$CmdLine[2] = name of variable to change
;$CmdLine[3] = path and filename of ini containing the variable to change

Local $progFiles = EnvGet("ProgramFiles(x86)")
Local $userPath = EnvGet("USERPROFILE")
Local Const $path2ini = @ScriptDir & '\' & $CmdLine[3]

; Display an open dialog to select a list of file(s).
Local $UserSelection
If $CmdLine[1] = "drive" Then
	$UserSelection = FileSelectFolder ( "Please Select a Drive", "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}" )
	If @error Then
		; Display the error message.
		MsgBox($MB_SYSTEMMODAL, "OOPS", "Something went wrong." & @CRLF & "Error = " & @error)
	Else
		IniWrite ( $path2ini, "Variables", $CmdLine[2], $UserSelection )
	EndIf
ElseIf $CmdLine[1] = "exe" Then
	$UserSelection = FileOpenDialog ( "Please Select an Exe File", $progFiles & "\", "Executable (*.exe)", $FD_FILEMUSTEXIST )
	If @error Then
		; Display the error message.
		MsgBox($MB_SYSTEMMODAL, "OOPS", "Something went wrong." & @CRLF & "Error = " & @error)
	Else
		IniWrite ( $path2ini, "Variables", $CmdLine[2], $UserSelection )
	EndIf
ElseIf $CmdLine[1] = "folder" Then
	$UserSelection = FileSelectFolder ( "Please Select a Folder" , $userPath & "\" )
	If @error Then
		; Display the error message.
		MsgBox($MB_SYSTEMMODAL, "OOPS", "Something went wrong." & @CRLF & "Error = " & @error)
	Else
		IniWrite ( $path2ini, "Variables", $CmdLine[2], $UserSelection )
	EndIf
EndIf

;~ MsgBox($MB_SYSTEMMODAL, "", "You chose the following:" & @CRLF & $UserSelection)
;~ MsgBox($MB_SYSTEMMODAL, "", "Variables location is:" & @CRLF & $path2ini)
