#include<iostream>
#include"BigInteger.h"

using namespace std;
int main() {
	BigInteger val(56742);
	BigInteger val2(56742);
	BigInteger mult1(211);
	BigInteger mult2(12345);
	BigInteger str("56742");
	cout << "Big Integer from Int value: " << val << endl;
	cout << "Big Integer from String value: " << str << endl;
	cout << endl;

	cout << "Addition: " << val + val2 << endl;
	cout << "multiplication: " << mult1 * mult2 << endl;
	cout << endl;

//task 3
	//Computing Fibo
	int count = 0;
	int fibo[1000];
	BigInteger fibos(1000);
	//int fib0 = 1;
	BigInteger fib0(1);
	//int fib1 = 1;
	BigInteger fib1(1);
	//int fib;
	BigInteger fib(0);
	for (int i = 2; i < 1000; ++i) {
		fib = fib0 + fib1;
		fib1 = fib0;
		fib0 = fib;
		//cout << fib << " ";
		
	}

	cout << "1000th Fibonacci number is: " << fib << endl;
	cout << endl;
//Testing operator==
	cout << "Testing operator==" << endl;
	if (val2 == val) {
		cout << "val2 == val" << endl;
	}
	 if (val == val2) {
		cout << "val == val2" << endl;
	}
	else {
		cout << "val2 and val are not equal. " << endl;
	}
	cout << endl;
//task5
	cout << "2^1000 < 2^1001: ";
	if (pow(2, 1000) < pow(2,1001)) {
		cout << "True." << endl;
	}
	else {
		cout << "false." << endl;
	}
	cout << "2^1000 * 2^1001 == 2^2001: ";
	if ((pow(2, 1000) * pow(2, 1001)) == pow(2,2001)) {
		cout << "True. " << endl;
	}
	else {
		cout << "False. " << endl;
	}

	return 0;
}
