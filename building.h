#ifndef BUILDING_H
#define BUILDING_H
#ifndef FLOOR_H
#include "floor.h"
#endif
#ifndef ELEVATOR_H
#include "elevator.h"
#endif
#ifndef GROUNDFLOOR_H
#include "groundfloor.h"
#endif
#ifndef AREA_H
#include "area.h"
#endif
#include <iostream>

using namespace std;

class Building: public Area{
	private:
		Floor* f1;
		Floor* f2;
		Floor* f3;
		Floor* f4;
		GroundFloor* gf;
		Elevator* elevator;

	public:

		//constructor of building 
		//to construct/create the building needs the capacity(N) 
		//initializes: N, no_visitors=0(is empty of visitors)
		Building(int N) { 
			C = N;
			cout << "A new building is ready for serving citizens." << endl; 
		}

		//the current no of ground floor's visitors 
		int GetSumVisGF(){
			return gf->GetNoVisitors();
		}

		//the current no of visitors in elevator 
		int GetSumVisEl(){
			return elevator->GetNoVisitors();
		}

		//Initializes the data member gf
		void CreateGroundFloor(GroundFloor* gf){
			this->gf = gf;
		}    
		
		//Initializes the data member f1,f2,f3,f4
		//Initializes area which is floor's data member
		void CreateFloors(Floor* f1, Floor* f2, Floor* f3, Floor* f4, EntranceArea* ea1, EntranceArea* ea2, EntranceArea* ea3, EntranceArea* ea4, int No){
			this->f1 = f1;
			(this->f1)->CreateFArea(ea1);
			(this->f1)->CreateOffices(No);
			this->f2 = f2;
			(this->f2)->CreateFArea(ea2);
			(this->f2)->CreateOffices(No);
			this->f3 = f3;
			(this->f3)->CreateFArea(ea3);
			(this->f3)->CreateOffices(No);
			this->f4 = f4;
			(this->f4)->CreateFArea(ea4);
			(this->f4)->CreateOffices(No);
		}

		//Initializes the data member elevator
		void CreateElevator(Elevator* elevator){
			this->elevator = elevator;
		}
		
		//check if the visitor can join the building and the ground floor
		//Increase the number of visitors the current time
		int Enter(){
            if(no_visitors < C){//visitor can join the building
                if ((this->gf)->Enter() ==1 ){
                    cout << "Visitor can join the building" << endl;
                    cout << "Visitor can join the ground floor" << endl;
                    (this->gf)->IncreaseVisitors();
                    IncreaseVisitors();
                    return 1;
            }
            }
            cout << "Please, come tomorrow" << endl;
            return 0;
        }
		
		//check if the visitor can join the elevator
		int EnterElevator(){
			return (this->elevator)->Enter();
		}
		
		//Elevator's operation
		void ElevatorOperate(Queue& queueElevator){
			elevator->Stop_Up(f1, queueElevator);
			elevator->Stop_Up(f2, queueElevator);
			elevator->Stop_Up(f3, queueElevator);
			elevator->Stop_Up(f4, queueElevator);
			elevator->Stop_Down(f4, f4->ReturnQueue(), f4->GetFArea()); 
			elevator->Stop_Down(f3, f3->ReturnQueue(), f3->GetFArea());
			elevator->Stop_Down(f2, f2->ReturnQueue(), f2->GetFArea());
			elevator->Stop_Down(f1, f1->ReturnQueue(), f1->GetFArea());
			no_visitors -= (elevator->Empty_All());
		}
		
		//Destructor of building
		~Building(){ 
			cout << "Service not available any longer. Go elsewhere!" << endl; 
			delete f1;
			delete f2;
			delete f3;
			delete f4;
			delete gf;
			delete elevator;
		}

};

#endif