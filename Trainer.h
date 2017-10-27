#include "StdInc.h"

class TrainerThread : public ScriptThread
{
private:
	void MonitorKeys();
	bool GetKeyPress(int key);



protected:
	void RunTick();

public:
	TrainerThread();
};