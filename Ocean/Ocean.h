#pragma once
#include <iostream>
#include "Random.h"
#include "Cell.h"
#include "Constants.h"
#include "Coordinate.h"
#include "Random.h"
#include "Visitor.h"
#include "OceanConsoleViewer.h"
#include "RandomInitializer.h"

class Ocean 
	
{
public:

	Ocean() : _visitor(max_rows* max_cols)
	{
		
	}

	void initialize();
	void run();
	void setCell(Coordinate& a_coord, Cell* a_cell);
	void setPredNum(unsigned num_predators);
	unsigned getNumPred();
	unsigned getNumRows();
	unsigned getNumCols();
	unsigned getNumPrey();
	void setNumPrey(unsigned new_col_prey);
	Cell* getCell(unsigned yvalue, unsigned xvalue);
	Cell* getCell(Coordinate a_coord);
	Coordinate north(Cell*);
	Coordinate south(Cell*);
	Coordinate east(Cell*);
	Coordinate west(Cell*);
	void swapCell(Coordinate&, Coordinate&, Cell*);

protected:

private:

	Coordinate getClearFieldCoord();
	void addObstacles();
	void addPredator();
	void addPrey();

	void displayBorder();
	void displayCells();
	void displayStats(int);

	void cleanGameField();
	void initCells();

	unsigned _size;
	unsigned _num_prey;
	unsigned _num_predators;
	unsigned _num_obstacles;
	unsigned _num_rows;
	unsigned _num_cols;

	RandomInitializer random;
	OceanConsoleViewer viewer;
	Visitor _visitor;
	Cell* _cells[max_rows][max_cols];
};

