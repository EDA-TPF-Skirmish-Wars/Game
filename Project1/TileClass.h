#pragma once
#include "classUnits.h"
#include "classBuilding.h"
#include "Position.h"
#include <string>
#include <iostream>
#include <vector>

//en get unit y get building NO DEVOLVER PUNTERO, solo clase
//ver de si necesito hacer dos funciones, una que devuelva ptr (getUnitPtr) y otra objeto (getUnit)

using namespace std;


typedef enum { GRASS, ROAD, FOREST, RIVER, HILL, BUILDING}terrains_d;

typedef enum { HOST, OPPONENT, NEUTRAL }player_d;

typedef enum {FOG_OFF, FOG_ON}fog_status;

typedef enum { SELECT_OFF, SELECT_ON }select_status;


class Tile
{
public:
	friend class Map;
	
	Tile(Position pos, terrains_d type, bool fog); //puntero unit y building NULL, fog true
	~Tile(); //borrar punteros

	Position getPosition();
	terrains_d getTypeOfTerrain();
	bool getFog();
	Unit * getUnit();
	Building * getBuilding();

	void clearFog();
	
	bool UnitOnTop();
	bool BuildingOnTop();

	bool setUnit(Unit * unitOnTop); //ver si hay building de capturar o de curar la unit
	bool setBuilding(Building * buildingOnTop);
	void setTile(Position pos, terrains_d type, bool fog);

	void removeUnit(); //ver si hay unit y building dejar de capturar

	void selectTile();
	void unselectTile();
	
private:
	Position pos;
	terrains_d type;
	Unit * unitOnTop;
	Building * buildingOnTop;
	bool fog; 
	bool select_status;
	string imagePath;
};