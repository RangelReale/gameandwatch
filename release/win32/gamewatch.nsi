; gamewatch.nsi
;!include "MUI.nsh"
;--------------------------------

; The name of the installer
Name "Game & Watch Simulator"

!define _VERSION "0.1.0.0"

; The file to write
OutFile "gamewatch_win32_${_VERSION}.exe"

Caption "Game & Watch Simulator ${_VERSION}"
BrandingText " "

; The default installation directory
InstallDir "$PROGRAMFILES\Game & Watch Simulator\"

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\Game & Watch Simulator" "Install_Dir"

;LoadLanguageFile "${NSISDIR}\Contrib\Language files\PortugueseBR.nlf"


;-------------------------
; Version
VIProductVersion "${_VERSION}"
VIAddVersionKey "ProductName" "Game & Watch Simulator"
VIAddVersionKey "CompanyName" "Hitnrun"
VIAddVersionKey "LegalCopyright" "© Hitnrun 2008"
VIAddVersionKey "FileDescription" "Game & Watch Simulator Installer"
VIAddVersionKey "FileVersion" "${_VERSION}"


;-------------------------
; Functions

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

;!insertmacro MUI_PAGE_WELCOME
;!insertmacro MUI_PAGE_COMPONENTS
;!insertmacro MUI_PAGE_DIRECTORY
;!insertmacro MUI_PAGE_INSTFILES

;Languages
; ;!insertmacro MUI_LANGUAGE "PortugueseBR"

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------


; The stuff to install
Section "Simulator (Required)" 
  ; required
  SectionIn RO

  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Main executable
  File ..\..\bin\Release\gamewatch.exe

  ; SDL dlls
  File /r ..\..\bin\Release\*.dll

  ; doc
  File ..\..\doc\README

  ; Set output path to the images.
  SetOutPath $INSTDIR\data

  ; exclude SVN dir
  File /r /x .svn ..\..\data\*.*

  ; Data
  File /r ..\..\data\*.*


  ; Write the installation path into the registry
  WriteRegStr HKLM "SOFTWARE\Game & Watch Simulator" "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GameAndWatchSimulator" "DisplayName" "Game & Watch Simulator"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GameAndWatchSimulator" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GameAndWatchSimulator" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GameAndWatchSimulator" "NoRepair" 1
  WriteUninstaller "uninstall.exe"

  ExecShell "open" "$INSTDIR\gamewatch.exe"
SectionEnd

; Optional section (can be disabled by the user)
Section "Shortcuts"

  CreateDirectory "$SMPROGRAMS\Game & Watch Simulator"
  CreateShortCut "$SMPROGRAMS\Game & Watch Simulator\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\Game & Watch Simulator\Game & Watch Simulator.lnk" "$INSTDIR\gamewatch.exe" "" "$INSTDIR\gamewatch.exe" 0
  
SectionEnd

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GameAndWatchSimulator"
  DeleteRegKey HKLM "SOFTWARE\Game & Watch Simulator"

  ; Remove files and uninstaller
  Delete /REBOOTOK $INSTDIR\gamewatch.exe
  Delete /REBOOTOK $INSTDIR\*.dll.exe
  Delete /REBOOTOK $INSTDIR\uninstall.exe
  Delete /REBOOTOK $INSTDIR\data\*.*

  ; Remove shortcuts, if any
  Delete /REBOOTOK "$SMPROGRAMS\Game & Watch Simulator\*.*"

  ; Remove directories used
  RMDir /REBOOTOK "$SMPROGRAMS\Game & Watch Simulator"
  RMDir /REBOOTOK "$INSTDIR"

  IfRebootFlag 0 noreboot
    MessageBox MB_YESNO|MB_ICONQUESTION "System must be restarted, restart now?" IDNO +2
      Reboot
noreboot:
    
SectionEnd

