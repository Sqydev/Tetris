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
extern float menuElapsedTime;

extern RenderTexture2D theboard;

#define boardWidth 10
#define boardHeight 20

#define BUTTON_SPACING 20
#define BUTTON_WIDTH (windowSize.x / 4)
#define BUTTON_HEIGHT (windowSize.y / 20)

extern int gameState;
extern int menuState;

extern int menuAnimationState[boardWidth];

#endif
