#include <stdbool.h>

typedef struct pipes *PipesPtr;

PipesPtr initPipes(int argc, char *argv[]);
void sendStringToPipe(PipesPtr channel, const char *data); //funkcja ktorej przekazuje pajpy i potem string - tablice charow
bool getStringFromPipe(PipesPtr channel, char *buffer, size_t size); //fcja ktorej daje pajpy, wskaznik gdzie ma dac to co sprubuje wyciagnac z pajpow a potem rozmiar, ale moze byc za duzy
void closePipes(PipesPtr channel);
