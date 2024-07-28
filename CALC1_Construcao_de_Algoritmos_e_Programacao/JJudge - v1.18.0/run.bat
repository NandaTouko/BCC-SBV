@ECHO OFF

SET GCC_PATH=C:\Program Files\CodeBlocks\MinGW\bin
SET GPP_PATH=C:\Program Files\CodeBlocks\MinGW\bin
SET JDK_PATH=C:\Program Files\OpenJDK\jdk-13.0.1+9\bin
SET PYTHON_PATH=C:\Program Files\CodeBlocks\MinGW\opt\bin

IF EXIST "%GCC_PATH%" SET PATH=%PATH%;%GCC_PATH%
IF EXIST "%GPP_PATH%" SET PATH=%PATH%;%GPP_PATH%
IF EXIST "%JDK_PATH%" SET PATH=%PATH%;%JDK_PATH%
IF EXIST "%PYTHON_PATH%" SET PATH=%PATH%;%PYTHON_PATH%

START "" "C:\Program Files\OpenJDK\jdk-13.0.1+9\bin\javaw.exe" -jar JJudge.jar -stt 5 
