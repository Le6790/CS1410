#include <iostream>
#include "Donations.hpp"
#include <string>


int main()
{
	double funds[] = { 5,100,5,25,10,5,25,5,5,100,10,15,10,5,10 };
	DonationList donations(15, funds);
	donations.show();
	donations.showSorted();
	return 0;
}