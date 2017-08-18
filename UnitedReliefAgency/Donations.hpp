#ifndef DONATIONS_HPP
#define DONATIONS_HPP

class DonationList
{
private:
	int numDonations; //number of donations recieved,used to dynamically allocate arrays for holding and processing the donation values
	double *donations; // a pointer that will point to a dynamically allocated array of doubles containing donation amounts
	double **arrPtr; // a pointer that will point to an array of pointers. the array of pointers will be dynamically allocated. Each element of the array will point to an element of the donation array
	void selectSort();
public:
	DonationList(int num, double gifts[]);
	~DonationList();
	void show();
	void showSorted();

};

DonationList::DonationList(int num, double gifts[])
{
	numDonations = num;
	if (num > 0)
	{
		// allocate an array of doubles
		donations = new double[num];
		//allocate an array of pointer to doubles
		arrPtr = new double*[num];
		for (int count = 0; count < numDonations; count++)
		{
			donations[count] = gifts[count];
			arrPtr[count] = &donations[count];
		}
		selectSort();
	}
}
DonationList::~DonationList()
{
	delete[] donations;
	donations = nullptr;
	delete[] arrPtr;
	arrPtr = nullptr;

}

void DonationList::selectSort()
{
	int minIndex;
	double *minElem;
	for (int scan = 0; scan < (numDonations - 1); scan++)
	{
		minIndex = scan;
		minElem = arrPtr[scan];
		for (int index = scan + 1; index < numDonations; index++)
		{
			if (*(arrPtr[index]) < *minElem)
			{
				minElem = arrPtr[index];
				minIndex = index;
			}
		}
		arrPtr[minIndex] = arrPtr[scan];
		arrPtr[scan] = minElem;

	}
}

void DonationList::show()
{
	std::cout << "SHOW: " << std::endl;
	for (int i = 0; i < numDonations; i++)
	{
		std::cout << donations[i] << std::endl;
	}
}

void DonationList::showSorted()
{
	std::cout << "SHOW SORTED: " << std::endl;
	for (int i = 0; i < numDonations; i++)
	{
		std::cout << *(arrPtr[i]) << std::endl;
	}
}

#endif