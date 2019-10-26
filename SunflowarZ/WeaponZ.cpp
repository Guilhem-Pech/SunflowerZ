#include "pch.h"
#include "WeaponZ.h"

#include <Windows.h>
#include <string>

int WeaponZ::powerZ = 0;
int WeaponZ::aimZ = 0;

void WeaponZ::aimUpZ(bool upZ) {
	upZ ? ++this->aimZ : --this->aimZ; //TODO do something about it, you're not supposed to do that !
}

void WeaponZ::useZ() {
	ProjectZ * bulletShotZ = this->getMunitionZ();
	bulletShotZ->speedZ = this->powerZ;
	bulletShotZ->setPos2DZ(*this->posUserZ);
	bulletShotZ->dirZ = this->aimZ;
}

WeaponZ::WeaponZ()
= default;

WeaponZ::~WeaponZ()
= default;

//------SUNPERZ--------
//---------------------

ProjectZ * SunperZ::getMunitionZ() {
	return new BeamZ();
}

SunperZ::SunperZ()
{
	this->aimZ = 0;
	this->powerZ = 9001; //it's over 9000 !!
}

SunperZ::~SunperZ()
= default;
