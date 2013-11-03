CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SiNES CXX)

INCLUDE_DIRECTORIES(
    code
)

# List of header files.
SET(include
    code/SiNES.hpp
    code/xplat/types.hpp
    code/xplat/platform.hpp
    #processors/Nintendo/LR35902/cpu.h
	code/processors/Processor.hpp
    code/processors/Nintendo/LR35902/LR35902.hpp
    #processors/Nintendo/LR35902/registers.h
)

# List of source files.
SET(src
    code/SiNES.cpp
    code/processors/Nintendo/LR35902/LR35902.cpp
)

# Generate the executable
ADD_EXECUTABLE(SiNES ${src} ${include})
