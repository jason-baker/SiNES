/*
 * Copyright 2013 Jason M. Baker
 */

#include "platform.h"
#include "SiNES_types.h"
#include <stdio.h>

typedef struct _MEDIA {
    FILE *pfImage;
    int hasHeader;
} MEDIA, FAR * LPMEDIA;

#define BTS(BOOL) (BOOL ? "True" : "False")
void log(char * msg, ...)
{
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    printf("\r\n");
    va_end(args);
}

/**
 * Load media.
 *
 * @param szPath : SINES_USZ    [IN]    The path to the image.
 *
 * @return @TODO figure out return type
 */
MEDIA loadMedia(SINES_USZ szPath)
{
    MEDIA newMedia = {0};
    newMedia.pfImage = fopen((char*)szPath, "rb");

    return newMedia;
}

/**
 * Entry point for the application.
 *
 * @param argv : char**     [IN]    The string argument array.
 * @param argc : int        [IN]    The number of arguments in the array.
 */
int main(char **argv, int argc)
{
    char arrMediaPath[] = "chronotrigger.smc";
    SINES_USZ szMediaPath = (SINES_USZ)arrMediaPath;
    /* @TODO Argument Parsing */
    MEDIA media = loadMedia(szMediaPath);

    log("Details From Media");
    log("media.hasHeader: %s", BTS(media.hasHeader));

    return 0;
}
