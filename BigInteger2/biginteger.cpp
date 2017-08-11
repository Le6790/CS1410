#include"BigInteger.h"

BigInteger::BigInteger() {
	digits = NULL;      // Default constructor: storing nothing!
	size = 0;
	nDigits = 0;
}

BigInteger::~BigInteger() {
	if (digits != NULL) delete[] digits;
	digits = NULL;
	size = 0;
	nDigits = 0;
}

void BigInteger::init(int size) {
	// Old Task 1. Allocate memory for digits and fill them as zeros
	digits = new char[size];
	for (int i = 0; i < size; ++i) {
		digits[i] = 0;
	}
}

void BigInteger::copy(const BigInteger &num) {
	size = num.size;            // copy digits array size 
	nDigits = num.nDigits;      // copy number of digits
	digits = new char[size];                 // allocate a new digits array with the same size in num
	memcpy(digits, num.digits, size); // copy digits array
}

BigInteger::BigInteger(const BigInteger &num) { // Copy constructor
	copy(num);
}

BigInteger& BigInteger::operator=(const BigInteger &num) {
	if (this != &num) {             // not assign to the same object
		if (digits != NULL) delete[] digits;  // release current digits array
	}
	copy(num);
	return *this;
}

BigInteger::BigInteger(int val) {
	// Old Task 2a. Construct a BigInteger from an int value
	//USE INIT FUNCTION
	int count = 0;
	int temp = val;
	int a;
	//char b;
	while (temp > 0) {
		temp = temp / 10;
		count++;
	}
	init(count);
	this->size = size;
	temp = val;
	int i = 0;
	while(temp>0){
		a=temp % 10;
		temp /= 10;
		setDigit(i,a);
		i++;
	}
}

BigInteger::BigInteger(string str) {
	// Old Task 2b. Construct a BigInteger from a string.
	//USE INIT FUNCTION	
	int temp = str.length();
	init(temp); // allocates the memory
	int j = 0;

	for (int i = str.length()-1; i >= 0; --i) {
		setDigit(j, str[i]-'0');
		j++;
	}
}
char BigInteger::getDigit(int pos) const {
	if (pos >= nDigits)
		return 0;
	else
		return digits[pos];
}

void BigInteger::setDigit(int pos, char digit) {
	if (pos >= size) {       // not enough space 
		int newSize = 1;
		while (newSize <= pos) newSize *= 2; // compute newSize as a power of 2 that is bigger than pos

		char* temp = digits;    // store link to current digits

		digits = new char[newSize]; // allocate a new array
		memset(digits, 0, newSize); // and fill zeros         

		if (temp != NULL)           // if there are some current digits
			memcpy(digits, temp, nDigits);        // copy them
		size = newSize;
	}

	digits[pos] = digit;    // put the given digit at position pos

	if (pos >= nDigits)      // update the number of digits!
		nDigits = pos + 1;
}

BigInteger multiply(BigInteger &x, int y, int pos) {
	int nx = x.numberOfDigits();
	BigInteger z;
	int carry = 0;
	for (int i = 0; i < nx; i++) {
		carry += x.getDigit(i) * y;
		z.setDigit(pos++, carry % 10);
		carry /= 10;
	}
	while (carry > 0) {
		z.setDigit(pos++, carry % 10);
		carry /= 10;
	}
	return z;
}

void BigInteger::print(bool debug) {
	if (digits == NULL)
		cout << '0';
	else
		for (int i = nDigits; --i >= 0;)
			cout << (int)digits[i];
	if (debug)
		printf(" [digits = %x, size = %d, nDigits = %d] ", digits, size, nDigits);
}

ostream& operator<<(ostream& out, BigInteger num) {
	// Old Task 3. Overload operator << to write a BigInteger object to screen
	num.print(false);
	return out;
}

//Task 1
BigInteger operator+( BigInteger &x, BigInteger &y) {
	int ndigits;
	if (y.numberOfDigits() > x.numberOfDigits()) {
		ndigits = y.numberOfDigits();

	}
	else {
		ndigits = x.numberOfDigits();
	}
	BigInteger results;
	int carry = 0;
	for (int i = 0; i < ndigits; i++) {
		carry += x.getDigit(i) + y.getDigit(i);
		results.setDigit(i, carry % 10);
		carry /= 10;

	}
	while (carry > 0) {
		results.setDigit(ndigits, carry % 10);
		carry /= 10;
	}
	return results;
}
//task2
BigInteger operator*(BigInteger &x, BigInteger &y) {
	int ndigits;
	if (y.numberOfDigits() > x.numberOfDigits()) {
		ndigits = y.numberOfDigits();

	}
	else {
		ndigits = x.numberOfDigits();
	}
	BigInteger results(0);
	for (int i = 0; i < ndigits; ++i) {
		BigInteger temp;
		temp = multiply(x , y.getDigit(i));
		for (int j = 0; j < i; ++j) {
			temp = multiply(temp, 10);
		}
	 results = results + temp;
	}
	return results;
}

//Task 4
bool operator>(BigInteger &x, BigInteger &y) {

	if (x.numberOfDigits() == y.numberOfDigits()) {
		for (int i = x.numberOfDigits() - 1; i >= 0; --i) {
			if (x.getDigit(i) == y.getDigit(i)) {
				continue;
			}
			else {
				if (x.getDigit(i) > y.getDigit(i)) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}
bool operator<(BigInteger &x, BigInteger &y) {
	if (x.numberOfDigits() == y.numberOfDigits()) {
		for (int i = x.numberOfDigits() - 1; i >= 0; --i) {
			if (x.getDigit(i) == y.getDigit(i)) {
				continue;
			}
			else {
				if (x.getDigit(i) < y.getDigit(i)) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

bool operator== (BigInteger &x, BigInteger &y) {
	if (x.numberOfDigits() == y.numberOfDigits()) {
		for (int i = x.numberOfDigits() - 1; i >= 0; --i) {
			if (x.getDigit(i) == y.getDigit(i)) {
				continue;
				return true;
			}
			else {
				if (x.getDigit(i) != y.getDigit(i)) {
					return false;
				}
			}
		}
	}
	else {
		return false;
	}
}

bool operator!=(BigInteger &x, BigInteger &y) {
	if (x.numberOfDigits() == y.numberOfDigits()) {
		for (int i = x.numberOfDigits() - 1; i >= 0; --i) {
			if (x.getDigit(i) != y.getDigit(i)) {
				return true;
			}
			else {
				if (x.getDigit(i) == y.getDigit(i)) {
					return false;
				}
			}
		}
	}
	if (x.numberOfDigits() != y.numberOfDigits()) {
		return true;
	}

}


