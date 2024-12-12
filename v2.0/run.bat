cmake -S . -B Release -G "MinGW Makefiles" 
cmake --install Release
cmake --build Release

cd Release

::runTests.exe
::pause

Studentai.exe
pause