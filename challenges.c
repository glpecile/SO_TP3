#include "challenges.h"
#define MAX_SIZE 1024
typedef struct
{
    int (*level)(int id);
    char answer[MAX_SIZE];
} t_challenge;

typedef struct
{
    FILE *fp;
    t_challenge *challenges;
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

void initGame(FILE *fp)
{
    game.fp = fp;
    // Inicializamos los niveles del juego.
    t_challenge aux[MAX_CHALLENGES] = {{&challenge1, "entendido\n"}, {&challenge2, "itba\n"}, {&challenge3, "M4GFKZ289aku\n"}};
    // {{&challenge1, "entendido\n"}, {&challenge2, "itba\n"}, {&challenge3, "M4GFKZ289aku\n"}, {&challenge4, "fk3wfLCm3QvS\n"}, {&challenge5, "too_easy\n"}, {&challenge6, ".RUN_ME\n"}, {&challenge7, "K5n2UFfpFMUN\n"}, {&challenge8, "BUmyYq5XxXGt\n"}, {&challenge9, "u^v\n"}, {&challenge10, "chin_chu_lan_cha\n"}, {&challenge11, "gdb_rules\n"}, {&challenge12, "normal\n"}}
    game.challenges = (t_challenge *)&aux;
    game.buffer = NULL;
    game.size = 0;
    printf("Se inicializo el juego\n");
}

int challenge(int challengeId)
{
    challengeId--;
    challengeMsg();
    return game.challenges[challengeId].level(challengeId);
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
    return processAnswer(game.challenges[0].answer, game.buffer);
}

// static int challenge2()
// {
//     printf(
//         "The Wire S1E5\n"
//         "5295 888 6288\n\n");
//     toInvestigateMsg();
//     printf("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");

//     if (getline(&game.buffer, &game.size, game.fp) == -1)
//     {
//         HANDLE_ERROR("Challenge2: Error in getline");
//     }
//     return processAnswer(game.challenges[1].answer, game.buffer);
// }

// static int challenge3()
// {
//     printf("https://ibb.co/tc0Hb6w\n");
//     toInvestigateMsg();
//     printf("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");

//     if (getline(&game.buffer, &game.size, game.fp) == -1) 
//     {
//         HANDLE_ERROR("Challenge3: Error in getline");
//     }
//     return processAnswer(game.challenges[2].answer, game.buffer);
// }

static void challengeMsg()
{
    printf("------------- DESAFIO -------------\n");
}

static void toInvestigateMsg()
{
    printf("----- PREGUNTA PARA INVESTIGAR -----\n");
}

static int processAnswer(char *answer, char *entered)
{
    int re = 1;
    if (strcmp(answer, entered) != 0)
    {
        printf("\nRespuesta incorrecta: %s\n", entered);
        re = 0;
    }
    return re;
}