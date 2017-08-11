#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class IPRecord {
private:
    unsigned int m_IP;      // IP address as a 32-bit unsighed int
    unsigned int m_freq;    // frequency of the IP

public:
    IPRecord() { m_IP = 0; m_freq = 0;  }

    void setIP(int IP)  { m_IP = IP; }
    void incFrequency() { m_freq++; }

    unsigned int getIP()        { return m_IP;}    
    unsigned int getFrequency() { return m_freq;}
};

int binarySearch(IPRecord *pTable, int size, unsigned int IP) 
{
    // TODO: Task 1 - 5 points. 
    // Lookup IPRecord with the given IP
	int first = 0;
	int last = size - 1;

	while (first <= last) {
		int mid = (first + last) / 2;
		if (pTable[mid].getIP() == IP && pTable[mid].getFrequency() > 0)
			return mid;
		if (pTable[mid].getIP() < IP)
			first = mid + 1;
		else
			last = mid - 1;
	}
	return -1;
}

void insert(IPRecord *pTable, int& rSize, unsigned int IP) {
    // TODO: Task 2 - 10 points. 
    // Create an IPRecord for the given IP and insert it in the proper location 
    // to keep array pTable sorted increasingly by IPs.
	
	IPRecord temp;
	temp.setIP(IP);
	temp.incFrequency();
	pTable[rSize]=temp;

	for (int i = rSize; i >0; i--) {

		if (pTable[i].getIP() < pTable[i - 1].getIP()) {
			
			IPRecord temp2 = pTable[i];
			pTable[i] = pTable[i - 1];
			pTable[i - 1] = temp2;
		}
		else
			break;
	
	}
	rSize++;
}

void sortFrequency(IPRecord *pTable, int size) 
{ 
	// TODO: Task 3 - 5 points. 
    // Sort the IP table by frequency descendingly
	IPRecord temp;
	bool swap;
	
	do {
		swap = false;
		for (int i = 0; i < size; ++i) {
			if (pTable[i].getFrequency() < pTable[i + 1].getFrequency()) {
				temp = pTable[i];
				pTable[i] = pTable[i + 1];
				pTable[i + 1] = temp;
				swap = true;
			}
		}
	}	while (swap);
   
}
 

int main() {
    IPRecord *myIPTable;    // dynamic array to store all IPRecords
    int maxSize;            // allocated size of myIPTable, i.e. number of distinct IPs 
    int size = 0;           // the current size of myIPTable, i.e. number of distinct IPs seen so far    

    ifstream fi("input.txt"); // open input file

    fi >> maxSize;            // read table size;
    
    myIPTable = new IPRecord[maxSize]; // allocate memory

    unsigned ip;
    while (fi >> ip) {     // reading IP addresses from input file until the end
        int pos = binarySearch(myIPTable, size, ip);    // looking up this IP in the table
        if (pos >= 0)
            myIPTable[pos].incFrequency();      // if found: increase its frequency
        else
            insert(myIPTable, size, ip);        // if not found: insert as a new IPRecord
    }
    
    fi.close();            // close input file

    sortFrequency(myIPTable, size); // sort IPRecords by frequency descendingly

    ofstream fo("output.txt"); // open output file

    for (int i = 0; i < size; i++) // print each IPRecord in one line
        fo << myIPTable[i].getIP() << ' ' << myIPTable[i].getFrequency() << endl;
    
    fo.close();         // close output file

    delete[] myIPTable; // de-allocate memory;
}
 

