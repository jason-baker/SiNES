/*
 * Copyright 2013 Jason M. Baker
 */

#include "platform.h"
#include "SiNES_types.h"
#include "LR35902\ops.hpp"
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
 * @param szPath : usz    [IN]    The path to the image.
 *
 * @return @TODO figure out return type
 */
MEDIA loadMedia(usz szPath)
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
    usz szMediaPath = (usz)arrMediaPath;
    /* @TODO Argument Parsing */
    MEDIA media = loadMedia(szMediaPath);

    log("Details From Media");
    log("media.hasHeader: %s", BTS(media.hasHeader));

    exec_op();

    return 0;
}
