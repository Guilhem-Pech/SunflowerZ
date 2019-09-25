#include "pch.h"
#include "WeaponZ.h"

#include <Windows.h>
#include <string>>

void WeaponZ::aimUpZ(bool upZ) {
	upZ ? ++this->aimZ : --this->aimZ;
}

void WeaponZ::useZ() {
	ProjectZ * bulletShotZ = this->getMunitionZ();
	bulletShotZ->speedZ = this->powerZ;
	bulletShotZ->posProjectilZ = this->posUserZ;
	bulletShotZ->dirZ = this->aimZ;
	bulletShotZ->travel();
}

ProjectZ *WeaponZ::getMunitionZ() {
}

void WeaponZ::updateZ() {

}

WeaponZ::WeaponZ()
{
	this->aimZ = 0;
	this->powerZ = 0;
}

WeaponZ::~WeaponZ()
{
}

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
{
}
