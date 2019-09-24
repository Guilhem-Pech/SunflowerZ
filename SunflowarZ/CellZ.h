#pragma once
#include <Windows.h>


enum CellType { air, ground, rock };

class CellZ
{
private:
	COORD pos;
	char sprite;
	WORD attributes;
	CellType typeOfCellZ;
	
public:
	CellZ(const COORD &position, const CellType &typeOfCellZ);
	void setType(const CellType &c);
	bool isType(const CellType &of) const;
	void setPos(const COORD &newCoordinates);
	COORD getPos() const;
	
	~CellZ();
};

