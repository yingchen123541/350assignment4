#include <iostream>

/** doubly1.h
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment4  Registrar’s Office Simulation
* purpose: initialize functions and variables to use in doubly linked list
* Version 3.0
* Date: April 22, 2020
*
*/

class doubly1{
 private:
   //initialize variables
   doublylinkedlist1 *front;
   doublylinkedlist1 *back;
   //this way zise's default value is from 0 to a big number instead of from negative infinite to positive inifinite
   unsigned int size;

 public:
   doubly1();
   //destructor
   ~doubly1();

//initialize functions 
   void insertFront(int data);
   void insertBack(int data);
   //int remove is under the same method as void
   int removeFront();
   int removeBack();
   int search(int value);//can return the value or position depending on implementation
   int removeAtPos(int pos);

// initialize functions
   unsigned int getSize();
   bool isEmpty();
   void printList();


};
