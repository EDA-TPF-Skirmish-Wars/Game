#pragma once
#include "classUnit.h"


typedef enum playerStatus { PURCHASING, MOV_AND_ATT, IDLE } playerStatus_d;

class Player {
public:
	Player(teams_d color);
	~Player();

	unsigned int getMoney();
	void collectIncome();
	void endTurn();
	void updateInventory(...);

	Unit buyUnit(units_d unitClass, Position pos);
	void captureNewBuilding(buildings_d type);

	void killedUnit(Position pos);
	void lostBuilding(buildings_d type);

	bool hasWon();

private:
	teams_d color;

	unsigned int money;
	unsigned int factories;
	unsigned int cities;
	unsigned int units;

	unsigned int HQCPoints;

	playerStatus_d status;
};