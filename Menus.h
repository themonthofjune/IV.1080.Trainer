#pragma once

enum MenuId {
	MenuNotOpen,
	MenuMain,
	MenuVehicles,
	MenuTeleports
};

namespace Menus {
	void Main();
	void Vehicles();
}