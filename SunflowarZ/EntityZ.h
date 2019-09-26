#pragma once
#include <Windows.h>

class EntityZ
{
public:

	char sprite2DZ; //the sprite of the entity
	COORD pos2DZ; //the 2D position of the entity

	char getSpriteZ(); //retrieve the sprite of the entity
	COORD getPos2DZ(); //retrieve the position of the entity
	void setPos2DZ(COORD posZ); //place the entity at posZ
	virtual COORD getNextMove2DZ()=0; //return the position of where the entity want to go.

	void updateZ();

	EntityZ();
	~EntityZ();
};

