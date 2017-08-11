#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bug.h"

using namespace std;

Bug::Bug(){
	legs=rand()%10;
	mass=rand()%10;
	odo=0;
}

Bug::Bug(int l ,int m, int o){
	//set private vars to inputs or min vals
	//whichever is greater
	legs=l>=0?l:0;
	mass=m>=3?m:3;
	odo=o>=0?o:0;
}


//nothing interesting here, move along
int Bug::getLegs(){return legs;} 
int Bug::getMass(){return mass;} 
int Bug::getOdo(){return odo;} 


//simple print function
void Bug::print(){
	cout<<"l: "<<legs;
	cout<<" m: "<<mass;
	cout<<" o: "<<odo;
	cout<<endl;
}

void Bug::eat(int bites){
	//a bug is what it eats
	mass+=bites;	
	//if a bug's mass exceeds 10, it
	//uses 5 units to grow a new leg
	if(mass>10){
		mass=5;
		legs++;
	}
		
}

void Bug::walk(int steps){
	//bugs with no legs nowhere
	if(legs==0)return;
	odo+=steps;
	//if a bug stop walking with a 0 on
	//the last digit of the odometer,
	//it sacrifices a leg
	if(odo%10==0)legs--;
}

void Bug::poop(){
	//try the new bug diet!
	mass-=rand()%5;
	//if a bug trys to poop itself into 
	//oblivion, it loses a leg instead
	if(mass<3){
		if(legs>0)legs--;
		mass=3;
	}
}
