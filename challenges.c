// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "challenges.h"
#include <stdio.h> // Intento de quitar los warnings de stdio.
#define MAX_SIZE 128
#define PIE 3.14159265358979323846

typedef struct
{
    FILE *fp;
    int (*challenges[MAX_CHALLENGES])(void);
    char *buffer;
    size_t size;
} t_game;

/**
    Variables locales
*/
static t_game game;

/**
    Funciones locales
*/
static int processAnswer(char *answer, char *entered);
static void challengeMsg();
static void toInvestigateMsg();
static int challenge1();
static int challenge2();
static int challenge3();
static int challenge4();
static int challenge5();
static int challenge6() __attribute__((section(".RUN_ME")));
static int challenge7();
static int challenge8();
static int challenge9();
static int challenge10();
static int challenge11();
static int challenge12();
static void gdbme();

char too_easy = 1;

void initGame(FILE *fp)
{
    game.fp = fp;

    game.challenges[0] = &challenge1;
    game.challenges[1] = &challenge2;
    game.challenges[2] = &challenge3;
    game.challenges[3] = &challenge4;
    game.challenges[4] = &challenge5;
    game.challenges[5] = &challenge6;
    game.challenges[6] = &challenge7;
    game.challenges[7] = &challenge8;
    game.challenges[8] = &challenge9;
    game.challenges[9] = &challenge10;
    game.challenges[10] = &challenge11;
    game.challenges[11] = &challenge12;

    game.buffer = NULL;
    game.size = 0;
    srand(time(0));
}

int challenge(int challengeId)
{
    system("clear");
    challengeId--;
    challengeMsg();
    return game.challenges[challengeId]();
}

void endGame()
{
    system("clear");
    printf("\nFelicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
    free(game.buffer);
}

static int challenge1()
{
    printf(
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
        "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel."
        "Además tendrán que investigar otras preguntas para responder durante la defensa."
        "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos"
        " y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta."
        "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
        "Deberán estar atentos a los easter eggs.\n\n"
        "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n");
    toInvestigateMsg();
    printf("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge1: Error in getline");
    }
    return processAnswer("entendido\n", game.buffer);
}

static int challenge2()
{
    printf(
        "The Wire S1E5\n"
        "5295 888 6288\n\n");
    toInvestigateMsg();
    printf("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge2: Error in getline");
    }
    return processAnswer("itba\n", game.buffer);
}

static int challenge3()
{
    printf("https://ibb.co/tc0Hb6w\n");
    toInvestigateMsg();
    printf("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge3: Error in getline");
    }
    return processAnswer("M4GFKZ289aku\n", game.buffer);
}

static int challenge4()
{
    char *res = "La respuesta es fk3wfLCm3QvS";
    if (write(13, res, strlen(res)) == -1)
    {
        perror("write");
    }
    printf("EBADF...\n\nwrite: Bad file descriptor\n");
    toInvestigateMsg();
    printf(
        "¿Qué útil abstraccion es utilizada para comunicarse con sockets?"
        " ¿se puede utilizar read(2) y write(2) para operar?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge4: Error in getline");
    }
    return processAnswer("fk3wfLCm3QvS\n", game.buffer);
}

static int challenge5()
{
    if (too_easy)
    {
        printf("respuesta = strings:172\n");
        toInvestigateMsg();
        printf("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");

        if (getline(&game.buffer, &game.size, game.fp) == -1)
        {
            HANDLE_ERROR("Challenge5: Error in getline");
        }
    }

    return processAnswer("too_easy\n", game.buffer);
}

static int challenge6()
{
    printf(".init .plt .text ? .fini .rodata .eh_frame_hdr\n");
    toInvestigateMsg();
    printf(
        "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes."
        "¿Qué conviene más?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge6: Error in getline");
    }
    return processAnswer(".RUN_ME\n", game.buffer);
}

static int challenge7()
{
    printf("Filter error\n");

    char *ans = "K5n2UFfpFMUN\n";
    int len = strlen(ans);
    for (int i = 0; i < len; i++)
    {
        printf("%c", ans[i]);
        for (int j = 0; j < (rand() % (20 - 6 + 1)) + 6; j++)
        {
            char a = (rand() % (122 - 65 + 1)) + 65;
            char aux[2] = {a, 0};
            write(2, aux, 1);
        }
    }
    printf("\n");
    toInvestigateMsg();
    printf("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");
    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge7: Error in getline");
    }
    return processAnswer(ans, game.buffer);
}

static int challenge8()
{
    printf("¿?\n\n");
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
    toInvestigateMsg();
    printf("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge8: Error in getline");
    }
    return processAnswer("BUmyYq5XxXGt\n", game.buffer);
}

static int challenge9()
{
    printf(
        "Latexme\n"
        "Si\n"
        "\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n"
        "entonces\n"
        "y = \n");
    toInvestigateMsg();
    printf("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge9: Error in getline");
    }
    return processAnswer("u^v\n", game.buffer);
}

static int challenge10()
{
    printf("quine\n\n");
    printf("\n");

    if (system("gcc quine.c -o quine") != 0)
    {
        printf("\nENTER para reinternar.\n");
    }
    else
    {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

        if (system("./quine | diff -quine.c") != 0)
        {
            printf("\n%s\n", "diff encontró diferencias.");
            printf("\nENTER para reinternar.\n");
        }
        else
        {
            printf("La respuesta es chin_chu_lan_cha\n\n");
        }
    }

    toInvestigateMsg();
    printf("¿Cuáles son las características del protocolo SCTP?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge10: Error in getline");
    }
    return processAnswer("chin_chu_lan_cha\n", game.buffer);
}

static int challenge11()
{
    printf("b gdbme y encontrá el valor mágico\n");
    gdbme();
    toInvestigateMsg();
    printf("¿Qué es un RFC?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge11: Error in getline");
    }
    return processAnswer("gdb_rules\n", game.buffer);
}

static int challenge12()
{
    printf("Me conoces\n");

    double x, y, aux;
    for (int i = 0; i < 1000; i++)
    {
        x = rand() / ((double)RAND_MAX + 1);
        y = rand() / ((double)RAND_MAX + 1);
        aux = sqrt(-2 * log(x)) * cos(2 * PIE * y);
        printf("%.6f ", aux);
    }
    putchar('\n');

    toInvestigateMsg();
    printf("¿Fue divertido?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("Challenge12: Error in getline");
    }
    return processAnswer("normal\n", game.buffer);
}

static void gdbme()
{
    if ((long)getpid() == 0x123456789)
    {
        printf("La respuesta es: gdb_rules\n\n");
    }
}

// ------------- DESAFIO -------------
static void challengeMsg()
{
    printf("------------- DESAFIO -------------\n");
}

// ----- PREGUNTA PARA INVESTIGAR -----
static void toInvestigateMsg()
{
    printf("----- PREGUNTA PARA INVESTIGAR -----\n");
}

// 1 correcta, 0 incorrecta.
static int processAnswer(char *answer, char *entered)
{
    int re = 1;
    if (strcmp(answer, entered) != 0)
    {
        printf("\nRespuesta incorrecta: %s\n", entered);
        sleep(1);
        re = 0;
    }
    return re;
}