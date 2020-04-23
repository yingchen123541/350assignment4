#include "doublylinkedlist1.h"

/** doublylinkedlist1.cpp
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment4  Registrar’s Office Simulation
* purpose: implement listnode to use in doubly1.h and doubly1.cpp 
* Version 3.0
* Date: April 22, 2020
*
*/

doublylinkedlist1::doublylinkedlist1(){
  data=0;
  //pointer always set to null, cause when remove and add things, not sure where it's pointing to
  next=NULL;
  prev=NULL;
}
//overload constructor
doublylinkedlist1::doublylinkedlist1(int d){
  data=d;
  next=NULL;
  prev=NULL;
}
//destructor
doublylinkedlist1::~doublylinkedlist1(){

}

//need to find the value in the list before we can delete
//this function does not take in a position as a parameter
int doublylinkedlist1::remove(int val){
  doubly *curr = front;
  while(curr->data != val)
  {
    //keep iterating until we find the value
    curr = curr->next;
    if (curr==NULL)
    return NULL; //might need return -1
  }
  //we found the value, now let's proceed delete
  if(curr == front){
    //check if node to be deleted is the front
    front = curr->next;
  }else{
    //node to be deleted is not the front or back (it's a value in the middle of the list)
    curr->prev->next = curr->next;
  }
  if(curr == back){
    back = curr->prev;
  }else{
    //node to be deleted is not in the front ot back, it's in between
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}

int doublylinkedlist1::search(int value){
//almost the same with single linked list, don't need to worry about backward pointers, cause search then go to the next
//variable to keep track of position to loop through whole list and search
//if position is negative, that value is not found, default at -1
int position = -1;
doublylinkedlist1 *curr = front;
while (curr != NULL){
  //iterate and attempt to find the value
  position++;

  if (curr->data == value){
    //exit the loop at current position if find the value
    break;
  }
  else{
    //if still haven't found the value, go to the next value
    curr = curr->next;
  }
}
//return after get out of the loop
//check for whether find the value after looping, return -1 if can't find the value
if (curr==NULL){
  position=-1; // we didn't find the value
}
return position;
}
