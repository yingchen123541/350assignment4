//#include "doubly1.cpp"
//#include "doublylinkedlist1.cpp"
#include<fstream>
#include <iostream>



using namespace std;

int main(int argc, char** argv) {

//  string inputfileName= argv[1];
cout << "enter file name" << endl;
string inputfileName;
cin >> inputfileName;

  string Line;
  int windowsOpen;
  bool timeGoing=true;
  int clocktick;
  int studentArrive;
  int windowTime;
  int lineNumber=0;
  int OpenWindow=0;
  int studentID=0;
  //store time student spend at window into window queue
  ///////////Queue *WindowQueue = new Queue(10);
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
    windowsOpen = stoi(Line);
    cout << "there are " << windowsOpen << " windows open" << endl;

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
      getline(InputFile, Line, '\n');
      //convert string to int
      windowTime = stoi(Line);
      cout << "student " << studentID << " spend " << windowTime << " clocktick at the window" << endl;



      //store time each student spend at window into queue
    /////  WindowQueue->insert(Line);
  } // end for
}//end while

    //store number of students that arrive at that time into variables or queue??

}//end else if (successfully open file )







  return 0;
}
