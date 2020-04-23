#include "Queue.h"

/** Queue.cpp
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment4  Registrar’s Office Simulation
* purpose: set up queue for use in main program
* define functions in queue
* Version 3.0
* Date: April 22, 2020
*
*/

Queue::Queue(){
  //default constructor
  myQueue = new char[128];
  mSize = 128;
  front=0;
  rear=-1;
  numElements=0;
}

//overload constructor
Queue::Queue(int maxSize){
  myQueue = new char[maxSize];
  //mSize can be a number like 128, can do myQueue = new char[128] and mSize=128 so that can check the size
  mSize = maxSize;
  front=0;
  rear=-1;
  numElements=0;
}
//destructor
Queue::~Queue(){
delete myQueue;
}
//insert function
void Queue::insert(char d){
  //add error checking
  myQueue[++rear] = d;
  ++numElements;
}
//remove function
char Queue::remove(){
  //error checking
  //initialize c
  char c = '\0';
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}
//peek function, return the first variable in queue
char Queue::peek(){
  return myQueue[front];
}
//or can do if (isFull==true;)
//function to check whether queue is full
bool Queue::isFull(){
  return (numElements == mSize);
}
//function to check whether queue is empty
bool Queue::isEmpty(){
  return (numElements == 0);
}
//function to get the queue size 
int Queue::getSize(){
  return numElements;
}
