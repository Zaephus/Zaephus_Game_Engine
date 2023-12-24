@echo off
setlocal enableDelayedExpansion

echo Compiling Shaders...

echo %1
echo %2

for /r %1 %%A in (*.frag) do (
    echo Found file: %%~nA%%~xA

	set sourceTimeStamp=%%~tA

	set targetPath=Bin/Shaders/%%~nA_frag.spv
	for %%X in (!targetPath!) do (
		set outputTimeStamp=%%~tX
	)

	if !sourceTimeStamp! GTR !outputTimeStamp! (
		%2\Bin\glslc.exe %%A -o !targetPath!
	) else (
		echo %%~nA%%~xA did not need to be recompiled.
	)
)

for /r %1 %%A in (*.vert) do (
	echo Found file: %%~nA%%~xA

	set sourceTimeStamp=%%~tA

	set targetPath=Bin/Shaders/%%~nA_vert.spv
	for %%X in (!targetPath!) do (
		set outputTimeStamp=%%~tX
	)

	if !sourceTimeStamp! GTR !outputTimeStamp! (
		%2\Bin\glslc.exe %%A -o !targetPath!
	) else (
		echo %%~nA%%~xA did not need to be recompiled.
	)
)

echo Finished Compiling Shaders.