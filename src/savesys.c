#include "./include/savesys.h"
#include "./include/globals.h"
#include "./include/raylib.h"
#include "./include/utils.h"

#include <stdbool.h>
#include <stdio.h>


bool IsSave(void) {
	FILE* file = fopen(CharMerge(savePath, "save.dat"), "r");

	if(file) {
		fclose(file);
		return true;
	}
	return false;
}

void CreateSave(void) {
	FILE* file = fopen(CharMerge(savePath, "save.dat"), "w");
	if(file) {
		// NOTE: Window sizes
		fprintf(file, "%d\n", (int)(GetMonitorWidth(GetCurrentMonitor()) * 0.8333));
		fprintf(file, "%d\n", (int)(GetMonitorHeight(GetCurrentMonitor()) * 0.3125));

		fclose(file);
	}
	// TODO: Here do err handling for file
	else {
		
	}
}

void LoadSave(void) {
}
