#include "StdInc.h"

MenuId g_menu_subMenu = MenuNotOpen;
int g_menu_subMenuLevel;
MenuId g_menu_lastSubMenu[20];
int g_menu_lastOption[20];
int g_menu_currentOption;
int g_menu_optionCount;
bool g_menu_newTimerTick = true;
bool g_menu_optionPress = false;
int g_menu_delayCounter = GetTickCount();
bool left_press = false;
bool right_press = false;

float g_titleX = 0.845f;
float g_titleBox = 0.845f;
float g_titleMenuText = 0.745f;
float g_backX = 0.845f;

int g_titleTextRed = 225;
int g_titleTextGreen = 225;
int g_titleTextBlue = 225;

int g_backgroundRed = 15;
int g_backgroundGreen = 15;
int g_backgroundBlue = 15;
int g_backgroundAlpha = 200;

int g_optionsRed = 255;
int g_optionsGreen = 255;
int g_optionsBlue = 255;

int g_navRed = 220;
int g_navGreen = 220;
int g_navBlue = 220;
int g_navAlpha = 190;

int g_indicatorRed = 255;
int g_indicatorGreen = 44;
int g_indicatorBlue = 55;
int g_indicatorAlpha = 255;