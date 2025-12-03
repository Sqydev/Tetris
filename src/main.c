#include "./include/globals.h"
#include "./include/raylib.h"
#include "./include/savesys.h"
#include "include/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	// NOTE: Here expanding ~ to /home/USER/
	const char* home = getenv("HOME");
	savePath = malloc((strlen(savePath) + strlen(home) + 1) * sizeof(char));
	// TODO: Here make merging strrings without ~ (becouse CharMerge merges also ~) (don't forget to add / after home/sqyd(here))

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

	return 0;
}
