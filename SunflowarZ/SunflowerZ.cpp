#include "pch.h"
#include "SunflowerZ.h"


void SunflowerZ::placeZ(const COORD& posZ) {
	this->posSunflowerZ = posZ;
}

void SunflowerZ::hitZ(int damage) {
	this->hpZ -= damage;
}
void SunflowerZ::dieZ() {

}

void SunflowerZ::switchWeaponZ(bool upZ) {
	upZ ? this->IdWeaponUsedZ++ : this->IdWeaponUsedZ--;
}
void SunflowerZ::shootWeaponZ() {

}

void SunflowerZ::moveZ() {

}
void SunflowerZ::jumpZ() {

}

SunflowerZ::SunflowerZ()
{
	this->posSunflowerZ = { 0,0 };
	this->hpZ = 100;
	this->movementZ = 5;
}


SunflowerZ::~SunflowerZ()
{
}
