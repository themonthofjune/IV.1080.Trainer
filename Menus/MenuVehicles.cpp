#include "../StdInc.h"

void Menus::Vehicles()
{
	SetMenuTitle("Vehicles");

	AddMenuEntry("nothing here yet :(");
	AddMenuEntry("Let's test scrollables!");

	for (int i = 0; i < 20; i++)
	{
		AddMenuEntry((char*)va("Test Item %i", i));
	}

	StyleMenu();
}