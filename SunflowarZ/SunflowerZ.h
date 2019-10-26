#pragma once
#include "pch.h"
#include "ObjectZ.h"
#include "EntityZ.h"

#include <vector>
#include <Windows.h>


class SunflowerZ : public EntityZ
{

public:

	void hurtZ(int damage); //resolve damage when the SFZ is hit by a weapon
	void dieZ(); //Triggered when the SFZ hit less than 1HP.

	void switchObjectZ(bool upZ); //if true, switch weapon increasively, else, decreasively
	void useObjectZ(); //use the Shoot action of the weapon used

	COORD getNextMove2DZ() override; //the SFZ go right or left or call jumpZ()
	void jumpZ(); //he jump

	void startTurn();

	void initZ(); //initialize the SFZ with HP, movement and everything else.

	SunflowerZ(COORD posZ = {0,0});
	SunflowerZ(const std::vector<ObjectZ> &inventoryListZ, COORD posZ);
	virtual ~SunflowerZ();

private:

	int hpZ{}; //number of Hit Points
	int movementZ{}; //number of movement the SFZ can do
	int idObjectUsedZ{}; //represent the weapon currently used
	std::vector<ObjectZ> inventoryZ; //all the weapons

};

