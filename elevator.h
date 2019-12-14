#ifndef ELEVATOR_H
#define ELEVATOR_H
#ifndef PG_H
#include "pg.h"
#endif
#ifndef FLOOR_H
#include "floor.h"
#endif
#ifndef AREA_H
#include "area.h"
#endif
#include <iostream>


using namespace std;

class Elevator: public Area {
	private:
		static int who_visitor;
		Queue queueDeletedVisitors;

	public:
		
		//constructor of elevator 
		//to construct/create the elevator needs the capacity(Nl) 
		//initializes: Nl, no_visitors=0(is empty of visitors)
		Elevator(int Nl){ 
			C = Nl; 
			cout << "A lift has been created" << endl;
		}
		//check if the visitor can join the elevator
        //Increase the number of visitors the current time
        int Enter(){
            if(no_visitors < C){ //Visitor can join the elevator
                IncreaseVisitors();
                cout << "Visitor in the lift. " << endl;
                return 1;
            }else{ 
                cout << "You are not allowed to enter!" << endl; 
                return 0;
            }
        }
		
		//if there is space in floor and there visitors in elevator
		//check if they are going to specific floor
		//(if yes) get office..	
		//	if can join the office put them in office and delete the from elevator 
		//	else put them in entrance area(if there is space) else go to next visitor
		//(If no) go to next floor
		void Stop_Up(Floor* f, Queue& queueElevator){
			int off =0;
			int x= f->Enter();
			while( x == 1 && who_visitor <= queueElevator.Size()){//visitor can join the floor
				cout << "Entering floor number: " << f->GetFloorNumber() << endl;
				cout << "Visitor in the entrance area " << endl;
				if((queueElevator.returnData(who_visitor))->GetFloor() == f->GetFloorNumber()){
					off = (queueElevator.returnData(who_visitor))->GetOffice();
					if(f->EnterOffice(off) == 1){ //put in office
						f->PutInOffices(queueElevator.returnData(who_visitor));
						cout << "Priority_number is: "<< (queueElevator.returnData(who_visitor))->GetPriorityNumber() << endl;
						Exit();
						queueElevator.specialDelete(who_visitor);
					}else{
						f->ReduceVisitorsOffice(off); //reduce visitors;
						if(f->EnterEa() == 1){
							cout << "Please, wait outside for entrance in office number " << off << endl;
							cout << "Priority_number is: "<< (queueElevator.returnData(who_visitor))->GetPriorityNumber() << endl;
							f->PutInEA(queueElevator.returnData(who_visitor));
							Exit();
							queueElevator.specialDelete(who_visitor);
						}else{
							f->ReduceEA();
							f->ReduceVisitors();
							who_visitor++;
						}
					}
					x = f->Enter();
				}else{
					//because it"s a sorted queue
					cout << "There isn't visitor that goes to floor "  << endl;
					f->ReduceVisitors();
					return;
				}
			}			 
			f->ReduceVisitors();
		}
		
		//Take random visitors from offices and put them in elevator
		//(if there is space)
		//Take visitors from entrance area and put them in offices
		void Stop_Down(Floor* f, Queue& queueInOffices, EntranceArea* area){
			int off;
			//cout << "queueInOffices is: ";
			//queueInOffices.display();
			if(queueInOffices.Size() != 0){//maybe list is empty
				int size = queueInOffices.Size();
				while(size>0 && Enter() == 1){ //until elevator = full && while there are visitors in offices
					cout << "Visitor can join the evavator" << endl;
					queueDeletedVisitors.insert(queueInOffices.returnData(1));
					off = (queueInOffices.returnData(1))->GetOffice();
					queueInOffices.delet();
		    		f->ReduceVisitorsOffice(off);		
					size = queueInOffices.Size();	
					if(size <= 0){
						break;
					}
			    	
				}
				if(size==0){ 
					Exit();
				}
			}else{
				return;
			}
			//cout << "queueDeletedVisitors is: ";
			//queueDeletedVisitors.display();
			Queue qArea = (area->GetQueue());
			//cout << "in ea: "<< endl;
			//qArea.display();
			if(qArea.GetLength() != 0){
				int i = 1;
				while((qArea.Size()) > 0){		
					int off = (qArea.returnData(i))->GetOffice();
					if(f->EnterOffice(off) == 1){
						queueInOffices.insert(qArea.returnData(i));
						if(i == 1){
							qArea.delet();
						}else{
							qArea.specialDelete(i); 
						}
						area->Exit();//no_visitors--;
					}else{
						i++;
						f->ReduceVisitorsOffice(off);
					}
				}
			}else{
				return;
			}
			
		}
		
		//At the end empty all visitors that have served from the building
		int Empty_All(){
			int size = queueDeletedVisitors.Size();
			while((queueDeletedVisitors.Size()) > 0){
				cout << "I cannot believe I finished!" << endl;
				cout << "My priority number is: " << (queueDeletedVisitors.returnData(1))->GetPriorityNumber() << endl;
				Exit();
				queueDeletedVisitors.delet();
			}
			return size;
			
		}

		//Destructor of elevator
		~Elevator(){ 
			cout << "No more ups and downs" << endl;
			
		}

};




int Elevator:: who_visitor = 1;


#endif