#include "./include/menu.h"
#include "./include/raylib.h"
#include "include/globals.h"
#include "include/utils.h"

#define MainMenuButtSizeX (windowSize.x / 4)
#define MainMenuButtSizeY (windowSize.y / 20)


void MenuLoop(void) {
	if(IsButtonRelesed((windowSize.x / 2) - (MainMenuButtSizeX / 2), (windowSize.y / 3) - (MainMenuButtSizeY / 2), MainMenuButtSizeX, MainMenuButtSizeY)) { gameState = 1; }

	BeginDrawing();
	ClearBackground(WHITE);

	DrawButton("Play", 50, WHITE, (windowSize.x / 2) - (MainMenuButtSizeX / 2), (windowSize.y / 3) - (MainMenuButtSizeY / 2), MainMenuButtSizeX, MainMenuButtSizeY, GRAY);

	EndDrawing();
}
