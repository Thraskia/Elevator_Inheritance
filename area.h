#ifndef AREA_H
#define AREA_H
#include <iostream>

using namespace std;

class Area{
protected:
	int C; //area's capacity
	int no_visitors;

public:
	Area(){
		no_visitors = 0;
	}

	//Increase the number of visitors the current time
	void IncreaseVisitors(){
		no_visitors++;
	}

	//Reduce the number of visitors the current time
	void ReduceVisitors(){
		no_visitors--;
	}

	//return the current no of visitors in area
	int GetNoVisitors(){
		return no_visitors;
	}

	virtual int Enter() = 0 ;

	int Exit(){
		ReduceVisitors();
	}

	virtual ~Area(){
		
	}

	
};

#endif