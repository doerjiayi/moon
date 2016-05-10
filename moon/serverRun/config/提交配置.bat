copy .\quest\*.csv ..\..\..\Client\客户端\data\config\zh-CN\quest\*.csv
copy .\skill\*.csv ..\..\..\Client\客户端\data\config\zh-CN\skill\*.csv
copy  .\stdItem\*.csv ..\..\..\Client\客户端\data\config\zh-CN\stdItem\*.csv
copy  .\scene\*.csv ..\..\..\Client\客户端\data\config\zh-CN\scene\*.csv
copy  .\monster\StdMonster.csv ..\..\..\Client\客户端\data\config\zh-CN\monster\*.csv

pushd ..\..\..\Client\客户端\data\config\zh-CN\
7z a config.zip *\*.csv

TortoiseProc.exe /command:commit /path:".\" /closeonend:3

popd
TortoiseProc.exe /command:commit /path:".\" /closeonend:3