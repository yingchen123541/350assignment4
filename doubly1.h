class doubly1{
 private:
   doublylinkedlist *front;
   doublylinkedlist *back;
   //this way zise's default value is from 0 to a big number instead of from negative infinite to positive inifinite
   unsigned int size;

 public:
   doubly1();
   //destructor
   ~doubly1();

   void insertFront(int data);
   void insertBack(int data);
   //int remove is under the same method as void
   int removeFront();
   int removeBack();
   int search(int value);//can return the value or position depending on implementation
   int removeAtPos(int pos);

// these are build in functions in c++, remove front might be build in too??? research, print list is not build in!!!
   unsigned int getSize();
   bool isEmpty();
   void printList();


};
