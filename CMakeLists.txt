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
    processors/Nintendo/LR35902/ops.h
    processors/Nintendo/LR35902/registers.h
)

# List of source files.
SET(src
    SiNES.c
    processors/Nintendo/LR35902/ops.c
)

# Generate the executable
ADD_EXECUTABLE(SiNES ${src} ${include})
