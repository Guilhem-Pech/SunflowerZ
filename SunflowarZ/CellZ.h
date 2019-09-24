#pragma once
#include <Windows.h>


class CellZ
{
private:
	COORD pos;
	char sprite;
	WORD attributes;
	
public:
	CellZ(const COORD &position,const WORD &attributes ,const char & sprite);
	void setSprite(const char &c);
	void setAttributes(const WORD &c);
	void setPos(const COORD &newCoordinates);
	COORD getPos() const;
	
	~CellZ();
};

