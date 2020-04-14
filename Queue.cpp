#include "Queue.h"

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

Queue::~Queue(){
delete myQueue;
}

void Queue::insert(char d){
  //add error checking
  myQueue[++rear] = d;
  ++numElements;
}

char Queue::remove(){
  //error checking
  //initialize c
  char c = '\0';
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}

char Queue::peek(){
  return myQueue[front];
}
//or can do if (isFull==true;)
bool Queue::isFull(){
  return (numElements == mSize);
}

bool Queue::isEmpty(){
  return (numElements == 0);
}

int Queue::getSize(){
  return numElements;
}
