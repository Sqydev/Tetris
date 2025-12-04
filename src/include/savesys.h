#ifndef SAVESYS_H
#define SAVESYS_H

#include <stdbool.h>


bool IsSave(void);
void mkdir_p(const char* what);
void CreateSave(void);
void LoadSave(void);
void SaveSave(void);

#endif
