doubly1::doubly1(){
  //empty List
  size=0;
  front=NULL;
  back=NULL;
}

doubly1::~doubly1(){
  //build some character
}

unsigned int doubly1::getSize(){
  return size;
}

bool doubly1::isEmpty(){
  return (size==0);
}

void doubly1::printList(){
  doubly1 *curr = front;
  while (curr != NUll){
    cout << curr->data <<endl;
    curr = curr->next;
  }
}

void doubly1::insertFront(int d){
  doubly1 *node = new doubly1(d);
  //check if front is empty
  if(isEmpty()){
    back=node;
  }else{
    //not empty
    front->prev=node;
    node->next = front;
  }
  front=node;
  size++;
}

void doubly1::insertBack(int d){
  doubly1 *node = new doubly1(d);
  //check if front is empty
  if(isEmpty()){
    front=node;
  }else{
    //not empty
    back->next = node;
    node->prev=back;
  }
  back=node;
  size++;
}

int doubly1::removeFront(){
  doubly1 *node = front;
  if (front->next = NULL){
    //we have one node in list
    back = NULL;
  }
  else{
    //there is more than one node in list
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  int tmp = temp->data;
  delete temp;
  size--;
  return tmp;
}

int doubly1::search(int value){
  //variable to keep track of position to loop through whole list and search
  //if position is negative, that value is not found, default at -1
  int position = -1;
  doublylinkedlist *curr = front;
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


}


int doubly1::removeAtPos(int pos){
  //error checking (make sure value not out of bound)
  int idx = 0;
  //keep track of the element at position, and the one before position(previous), cause node of previous one will update when we remove the one at position
  doublylinkedlist *curr = front;
  doublylinkedlist *prev = front;

  //loop until position
  while(idx != pos){
   prev = curr;
   curr = curr->next;
   idx++;
  }
  //we found the position of the node to be deleted using the while loop
  prev->next = curr->next;
  //null the position pointer out, so that the previous one's pointer can point to the next one when remove at position
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;
  return temp;

}
