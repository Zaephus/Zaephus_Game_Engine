@echo off

for /r %1 %%g in (*.frag) do (
	%2\Bin\glslc.exe %%g -o %%~pg%%~ng_frag.spv
)

for /r %1 %%g in (*.vert) do (
	%2\Bin\glslc.exe %%g -o %%~pg%%~ng_vert.spv
)