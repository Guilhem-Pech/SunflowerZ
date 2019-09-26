#pragma once
#include <Windows.h>

class ProjectZ
{
public:

	COORD posProjectilZ{}; //coordinate for displaying the projectil
	int dirZ{}; //direction [0;7] with 0 being right and +1 being trigonometric rotation
	int speedZ{};
	int massZ{};
	int damageZ{};
	int radiusZ{};

	COORD travel();

	void updateZ();

	ProjectZ();
	~ProjectZ();
};

class BeamZ : public ProjectZ
{
public:
	BeamZ();
	~BeamZ();
};

