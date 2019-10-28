#pragma once

#include <vector>

#include "SunflowerZ.h"
#include "CollisionControllerZ.h"
#include "EntityManagerZ.h"
#include "MapZ.h"
#include "NYTimer.h"

#define _WIN32_WINNT 0x0500
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40
#define MENU_HEIGHT 10

class GameZ
{
private:
	HANDLE hOutput;
	CHAR_INFO bufferGame[SCREEN_HEIGHT][SCREEN_WIDTH];
	CHAR_INFO bufferMenu[MENU_HEIGHT][SCREEN_WIDTH];
	
	COORD dwBufferSizeGame = { SCREEN_WIDTH,SCREEN_HEIGHT };
	COORD dwBufferSizeMenu = { SCREEN_WIDTH,MENU_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };

	SMALL_RECT gameView = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
	SMALL_RECT menuView = { 0, SCREEN_HEIGHT, SCREEN_WIDTH - 1, (SCREEN_HEIGHT - 1) + MENU_HEIGHT };
	
	std::unique_ptr<EntityManagerZ> entityManager;
	std::unique_ptr<MapZ> mapZ;
	
	short indexSunflowersP1 = 0;
	short indexSunflowersP2 = 0;
	
	void update() const;
	void calcMap();
	void calcEntities();
	string getCurrentPlayerString() const;
	void calcMenu();
	
	void draw(SMALL_RECT rcRegion, const CHAR_INFO* bufferConsole) const;
	void DrawMenu();
	void showText(int y, std::string text, int color);
	void init();
	GameZ();
	~GameZ();

	EntityManagerZ::owner currentPlayer = EntityManagerZ::owner::player1;
public:
	int nbOfSunflowerZByTeam = 3;	
	NYTimer time;
	static GameZ* get();
	CHAR_INFO* getBuffer();
	const EntityManagerZ& getEntManager() const;
	std::shared_ptr<EntityZ> getCurrentSunflowerZ();
	void changeCurrentSunflowerZ();
	static void writeString(CHAR_INFO bufferConsole[MENU_HEIGHT][SCREEN_WIDTH], string text, COORD begin,
		WORD attribute = 0x0000);
	void run();
	
};

