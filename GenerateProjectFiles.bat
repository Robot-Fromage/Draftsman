@echo off

if not exist "%~dp0Draftsman\Tools\Scripts\Windows\GenerateProjectFiles.bat" goto Error_NotFound
call "%~dp0Draftsman\Tools\Scripts\Windows\GenerateProjectFiles.bat" %*
exit /B %ERRORLEVEL%

:Error_NotFound
echo GenerateProjectFiles ERROR: The batch file does not appear to be located where it should.
pause
exit /B 1
