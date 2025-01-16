@echo off
setlocal enabledelayedexpansion

:: Set the directory where the files are located
set folder_path=%~dp0
echo folder_path
:: Loop through the files with .cpp, .h, .txt extensions in the specified folder
for /R %%F in (%folder_path%\*.cpp %folder_path%\*.h %folder_path%\*.txt) do 
(
    echo Processing: %%F

    :: Convert the file to UTF-8 using PowerShell
    powershell -Command "Get-Content '%%F' | Set-Content '%%F' -Encoding utf8NoBOM"

    echo Done: %%F
)

echo All files processed!
pause