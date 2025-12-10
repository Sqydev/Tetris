#include "./include/globals.h"
#include "./include/raylib.h"
#include "./include/utils.h"

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

bool IsButtonPressed(int posX, int posY, int width, int height) {
	if(IsButtonHovered(posX, posY, width, height) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		return true;
	}
	return false;
}
bool IsButtonDown(int posX, int posY, int width, int height) {
	if(IsButtonHovered(posX, posY, width, height) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		return true;
	}
	return false;
}
bool IsButtonRelesed(int posX, int posY, int width, int height) {
	if(IsButtonHovered(posX, posY, width, height) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		return true;
	}
	return false;
}
bool IsButtonHovered(int posX, int posY, int width, int height) {
	if(mousePos.x >= posX && mousePos.x <= posX + width &&
	   mousePos.y >= posY && mousePos.y <= posY + height
	) {
		return true;
	}
	return false;
}
Vector2 GetMenuButtonPosition(int index, int totalButtons) {
	float centerY = windowSize.y / 2;
	float offsetY = -(totalButtons / 2.0f) * (BUTTON_HEIGHT + BUTTON_SPACING) + (index * (BUTTON_HEIGHT + BUTTON_SPACING));
	float centerX = (windowSize.x / 2) - (BUTTON_WIDTH / 2);

	return (Vector2){centerX, centerY + offsetY};
}
void DrawButton(const char* text, int fontsize, Color textcolor, int posX, int posY, int width, int height, Color color, bool enableHover, Color hoverColor) {
	// NOTE: Be not afraid, if !enableHover then !IsButtonHovered won't even execute becouse that's how || works
	// NOTE: Only enableHover and not enableHover && enableColorHover becouse that just faster and simpler, also If you wanna disable only hoverColor then just set it to ba the same as color
	if(!enableHover || !IsButtonHovered(posX, posY, width, height)) {
		DrawRectangle(posX, posY, width, height, color);
	}
	else {
		DrawRectangle(posX, posY, width, height, hoverColor);
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
	}

	unsigned int TextLen = MeasureText(text, fontsize);

	DrawText(text, posX + (width - TextLen) / 2, posY + (height - fontsize) / 2, fontsize, textcolor);
}
