#include "StdInc.h"

// private / utils

void SetFont(int red, int green, int blue, trainerFont font)
{
	SetTextFont((eTextFont)font);
	SetTextScale(0.236f, 0.36f);
	SetTextColour(red, green, blue, 255);
	SetTextDropshadow(true, 0, 0, 0, 255);
}

void ChangeSubmenu(MenuId newSubmenu)
{
	g_menu_lastSubMenu[g_menu_subMenuLevel] = g_menu_subMenu;
	g_menu_lastOption[g_menu_subMenuLevel] = g_menu_currentOption;
	g_menu_currentOption = 1;
	g_menu_subMenu = newSubmenu;
	g_menu_subMenuLevel++;
}

// public

void SetMenuTitle(char* title)
{
	SetFont(g_titleTextRed, g_titleTextGreen, g_titleTextBlue, trainerFont::Title);
	DisplayTextWithLiteralString(g_titleX, 0.08f, "STRING", "June's Trainer");

	SetFont(g_titleTextRed, g_titleTextGreen, g_titleTextBlue, trainerFont::Title);
	DisplayTextWithLiteralString(g_titleX, 0.1f, "STRING", title);
}

void DrawWaitText(char* text)
{
	SetFont(g_titleTextRed, g_titleTextGreen, g_titleTextBlue, trainerFont::Title);
	DisplayTextWithLiteralString(g_titleX, 0.09f, "STRING", text);
}


int AddMenuEntry(char* option)
{
	g_menu_optionCount++;

	if (g_menu_currentOption <= 16 && g_menu_optionCount <= 16)
	{
		SetFont(g_optionsRed, g_optionsGreen, g_optionsBlue, trainerFont::Regular);
		DisplayTextWithLiteralString(g_titleMenuText, (g_menu_optionCount * 0.035f + 0.128f), "STRING", option);
	}
	else if ((g_menu_optionCount > (g_menu_currentOption - 16)) && g_menu_optionCount <= g_menu_currentOption)
	{
		SetFont(g_optionsRed, g_optionsGreen, g_optionsBlue, trainerFont::Regular);
		DisplayTextWithLiteralString(g_titleMenuText, ((g_menu_optionCount - (g_menu_currentOption - 16)) * 0.035f + 0.128f), "STRING", option);
	}
	return g_menu_optionCount;
}

void AddMenuOption(char* option, MenuId newSubmenu)
{
	AddMenuEntry(option);

	if (g_menu_currentOption == g_menu_optionCount && g_menu_optionPress)
	{
		ChangeSubmenu(newSubmenu);
	}
}

void StyleMenu()
{
	HideHelpTextThisFrame();

	// SetCinematicButtonEnabled false
	NativeInvoke::Invoke<NATIVE_SET_CINEMATIC_BUTTON_ENABLED, ScriptVoid>(false);

	// TODO: disable hud

	// background rectangle
	//DrawRect(g_backX, 0.5f, (1.0f - g_backX) * 2.0f, 1.0f, g_backgroundRed, g_backgroundGreen, g_backgroundBlue, g_backgroundAlpha);

	if (g_menu_optionCount > 16)
	{
		DrawRect(g_backX, (((16 * 0.035f) / 2) + 0.159f), 0.23f, (16 * 0.035f), g_backgroundRed, g_backgroundGreen, g_backgroundBlue, g_backgroundAlpha); // background

		if (g_menu_currentOption > 16)
		{
			DrawRect(g_backX, ((16 * 0.035f) + 0.1415f), 0.23f, 0.035f, g_navRed, g_navGreen, g_navBlue, g_navAlpha); // selected item

			DrawRect(g_backX, 0.156f, 0.23f, 0.005f, g_indicatorRed, g_indicatorGreen, g_indicatorBlue, g_indicatorAlpha); // up indicator
		}
		else
		{
			DrawRect(g_backX, ((g_menu_currentOption * 0.035f) + 0.1415f), 0.23f, 0.035f, g_navRed, g_navGreen, g_navBlue, g_navAlpha); // selected item

			DrawRect(g_backX, 0.156f, 0.23f, 0.005f, g_indicatorRed, g_indicatorGreen, g_indicatorBlue, g_indicatorAlpha); // up indicator
		}
		if (g_menu_currentOption != g_menu_optionCount)
		{
			DrawRect(g_backX, 0.721f, 0.23f, 0.005f, g_indicatorRed, g_indicatorGreen, g_indicatorBlue, g_indicatorAlpha); // down indicator
		}
	}
	else
	{
		DrawRect(g_backX, (((g_menu_optionCount * 0.035f) / 2) + 0.159f), 0.23f, (g_menu_optionCount * 0.035f), g_backgroundRed, g_backgroundGreen, g_backgroundBlue, g_backgroundAlpha); // background

		DrawRect(g_backX, ((g_menu_currentOption * 0.035f) + 0.1415f), 0.23f, 0.035f, g_navRed, g_navGreen, g_navBlue, g_navAlpha); // selected item
	}
}

int GetMenuEntry()
{
	if (g_menu_optionPress)
	{
		return g_menu_currentOption;
	}
	else
	{
		return 0;
	}
}

#define BUFFER_COUNT 8
#define BUFFER_LENGTH 32768

const char* va(const char* string, ...)
{
	static thread_local int currentBuffer;
	static thread_local std::vector<char> buffer;

	if (!buffer.size())
	{
		buffer.resize(BUFFER_COUNT * BUFFER_LENGTH);
	}

	int thisBuffer = currentBuffer;

	va_list ap;
	va_start(ap, string);
	int length = vsnprintf(&buffer[thisBuffer * BUFFER_LENGTH], BUFFER_LENGTH, string, ap);
	va_end(ap);

	if (length >= BUFFER_LENGTH)
	{
		//GlobalError("Attempted to overrun string in call to va()!");
		return "";
	}

	buffer[(thisBuffer * BUFFER_LENGTH) + BUFFER_LENGTH - 1] = '\0';

	currentBuffer = (currentBuffer + 1) % BUFFER_COUNT;

	return &buffer[thisBuffer * BUFFER_LENGTH];
}

const wchar_t* va(const wchar_t* string, ...)
{
	static thread_local int currentBuffer;
	static thread_local std::vector<wchar_t> buffer;

	if (!buffer.size())
	{
		buffer.resize(BUFFER_COUNT * BUFFER_LENGTH);
	}

	int thisBuffer = currentBuffer;

	va_list ap;
	va_start(ap, string);
	int length = vswprintf(&buffer[thisBuffer * BUFFER_LENGTH], BUFFER_LENGTH, string, ap);
	va_end(ap);

	if (length >= BUFFER_LENGTH)
	{
		//GlobalError("Attempted to overrun string in call to va()!");
		return L"";
	}

	buffer[(thisBuffer * BUFFER_LENGTH) + BUFFER_LENGTH - 1] = '\0';

	currentBuffer = (currentBuffer + 1) % BUFFER_COUNT;

	return &buffer[thisBuffer * BUFFER_LENGTH];
}