CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SiNES C)

INCLUDE_DIRECTORIES(
    include
    include/processors
    include/processors/Nintendo
    include/processors/Nintendo/5A22
)

# List of header files.
SET(include
    include/SiNES.h
    include/SiNES_types.h
    include/platform.h
    include/processors/Nintendo/5A22/65c816.h
)

# List of source files.
SET(src
    src/SiNES.c
    src/processors/Nintendo/5A22/65c816.c
)

# Generate the executable
ADD_EXECUTABLE(SiNES ${src} ${include})
