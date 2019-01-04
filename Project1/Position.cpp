#include "Position.h"

Position::Position()
{
	row = column = 0;
}

Position::Position(unsigned int row, unsigned int column)
{
	this->column = column;
	this->row = row;
}
