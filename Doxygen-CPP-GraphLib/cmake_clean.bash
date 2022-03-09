#!/bin/bash

for fld in $(find . -name "CMakeLists.txt" -exec dirname {} \;)
do
    for cmakefile in CMakeCache.txt cmake_install.cmake CTestTestfile.cmake CMakeFiles Makefile CMakeDoxygenDefaults.cmake CMakeDoxyfile.in doxygen/build DoxygenWarningLog.txt Doxyfile make.bat 
    do
        rm -rfv $fld/$cmakefile
    done
done
