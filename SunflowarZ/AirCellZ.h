#pragma once
#include "CellZ.h"
class AirCellZ : public CellZ
{
private:
public:
	AirCellZ(const COORD &position);
	string getTypeName() override;
};

