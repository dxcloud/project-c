# Make System for SaC2
__SaC2__ __Version:__ 0.1    
__Date:__ 2013-04-18

Description:
------------
This __Make__ __System__ provides several rules to make a _Makefile_ easier
to write.

__NOTE:__ GNU Make 3.80 or above is required.

Getting started:
----------------
Fisrt set __SAC_MAKE__ environment variable, the script _sac2.sh_ in the 
root directory can be used for setting this variable.

In a _Makefile_, the line: `include $(SAC_MAKE)` is sufficient for any basic
application. The following flags can be used:
        - CXX      : compiler, by default __g++__ is used
        - CXXFLAGS : extra C++ compilation options (by default `-Wall -pedantic -O`)
        - EXEC     : name of the executable

Author:
-------
Chengwu HUANG

##TODO: write command help message in the file help.mk

