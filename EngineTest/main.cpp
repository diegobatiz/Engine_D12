#pragma comment(lib, "engine.lib")

#include "TestEntityComponent.h"

#define TEST_ENTITY_COMPONENTS 1

int main()
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	EngineTest test{};

	if (test.Initialize())
	{
		test.Run();
	}

	test.Shutdown();
}