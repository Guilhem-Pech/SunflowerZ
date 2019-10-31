#include "pch.h"
#include "SunflowerZ.h"


const int move = 5;

void SunflowerZ::hurtZ(int damage) {
	this->hpZ -= damage;
}

void SunflowerZ::dieZ() {
	//TODO
	this->~SunflowerZ();
}

void SunflowerZ::switchObjectZ(bool upZ) {
	upZ ? this->idObjectUsedZ++ : this->idObjectUsedZ--;
}

void SunflowerZ::useObjectZ() {
	this->inventoryZ[this->idObjectUsedZ].useZ();
}

COORD SunflowerZ::getNextMove2DZ() {
	COORD temp = this->pos2DZ;
	if (this->movementZ > 0) {
		//TODO
	}
	return (temp);
}

void SunflowerZ::jumpZ() {
	//TODO
}

void SunflowerZ::startTurn() {
	this->movementZ = move;
}

void SunflowerZ::initZ() {
	this->isSFZ = true;
	this->sprite2DZ = '*';
	this->hpZ = 100;
	this->movementZ = move;
	this->idObjectUsedZ = 0;
}

void SunflowerZ::updateZ() {
	if (this->hpZ < 1) this->dieZ();
}

SunflowerZ::SunflowerZ(COORD pos) :EntityZ() {
	this->pos2DZ = pos;
	this->initZ();
}

SunflowerZ::SunflowerZ(const std::vector<ObjectZ> & inventoryListZ, COORD pos = { 0,0 }) : EntityZ() {
	this->pos2DZ = pos;
	this->initZ();
	this->inventoryZ = inventoryListZ;
}

SunflowerZ::~SunflowerZ(){
	this->inventoryZ.clear();
}
