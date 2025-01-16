@echo off
REM Ensure PowerShell is available
where powershell >nul 2>&1
if %errorlevel% neq 0 (
    echo PowerShell is required to run this script. Please install it and try again.
    exit /b 1
)

REM Get the current folder
set "baseFolder=%~dp0"

echo Traversing folders and converting .cpp and .h files to UTF-8 without BOM...

REM Use a single-line PowerShell command for better compatibility
powershell -NoProfile -Command "Get-ChildItem -Path '%baseFolder%' -Recurse -Include '*.cpp', '*.h' | ForEach-Object { $content = Get-Content -Path $_.FullName -Raw; [System.IO.File]::WriteAllText($_.FullName, $content, [System.Text.Encoding]::UTF8); Write-Host ('Converted: ' + $_.FullName) }"

echo Conversion completed.
pause
