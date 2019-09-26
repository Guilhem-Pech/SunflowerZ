#pragma once
#include "ObjectZ.h"
#include "ProjectZ.h"
#include <string>

class ProjectZ;
class WeaponZ : public ObjectZ
{
public:
	static int powerZ; //store the power of the weapon, used for shooting munitions
	static int aimZ; //direction [0;7] with 0 being right and +1 being trigonometric rotation
	COORD * posUserZ;

	void aimUpZ(bool upZ); // change the aiming direction
	void useZ(); //shoot the weapons, will create a projectil with a base speed and a direction

	virtual ProjectZ *getMunitionZ() = 0; //retrieve the munition of the weapon

	void updateZ();

	WeaponZ();
	~WeaponZ();
};

class SunperZ : WeaponZ
{
public:
	ProjectZ *getMunitionZ();

	SunperZ();
	~SunperZ();
};
