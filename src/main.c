#include "./include/globals.h"
#include "./include/raylib.h"
#include "./include/savesys.h"
#include "include/utils.h"

#include <stdlib.h>
#include <stdio.h>

void Init() {
	// NOTE: Here expanding ~ to /home/USER/
	if(saveDirPath[0] == '~') {
		const char* home = getenv("HOME");
		saveDirPath = Strconcat(home, saveDirPath + 1);
	}
	saveFilePath = Strconcat(saveDirPath, saveFileName);

	LoadSave();

	// NOTE: Window init
	InitWindow(windowSize.x, windowSize.y, "Tetris");
	Fps = GetMonitorRefreshRate(GetCurrentMonitor());
	SetTargetFPS(Fps);

	// NOTE: Save init
	if(!IsSave()) {
		mkdir_p(saveDirPath);

		CreateSave();

		LoadSave();

		// NOTE: If there's no safe it reinits becouse without a save the size is 0
		CloseWindow();
		InitWindow(windowSize.x, windowSize.y, "Tetris");
	}
}

int main() {
	Init();

	while(!WindowShouldClose()) {
		deltaTime = GetFrameTime();

		// NOTE: Save the game avery secound
		elapsedSaveTime += deltaTime;
		if(elapsedSaveTime >= 1.0f) {
			SaveSave();

			elapsedSaveTime = 0.0f;
		}

		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();
	}

	InitWindow(windowSize.x, windowSize.y, "Tetris");
	free(saveDirPath);
	free(saveFilePath);

	return 0;
}
