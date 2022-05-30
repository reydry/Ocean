#include <iostream>

#include "Ocean.h"

using namespace std; // TODO: pascal casing

int main()
{
	Ocean* ocean = new Ocean();
	ocean->initialize();
	ocean->run();

	return 0;
}