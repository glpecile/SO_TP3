#ifndef __CHALLENGES_H__
#define __CHALLENGES_H__
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_CHALLENGES 12
#define HANDLE_ERROR(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)
void initGame(FILE *fp);
// Ejecuta el nivel que se envia por parametro.
int challenge(int challengeId);
// Finaliza el juego y se liberan los recursos.
void endGame();

#endif