#pragma once
#include "pch.h"
#include <Windows.h>


//TO REMOVE
typedef Weapon;

class SunflowerZ
{

public:

	COORD posSunflowerZ;

	void placeZ(const COORD& posZ);
	void hitZ(int damage);
	void switchWeaponZ(bool upZ);

	SunflowerZ();
	~SunflowerZ();

private:

	int hpZ;
	int movementZ;
	int IdWeaponUsedZ = 0;
	Weapon inventoryZ[10];


};

