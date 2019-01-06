#pragma once

#include "TileClass.h"
#include "unitInfo.h" //hacer

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

typedef enum { TEAM_RED, TEAM_BLUE, TEAM_GREEN, TEAM_YELLOW, NO_TEAM }teams_d;


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

	Unit getUnit(Position pos);
	Building getBuilding(Position pos);
	unit_types_d getUnitType(Position pos);
	teams_d getUnitTeam(Position p);
	teams_d getBuildingTeam(Position p);
	bool getFog(Position pos);
	terrains_d getTerrain(Position pos);

	int getTeam(); //del mapa
	int getEnemyTeam();

	bool IsUnitOnTop(Position pos);
	bool IsBuildingOnTop(Position pos);
	bool IsPositionInsideBoard(Position pos);
	
	void setTerrains(vector<Tile> newTile);
	void setTeam();
	void setEnemyTeam(int enemyTeam);

	void addTile(Position pos, terrains_d type, bool fog);
	void addBuilding(buildings_d type, teams_d color, Position pos);
	void addUnit(Unit newUnit);//ver 

	options_s getOptions(Position pos);
	
	//funciones para completar options_s
	bool buyingAvailable(Position pos, teams_d color);
	bool captureAvailable(Position pos, teams_d color);
	//movesAvailable


	void killUnit(Position pos);
	void changeUnitPos(Position pos, Position newPos);
	void selectTile(Position pos);
	void unselectTile(Position pos);

	//void updatePlayerInventory (team, HP_hq, numberFactories, numberCities, numberUnits) //ver donde llevar la cuenta para saber cuando se termina el juego
	 
	options_s getOptions(Position pos); //cambia si en esa tile hay solo building, solo unit o hay ambas 

private:
	Tile * board[BOARD_HEIGHT][BOARD_WIDTH]; //para agregar tile uso la position
	int team;
	int enemyTeam;
};

