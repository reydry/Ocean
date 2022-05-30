#pragma once
#include "Ocean.h"

class OceanConsoleViewer
{
public:

    virtual ~OceanConsoleViewer();
    void display(char);
    void displayBorder(unsigned);
    void displayStats(unsigned, unsigned, unsigned, unsigned, unsigned );
    void displayCells(unsigned, unsigned, Ocean* );

};

