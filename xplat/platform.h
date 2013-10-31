/*
 * Copyright 2013 Jason M. Baker
 */

#ifndef SINES_PLATFORM_H        /* START: HEADER GUARD */
#define SINES_PLATFORM_H

#ifdef WIN32        /* Windows Systems. */
    #define _CRT_SECURE_NO_WARNINGS 1
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #include <windows.h>
#else               /* Non-Windows systems. */
    #error Not supported yet
#endif

#ifndef TRUE
    #error TRUE not defined
#endif
#ifndef FALSE
    #error FALSE not defined
#endif

#endif                          /* END: HEADER GUARD */

