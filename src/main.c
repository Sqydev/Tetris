#include "include/globals.h"
#include "./include/raylib.h"


int main() {
	defaultWindowSize = (Vector2){ 800, 1200 };

	// TODO: Here savesysInit
	inicialWindowSize = defaultWindowSize;

	InitWindow(inicialWindowSize.x, inicialWindowSize.y, "Tetris");

	while(!WindowShouldClose()) {
		deltaTime = GetFrameTime();

		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();
	}

	return 0;
}
