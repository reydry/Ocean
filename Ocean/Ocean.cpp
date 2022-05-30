#include "Ocean.h"
#include "Obstacle.h"
#include "Prey.h"
#include "Predator.h"
#include <time.h>
#include "windows.h"
//enum
using namespace std;

void Ocean::initialize(void)
{
	//_random.initialize();
	srand(time(NULL));
	_num_rows = max_rows;
	_num_cols = max_cols;
	_size = _num_rows * _num_cols;
	_num_obstacles = random.numOfObs(_size);
	_num_predators = random.numOfPred(_size);
	_num_prey = random.numOfPrey(_size);
	initCells();
}

void Ocean::run(void)
{
	//unsigned num_iterations = default_num_iterations;
	unsigned num_iterations = 10;

	for (unsigned iteration = 0; iteration < num_iterations; iteration++)
	{
		_visitor.clear();

		if (_num_predators > 0 && _num_prey > 0)
		{
			for (unsigned row = 0; row < _num_rows; row++)
			{
				for (unsigned col = 0; col < _num_cols; col++)
				{
					Cell* currentItem = _cells[row][col];

					if (!_visitor.isVisited(_cells[row][col]) && currentItem!=nullptr)
					{
						currentItem->process();
						_visitor.visit(currentItem);
					}
				}
			}
		}
		viewer.displayStats(_num_obstacles, _num_prey, _num_predators, iteration, _num_cols);
		viewer.displayCells(_num_rows, _num_cols, this);
		cout.flush();
		//Sleep(250);
		//system("cls");
	}
	cout << "\n\nEnd of simulation\n";
	cout.flush();
}

void Ocean::setCell(Coordinate& a_coord, Cell* a_cell)
{
	_cells[a_coord.getY()][a_coord.getX()] = a_cell;
}

void Ocean::setPredNum(unsigned num_predators)
{
	_num_predators = num_predators;
}

unsigned Ocean::getNumPred()
{
	return _num_predators;
}

unsigned Ocean::getNumRows()
{
	return _num_rows;
}

unsigned Ocean::getNumCols()
{
	return _num_cols;
}

unsigned Ocean::getNumPrey()
{
	return _num_prey;
}

void Ocean::setNumPrey(unsigned new_col_prey)
{
	_num_prey = new_col_prey;
}

Cell* Ocean::getCell(unsigned yvalue, unsigned xvalue)
{
	return _cells[yvalue][xvalue];
}

Cell* Ocean::getCell(Coordinate a_coord)
{
	return _cells[a_coord.getY()][a_coord.getX()];
}

void Ocean::cleanGameField(void)
{
	for (unsigned row = 0; row < _num_rows; row++)
	{
		for (unsigned col = 0; col < _num_cols; col++)
		{
			
			_cells[row][col] = nullptr;
			//gof visitor
		}
		//gof flyweight
	}
}

void Ocean::initCells(void)
{
	cleanGameField();
	addObstacles();
	addPredator();
	addPrey();
	viewer.displayStats(_num_obstacles, _num_prey, _num_predators, 0, _num_cols);
	viewer.displayCells(_num_rows, _num_cols, this);
}

void Ocean::displayBorder(void)
{
	cout << '\n';
	for (unsigned col = 0; col < _num_cols; col++)
	{
		cout << "*";
	}
	cout << '\n';
}

void Ocean::displayCells()
{
	for (unsigned row = 0; row < _num_rows; row++)
	{
		for (unsigned col = 0; col < _num_cols; col++)
		{
			if (_cells[row][col]!=nullptr)
			{
				_cells[row][col]->display();
			}
			else
			{
				cout << default_image;
			}
		}
		cout << '\n';
	}
}

void Ocean::displayStats(int iteration)
{
	cout << "\n\n";
	cout << "iteration: " << ++iteration;
	cout << "; obstacles: " << _num_obstacles;
	cout << "; predators: " << _num_predators;
	cout << "; prey: " << _num_prey;
	cout.flush();
	displayBorder();
}

Coordinate Ocean::getClearFieldCoord()
{
	unsigned x, y;
	
	do
	{
		x = rand() % 74 + 0;
		y = rand() % 24 + 0;
	} while (_cells[y][x] != nullptr);
	//empty = _cells[y][x]->getOffset();
	Coordinate empty(x, y);
	delete _cells[y][x];
	
	return empty;
}

void Ocean::addObstacles()
{
	Coordinate empty;
	for (unsigned count = 0; count < _num_obstacles; count++)
	{
		empty = getClearFieldCoord();
		_cells[empty.getY()][empty.getX()] = new Obstacle(this, empty);
	}
}

void Ocean::addPredator()
{
	Coordinate empty;
	for (unsigned count = 0; count < _num_predators; count++)
	{
		empty = getClearFieldCoord();
		_cells[empty.getY()][empty.getX()] = new Predator(this,empty);
	}
}

void Ocean::addPrey()
{
	Coordinate empty;
	for (unsigned count = 0; count < _num_prey; count++)
	{
		empty = getClearFieldCoord();
		_cells[empty.getY()][empty.getX()] = new Prey(this,empty);
	}
}

Coordinate Ocean::north(Cell* center)
{
	
	unsigned yvalue;
	
	yvalue = (center->getOffset().getY() > 0) ? (center->getOffset().getY() - 1) : _num_rows - 1;
	
	Coordinate temp(center->getOffset().getX(), yvalue);

	return temp;
}

Coordinate Ocean::south(Cell* center)
{
	unsigned yvalue;

	yvalue = (center->getOffset().getY() + 1) % _num_rows;

	Coordinate temp(center->getOffset().getX(), yvalue);
	
	return temp;
}

Coordinate Ocean::east(Cell* center)
{
	unsigned xvalue;

	xvalue = (center->getOffset().getX() + 1) % _num_cols;

	Coordinate temp(xvalue, center->getOffset().getY());
	
	return temp;
}

Coordinate Ocean::west(Cell* center)
{
	unsigned xvalue;

	xvalue = (center->getOffset().getX() > 0) ? (center->getOffset().getX() - 1) : _num_cols - 1;

	Coordinate temp(xvalue, center->getOffset().getY());

	return temp;
}

void Ocean::swapCell(Coordinate& to, Coordinate& from, Cell* item)
{
	setCell(to, item);
	_cells[from.getY()][from.getX()]=nullptr;
}
