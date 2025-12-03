#include <string.h>
#include <stdlib.h>



char* CharMerge(const char* first, const char* sec) {
	// TODO: Malloc err handling
	char* res = malloc((strlen(first) + strlen(sec) + 1) * sizeof(char));

	strcpy(res, first);
    strcat(res, sec);

	return res;
}
