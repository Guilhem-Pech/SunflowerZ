#pragma once
#include "CellZ.h"

class GroundCellZ : public CellZ
{
public:
	GroundCellZ(const COORD& position, const char& sprite = ' ');
	string getTypeName() override;
};
