#pragma once
#include "Position.h"

#define HQ_CP 8
#define FACTORY_CP 4
#define CITY_CP 4

typedef enum buildings { HQ, FACTORY, CITY} buildings_d;
typedef enum { TEAM_RED, TEAM_BLUE, TEAM_GREEN, TEAM_YELLOW, NEUTRAL }teams_d;

class Building {
public:
	Building(buildings_d type, teams_d color, Position pos);//setea los CP seg�n el tipo de building

	buildings_d getBuildingType();
	unsigned int getCapturePoints();
	teams_d getBuildingTeam();
	Position getPosition();

	bool BuildingUnderAttack(); 
	void captureBuilding(teams_d color, bool UnitReduced); //resta los CP dependiendo si la unidad est� reducida y si la termin� de capturar(CP = 0) setea el team correspondiente
	void setToNeutral();
		

private:
	buildings_d type;
	teams_d color;
	unsigned int capturePoints;
	Position pos;
	bool buildingIsFree;
};