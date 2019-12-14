#ifndef OFFICE_H
#define OFFICE_H
#ifndef AREA_H
#include "area.h"
#endif
#include <iostream>

using namespace std;

class Office: public Area{
	private:
		int office_number; //number of office

	public:
		
		//constructor of office 
		//to construct/create the office needs the capacity(No) 
		//and office_number
		//initializes: office_number
		Office(int No, int office_number){ 
			C = No; 
			cout << "Office number: " << office_number << " has been created." << endl; 
		}

		int Enter(){
            if(no_visitors < C){
                IncreaseVisitors();
                cout << "Entering office number: " << office_number << endl;
                return 1;
            }else{
                return 0;
            }
        }

		//Destructor of office
		~Office(){ 
			cout << "End of the work!" << endl;
		}
};

#endif