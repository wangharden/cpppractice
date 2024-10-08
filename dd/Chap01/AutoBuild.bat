@echo off

for /f "delims=" %%i in ('dir /ad/b %CD%') do (
echo %%~ni
cd %%~ni
g++ main.cpp -o main.exe && echo build success
cd ..
)

pause