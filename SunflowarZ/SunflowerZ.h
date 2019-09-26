#pragma once
#include "pch.h"
#include "ObjectZ.h"

#include <vector>
#include <Windows.h>


class SunflowerZ
{

public:

	COORD posSunflowerZ;

	void placeZ(const COORD& posZ); //place the SFZ in the Map, give to MapZ a X coordinate to obtain a Y coordinate.

	void hurtZ(int damage); //resolve damage when the SFZ is hit by a weapon
	void dieZ(); //Triggered when the SFZ hit less than 1HP.

	void switchObjectZ(bool upZ); //if true, switch weapon increasively, else, decreasively
	void useObjectZ(); //use the Shoot action of the weapon used

	void moveZ(); //the SFZ go right or left or call jumpZ()
	void jumpZ(); //he jump

	void startTurn();

	void initZ(); //initialize the SFZ with HP, movement and everything else.
	void updateZ();

	SunflowerZ(COORD posZ);
	SunflowerZ(std::vector<ObjectZ> inventoryListZ, COORD posZ);
	~SunflowerZ();

private:

	int hpZ; //number of Hit Points
	int movementZ; //number of movement the SFZ can do
	int idObjectUsedZ; //represent the weapon currently used
	std::vector<ObjectZ> inventoryZ; //all the weapons

};

