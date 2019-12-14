#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>
using namespace std;

class Visitor{
	private: 
		int no_office; //office that need to visit
		int no_floor; //floor that need to visit
		int priority_number; //priority number of visitor

	public:
		
		//constructor of visitor 
		//to construct/create a visitor needs the office and the floor
		//initializes: no_office, no_floor, priority_number=0
		Visitor(int no_office,int no_floor){ 
			this->no_office = no_office; 
			this->no_floor = no_floor;
			this->priority_number = 0;
		}

		void SetPriorityNumber(int priority_number){
			this->priority_number = priority_number;
		}

		int GetPriorityNumber(){
			return priority_number;
		}

		int GetFloor(){
			return this->no_floor;
		}

		int GetOffice(){
			return no_office;
		}

		//void Print(void){
		//	cout << "[( " << this->no_office << "," << this->no_floor << " )]";
		//}
};

#endif