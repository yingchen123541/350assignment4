//#include "doubly1.cpp"
//#include "doublylinkedlist1.cpp"
#include "Queue.cpp"
#include<fstream>

using namespace std;

int main(int argc, char** argv) {

//  string inputfileName= argv[1];
cout << "enter file name" << endl;
string inputfileName;
cin >> inputfileName;

  string Line;
  int windows;
  bool timeGoing=true;
  int clocktick;
  int studentArrive;
  int windowTime;
  int lineNumber=0;
  int OpenWindow=0;
  int studentID=0;
  int windowID=0;
  int studentInline=0;
  //queue size is the same as total window size
  Queue *WindowQueue = new Queue(windows);
  Queue *inlineStudent = new Queue(100);
//open file and read from it
  ifstream InputFile;
  InputFile.open(inputfileName);

  //if fail to open input file
if(!InputFile)
{
  //output error message
  cerr << "unable to open file" << endl;
  exit(1);
}
//input file is successfully opened
else if(InputFile)
{
    //read the first line from input file
    getline(InputFile, Line, '\n');
    //convert string to int
    windows = stoi(Line);
    cout << "there are " << windows << " windows in total" << endl;
    //add all windows into queue, and remove each window when it's occupied
    for (int b=0; b<windows; b++)
    {
      windowID=windowID+1;
      //keep track of the number of open window
      OpenWindow=OpenWindow+1;
      WindowQueue->insert(windowID);
      cout<< "insert" << endl;
    }// end b for

//put this part in a loop too
while (timeGoing){
    //read the second line from input file
    getline(InputFile, Line, '\n');
//check whether have already reached the last line
    if(Line.empty())
    {
      cout << "reach the last line, stop reading" << endl;
      break;
    }
    //convert string to int
    clocktick = stoi(Line);
    cout <<"at clocktick " << clocktick << endl;

    //read the third line from input file
    getline(InputFile, Line, '\n');
    //convert string to int
    studentArrive = stoi(Line);
    cout << studentArrive << " students arrive" << endl;

    //loop the number of student arrive time to get window time for each student
    for(int a=0; a<studentArrive; a++)
    {
      studentID=studentID+1;
      //keep track of the number of students inline
      studentInline=studentInline+1;
      //put all students who arrive into queue to wait in line, remove from queue when it's that student's turn
      inlineStudent->insert(studentID);
      cout << "insert student" << endl;
      getline(InputFile, Line, '\n');
      //convert string to int
      windowTime = stoi(Line);
      cout << "student " << studentID << " spend " << windowTime << " clocktick at the window" << endl;
  } // end a for

  //while there are still open window
  while (OpenWindow>0){
    if(!inlineStudent->isEmpty()){
     //there are students inline, remove student with each matching window from queue
     inlineStudent->remove();
     //keep track of the number of students in line
     studentInline=studentInline-1;
     cout << "remove inline student" << endl;
     WindowQueue->remove();
     //keep track of the number of open window
     OpenWindow=OpenWindow-1;
     cout << "remove open window" << endl;
   }// end if
   //there is no students inline
   else if (inlineStudent->isEmpty())
   {
     cout << "window idle" << endl;
     break;
   }//end else if
 }//end while
 //there is no open window
   while(OpenWindow<=0){
   //there are students inline
    if (!inlineStudent->isEmpty())
   {
     cout << "no open window, students are waiting inline" << endl;
     break;
   }// end if
   //no student inline
   else if(inlineStudent->isEmpty())
   {
     cout << "great use of resources!" << endl;
     break;
   }//end else if
 }//end while

}//end while

}//end else if (successfully open file )







  return 0;
}//end main
