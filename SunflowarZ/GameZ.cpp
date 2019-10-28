#include "pch.h"
#include "GameZ.h"
#include <random>

void GameZ::update() const
{
	entityManager->update();
}


void GameZ::calcMap()
{
	const std::vector<std::vector<std::shared_ptr<CellZ>>> & map = mapZ->getCellsZ();

	for (int i(0); i < map.size(); ++i)
	{
		for (int j(0); j < map[i].size(); ++j)
		{
			const std::shared_ptr<CellZ>& cell(map[i][j]);
			bufferGame[j][i].Attributes = cell->getAttributes();
			bufferGame[j][i].Char.AsciiChar = cell->getSprite();
		}
	}
}

void GameZ::calcEntities()
{
	for (const auto& ent : entityManager->getListOfEntitiesZ())
	{
		COORD coord = ent->getPos2DZ();
		bufferGame[coord.X][coord.Y].Char.AsciiChar = ent->sprite2DZ;
		if (ent == getCurrentSunflowerZ())
			bufferGame[coord.X][coord.Y].Attributes = BACKGROUND_RED;
	}
}

string GameZ::getCurrentPlayerString() const
{
	switch (currentPlayer)
	{
	case EntityManagerZ::owner::player1:
		return "Player 1";
	case EntityManagerZ::owner::player2:
		return "Player 2";
	default:
		return "Unknown";
	}
}

void GameZ::calcMenu()
{
	for (auto i(0); i < SCREEN_WIDTH; ++i)
		for (auto j(0); j < MENU_HEIGHT; ++j) {
			bufferMenu[j][i].Attributes = BACKGROUND_RED | BACKGROUND_GREEN;
		}

	writeString(bufferMenu, "SunflowarZ", { 1,1 }, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	writeString(bufferMenu, "Current player: ", { 3,1 }, BACKGROUND_RED | BACKGROUND_GREEN);
	writeString(bufferMenu, getCurrentPlayerString(), { 3,18 }, BACKGROUND_RED | BACKGROUND_BLUE);
}

void GameZ::draw(SMALL_RECT rcRegion, const CHAR_INFO* bufferConsole) const
{
	WriteConsoleOutput(hOutput, bufferConsole, dwBufferSizeGame, dwBufferCoord, &rcRegion);
}

void GameZ::writeString(CHAR_INFO bufferConsole[MENU_HEIGHT][SCREEN_WIDTH], string text, COORD begin,
                        WORD attribute)
{
	for (int i(0); i < text.size(); ++i)
	{
		bufferConsole[begin.X][begin.Y + i].Char.AsciiChar = text[i];
		bufferConsole[begin.X][begin.Y + i].Attributes = attribute;
	}
}

void GameZ::init()
{
	mapZ->fillMap();
	const int sizeY = mapZ->getSizeZ().Y - 1;
	
	for (int i = 0; i < nbOfSunflowerZByTeam; ++i)
	{
		entityManager->spawnAndRegister(EntityZFactoryZ::Sunflower,
			mapZ->getGroundCellZ(rand() % sizeY / 2)->getPos(),
			EntityManagerZ::owner::player1);

	}

	for (int i = 0; i < nbOfSunflowerZByTeam; ++i)
	{
		entityManager->spawnAndRegister(EntityZFactoryZ::Sunflower,
			mapZ->getGroundCellZ((rand() % sizeY / 2) + (sizeY / 2))->getPos(),
			EntityManagerZ::owner::player2);
	}
}

GameZ::GameZ() : hOutput((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE)), entityManager(EntityManagerZ::getInstance())
{
	COORD size = { SCREEN_HEIGHT,SCREEN_WIDTH };
	mapZ = std::make_unique<MapZ>(size);
	
	time.getElapsedMs(true);
	
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	MoveWindow(consoleWindow, 40, 100, 840, 840, TRUE);

	ReadConsoleOutput(hOutput, (CHAR_INFO*)bufferGame, dwBufferSizeGame, dwBufferCoord, &gameView);	
	ReadConsoleOutput(hOutput, (CHAR_INFO*)bufferMenu, dwBufferSizeMenu, dwBufferCoord, &menuView);
}

GameZ::~GameZ(){}

GameZ* GameZ::get()
{
	static GameZ game;
	return &game;
}

CHAR_INFO* GameZ::getBuffer()
{
	return *this->bufferGame;
}

const EntityManagerZ& GameZ::getEntManager() const
{
	return *entityManager;
}

std::shared_ptr<EntityZ> GameZ::getCurrentSunflowerZ()
{
		return entityManager->getListOfPlayersEntitiesZ(currentPlayer).at(
			currentPlayer == EntityManagerZ::owner::player1
				? indexSunflowersP1
				: indexSunflowersP2);
}

void GameZ::changeCurrentSunflowerZ()
{
	if(currentPlayer == EntityManagerZ::owner::player1)
	{
		++indexSunflowersP1;
		if (indexSunflowersP1 >= entityManager->getListOfPlayersEntitiesZ(currentPlayer).size())
			indexSunflowersP1 = 0;
	}
	else
	{
		++indexSunflowersP2;
		if (indexSunflowersP2 >= entityManager->getListOfPlayersEntitiesZ(currentPlayer).size())
			indexSunflowersP2 = 0;
	}
}

void GameZ::run()
{
	init();
	bool exit = false;
	
	EntityManagerZ::owner currentPlayer = EntityManagerZ::owner::player1;
	
	
	for (; !exit;)
	{
		 calcMap();
		calcEntities();
		draw(gameView, (CHAR_INFO*)bufferGame);
		calcMenu();
		draw(menuView, (CHAR_INFO*) bufferMenu);
		update();
				
		if (GetAsyncKeyState(VK_ESCAPE))exit = true;
	}
}
