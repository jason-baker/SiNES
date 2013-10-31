CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SiNES C CXX)

INCLUDE_DIRECTORIES(
    processors
    processors/Nintendo
    processors/Nintendo/5A22
    xplat
)

# List of header files.
SET(include
    xplat/SiNES_types.h
    xplat/platform.h
    processors/Nintendo/LR35902/ops.hpp
    processors/Nintendo/LR35902/registers.hpp
)

# List of source files.
SET(src
    SiNES.c
    processors/Nintendo/LR35902/ops.cpp
    processors/Nintendo/LR35902/registers.cpp
)

# Generate the executable
ADD_EXECUTABLE(SiNES ${src} ${include})
