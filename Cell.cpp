#include "Cell.h"
#include "Ocean.h"

Coordinate Cell::getNeighCoord(Cell* item)
{
	unsigned rand_world_side = rand() % 3 + 0;	

	switch (rand_world_side)
	{
		case 0:
		{
			Coordinate temp(_owner.north(item).getX(), _owner.north(item).getY());

			return temp;
			break;
		}
		case 1:
		{
			Coordinate temp(_owner.south(item).getX(), _owner.south(item).getY());

			return temp;
			break;
		}
		case 2:
		{
			Coordinate temp(_owner.east(item).getX(), _owner.east(item).getY());

			return temp;
			break;
		}
		case 3:
		{
			Coordinate temp(_owner.west(item).getX(), _owner.west(item).getY());

			return temp;
			break;
		}
		default:
		{
			break;
		}
	}
	
}

void Cell::assignCellAt(Coordinate a_coord, Cell* a_cell)
{
	_owner.setCell(a_coord, a_cell);
}

void Cell::reproduce(Coordinate a_coord, Cell* a_cell)
{
	_owner.setCell(a_coord, a_cell);
}

Cell* Cell::getCellAt(Coordinate a_coord)
{
	return _owner.getCell(a_coord);
}

Cell* Cell::getPreyCoord(Cell* item)
{
	Cell* temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
		
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());

	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
	}

	return nullptr;
}
 