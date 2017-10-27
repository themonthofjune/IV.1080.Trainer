#include "StdInc.h"
#include "Trainer.h"

static TrainerThread trainer;

BOOL APIENTRY DllMain(HANDLE, DWORD  reason, LPVOID)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
		{
			ScriptHookManager::RegisterThread(&trainer);
			break;
		}
	}
	return TRUE;
}