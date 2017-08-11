#include <iostream>
#include <cstdlib>
#include "bug.h"
#include <vector>

using namespace std;


//TODO:write a function that prints all the contents of the 
//     bug array.  Use Bug::print() for each bug. 

void printBugs(vector<Bug> bugs) {
	for (int i = 0; i < bugs.size(); i++)
		bugs[i].print();
	cout << endl;
}



//TODO:write a function to bubble sort the contents of a
//     bug array based on the mass

//end of TODO

void sortMass(vector<Bug> &bugs, int index[], int size) {
	for (int i = 0; i < size; i++)
		index[i] = i;
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (bugs[index[i]].getMass() > bugs[index[j]].getMass()) {
				int temp = index[i];
				index[i] = index[j];
				index[j] = temp;
			}
}

void sortLegs(vector<Bug> &bugs, int index[], int size) {
	for (int i = 0; i < size; i++)
		index[i] = i;
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (bugs[index[i]].getLegs() > bugs[index[j]].getLegs()) {
				int temp = index[i];
				index[i] = index[j];
				index[j] = temp;
			}
}



int binarySearchByMass(vector<Bug> &bugs, int index[], int size, int mass) {
	int first = 0, last = size - 1;

	while (first <= last) {
		int mid = (first + last) / 2;

		if (bugs[index[mid]].getMass() == mass)
			return index[mid];

		if (bugs[index[mid]].getMass() > mass)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return -1;

}

int main() {
	const int NUMBUGS = 5;
	int pos;
	vector<Bug> bug;
	for (int i = 0; i < NUMBUGS; i++)
		bug.push_back(Bug());

	printBugs(bug);
	cout << "====\n";

	//sort the bugs
	int indexForMass[5];
	sortMass(bug, indexForMass, 5);
	cout << "After sorting by mass: " << endl;
	for (int i = 0; i < bug.size(); i++)
		bug[indexForMass[i]].print();
	cout << endl;

	cout << "====\n";

	//sort the bugs by number of legs
	int indexForLegs[5];
	sortLegs(bug, indexForLegs, 5);
	cout << "After sorting by legs: " << endl;
	for (int i = 0; i < bug.size(); i++)
		bug[indexForLegs[i]].print();
	cout << endl;

	cout << "The original collection: " << endl;
	printBugs(bug);
	cout << "====\n";

	pos = binarySearchByMass(bug, indexForMass, 5, 4);

	if (pos == -1)
		cout << "No butterfly is collected";
	else
		bug[pos].print();


	pos = binarySearchByMass(bug, indexForMass, 5, 4);

	if (pos == -1)
		cout << "No bug with mass of 4 is collected";
	else
		bug[pos].print();

	
	return 0;
}