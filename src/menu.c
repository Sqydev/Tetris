#include "./include/menu.h"
#include "./include/raylib.h"
#include "include/globals.h"
#include "include/utils.h"

#define MainMenuButtSizeX (windowSize.x / 4)
#define MainMenuButtSizeY (windowSize.y / 20)


void MenuLoop(void) {
	switch(menuState) {
		case 0:
			MainMenuLoop();
			break;

		case 1:
			MainSettingsLoop();
			break;
	}
}

void MainMenuLoop(void) {
	if(IsButtonRelesed((windowSize.x / 2) - (MainMenuButtSizeX / 2), (windowSize.y / 3) - (MainMenuButtSizeY / 2), MainMenuButtSizeX, MainMenuButtSizeY)) { gameState = 1; }
	if(IsButtonRelesed((windowSize.x / 2) - (MainMenuButtSizeX / 2), (windowSize.y / 2.5) - (MainMenuButtSizeY / 2), MainMenuButtSizeX, MainMenuButtSizeY)) { menuState = 1; }

	BeginDrawing();
	ClearBackground(WHITE);

	DrawButton("Play", 50, WHITE, (windowSize.x / 2) - (MainMenuButtSizeX / 2), (windowSize.y / 3) - (MainMenuButtSizeY / 2), MainMenuButtSizeX, MainMenuButtSizeY, GRAY, true, LIGHTGRAY);
	DrawButton("Options", 50, WHITE, (windowSize.x / 2) - (MainMenuButtSizeX / 2), (windowSize.y / 2.5) - (MainMenuButtSizeY / 2), MainMenuButtSizeX, MainMenuButtSizeY, GRAY, true, LIGHTGRAY);

	EndDrawing();
}

void MainSettingsLoop() {
	BeginDrawing();
	ClearBackground(WHITE);

	DrawCircle(windowSize.x / 2, windowSize.y / 2, 67, BLACK);

	EndDrawing();
}
