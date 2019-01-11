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

/////////////////////////FALTA////////////////////////////
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