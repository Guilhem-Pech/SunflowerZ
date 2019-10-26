#pragma once
#include "CellZ.h"

class RockCellZ : public CellZ
{
	
public:
	RockCellZ(const COORD& position, const char& sprite);

	string getTypeName() override;
};
