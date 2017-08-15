#include <iostream>
#include "Abstract.hpp"
#include <vector>
int main()
{
	std::vector<Geometry*> items;

	items.push_back(new Box("Box 1", 1, 2, 3));
	items.push_back(new Box("Box 2", 2, 3, 4));
	items.push_back(new Sphere("Sphere 1", 5));
	items.push_back(new Sphere("Sphere 2", 6));

	for (unsigned int i =0; i < items.size(); i++)
	{
		report(items[i]);
		delete items[i];
		items[i] = nullptr;

	}

	return 0;
	
}