#include "StdInc.h"
#include "Trainer.h"

bool TrainerThread::GetKeyPress(int key)
{
	return (GetAsyncKeyState(key) & 0xFFFF) == 0x8001;
}

void TrainerThread::MonitorKeys()
{
	if (GetTickCount() - g_menu_delayCounter > 150)
	{
		if (g_menu_subMenu == MenuNotOpen)
		{
			if (GetKeyPress(VK_F3))
			{
				g_menu_delayCounter = GetTickCount();
				g_menu_subMenu = MenuMain;
				g_menu_subMenuLevel = 0;
				g_menu_currentOption = 1;
			}
		}
		else
		{
			if (GetKeyPress(VK_BACK) && g_menu_subMenu != 0)
			{
				g_menu_delayCounter = GetTickCount();

				if (g_menu_subMenu == MenuMain)
				{
					g_menu_subMenu = MenuNotOpen;
				}
				else 
				{
					g_menu_subMenu = g_menu_lastSubMenu[g_menu_subMenuLevel - 1];
					g_menu_currentOption = g_menu_lastOption[g_menu_subMenuLevel - 1];
					g_menu_subMenuLevel--;
				}
			}
			else if (GetKeyPress(VK_RETURN) && g_menu_subMenu != 0)
			{
				g_menu_delayCounter = GetTickCount();

				g_menu_optionPress = true;
			}
			else if (GetKeyPress(VK_UP) && g_menu_subMenu != 0)
			{
				g_menu_delayCounter = GetTickCount();

				g_menu_currentOption--;
				g_menu_currentOption = g_menu_currentOption < 1 ? g_menu_optionCount : g_menu_currentOption;
			}
			else if (GetKeyPress(VK_DOWN) && g_menu_subMenu != 0)
			{
				g_menu_delayCounter = GetTickCount();

				g_menu_currentOption++;
				g_menu_currentOption = g_menu_currentOption > g_menu_optionCount ? 1 : g_menu_currentOption;
			}
			else if (GetKeyPress(VK_LEFT))
			{
				g_menu_delayCounter = GetTickCount();

				left_press = true;
			}
			else if (GetKeyPress(VK_RIGHT))
			{
				g_menu_delayCounter = GetTickCount();

				right_press = true;
			}
		}
	}
}

TrainerThread::TrainerThread()
{
	SetName("June's Trainer");
}

void TrainerThread::RunTick()
{
	MonitorKeys();

	g_menu_optionCount = 0;

	switch (g_menu_subMenu)
	{
	case MenuMain:
		Menus::Main();
		break;
	case MenuVehicles:
		Menus::Vehicles();
		break;
	}

	g_menu_optionPress = false;

	//Wait(0);
}