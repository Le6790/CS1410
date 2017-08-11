// a frivilous class of generic bugs
class Bug {
public:
	//constructors and destructors
	Bug();
	Bug(int l, int m, int o);

	//accessors
	int getLegs();
	int getMass();
	int getOdo();
	
	//the good stuff
	
	
	void print();
	void eat(int bites);
	void walk(int steps);
	void poop();
private:
	int legs;
	int mass;
	int odo;
	//int pos;
	//string name;
};

