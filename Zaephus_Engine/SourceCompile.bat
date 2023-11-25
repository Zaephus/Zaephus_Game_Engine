@echo off
setlocal enableDelayedExpansion

echo Compiling Application...

for /r %1 %%A in (*.cpp) do (
    echo Found file: %%~nA%%~xA

    set sourceTimeStamp=%%~tA

	set targetPath=Bin/%%~nA.o
	for %%X in (!targetPath!) do (
		set outputTimeStamp=%%~tX
	)

	if !sourceTimeStamp! GTR !outputTimeStamp! (
        %2/g++.exe -O0 -g -I%1 -I%3 -I%4 -I%5 -I%6 -c -o Bin/%%~nA.o %%~pA%%~nA%%~xA
    ) else (
        echo %%~nA%%~xA did not need to be recompiled.
    )
)

for /r %1 %%A in (*.c) do (
    echo Found file: %%~nA%%~xA

    set sourceTimeStamp=%%~tA

	set targetPath=Bin/%%~nA.o
	for %%X in (!targetPath!) do (
		set outputTimeStamp=%%~tX
	)

	if !sourceTimeStamp! GTR !outputTimeStamp! (
        %2/g++.exe -O0 -g -I%1 -I%3 -I%4 -I%5 -I%6 -c -o Bin/%%~nA.o %%~pA%%~nA%%~xA
    ) else (
        echo %%~nA%%~xA did not need to be recompiled.
    )
)

echo Compilation complete!