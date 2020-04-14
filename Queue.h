#include <iostream>

class Queue
{
  public:
    Queue();//default constructor
    Queue(int maxSize); //overload constructor
    ~Queue();

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
