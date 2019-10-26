#include "pch.h"
#include "EntityZ.h"
#include "EntityManagerZ.h"

#include <Windows.h>


char EntityZ::getSpriteZ() {
	return this->sprite2DZ;
}

COORD EntityZ::getPos2DZ() {
	return this->pos2DZ;
}

void EntityZ::setPos2DZ(COORD posZ) {
	this->pos2DZ = posZ;
}

void EntityZ::setSprite2DZ(char c)
{
	this->sprite2DZ = c;
}

void EntityZ::updateZ() {
	//TODO
}

EntityZ::EntityZ()
{
	
}

EntityZ::EntityZ(char sprite2DZ, const COORD& pos2dz): EntityZ()
{
	this->sprite2DZ = sprite2DZ;
	this->pos2DZ = pos2dz;
}


EntityZ::~EntityZ()
= default;
