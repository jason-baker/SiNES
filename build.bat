@echo off
REM build on windows using cmake, using visual studio express 2010, and windows sdk

REM Pull in the Visual Studio Variables
IF "%VSINSTALLDIR%" EQU "" (
    CALL "%VS100COMNTOOLS%vsvars32.bat"
)

REM Create the project
ECHO "Making build directory..."
mkdir build
ECHO "Running cmake..."
cmake -G "Visual Studio 10" -Bbuild -H.

REM Build the project
ECHO "Running msbuild..."
msbuild build\SiNES.sln
