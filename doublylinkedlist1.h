#include <iostream>

/** doublylinkedlist1.h
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment4  Registrar’s Office Simulation
* purpose: define listnode for use in doubly1.h and doubly1.cpp 
* Version 3.0
* Date: April 22, 2020
*
*/

class  doublylinkedlist1{
  public:
    int data;
    //pointer to linkedlist
    doublylinkedlist1 *next;
    doublylinkedlist1 *prev;


    doublylinkedlist1();//default constructor
    doublylinkedlist1(int d);//overloaded constructor
    ~doublylinkedlist1();//destructor

};
