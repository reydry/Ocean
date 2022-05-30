#pragma once
#include "Ocean.h"

class OceanConsoleViewer
{
public:

    virtual ~OceanConsoleViewer();

    void display(char _image);

    void displayBorder(unsigned _NumCols);

    void displayStats(unsigned _num_obstacles, unsigned _num_prey, unsigned _num_predators, unsigned _iteration, unsigned _num_cols);

    void displayCells(unsigned _numRows, unsigned _numCols, Ocean* _owner);

};

