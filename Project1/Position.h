#pragma once

class Position
{
public:
	Position();
	Position(unsigned int row, unsigned int column);

	unsigned int row;
	unsigned int column;
};