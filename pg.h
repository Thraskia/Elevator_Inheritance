#ifndef PG_H
#define PG_H
#ifndef VISITOR_H
#include "visitor.h"
#endif
#include <iostream>

using namespace std;

struct Node{
    Visitor* data;
    Node* next;
};

class Queue{
    Node *front,*rear;
    int length;
public:
    
    //constructor of queue 
    //initializes: front, rear and length
    Queue(){
        front=NULL;
		rear=NULL;
        length = 0;
    }
    
    //return the Visitor* in "position" of queue
    Visitor* returnData(int position){
    	Node* node = new Node;
		if(position == 1){
			return front->data;
		}else if(position == Size()){
			return rear->data;
		}else{
			node = front;
			for(int i=1; i < position; i++){
	    		node = node->next;
			}
	    	return node->data;
		}
    	
	} 

    int GetLength(){
        return length;
    }

	// size of queue
	int Size(){ 
		Node* node = new Node;
		node = front;
		int size = 0;
        while(node != NULL){
            size++;
            node = node->next;
        }
        return size--;
		
	}
    
    //insert item at the end of queue
    void insert(Visitor* item){
        length++;
        Node *node;
        node = new Node;
        if(front==NULL){
            rear=front=node;
            rear->next=NULL;
            front->next = NULL;
            front->data=item;
        }else{
			Node *temp = new Node;
			temp = front;
            if(temp == rear){//we have one node
                temp->next = node;
                rear = node;
                rear->data = item;
                rear->next = NULL;
            }else{
            	while(temp!=rear){
            		temp = temp->next;
				}
				temp->next = node;
				node->data = item;
				node->next = NULL;
				rear = node;
            }
        }
    }

    //sort the queue from smaller to bigger
    void Sort(){
        Node* curr_i = new Node;
        curr_i = front;
        Node* curr_j = new Node;
        Node* temp = new Node;
        if(front==NULL){
                return;
        }else{
            for(int i=1; i<Size(); i++){
                curr_j= curr_i->next;
                for(int j=i+1; j<=Size(); j++){
                    if((curr_i->data)->GetFloor() >(curr_j->data)->GetFloor()){
                        temp->data = curr_i->data;
                        curr_i->data = curr_j->data;
                        curr_j->data = temp->data;
                    }
                    curr_j = curr_j->next;
                }
                if (i==1){
                    front->data = curr_i->data;
                }
                curr_i = curr_i->next;
            }
            rear->data = curr_i->data;
            return;
        }
    }
    
    //delete the 1st node of queue
    void delet(){
        Node *temp = new Node;
        if(front!=NULL){		
            //cout << "Deleted element is " << front->data << endl;
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    
    //delete the node in "position" of queue
    void specialDelete(int position){
            Node* curr = new Node;
            curr = front;
            if(front == NULL){
                return;
            }
            if(position == 1){
                delet();
                return;
            }
            if(length == 2){
                if(position == 2){
                    curr = rear;
                    front->next = NULL;
                    rear = front;
                }
                length--;
                delete curr;
                //delete curr->temp
            }else{
                Node* prev = new Node;
                if(position == length){
                    for (int i = 1; i < length-1; i++){
                        curr = curr->next;
                    }
                    curr->next = NULL;
                    prev = curr;
                    curr = rear;
                    delete curr;
                    rear = prev;
                }else{
                    for(int i= 1; i< position; i++){
                        prev = curr;
                        curr = curr->next;
                    }
                    prev->next = curr->next;
                    delete curr;
                }
                length--;
            }
        }
        
    //print the queue
    void display(){
        Node *temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

#endif