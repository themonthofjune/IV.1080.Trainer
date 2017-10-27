#pragma once

// https://www.gtamodding.com/wiki/SET_TEXT_FONT
enum trainerFont {
	Regular = 0,
	Title = 5
};

void SetMenuTitle(char* title);
void DrawWaitText(char* text);
int AddMenuEntry(char* option);
void AddMenuOption(char* option, MenuId newSubmenu);
void StyleMenu();
int GetMenuEntry();

const char* va(const char* string, ...);
const wchar_t* va(const wchar_t* string, ...);