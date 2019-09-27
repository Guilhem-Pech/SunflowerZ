#pragma once
#include "EntityZ.h"
#include <Windows.h>

class ProjectZ : public EntityZ
{
public:

	int dirZ; //direction [0;7] with 0 being right and +1 being trigonometric rotation
	int speedZ;
	int damageZ;
	int radiusZ;

	COORD getNextMove2DZ() override;

	ProjectZ();
	virtual ~ProjectZ();
};


//----AMMUNITION TYPES-------
//---------------------------
class BeamZ : public ProjectZ
{
public:
	BeamZ();
	virtual ~BeamZ();
};

