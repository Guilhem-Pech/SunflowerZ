#pragma once
#include "pch.h"
#include <Windows.h>


//TO REMOVE
typedef Weapon;

class SunflowerZ
{

public:

	COORD posSunflowerZ;

	void placeZ(const COORD& posZ); //place the SFZ in the Map, give to MapZ a X coordinate to obtain a Y coordinate.

	void hitZ(int damage); //resolve damage when the SFZ is hit by a weapon
	void dieZ(); //Triggered when the SFZ hit less than 1HP.

	void switchWeaponZ(bool upZ); //if true, switch weapon increasively, else, decreasively
	void shootWeaponZ(); //use the Shoot action of the weapon used

	void moveZ(); //the SFZ go right or left or call jumpZ()
	void jumpZ(); //he jump

	SunflowerZ();
	~SunflowerZ();

private:

	int hpZ; //number of Hit Points
	int movementZ; //number of movement the SFZ can do
	int IdWeaponUsedZ = 0; //represent the weapon currently used
	Weapon inventoryZ[10]; //all the weapons


};

