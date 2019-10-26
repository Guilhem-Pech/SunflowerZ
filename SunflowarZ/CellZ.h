#pragma once
#include <Windows.h>
#include <string>

typedef std::string string;

class CellZ
{
private:
	char sprite;	
	COORD pos{};
protected:
	WORD attributes;
public:
	virtual ~CellZ() = default;
	void setAttribute(WORD word);

	CellZ();
	CellZ(const COORD &position, const char &sprite = ' ');
	void setSprite(const char &c);
	void setPos(const COORD &newCoordinates);
	COORD getPos() const;
	virtual string getTypeName();
	WORD getAttributes() const;
	char getSprite() const;
};

