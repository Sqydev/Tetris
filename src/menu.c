#include "./include/menu.h"
#include "./include/raylib.h"
#include "./include/globals.h"
#include "./include/utils.h"

#include <stdio.h>


// TODO: Naw, fix the logic when you can
void MenuBackgroundLogic(void) {
	int type = BetterRand(0, 10);
	int posRand = BetterRand(0, 4);

	// NOTE:
	// 0: ##
	//    ##
	switch(type) {
		case 0:
			menuBackgroundState[(boardWidth - 2) / posRand][boardHeight - 1] = posRand;
			menuBackgroundState[(boardWidth - 1) / posRand][boardHeight - 1] = posRand;
			menuBackgroundState[(boardWidth - 2) / posRand][boardHeight - 2] = posRand;
			menuBackgroundState[(boardWidth - 1) / posRand][boardHeight - 2] = posRand;
	}

	// NOTE: Gravity
	for(int y = 1; y < boardHeight; y++) {
		for(int x = 0; x < boardWidth; x++) {
			if(menuBackgroundState[x][y - 1] != 0) {
				menuBackgroundState[x][y - 1] = menuBackgroundState[x][y];
				menuBackgroundState[x][y] = 0;
			}
		}
	}
}

void MenuBackgroundDrawing(void) {

}

void MenuLoop(void) {
	menubgElapsedTime += deltaTime;
	if(menubgElapsedTime >= 1.0f) {
		MenuBackgroundLogic();

		menubgElapsedTime -= 1.0f;
	}

	switch(menuState) {
		case 0:
			MainMenuLoop();
			break;

		case 1:
			MainSettingsLoop();
			break;

		default:
			gameState = -1;
			break;
	}
}

void MainMenuLoop(void) {
	int totalButtons = 3;

	Vector2 playPos = GetMenuButtonPosition(0, totalButtons);
	Vector2 optionsPos = GetMenuButtonPosition(1, totalButtons);
	Vector2 quitPos = GetMenuButtonPosition(2, totalButtons);

	if(IsButtonRelesed(playPos.x, playPos.y, BUTTON_WIDTH, BUTTON_HEIGHT)) { gameState = 1; }
	if(IsButtonRelesed(optionsPos.x, optionsPos.y, BUTTON_WIDTH, BUTTON_HEIGHT)) { menuState = 1; }
	if(IsButtonRelesed(quitPos.x, quitPos.y, BUTTON_WIDTH, BUTTON_HEIGHT)) { gameState = -1; }

	BeginDrawing();
	ClearBackground(WHITE);

	MenuBackgroundDrawing();

	DrawButton("Play", 50, WHITE, playPos.x, playPos.y, BUTTON_WIDTH, BUTTON_HEIGHT, GRAY, true, LIGHTGRAY);
	DrawButton("Options", 50, WHITE, optionsPos.x, optionsPos.y, BUTTON_WIDTH, BUTTON_HEIGHT, GRAY, true, LIGHTGRAY);
	DrawButton("Quit", 50, WHITE, quitPos.x, quitPos.y, BUTTON_WIDTH, BUTTON_HEIGHT, GRAY, true, LIGHTGRAY);

	EndDrawing();
}

void MainSettingsLoop() {
	BeginDrawing();
	ClearBackground(WHITE);

	MenuBackgroundDrawing();

	DrawCircle(windowSize.x / 2, windowSize.y / 2, 67, BLACK);

	EndDrawing();
}
