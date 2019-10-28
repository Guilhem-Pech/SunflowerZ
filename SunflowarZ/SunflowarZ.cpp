#include "pch.h"
#include "GameZ.h"

#define _WIN32_WINNT 0x0500

int main()
{
	GameZ* g = GameZ::get();
	g->run();
	return 0;	
}


