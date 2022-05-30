
#include "Cell.h"
#include "Ocean.h"
#include <iostream>
#include "OceanConsoleViewer.h"

using namespace std;

OceanConsoleViewer::~OceanConsoleViewer()
{
}

void OceanConsoleViewer::display(char _image)
{
    cout << _image;
}

void OceanConsoleViewer::displayBorder(unsigned _NumCols)
{
    for (unsigned col = 0; col < _NumCols; col++)
    {
        cout << "*";
    }
    cout << "\n";
}

void OceanConsoleViewer::displayStats(unsigned _num_obstacles, unsigned _num_prey, unsigned _num_predators, unsigned _iteration, unsigned _num_cols)
{
    cout << "\n\n";
    cout << "Iteration: " << ++_iteration;
    cout << "Obstacles: " << _num_obstacles;
    cout << "Prey: " << _num_prey;
    cout << "Predators: " << _num_predators << "\n";
    cout.flush();
    displayBorder(_num_cols);
}

void OceanConsoleViewer::displayCells(unsigned _num_rows, unsigned _num_cols, Ocean* _owner)
{
   // Cell* _cell;
    for (unsigned row = 0; row < _num_rows; row++)
    {
        for (unsigned col = 0; col < _num_cols; col++)
        {
            //_cell = _owner->getCell(row, col);
            if (_owner->getCell(row, col) == nullptr)
            {
                display(default_image);
            }
            else
            {
                display(_owner->getCell(row, col)->getImage());
            }
        }
        cout << "\n";
    }
}
