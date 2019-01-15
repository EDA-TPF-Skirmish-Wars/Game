#include "classUnit.h"
#include "classAPC.h"


Unit::Unit(units_d unitClass, Position pos, teams_d owner)
{
	this->unitClass = unitClass;
	this->owner = owner;
	this->pos = pos;
	healthPoints = HP_MAX;
	status = IDLE;

	switch (unitClass)
	{
	case INFANTRY:
	{
		type = typeInfantry;

		firePowerRatingFOOT = fpFOOTinfantry;
		firePowerRatingTREAD = fpTREADinfantry;
		firePowerRatingWHEEL = fpWHEELinfantry;

		firePowerReducedFOOT = fpReducedFOOTinfantry;
		firePowerReducedTREAD = fpReducedTREADinfantry;
		firePowerReducedWHEEL = fpReducedWHEELinfantry;

		mcGrass = mcGrassInfantry;
		mcRoad = mcRoadInfantry;
		mcForest = mcForestInfantry;
		mcRiver = mcRiverInfantry;
		mcHill = mcHillInfantry;

		rangeMax = rangeMaxInfantry;
		rangeMin = rangeMinInfantry;

		defense = defenceInfantry;
		movingPoints = mpInfantry;
		maxMP = mpInfantry;

		unitCost = costInfantry;
	}break;
	case MECH:
	{
		type = typeMech;

		firePowerRatingFOOT = fpFOOTmech;
		firePowerRatingTREAD = fpTREADmech;
		firePowerRatingWHEEL = fpWHEELmech;

		firePowerReducedFOOT = fpReducedFOOTmech;
		firePowerReducedTREAD = fpReducedTREADmech;
		firePowerReducedWHEEL = fpReducedWHEELmech;

		mcGrass = mcGrassMech;
		mcRoad = mcRoadMech;
		mcForest = mcForestMech;
		mcRiver = mcRiverMech;
		mcHill = mcHillMech;

		rangeMax = rangeMaxMech;
		rangeMin = rangeMinMech;

		defense = defenceMech;
		movingPoints = mpMech;
		maxMP = mpMech;

		unitCost = costMech;
	}break;
	case RECON:
	{
		type = typeRecon;

		firePowerRatingFOOT = fpFOOTrecon;
		firePowerRatingTREAD = fpTREADrecon;
		firePowerRatingWHEEL = fpWHEELrecon;

		firePowerReducedFOOT = fpReducedFOOTrecon;
		firePowerReducedTREAD = fpReducedTREADrecon;
		firePowerReducedWHEEL = fpReducedWHEELrecon;

		mcGrass = mcGrassRecon;
		mcRoad = mcRoadRecon;
		mcForest = mcForestRecon;
		mcRiver = mcRiverRecon;
		mcHill = mcHillRecon;

		rangeMax = rangeMaxRecon;
		rangeMin = rangeMinRecon;

		defense = defenceRecon;
		movingPoints = mpRecon;
		maxMP = mpRecon;

		unitCost = costRecon;
	}break;
	case TANK:
	{
		type = typeTank;

		firePowerRatingFOOT = fpFOOTtank;
		firePowerRatingTREAD = fpTREADtank;
		firePowerRatingWHEEL = fpWHEELtank;

		firePowerReducedFOOT = fpReducedFOOTtank;
		firePowerReducedTREAD = fpReducedTREADtank;
		firePowerReducedWHEEL = fpReducedWHEELtank;

		mcGrass = mcGrassTank;
		mcRoad = mcRoadTank;
		mcForest = mcForestTank;
		mcRiver = mcRiverTank;
		mcHill = mcHillTank;

		rangeMax = rangeMaxTank;
		rangeMin = rangeMinTank;

		defense = defenceTank;
		movingPoints = mpTank;
		maxMP = mpTank;

		unitCost = costTank;
	}break;
	case MEDTANK:
	{
		type = typeMedTank;

		firePowerRatingFOOT = fpFOOTmedtank;
		firePowerRatingTREAD = fpTREADmedtank;
		firePowerRatingWHEEL = fpWHEELmedtank;

		firePowerReducedFOOT = fpReducedFOOTmedtank;
		firePowerReducedTREAD = fpReducedTREADmedtank;
		firePowerReducedWHEEL = fpReducedWHEELmedtank;

		mcGrass = mcGrassMedTank;
		mcRoad = mcRoadMedTank;
		mcForest = mcForestMedTank;
		mcRiver = mcRiverMedTank;
		mcHill = mcHillMedTank;

		rangeMax = rangeMaxMedTank;
		rangeMin = rangeMinMedTank;

		defense = defenceMedTank;
		movingPoints = mpMedTank;
		maxMP = mpMedTank;

		unitCost = costMedTank;
	}break;
	case APC:
	{
		type = typeAPC;

		firePowerRatingFOOT = fpFOOTapc;
		firePowerRatingTREAD = fpTREADapc;
		firePowerRatingWHEEL = fpWHEELapc;

		firePowerReducedFOOT = fpReducedFOOTapc;
		firePowerReducedTREAD = fpReducedTREADapc;
		firePowerReducedWHEEL = fpReducedWHEELapc;

		mcGrass = mcGrassApc;
		mcRoad = mcRoadApc;
		mcForest = mcForestApc;
		mcRiver = mcRiverApc;
		mcHill = mcHillApc;

		rangeMax = rangeMaxApc;
		rangeMin = rangeMinApc;

		defense = defenceApc;
		movingPoints = mpApc;
		maxMP = mpApc;

		unitCost = costApc;
	}break;
	case ARTILLERY:
	{
		type = typeArtillery;

		firePowerRatingFOOT = fpFOOTartillery;
		firePowerRatingTREAD = fpTREADartillery;
		firePowerRatingWHEEL = fpWHEELartillery;

		firePowerReducedFOOT = fpReducedFOOTartillery;
		firePowerReducedTREAD = fpReducedTREADartillery;
		firePowerReducedWHEEL = fpReducedWHEELartillery;

		mcGrass = mcGrassArtillery;
		mcRoad = mcRoadArtillery;
		mcForest = mcForestArtillery;
		mcRiver = mcRiverArtillery;
		mcHill = mcHillArtillery;

		rangeMax = rangeMaxArtillery;
		rangeMin = rangeMinArtillery;

		defense = defenceArtillery;
		movingPoints = mpArtillery;
		maxMP = mpArtillery;

		unitCost = costArtillery;
	}break;
	case ANTIAIR:
	{
		type = typeAntiAir;

		firePowerRatingFOOT = fpFOOTantiair;
		firePowerRatingTREAD = fpTREADantiair;
		firePowerRatingWHEEL = fpWHEELantiair;

		firePowerReducedFOOT = fpReducedFOOTantiair;
		firePowerReducedTREAD = fpReducedTREADantiair;
		firePowerReducedWHEEL = fpReducedWHEELantiair;

		mcGrass = mcGrassAntiAir;
		mcRoad = mcRoadAntiAir;
		mcForest = mcForestAntiAir;
		mcRiver = mcRiverAntiAir;
		mcHill = mcHillAntiAir;

		rangeMax = rangeMaxAntiAir;
		rangeMin = rangeMinAntiAir;

		defense = defenceAntiAir;
		movingPoints = mpAntiAir;
		maxMP = mpAntiAir;

		unitCost = costAntiAir;
	}break;
	default:
		break;
	}
}
Unit::~Unit()
{}

unsigned int Unit::getCost()
{
	return unitCost;
}
unsigned int Unit::getCost(units_d unitClass)
{
	switch (unitClass)
	{
	case INFANTRY:
	{
		return costInfantry;
	}break;
	case TANK:
	{
		return costTank;
	}break;
	case MEDTANK:
	{
		return costMedTank;
	}break;
	case RECON:
	{
		return costRecon;
	}break;
	case APC:
	{
		return costApc;
	}break;
	case ANTIAIR:
	{
		return costAntiAir;
	}break;
	case ARTILLERY:
	{
		return costArtillery;
	}break;
	case ROCKET:
	{
		return costRocket;
	}break;
	}
}
unsigned int Unit::getActualMP()
{
	return movingPoints;
}
unsigned int Unit::getMaxMps()
{
	return maxMP;
}
unsigned int Unit::getDefense()
{
	return defense;
}
unsigned int Unit::getHP()
{
	return healthPoints;
}
unsigned int Unit::getTerrainMC(terrains_d type)
{
	switch (type)
	{
	case HILL:
	{
		return mcHill;
	}break;
	case FOREST:
	{
		return mcForest;
	}break;
	case ROAD:
	{
		return mcRoad;
	}break;
	case RIVER:
	{
		return mcRiver;
	}break;
	case GRASS:
	{
		return mcGrass;
	}break;
	}
}

unsigned int Unit::getAttackFP(unit_type TargetUnitType, bool Isreduced)
{
	if (Isreduced)
	{
		switch (TargetUnitType)
		{
		case FOOT:
		{
			return firePowerReducedFOOT;
		}break;
		case WHEEL:
		{
			return firePowerReducedWHEEL;
		}break;
		case TREAD:
		{
			return firePowerReducedTREAD;
		}break;
		}
	}
	else
	{
		switch (TargetUnitType)
		{
		case FOOT:
		{
			return firePowerRatingFOOT
		}break;
		case WHEEL:
		{
			return firePowerRatingWHEEL;
		}break;
		case TREAD:
		{
			return firePowerRatingTREAD;
		}break;
		}
	}

}
Position Unit::getPosition()
{
	return pos;
}
teams_d Unit::getTeam()
{
	return owner;
}
units_d Unit::getUnitClass()
{
	return unitClass;
}
unit_type Unit::getType()
{
	return type;
}
unsigned int Unit::getMaxRange()
{
	return rangeMax;
}
unsigned int Unit::getMinRange()
{
	return rangeMin;
}


bool Unit::isReduced()
{
	return (healthPoints <= HP_REDUCED && healthPoints > 0);
}
bool Unit::isAlive()
{
	return (healthPoints > 0);
}

Unit* Unit::boughtUnit(units_d unitClass, Position position, teams_d color)
{
	Unit * newUnit = nullptr;
	switch (unitClass)
	{
	case INFANTRY:
	{
		newUnit = new Unit(INFANTRY, position, color);	
	}break;
	case TANK:
	{
		newUnit = new Unit(TANK, position, color);
	}break;
	case MEDTANK:
	{
		newUnit = new Unit(MEDTANK, position, color);
	}break;
	case RECON:
	{
		newUnit = new Unit(RECON, position, color);
	}break;
	case APC:
	{
		newUnit = new Unit(APC, position, color);
	}break;
	case ANTIAIR:
	{
		newUnit = new Unit(ANTIAIR, position, color);
	}break;
	case ARTILLERY:
	{
		newUnit = new Unit(ARTILLERY, position, color);
	}break;
	case ROCKET:
	{
		newUnit = new Unit(ROCKET, position, color);
	}break;
	}

	return newUnit;
}

void Unit::endTurn()
{
	resetMP();
	status = IDLE;
}

void Unit::resetMP()
{
	movingPoints = maxMP;
}

void Unit::blockUnit()
{
	status = BLOCKED;
}

void Unit::heal()
{
	healthPoints = healthPoints + HEAL_HP;
	if (healthPoints > HP_MAX)
		healthPoints = HP_MAX;
	if (unitClass == APC)
	{
		((classAPC*) this)->healLoadedUnits();
	}

}

bool Unit::ifAPCisFull()
{
	if (isItAPC() && ((classAPC *)this)->isFull())
		return true;
	else
		return false;
}

bool Unit::isItAPC()
{
	if (unitClass == APC)
		return true;
	else
		return false;
}

int Unit::attackDamage(int initdamage, unsigned dice, terrains_d enemyTerrain, buildings_d Building)
{
	int damage;
	unsigned int col, row;
	row = initdamage + 3; //para que arranque en cero el indice
						  //HILL/HQ, CITY, FOREST, GRASS, ROAD/RIVER
	switch (enemyTerrain)
	{
	case HILL:
	{
		col = 0;
	}break;
	case FOREST:
	{
		col = 2;
	}break;
	case ROAD:
	{
		col = 4;
	}break;
	case RIVER:
	{
		col = 4;
	}break;
	case GRASS:
	{
		col = 3;
	}break;
	}

	if (Building == HQ)
		col = 0;
	else
		col = 1;

	damage = terrainDefenceModifieres[row][col].terrainMod;

	if (dice <= terrainDefenceModifieres[row][col].dice)
		damage++;
	return damage;
}
list<Position> Unit::getPossibleAttacks(Position position, unsigned int mps)
{
	list<Position> posibleAttacks;

	for (unsigned int i = 0; i < BOARD_HEIGHT; i++) {
		for (unsigned int j = 0; j < BOARD_WIDTH; i++) {

			Position pos(i, j);
			unsigned int dist = abs(pos.row - this->pos.row) + abs(pos.column - this->pos.column);
			if(dist >= rangeMin && dist <= rangeMax && )
		}
	}

}


/////////////////////////FALTA////////////////////////////

bool move();
bool attack(); //devolver el daño hecho uso función attackDamage()
bool capture();
bool loadAPC();
bool unloadAPC();

void ChangeUnitPosition();


bool IsValidMove(); //VER mp!!! que devuelva los que necesita
bool IsValidAttack();



int attackTargetDefenceRating();	//obtengo el defence rating de la unidad que estoy atacando

int attackWhatTypeIsUnit();//obtengo que tipo de unidad es el que estoy atacando
int attackWhatUnitIs(); //que tipo de unit estoy atacando




void getPossibleMoves(list<Position>& moves, Position start, Position curr, unsigned int mps);




