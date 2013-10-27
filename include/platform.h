/*
 * Copyright 2013 Jason M. Baker
 */

#ifndef SINES_PLATFORM_H        /* START: HEADER GUARD */
#define SINES_PLATFORM_H

#ifdef WIN32        /* Windows Systems. */
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #include <windows.h>
#else               /* Non-Windows systems. */
    #error Not supported yet
#endif

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

#endif                          /* END: HEADER GUARD */

