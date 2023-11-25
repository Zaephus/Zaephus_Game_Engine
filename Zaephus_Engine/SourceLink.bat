@echo off

echo Linking Application...

%2\g++.exe -o Build/main.exe Bin/*.o -L%3 -lvulkan-1 -L%4 -lglfw3dll -lglfw3

echo Linking complete!