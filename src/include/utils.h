#ifndef UTILS_H
#define UTILS_H

#include "./raylib.h"

char* Strconcat(const char* first, const char* sec); 

bool IsButtonPressed(int posX, int posY, int width, int height);
bool IsButtonDown(int posX, int posY, int width, int height);
bool IsButtonRelesed(int posX, int posY, int width, int height);
bool IsButtonHovered(int posX, int posY, int width, int height);
Vector2 GetMenuButtonPosition(int index, int totalButtons);
void DrawButton(const char* text, int fontsize, Color textcolor, int posX, int posY, int width, int height, Color color, bool enableHover, Color hoverColor);

int BetterRand(int low, int high, int step);

#endif
