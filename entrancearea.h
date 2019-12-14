#ifndef ENTRANCEAREA_H
#define ENTRANCEAREA_H
#ifndef PG_H
#include "pg.h"
#endif
#ifndef VISITOR_H
#include "visitor.h"
#endif
#ifndef AREA_H
#include "area.h"
#endif
#include <iostream>

using namespace std;

class EntranceArea: public Area{
	private:
		Queue queueInEA;

	public:
		
		//constructor of entrance area 
		//to construct/create the area needs the capacity(Ne) 
		//initializes: Ne, no_visitors=0(is empty of visitors)
		EntranceArea(int Ne){ 
			cout << "The entrance has been created" << endl;		
			C = Ne;
		}

		int Enter(){
            if(no_visitors < C ){
                IncreaseVisitors();
                return 1;
            }else{
                return 0;
            }
        }
		
		void PutInEA(Visitor* vis){
			queueInEA.insert(vis);
		}

		Queue GetQueue(){
			return queueInEA;
		}
		
		//Destructor of entrance area
		~EntranceArea(){ 
			cout << "End of waiting people" << endl;
		}

	
};

#endif