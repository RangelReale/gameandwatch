[Setup]
AppName=Game & Watch Simulator
AppVerName=Game & Watch Simulator 0.2
DefaultDirName={pf}\Game & Watch Simulator
DefaultGroupName=Game & Watch Simulator
SourceDir=..\..
OutputBaseFilename=gameandwatch_0.2_win32_install
OutputDir=release\win32

[Dirs]
Name: "{app}\data"

[Files]
Source: "bin\Release\gamewatch.exe"; DestDir: "{app}"
Source: "bin\Release\*.dll"; DestDir: "{app}"
Source: "data\*"; DestDir: "{app}\data"; Excludes: "Makefile.*,.svn"; Flags: recursesubdirs

[Icons]
Name: "{group}\Game & Watch Simulator"; Filename: "{app}\gamewatch.exe"; WorkingDir: "{app}"
Name: "{group}\Uninstall Game & Watch Simulator"; Filename: "{uninstallexe}"
