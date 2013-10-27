CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(SiNES C)

# List of header files.
SET(include
    include/SiNES.h
)

# List of source files.
SET(src
    src/SiNES.c
)

# Generate the executable
add_executable(SiNES ${src} ${include})
