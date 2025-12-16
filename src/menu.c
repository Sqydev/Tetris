#include "./include/menu.h"
#include "./include/raylib.h"
#include "./include/globals.h"
#include "./include/utils.h"

#include <stdio.h>


// TODO: DO it so there can be also floating blocks like in tetris
// I know, make the menuBackgroundState chars and make it be like 10 colors so 51 is static(nonfalling) block of color identyfied by 5(idk what color it will be) and 50 is the same but falling and you can add more modes and you can make it static it it can't move becouse of a block
// NOTE: X is type(color) of block, Y is mode of block(static(non falling) or not)
void MenuBackgroundLogic(void) {
	// NOTE: Remamber type is shape
	int type = /*BetterRand(0, 9)*/ 0;
	// NOTE: Remamber, it is both color and pos, ale it is divising something so don't make it zero
	int posRand = BetterRand(1, 5);

	// NOTE:
	// 0: ##
	//    ##
	switch(type) {
		case 0:
			menuBackgroundState[(boardWidth - 2) / posRand][boardHeight - 1] = (Vector2){type, 0};
			menuBackgroundState[(boardWidth - 1) / posRand][boardHeight - 1] = (Vector2){type, 0};
			menuBackgroundState[(boardWidth - 2) / posRand][boardHeight - 2] = (Vector2){type, 0};
			menuBackgroundState[(boardWidth - 1) / posRand][boardHeight - 2] = (Vector2){type, 0};
	}

	// NOTE: Gravity
	for(int y = 1; y < boardHeight; y++) {
		for(int x = 0; x < boardWidth; x++) {
			if(menuBackgroundState[x][y - 1].x != 0 && menuBackgroundState[x][y].y == 0) {
				menuBackgroundState[x][y - 1] = menuBackgroundState[x][y];
				menuBackgroundState[x][y] = (Vector2){0, 0};
			}
			else {
				menuBackgroundState[x][y].y = 1;
			}
		}
	}

	for(int i = 0; i < boardWidth; i++) {
		for(int j = 0; j < boardHeight; j++) {
			printf("| %d |", (int)menuBackgroundState[i][j].x);
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");
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
