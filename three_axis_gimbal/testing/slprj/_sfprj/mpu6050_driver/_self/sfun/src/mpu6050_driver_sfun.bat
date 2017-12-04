@echo off
set COMPILER=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\bin\gcc
                set CXXCOMPILER=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\bin\g++
                set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -DTARGET_API_VERSION=700   -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set CXXCOMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -std=c++11 -DTARGET_API_VERSION=700   -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set OPTIMFLAGS=-O -DNDEBUG
                set DEBUGFLAGS=-g
                set LINKER=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\bin\gcc
                set CXXLINKER=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\bin\g++
                set LINKFLAGS=-m64 -Wl,--no-undefined -shared -L"C:\Program Files\MATLAB\R2017a\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -Wl,"C:\Program Files\MATLAB\R2017a/extern/lib/win64/mingw64/mexFunction.def"
                set LINKDEBUGFLAGS=-g
                set NAME_OUTPUT=-o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\bin;C:\Program Files\MATLAB\R2017a\extern\include\win64;C:\Program Files\MATLAB\R2017a\extern\include;C:\Program Files\MATLAB\R2017a\simulink\include;C:\Program Files\MATLAB\R2017a\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\include;;%INCLUDE%
set LIB=C:\ProgramData\MATLAB\SupportPackages\R2017a\MW_MinGW_4_9\lib;;%LIB%
set LIBPATH=C:\Program Files\MATLAB\R2017a\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f mpu6050_driver_sfun.gmk
