#pragma once

#include "classUnit.h"

typedef enum { EMPTY, ONE, FULL } APCstatus;
#define APC_MAX_LOAD 2

class APC : public Units
{
public:
	~APC(); //destruir las unidades que queden aadntro

	bool isFull();	// Si esta lleno el APC devuelve un true

	bool loadUnitIfPossible(Unit unitToLoad); //ver cuando se puede 

	bool unloadingUnitIfPossible(Position pos); //mostrar en pantalla los lufares posibles, sacar unidad del arreglo
	void getPossibleUnloadPos(list<Position> positions);

	bool healLoadedUnits();
	void ChangeUnitsPosition();

private:
	unsigned int NUnitsInside; //cuantifica la cantidad de unidades que tiene adentro 0 1 2
	list<Unit> UnitsLoaded;
	APCstatus status;
};