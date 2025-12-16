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
float menubgElapsedTime = 0.0f;

// Globals are filled with 0s
Vector2 menuBackgroundState[boardWidth][boardHeight];

// NOTE:
// gameState: -1 = close
// gameState: 0 = menu
// gameState: 1 = game
// gameState: 2 = gameover
int gameState;

// NOTE:
// menuState: 0 = main
// menuState: 1 = main_settings
int menuState;
