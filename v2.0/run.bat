cmake -S . -B Release -G "MinGW Makefiles" 
cmake --build Release
cmake --install Release

cd Release

runTests.exe
pause

Studentai.exe
pause