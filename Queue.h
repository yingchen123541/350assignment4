#include <iostream>

/** Queue.h
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment4  Registrar’s Office Simulation
* purpose: set up queue and initialize functions and variables
* Version 3.0
* Date: April 22, 2020
*
*/

class Queue
{
  public:
    Queue();//default constructor
    Queue(int maxSize); //overload constructor
    ~Queue(); //destructor

 //core functions
    void insert(char d); // enqueue
    char remove(); //dequeue

//aux functions
    char peek();
    bool isFull();
    bool isEmpty();
    int getSize();

    //vars
    int front;// aka head
    int rear; //aka tail
    int mSize;
    int numElements;

    char *myQueue; //array



};
