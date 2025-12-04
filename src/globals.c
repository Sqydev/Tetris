#include "./include/globals.h"
#include "./include/raylib.h"

Vector2 windowSize;

int Fps;

float deltaTime;

char* saveDirPath = "~/.local/share/SQYD_tetris/";
char* saveFileName = "save.dat";
char* saveFilePath;
