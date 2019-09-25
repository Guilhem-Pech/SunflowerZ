#include "pch.h"
#include "SunflowerZ.h"


const int move = 5;

void SunflowerZ::placeZ(const COORD& posZ) {
	this->posSunflowerZ = posZ;
}

void SunflowerZ::hurtZ(int damage) {
	this->hpZ -= damage;
}
void SunflowerZ::dieZ() {
	//TODO
}

void SunflowerZ::switchObjectZ(bool upZ) {
	upZ ? this->idObjectUsedZ++ : this->idObjectUsedZ--;
}
void SunflowerZ::useObjectZ() {
	this->inventoryZ[this->idObjectUsedZ].useZ();
}

void SunflowerZ::moveZ() {
	if (this->movementZ > 0) {
		//TODO
	}
}
void SunflowerZ::jumpZ() {
	//TODO
}

void SunflowerZ::startTurn() {
	this->movementZ = move;
}

void SunflowerZ::initZ() {
	this->hpZ = 100;
	this->movementZ = move;
	this->idObjectUsedZ = 0;
}

void SunflowerZ::updateZ() {

}

SunflowerZ::SunflowerZ(COORD pos = { 0,0 })
{
	this->posSunflowerZ = pos;
	this->initZ();
}

SunflowerZ::SunflowerZ(COORD pos = { 0,0 }, std::vector<ObjectZ> inventoryListZ)
{
	this->posSunflowerZ = pos;
	this->initZ();
	this->inventoryZ = inventoryListZ;
}

SunflowerZ::~SunflowerZ()
{
	this->inventoryZ.clear();
}
