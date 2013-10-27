REM build on windows using cmake, using visual studio express 2010, and windows sdk

REM Pull in the Visual Studio Variables
%VS100COMNTOOLS%\vsvars32.bat

mkdir build
cmake -G "Visual Studio 10" -Bbuild -H.
