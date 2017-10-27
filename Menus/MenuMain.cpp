#include "../StdInc.h"

void Menus::Main() 
{
	SetMenuTitle("Main Menu");

	AddMenuOption("Vehicles", MenuVehicles);
	AddMenuOption("Teleports", MenuTeleports);

	int t1 = AddMenuEntry("Spawn Banshee");

	if (GetMenuEntry() == t1)
	{
		auto banshee = MODEL_BANSHEE;
		RequestModel(banshee);

		while (!HasModelLoaded(banshee))
		{
			DrawWaitText("Loading model...");
		}

		Ped ped;
		Vehicle vehicle;
		f32 x, y, z;

		Player playerIndex = ConvertIntToPlayerIndex(GetPlayerId());
		GetPlayerChar(playerIndex, &ped);

		GetCharCoordinates(ped, &x, &y, &z);

		CreateCar(banshee, x, y, z, &vehicle, true);

		MarkModelAsNoLongerNeeded(banshee);
	}

	StyleMenu();
}