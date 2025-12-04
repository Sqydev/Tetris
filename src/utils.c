#include <string.h>
#include <stdlib.h>



char* Strconcat(const char* first, const char* sec) {
    size_t first_len = strlen(first);
    size_t sec_len = strlen(sec);
    
	// TODO: Malloc err handling
	char* res = malloc((first_len + sec_len + 1) * sizeof(char));

    memcpy(res, first, first_len);
    memcpy(res + first_len, sec, sec_len);
	res[first_len + sec_len] = '\0';

	return res;
}
