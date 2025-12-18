#include "./include/menu.h"
#include "./include/raylib.h"
#include "./include/globals.h"
#include "./include/utils.h"

// TODO: Fix the block having 10px offset
void MenuBackgroundLogic(void) {
	for(int i = 0; i < boardWidth; i++) {
		menuAnimationState[i] += windowSize.y / boardHeight;

		if(menuAnimationState[i] >= windowSize.y + boardHeight) {
			menuAnimationState[i] = BetterRand(-windowSize.y, 0, windowSize.y / boardHeight);
		}
	}
}

void MenuBackgroundDrawing(void) {
	for(int i = 0; i < boardWidth; i++) {
		DrawRectangle(i * windowSize.x / boardWidth, menuAnimationState[i] - boardHeight, windowSize.x / boardWidth, windowSize.x / boardWidth, BLACK);
	}
}

void MenuLoop(void) {
	menuElapsedTime += deltaTime;
	if(menuElapsedTime >= 0.16f) {
		MenuBackgroundLogic();
		menuElapsedTime -= 0.16f;
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

	EndDrawing();
}
