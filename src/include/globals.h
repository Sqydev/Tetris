#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

extern Vector2 windowSize;
extern int Fps;

extern float deltaTime;

extern Vector2 mousePos;

extern char* saveDirPath;
extern char* saveFilePath;
extern char* saveFileName;

extern float elapsedSaveTime;
extern float menubgElapsedTime;

#define boardWidth 10
#define boardHeight 20

extern int menuBackgroundState[boardWidth][boardHeight];

extern int gameState;
extern int menuState;

#endif
