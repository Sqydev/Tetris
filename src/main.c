#include "./include/globals.h"
#include "./include/raylib.h"
#include "./include/savesys.h"
#include "include/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	// NOTE: Here expanding ~ to /home/USER/
	if(savePath[0] == '~') {
		const char* home = getenv("HOME");
		savePath = Strconcat(home, savePath + 1;
	}

	if(!IsSave()) {
		CreateSave();
		printf("%s", savePath);
	}
	LoadSave();

	InitWindow(windowSize.x, windowSize.y, "Tetris");

	Fps = GetMonitorRefreshRate(GetCurrentMonitor());

	SetTargetFPS(Fps);

	while(!WindowShouldClose()) {
		deltaTime = GetFrameTime();

		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();
	}

	free(savePath);

	return 0;
}
