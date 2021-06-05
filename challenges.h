#ifndef __CHALLENGES_H__
#define __CHALLENGES_H__
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 200809L
#define MAX_CHALLENGES 12
#define HANDLE_ERROR(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)
void initGame(FILE *fp);
int challenge(int challengeId); //Ejecuta el nivel que se envia por parametro.
#endif