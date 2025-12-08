#include "./include/globals.h"
#include "./include/raylib.h"

Vector2 windowSize;

int Fps;

float deltaTime;

Vector2 mousePos;

char* saveDirPath = "~/.local/share/SQYD_tetris/";
char* saveFileName = "save.dat";
char* saveFilePath;

float elapsedSaveTime = 0.0f;

// NOTE:
// gameState: 0 = menu
// gameState: 1 = game
// gameState: 2 = gameover
int gameState;
