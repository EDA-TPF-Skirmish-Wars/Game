#pragma once

#include "TileClass.h"
#include "unitInfo.h" //hacer

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10


typedef struct {
	bool attackUpAvailable;
	bool attackDownAvailable;
	bool attackRightAvailable;
	bool attackLeftAvailable;
	bool buyAvailable;
	bool moveUpAvailable;
	bool moveDownAvailable;
	bool moveLeftAvailable;
	bool moveRightAvailable;
	bool passAvailable;

}options_s;

class Map
{
public:
	Map(VER QUE LE PASO); //creo que no hace falta
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

	void addTile(Position pos, terrains_d type, bool fog);
	void addBuilding(Building newBuilding);//cuando tenga los .h de esto te digo que necesito que me pases
	void addUnit(Unit newUnit);

	options_s getOptions(Position pos);
	
	//funciones para completar options_s
	buyingAvailable
	captureAvailable
	movesAvailable


	killUnit
	changeUnitPos
	selectTile
	unselectTile

	void updatePlayerInventory (team, HP_hq, numberFactories, numberCities, numberUnits) //ver donde llevar la cuenta para saber cuando se termina el juego
	 
	
	options_s getOptions(Position pos); //cambia si en esa tile hay solo building, solo unit o hay ambas 

private:
	Tile * board[BOARD_HEIGHT][BOARD_WIDTH]; //para agregar tile uso la position
	int team;
	int enemyTeam;
};

