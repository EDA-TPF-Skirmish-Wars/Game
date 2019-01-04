#pragma once

#include "TileClass.h"
#include "unitInfo.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

class Map
{
public:
	Map(VER QUE LE PASO);
	~Map();

	terrains_d getTerrain(Position pos); //sin puntero
	Unit getUnit(Position pos);
	Building getBuilding(Position pos);
	unit_types_d getUnitType(Position pos);
	player_d getUnitPlayer(Position p);
	player_d getBuildingPlayer(Position p);
	bool getFog(Position pos);

	int getTeam();
	int getEnemyTeam();

	bool IsUnitOnTop(Position pos);
	bool IsBuildingOnTop(Position pos);
	bool IsPositionInsideBoard(Position pos);
	
	void setTerrains(vector<Tile> newTile);
	void setTeam();
	void setEnemyTeam(int enemyTeam);

	void addTerrain(Terrain newTerrain);
	void addBuilding(Building newBuilding);
	void addUnit(Unit newUnit);
	
	
	addTile 
	addUnit

	killUnit
	select
	unselect
	 
	
	options_s getOptions(int x, int y);



protected:
	bool isThereAnEnemyThere(int x, int y, int enemyTeam);
	bool isThereAFriendUnitThere(int x, int y);
	bool isThereAFriendBuildingThere(int x, int y);
	
	std::vector<Terrain> terrains;

private:

	Tile * board[BOARD_HEIGHT][BOARD_WIDTH]; //para agregar tile uso la position
	int team;
	int enemyTeam
};

