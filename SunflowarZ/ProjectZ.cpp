#include "pch.h"
#include "ProjectZ.h"



COORD ProjectZ::travel() {
	COORD temp = this->posProjectilZ;
	short y = 1;
	if (this->speedZ = 1) {
		y = -1;
	}
	switch (this->dirZ)
	{
	case 2:
		temp.Y-= y;
		break;
	case 6:
		++temp.Y;
		break;
	case 0:
		++temp.X;
		if (y == -1)
			++temp.Y;
		break;
	case 4:
		--temp.X;
		if (y == -1)
			++temp.Y;
		break;
	case 1:
		++temp.X;
		temp.Y-= y;
		break;
	case 3:
		--temp.X;
		temp.Y -= y;
		break;
	case 7:
		++temp.X;
		++temp.Y;
		break;
	case 5:
		--temp.X;
		++temp.Y;
		break;
	default:
		break;
	}

	return temp;
}

void ProjectZ::updateZ() {
	COORD temp = this->travel();
/*
	if (!gameZ.IsCollisionZ(temp)) { //gameZ is the game manager and collisionZ the collision manager
		this->posProjectilZ = temp;
	}
*/
}

ProjectZ::ProjectZ()
{
}

ProjectZ::~ProjectZ()
{
}

BeamZ::BeamZ() {
	this->damageZ = 70;
	this->radiusZ = 0;
}

BeamZ::~BeamZ() {
}
