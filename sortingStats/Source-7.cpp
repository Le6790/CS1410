#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;


void bubbleSort(vector<int> &number, int &CountS, int &CountC) {
	int size = number.size();
	int temp;
	// This sets the number in the vector to a number from 0 - size
/*	for (int i = 0; i < size; i++) {
		number[i] = i;
	}*/
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (number[i] > number[j]) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
				CountS++;
			}
			CountC++;
		}
	}

}
void selectionSort(vector<int> &number, int &countS, int &countC) {
	int size = number.size();
	int temp;
	int minIndex;
	int minVal;
	for (int i = 0; i < size - 1; ++i) {
		minIndex = i;
		minVal = number[i];
		for (int j = i+1; j < size; ++j) {
			if (number[j] < minVal) {
				minVal = number[j];
				minIndex = j;
			}
			countC++;
		}
		countS++;
		number[minIndex] = number[i];
		number[i] = minVal;
	}
}

int main() {
	int random = rand();
	int num = 10;
	int countS = 0;
	int countC = 0; 
	vector<int> number;
	vector<int> number2;

	vector<int> Bswaps;
	vector<int> Bcompares;

	vector<int> Sswaps;
	vector<int> Scompares;
	//adds random integers into vector
	for (int i = 0; i < num; i++) {
		int temp = rand();
		number2.push_back(temp);
		number.push_back(temp);
	}
	cout << "Bubble Sort: " << endl;
	bubbleSort(number, countS, countC);
	for (int i = 0; i < number.size(); ++i) {
		cout << number[i] << endl;
	} 
	cout << "-------------------------" << endl;
	cout << "Selection sort: " << endl;
	selectionSort(number2, countS, countC);
	for (int j = 0; j < number.size(); ++j) {
		cout << number[j] << endl;
	}
	cout << "-------------------------" << endl;
	for (int i = 100; i <= 1000; i += 100) {
		number.clear();
		number2.clear();
		for (int j = 0; j < i; ++j) {
			int temp = rand();
			number2.push_back(temp);
			number.push_back(temp);
		}
		countC = 0;
		countS = 0;
		bubbleSort(number, countS, countC);
		Bswaps.push_back(countS);
		Bcompares.push_back(countC);
		
		countC = 0;
		countS = 0;
		selectionSort(number2, countS, countC);
		Sswaps.push_back(countS);
		Scompares.push_back(countC);
	}
	cout << "Compares: " << endl;
	cout << "Size:  Bubble: Selection: " << endl;

	int j = 0;
	for (int i = 100; i <= 1000; i += 100) {
		cout << i << "   " << Bcompares[j] << "   " << Scompares[j] << endl;
		j++;
	}
	cout << "-------------------------" << endl;
	cout << "Swaps: " << endl;
	cout << "Size:  Bubble: Selection: " << endl;

	int k = 0;
	for (int i = 100; i <= 1000; i += 100) {
		cout << i << "   " << Bswaps[k] << "   " << Sswaps[k] << endl;
		k++;
	}

	return 0;
} 
/* ====Debug Outputs Begin==== 
Bubble Sort: 
5705
6334
11478
15724
18467
19169
24464
26500
26962
29358
-------------------------
Selection sort: 
5705
6334
11478
15724
18467
19169
24464
26500
26962
29358
-------------------------
Compares: 
Size:  Bubble: Selection: 
100   4950   4950
200   19900   19900
300   44850   44850
400   79800   79800
500   124750   124750
600   179700   179700
700   244650   244650
800   319600   319600
900   404550   404550
1000   499500   499500
-------------------------
Swaps: 
Size:  Bubble: Selection: 
100   2348   99
200   9855   199
300   22402   299
400   40368   399
500   64614   499
600   84416   599
700   125956   699
800   161042   799
900   199536   899
1000   249065   999
 
====Debug Outputs End==== */  
 

