#ifndef GROUNDFLOOR_H
#define GROUNDFLOOR_H
#ifndef AREA_H
#include "area.h"
#endif

using namespace std;

class GroundFloor: public Area{
	private:
		int waiting_number;

	public:
		
		//constructor of ground floor
		//to construct/create the ground floor needs the capacity(Ng) 
		//initializes: waiting_number
		GroundFloor(int Ng){ 
			C = Ng; 
			waiting_number = 0;
			cout << "The ground floor has been created" << endl;
		}

		int Enter(){
            if(no_visitors < C){ 
                cout << "Visitor can join the ground floor" <<endl;
                return 1;
            }else{ 
                return 0;
            }
        }

		//Give priority number to visitors that join the ground floor
		int Wait(Visitor* vis){
			waiting_number++;
			vis->SetPriorityNumber(waiting_number);
			cout << "Waiting for the lift!" << endl;
			return waiting_number;
		}

		//Destructor of ground floor
		~GroundFloor(){ 
			cout << "End of service!" << endl;
		}

};

#endif