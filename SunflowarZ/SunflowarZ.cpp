#include "pch.h"
#include "SunflowerZ.h"
#include "GameZ.h"
#include "WeaponZ.h"

#include <Windows.h>
#include <iostream>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40
COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
HANDLE hOutput;

int main()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
}