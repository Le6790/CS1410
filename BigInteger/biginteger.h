#ifndef BIG_INTEGER
#define BIG_INTEGER 1

#include<iostream>
#include<string>
using namespace std;

class BigInteger
{
private:
	char* digits;   // the array storing digits
	int size;       // the current size of digits array
	int nDigits;    // the current number of digits

	void init(int size);
	void copy(const BigInteger &num);

public:
	BigInteger();       // Default constructor
	~BigInteger();       // Default destructor

	BigInteger(int val);     // Initialize a BigInteger with an integer value
	BigInteger(string str);     // Initialize a BigInteger with a string storing a number

	BigInteger(const BigInteger &num); // Copy constructor
	BigInteger& operator=(const BigInteger &num); // Copy assignment operator

	int  numberOfDigits() const { return nDigits; }
	char getDigit(int pos) const;     // get the digit at position pos
	void setDigit(int pos, char digit);     // set the digit at position pos

	void print(bool debug = true);
};

ostream& operator<<(ostream& out, BigInteger num);


ostream& operator<<(ostream& out, BigInteger num);

BigInteger operator+(BigInteger &x, BigInteger &y);
BigInteger operator*(BigInteger &x, int y);
BigInteger multiply(BigInteger &x, int y, int pos = 0);
/*
bool operator==(BigInteger &x, BigInteger &y);
bool operator!=(BigInteger &x, BigInteger &y);
bool operator<(BigInteger &x, BigInteger &y);
bool operator>(BigInteger &x, BigInteger &y);
*/
#endif