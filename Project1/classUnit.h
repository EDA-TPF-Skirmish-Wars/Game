#pragma once
#include "unitsInfo.h"
#include "classMap.h"
#include <list>

typedef enum { IDLE, SELECTED, ATTACKING, MOVING, BLOCKED, DEAD } unit_state_d; // estados dependiendo en si pueden ser clickeadas o no

class Unit {
public:

	Unit(units_d unitClass, Position pos, teams_d owner);
	~Unit();

	static unsigned int getCost(units_d unitClass);
	unsigned int getCost();
	unsigned int getActualMP();
	unsigned int getMaxMps();
	unsigned int getDefense();
	unsigned int getHP();
	unsigned int getTerrainMC(terrains_d type);
	unsigned int getAttackFP(unit_type TargetUnitType, bool Isreduced);
	Position getPosition();
	teams_d getTeam();
	units_d getUnitClass();
	unit_type getType();
	unsigned int getMaxRange();
	unsigned int getMinRange();


	bool isReduced();
	bool isAlive();

	void heal();
	bool move();
	bool attack(); //devolver el daño hecho uso función attackDamage()
	bool capture();
	bool loadAPC();
	bool unloadAPC();

	void ChangeUnitPosition(Position where);
	static Unit* boughtUnit(units_d unitClass, Position position, teams_d color);

	bool IsValidMove(); //VER mp!!! que devuelva los que necesita
	bool IsValidAttack();

	int attackDamage(int initdamage, unsigned dice, terrains_d enemyTerrain, buildings_d isThereBuilding); //Devuelve el fp con el que ataca la unuidad( le paso el damage con el defence ya restado)
	int attackTargetDefenceRating();//obtengo el defence rating de la unidad que estoy atacando
	int attackTerrainModTable(); //tabla de trrain modifier
	int attackTerrainMod(); // devuelve el valor que modifica el dado con el initial damage
	int attackWhatTypeIsUnit();//obtengo que tipo de unidad es el que estoy atacando
	int attackWhatUnitIs(); //que tipo de unit estoy atacando

	void blockUnit(); //ya no la puedo usar mas durante el turno
	void endTurn(); //reseteo variables necesarias
	void resetMP();
	
	void getPossibleMoves(list<Position>& moves, Position start, Position curr, unsigned int mps);
	list<Position> getPossibleAttacks(Position position, unsigned int mps);

	bool isItAPC();
	bool ifAPCisFull();


private:
	units_d unitClass;
	unit_type type;
	teams_d owner;
	Position pos;

	static unsigned int maxMP;
	unsigned int movingPoints;
	unsigned int healthPoints;

	static unsigned int unitCost;

	unsigned int rangeMax;
	unsigned int rangeMin;

	unsigned int defense;

	unsigned int mcGrass;
	unsigned int mcRoad;
	unsigned int mcForest;
	unsigned int mcRiver;
	unsigned int mcHill;

	unsigned int firePowerRatingFOOT;
	unsigned int firePowerRatingTREAD;
	unsigned int firePowerRatingWHEEL;

	unsigned int firePowerReducedFOOT;
	unsigned int firePowerReducedTREAD;
	unsigned int firePowerReducedWHEEL;

	unit_state_d status;

};

