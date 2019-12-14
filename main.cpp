#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include "visitor.h"
#include "pg.h"
#include "office.h"
#include "groundfloor.h"
#include "entrancearea.h"
#include "floor.h"
#include "elevator.h"
#include "building.h"

using namespace std;

int main(int argc, char *argv[]){
	//int N = atoi(argv[1]);
	//int Nf = atoi(argv[2]);
	//int Ng = atoi(argv[3]);
	//int No = atoi(argv[4]);
	//int Nl = atoi(argv[5]);
	//int K = atoi(argv[6]);
	//int L = atoi(argv[7]);

	int K=50;
	int N = 300;
	int Nf = 50;
	int Ng = 90;
	int No = 4;
	int Nl = 10;
	int L = 1; //Circles that the elevator must work

	int Ne = Nf - 10*No;
	int end=0;

	//if entries are right create:
	//1 building, 1 ground floor, 4 floors, 4 areas and
	//10 offices for each floor 
	Building building(N);
	GroundFloor* gf;
	if(Ng < N/2){
		gf = new GroundFloor(Ng);
		building.CreateGroundFloor(gf);
	}else{
		cout << "wrong input" << endl;
		return -1;
	}

	Floor *f1;
	Floor *f2;
	Floor *f3;
	Floor *f4;
	EntranceArea* ea1;
	EntranceArea* ea2;
	EntranceArea* ea3;
	EntranceArea* ea4;
	Elevator* elevator;

	if(Nf < N/3 && No < Nf){
		f1 = new Floor(Nf, 1); 
		f2 = new Floor(Nf, 2);
		f3 = new Floor(Nf, 3);
		f4 = new Floor(Nf, 4);
		ea1 = new EntranceArea(Ne);
		ea2 = new EntranceArea(Ne);
		ea3 = new EntranceArea(Ne);
		ea4 = new EntranceArea(Ne); 
		building.CreateFloors(f1, f2,f3,f4, ea1, ea2, ea3, ea4, No);
	}else{
		return -1;
	}
	if(Nl > No){
		elevator = new Elevator(Nl);
		building.CreateElevator(elevator);
	}else{
		return -1;
	}

	//create K visitors with random floor and office destination 
	//1<=offices<=10 and 1<=floors<=4 
	Visitor** visitors = new Visitor* [K];
	srand(time(NULL));
	for(int i=0; i<K; i++){ //K== number of visitors that have created
		int random_floor = rand();
    	while(random_floor >= 5){ //create random floor
    		random_floor = random_floor% 5;
    		if(random_floor == 0 ){
    			random_floor = rand();
    		}
    	}
    	int random_office = rand();
    	while(random_office >= 11){ //create random office
    		random_office = random_office%10;
    		if(random_office == 0){
    			random_office = rand();
    		}
    	}
    	visitors[i] = new Visitor(random_office, random_floor);
	}
	int l=1;
	Queue queueGF;
	Queue queueElevator;
	int flag = 1; //vis_build!=0 && end!=K
	while(l<=L && flag==1){
		int pn = building.Enter();
		int size = end;
		int count = size;
		while( size<K  && pn != 0){
			cout << "Visitor can join the building" << endl;
			cout << "Visitor can join the ground floor" << endl;
			queueGF.insert(visitors[size]);
			gf->Wait(visitors[size]);
			pn = building.Enter();
			size++;
			end++;
		}
		//queueGF.display();
		int x = building.EnterElevator();
		while(count<end && x ==1){
			cout << "Visitor in the elevator " << endl;
			queueElevator.insert(visitors[count]);
			queueGF.delet();
			count++;
			if(count < end){
				x = building.EnterElevator();
			}
		}
		//queueElevator.display();
		queueElevator.Sort();
		//queueElevator.display();
		building.ElevatorOperate(queueElevator);	
		l++;
		//there aren't visitors in building && there aren't visitors outside the building
		if(building.GetNoVisitors()==0 && end == K){
			flag == 0;
		}
	}
	for(int i=0; i<K; i++){
		delete visitors[i];
	}
	delete visitors;
	
	return 0;
}