#include "./include/menu.h"
#include "./include/raylib.h"
#include "./include/globals.h"
#include "./include/utils.h"


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
	int totalButtons = 3;

	Vector2 playPos = GetMenuButtonPosition(0, totalButtons);
	Vector2 optionsPos = GetMenuButtonPosition(1, totalButtons);
	Vector2 quitPos = GetMenuButtonPosition(2, totalButtons);

	if(IsButtonRelesed(playPos.x, playPos.y, BUTTON_WIDTH, BUTTON_HEIGHT)) { gameState = 1; }
	if(IsButtonRelesed(optionsPos.x, optionsPos.y, BUTTON_WIDTH, BUTTON_HEIGHT)) { menuState = 1; }
	if(IsButtonRelesed(quitPos.x, quitPos.y, BUTTON_WIDTH, BUTTON_HEIGHT)) { gameState = -1; }

	BeginDrawing();
	ClearBackground(WHITE);

	DrawButton("Play", 50, WHITE, playPos.x, playPos.y, BUTTON_WIDTH, BUTTON_HEIGHT, GRAY, true, LIGHTGRAY);
	DrawButton("Options", 50, WHITE, optionsPos.x, optionsPos.y, BUTTON_WIDTH, BUTTON_HEIGHT, GRAY, true, LIGHTGRAY);
	DrawButton("Quit", 50, WHITE, quitPos.x, quitPos.y, BUTTON_WIDTH, BUTTON_HEIGHT, GRAY, true, LIGHTGRAY);

	EndDrawing();
}

void MainSettingsLoop() {
	BeginDrawing();
	ClearBackground(WHITE);

	DrawCircle(windowSize.x / 2, windowSize.y / 2, 67, BLACK);

	EndDrawing();
}
