#include "./include/savesys.h"
#include "./include/globals.h"
#include "./include/raylib.h"

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


bool IsSave(void) {
	FILE* file = fopen(saveFilePath, "r");

	if(file) {
		fclose(file);
		return true;
	}
	return false;
}

void mkdir_p(const char* what) {
	size_t len = strlen(what);
	char* workspace = malloc(len + 1);
	// TODO: Malloc error handling here!
	if(!workspace) {
		return;
	}

	size_t curr_pos = 0;

	for(int i = 0; i <= (int)len; i++) {
		workspace[curr_pos++] = what[i];

		if(what[i] == '/' && curr_pos > 1) {
			workspace[curr_pos - 1] = '\0';

			// NOTE: Ignore errno EEXIT
			if(mkdir(workspace, 0700) != 0 && errno != EEXIST) {
				printf("ERROR: cannot create directory %s\n", workspace);
				free(workspace);
				return;
			}

			workspace[curr_pos - 1] = '/';
		}
	}

	workspace[curr_pos] = '\0';
    if (mkdir(workspace, 0700) != 0 && errno != EEXIST) {
        printf("Error: cannot create directory %s\n", workspace);
    }

	free(workspace);
}

// NOTE: SAVE FILE'S OBJECT like ORDER
// 1: (int)Monitor Width
// 2: (int)Monitor Height
void CreateSave(void) {
	FILE* file = fopen(saveFilePath, "w");

	// TODO: Here do err handling for file
	if(!file) {
		printf("ERROR: Cannot create new save file in: %s\n", saveFilePath);

		return;
	}

	printf("INFO: Creating new save file in: %s\n", saveFilePath);

	// NOTE: Window sizes
	fprintf(file, "%d\n", (int)(GetMonitorWidth(GetCurrentMonitor()) * 0.3125));
	fprintf(file, "%d\n", (int)(GetMonitorHeight(GetCurrentMonitor()) * 0.8333));

	fclose(file);
}

void LoadSave(void) {
	FILE* file = fopen(saveFilePath, "r");

	// TODO: Here do err handling for file
	if(!file) {
		printf("ERROR: Cannot load save file in: %s\n", saveFilePath);

		return;
	}

	printf("INFO: Loading save file in: %s\n", saveFilePath);

	// NOTE: I chose fscanf to read saveFile becouse I'm really lazy and I don't want to format the data manualy
	if(fscanf(file, "%f", &windowSize.x) != 1) printf("ERROR: Couldn't read window width from save file\n");
	if(fscanf(file, "%f", &windowSize.y) != 1) printf("ERROR: Couldn't read window height from save file\n");

	fclose(file);
}

void SaveSave(void) {

}
