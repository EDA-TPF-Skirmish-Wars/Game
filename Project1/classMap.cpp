#include "classMap.h"

Map::Map()
{
	for (unsigned int i = 0; i < BOARD_HEIGHT; i++) {
		for (unsigned int j = 0; j < BOARD_WIDTH; j++) {
			board[i][j] = nullptr;
		}
	}
}

Map::~Map()
{
	for (unsigned int i = 0; i < BOARD_HEIGHT; i++) {
		for (unsigned int j = 0; j < BOARD_WIDTH; j++) {
			delete board[i][j];
		}
	}
}

Unit Map::getUnit(Position pos)
{
	return *board[pos.row][pos.column]->unitOnTop;
}

Building Map::getBuilding(Position pos)
{
	return *board[pos.row][pos.column]->buildingOnTop;
}

Building * Map::getBuildingPtr(Position pos)
{
	return board[pos.row][pos.column]->buildingOnTop;
}

Unit * Map::getUnitPtr(Position pos)
{
	return board[pos.row][pos.column]->unitOnTop;
}

unit_type Map::getUnitType(Position pos)
{
	return board[pos.row][pos.column]->unitOnTop->getType();	
}
teams_d Map::getUnitTeam(Position pos)
{
	return board[pos.row][pos.column]->unitOnTop->getTeam();

}
teams_d Map::getBuildingTeam(Position pos)
{
	return board[pos.row][pos.column]->buildingOnTop->getBuildingTeam();
}
bool Map::getFog(Position pos)
{
	return board[pos.row][pos.column]->getFog();
}

terrains_d Map::getTerrain(Position pos)
{
	return board[pos.row][pos.column]->getTypeOfTerrain();
}

teams_d Map::getTeam()
{
	return team;
}
teams_d Map::getEnemyTeam()
{
	return enemyTeam;
}

bool Map::IsUnitOnTop(Position pos)
{
	return board[pos.row][pos.column]->unitOnTop != nullptr;
}
bool Map::IsBuildingOnTop(Position pos)
{
	return board[pos.row][pos.column]->buildingOnTop != nullptr;
}
void Map::setTeam(teams_d team)
{
	this->team = team;
}
void Map::setEnemyTeam(teams_d enemyTeam)
{
	this->enemyTeam = enemyTeam;
}

void Map::addTile(Position pos, terrains_d type, bool fog)
{
	board[pos.row][pos.column] = new Tile(pos, type, fog);
}

bool Map::addBuilding(buildings_d type, teams_d color, Position pos)
{
	if (board[pos.row][pos.column]->buildingOnTop != nullptr)
		return false;
	else
	{
		board[pos.row][pos.column]->buildingOnTop = new Building(type, color, pos);
		return true;
	}
}

bool Map::addUnit(units_d unitClass, Position pos, teams_d owner)
{
	if (board[pos.row][pos.column]->unitOnTop != nullptr)
		return false;
	else
	{
		board[pos.row][pos.column]->unitOnTop = new Unit(unitClass, pos, owner);
		return true;
	}
}

void Map::removeUnit(Position pos)
{
	board[pos.row][pos.column]->removeUnit();
}

void Map::selectTile(Position pos)
{
	board[pos.row][pos.column]->selectTile();
}

void Map::unselectTile(Position pos)
{
	board[pos.row][pos.column]->unselectTile();
}


p_inv_s Map::getPlayerInventory(teams_d color)
{
	p_inv_s temp;
	temp.HQCPoints = 0;
	temp.numberCities = 0;
	temp.numberFactories = 0;
	temp.numberUnits = 0;
	temp.team = color;

	for (unsigned int i = 0; i < BOARD_HEIGHT; i++) {
		for (unsigned int j = 0; j < BOARD_WIDTH; j++) {

			Position pos(i, j);

			if (IsBuildingOnTop(pos)) {
				if (getBuildingTeam(pos) == color)
				{
					switch (board[pos.row][pos.column]->buildingOnTop->getBuildingType)
					{
					case HQ:
					{
						temp.HQCPoints = board[pos.row][pos.column]->buildingOnTop->getCapturePoints();
					} break;
					case FACTORY:
					{
						temp.numberFactories++;
					}break;
					case CITY:
					{
						temp.numberCities++;
					}break;
					default:
						break;
					}
				}
			}

			if (IsUnitOnTop(pos)) {
				if (getUnitTeam(pos) == color) {
					temp.numberUnits++;
				}
			}
		}
	}
	return temp;
}

void Map::clearFog(Position pos)
{
	Position posR(pos.row, pos.column+1);
	Position posL(pos.row, pos.column-1);
	Position posU(pos.row+1, pos.column);
	Position posD(pos.row-1, pos.column);

	board[pos.row][pos.column]->clearFog();

	if(posInMap(posR))
		board[posR.row][posR.column]->clearFog();
	if (posInMap(posL))
		board[posL.row][posL.column]->clearFog();
	if (posInMap(posU))
		board[posU.row][posU.column]->clearFog();
	if (posInMap(posD))
		board[posD.row][posD.column]->clearFog();
}

bool Map::posInMap(Position pos)
{
	if (pos.row < BOARD_HEIGHT && pos.row >= 0 && pos.column < BOARD_WIDTH && pos.column >= 0)
		return true;
	else
		return false;
}

bool Map::buyingAvailable(Position pos)
{
	if (board[pos.row][pos.column]->getBuilding()->getBuildingType() == FACTORY
		&& (board[pos.row][pos.column]->getBuilding()->getBuildingTeam == team))
		return true;
	else
		return false;
}
		

bool Map::loadAvailable(Position pos)
{
	if (IsUnitOnTop(pos) && getUnitPtr(pos)->getUnitClass() == APC)
	{
		classAPC * apc = (classAPC *)getUnitPtr(pos);
		if (apc->canLoad(this->team))
			return true;
		else
			return false;
	}
	return false;
}

bool Map::unloadAvailable(Position pos, Position WhereTo)
{
	if (IsUnitOnTop(pos) && getUnitPtr(pos)->getUnitClass() == APC)
	{
		classAPC * apc = (classAPC *)getUnitPtr(pos);
		if (apc->canUnload(WhereTo))
			return true;
		else
			return false;
	}
	return false;
}



bool Map::captureAvailable(Position pos)
{
	if (IsBuildingOnTop(pos) && (getBuildingTeam(pos) != this->team) && (!IsUnitOnTop(pos)))
		return true;
	else
		return false;
}

void Map::changeUnitPos(Position pos, Position newPos)
{
	if (IsUnitOnTop(newPos) && (getUnitPtr(newPos)->getUnitClass() == APC))
	{
		if (getUnitType(pos) == FOOT && loadAvailable(newPos)) {
			classAPC * apc = (classAPC *)getUnitPtr(newPos);
			apc->loadUnitIfPossible(getUnit(pos), getUnitTeam(pos));
		}

	}
	else
	{
		if (getUnitType(pos) == FOOT && captureAvailable(newPos))
		{
			getBuildingPtr(newPos)->captureBuilding(getUnitTeam(pos), getUnit(pos).isReduced());
		}
		clearFog(newPos);
		board[newPos.row][newPos.column]->setUnit(getUnitPtr(pos));

	}

	removeUnit(pos);
}

///////////////////////LO QUE FALTA//////////////////////////////////



options_s Map::getOptions(Position pos)
{
	options_s tmp;
	tmp.attackDownAvailable = false;
	tmp.attackLeftAvailable = false;
	tmp.attackRightAvailable = false;
	tmp.attackUpAvailable = false;
	tmp.buyAvailable = false;
	tmp.moveDownAvailable = false;
	tmp.moveLeftAvailable = false;
	tmp.moveRightAvailable = false;
	tmp.moveUpAvailable = false;
	tmp.passAvailable = true;
	tmp.captureAvailable = false;
	tmp.canLoad = false;
	tmp.canUnload = false;

	Position temp = pos;

	temp.row++;

	if (IsUnitOnTop(temp) && getUnitTeam(temp) != team)
	{
			tmp.attackUpAvailable = true;
	}
	else 
	{
		tmp.moveUpAvailable = true;
	}
		if (isThereAnEnemyThere(x, y + 1, getEnemyTeam())) {
			tmp.attackDownAvailable = true;
			tmp.moveDownAvailable = false;
		}
		else {
			tmp.attackDownAvailable = false;
			tmp.moveDownAvailable = true;
		}
		if (isThereAnEnemyThere(x - 1, y, getEnemyTeam())) {
			tmp.attackLeftAvailable = true;
			tmp.moveLeftAvailable = false;
		}
		else {
			tmp.attackLeftAvailable = false;
			tmp.moveLeftAvailable = true;
		}
		if (isThereAnEnemyThere(x + 1, y, getEnemyTeam())) {
			tmp.attackRightAvailable = true;
			tmp.moveRightAvailable = false;
		}
		else {
			tmp.attackRightAvailable = false;
			tmp.moveRightAvailable = true;
		}
	}
	else if (isThereAFriendBuildingThere(x, y)) {
		tmp.buyAvailable = true;
	}
	return tmp;
}


}




//movesAvailable

