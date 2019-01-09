#pragma once
#include "unitsInfo.h"
#include "classMap.h"
#include <list>

#define HEAL_HP 2

typedef enum { IDLE, SELECTED, ATTACKING, MOVING, BLOCKED, DEAD } unit_state_d; // estados dependiendo en si pueden ser clickeadas o no

class Unit {
public:

	Unit(units_d unitClass, Position pos, teams_d owner);
	~Unit();

	static unsigned int getCost(units_d class);
	unsigned int getActualMP();
	unsigned int getMaxMps(units_d type);
	unsigned int getDefense();
	unsigned int getHP();
	unsigned int getTerrainMC(units_d Utype, terrains_d type);
	unsigned int getAttackFP(units_d type, unit_type TargetUnitType, bool Isreduced);
	Position getPosition();
	teams_d getTeam();
	units_d getUnitClass();
	unit_type getType();
	unsigned int getRange(units_d type, unsigned int& minRange, unsigned int& maxRange);


	bool isReduced();
	bool isAlive();

	void heal();
	bool move();
	bool attack(); //devolver el daño hecho uso función attackDamage()
	bool capture();
	bool loadAPC();
	bool unloadAPC();

	void ChangeUnitPosition();
	static Unit boughtUnit(units_d type, Position position, teams_d color);

	bool IsValidMove(); //VER mp!!! que devuelva los que necesita
	bool IsValidAttack();

	int attackDamage(); //Devuelve el valor que le reducio la unidad
	int attackTerrainModTable(); //tabla de trrain modifier para calcular el daño hecho
	int attackDiceMod(); // devuelve el valor que modifica el dado con el initial damage
	int attackTargetDefenceRating();	//obtengo el defence rating de la unidad que estoy atacando

	int attackWhatTypeIsUnit();//obtengo que tipo de unidad es el que estoy atacando
	int attackWhatUnitIs(); //que tipo de unit estoy atacando

	void blockUnit(); //ya no la puedo usar mas durante el turno
	void endTurn(); //reseteo variables necesarias
	void resetMP();
	
	void getPossibleMoves(list<Position>& moves, Position start, Position curr, unsigned int mps);
	void getPossibleAttacks(list<Position>& attacks, Position position, unsigned int mps);

	bool isItAPC();
	bool ifAPCisFull();
	bool APCUnloadUnit();


private:
	units_d unitClass;
	unit_type type;
	teams_d owner;
	Position pos;

	unsigned int movingPoints;
	unsigned int healthPoints;

	unsigned int unitCost;

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

