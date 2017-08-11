#include<iostream>
#include"BigInteger.h"

using namespace std;
int main() {
	BigInteger val(56742);
	BigInteger str("56742");
	cout << "Big Integer from Int value: " << val << endl;
	cout << "Big Integer from String value: " << str << endl;
	
	// Task 4. Compute 999!
	int a = 1;
	BigInteger B(1);
	cout << "The factorial of 999! is: " << endl;
	for (a = 1; a <= 999; a++) 
	{
		B = multiply(B, a);
	}
	
	cout << B << endl;

	return 0;
}