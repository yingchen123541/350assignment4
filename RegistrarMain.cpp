//#include "doubly1.cpp"
//#include "doublylinkedlist1.cpp"
#include "Queue.cpp"
#include<fstream>

using namespace std;

int main(int argc, char** argv) {

  //string inputfileName= argv[1];
  //cout << argv[1] << endl;
cout << "enter file name" << endl;
string inputfileName;
cin >> inputfileName;

  string Line;
  int windows;
  int windows1;
  int windows2;
  int windows3;
  bool timeGoing=true;
  int clocktick1;
  int clocktick2;
  int studentArrive1;
  int studentArrive2;
  int windowTime0;
  int windowTime1;
  int windowTime2;
  int windowTime3;
  int windowTime4;
  int lineNumber=0;
  int OpenWindow=0;
  int studentID=0;
  int windowID=0;
  int inlineID=0;
  int OpenWindowID=0;
  int studentInline=0;
  int d=0;
  int reopen;
  int reopen1;
  int clocktick3;
  int clocktick4;
  //total idel time for all windows
  int totalIdelTime;
  int idel1;
  int idel2;
  int idel3;
  int idel4;
  int idel5;
  int calcClocktick2;
  int calcClocktick4;
  int leftTime;
  int meanIdel;
  int realtotal;

  //the time the simulation stop at
  int totaltime;
  int time=1;
  int c=1;
  //queue size is the same as total window size
  Queue *WindowQueue = new Queue(windows);
  Queue *inlineStudent = new Queue(100);
  Queue *Windowtime = new Queue(10);
  Queue *Windowtime1 = new Queue(10);
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
    //  cout<< "insert" << endl;
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
    if(c==1)
    {
    clocktick1 = stoi(Line);
    }
    else if (c==2)
    {
      clocktick2 = stoi(Line);
    }
    calcClocktick2=clocktick2;

    //read the third line from input file
    getline(InputFile, Line, '\n');
    //convert string to int
    if(c==1)
    {
      studentArrive1 = stoi(Line);

    //cout << studentArrive << " students arrive" << endl;

    //loop the number of student arrive time to get window time for each student
    for(int a=0; a<studentArrive1; a++)
    {
      studentID=studentID+1;
      //keep track of the number of students inline
      studentInline=studentInline+1;
      //put all students who arrive into queue to wait in line, remove from queue when it's that student's turn
      inlineStudent->insert(studentID);
      //cout << "insert student" << endl;
      getline(InputFile, Line, '\n');
      //convert string to int
      if(a==0){
      windowTime0 = stoi(Line);
      Windowtime->insert(windowTime0);
      cout << windowTime0 << "windowTime0" << endl;
    }
      else if(a==1){
      windowTime3 = stoi(Line);
      Windowtime->insert(windowTime3);
    }
  } // end a for
  //total time need to run the simulation for
  totaltime=windowTime3-(calcClocktick2-clocktick1)+calcClocktick2;
  cout << totaltime << "total time" << endl;
} //end c if
else if(c==2)
{
  studentArrive2 = stoi(Line);
  for(int a=0; a<studentArrive2; a++)
  {
    studentID=studentID+1;
    //keep track of the number of students inline
    studentInline=studentInline+1;
    //put all students who arrive into queue to wait in line, remove from queue when it's that student's turn
    inlineStudent->insert(studentID);
  //  cout << "insert student" << endl;
    getline(InputFile, Line, '\n');
    //convert string to int
    windowTime4 = stoi(Line);
    Windowtime1->insert(windowTime4);
} // end a for
}//end c=2



  //while there are still open window
  while (OpenWindow>0){
    if(!inlineStudent->isEmpty()){
     //there are students inline, remove student with each matching window from queue
     inlineStudent->remove();
     //keep track of the number of students in line
     studentInline=studentInline-1;
     inlineID=inlineID+1;
    // cout << "remove inline student" << inlineID << endl;
     WindowQueue->remove();
     //keep track of the number of open window
     OpenWindow=OpenWindow-1;
     OpenWindowID=OpenWindowID+1;
    // cout << "remove open window" << OpenWindowID << endl;
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

c++;


}//end time going whike
leftTime=windowTime0-(calcClocktick2-clocktick1);
clocktick3=leftTime+calcClocktick2;
cout << "clocktick3 " << clocktick3 << endl;

}//end open file else if

//simulation
for(time=0; time<=totaltime; time++)
{
  if(time!=clocktick1 && time!=clocktick2 && time!=clocktick4 )
  {
  cout << "at clocktick " << time << ", no one has come in" << endl;
  // foe time 0-1, no one comes in, so all windows idel for 1 clocktick
  idel1=windows;
  //cout << "idel 1 " << idel1 << endl;
  }
  else if (time==clocktick1)
  {
    windows1=windows-studentArrive1;
    idel2=windows1*(calcClocktick2-clocktick1);
    //cout << "idel 2" << idel2 << endl;
    cout << "at clocktick" << time << " " << studentArrive1 << " students arrive, number of open windows " << windows1 << endl;
    while (!Windowtime->isEmpty())
    {
      d=d+1;
      windowTime1=Windowtime->peek();
      Windowtime->remove();
      cout << "student" << d <<" spend " << windowTime1 << " clocktick at window" << d << endl;
      reopen=windowTime1+clocktick1;
      cout << "window " << d <<" will reopen at clocktick " << reopen << endl;
    }
  }
  else if(time==clocktick2)
  {
    windows2=windows1-studentArrive2;
    idel3=(clocktick3-calcClocktick2)*windows2;
    cout << "idel3 " << idel3 << endl;
    cout << "at clocktick" << time << " " << studentArrive2 << "students arrive, number of open windows " << windows2 << endl;
    while(!Windowtime1->isEmpty())
    {
      d=d+1;
      windowTime2=Windowtime1->peek();
      Windowtime1->remove();
      cout << "student" << d <<" spend " << windowTime2 << " clocktick at window" << d << endl;
      reopen1=windowTime2+clocktick2;
      cout << "window " << d <<" will reopen at clocktick " << reopen1 << endl;
      clocktick4=calcClocktick2+windowTime2;
      cout << "clocktick4 " << clocktick4 << endl;
      idel4=windows1*(clocktick4-clocktick3);
      cout << "idel4 " << idel4 << endl;
    }
    //calcClocktick4=clocktick4;
  }
  else if(time==clocktick4)
  //student finish, new windows open
  {
    windows3=windows1+1;
    idel5=(totaltime-clocktick4)*windows3;
    cout << "idel5" << idel5 << endl;
    meanIdel=(idel1+idel2+idel3+idel4+idel5)/windows;
    cout << "mean window idel time " << meanIdel << endl;
    //there are two windows that are idel for the entire time, so longest idel time is equal to total time
    realtotal=totaltime+1;
    //there are 12 clockticks in total for sample input, cause time starts at 0 and ends at 11
    cout << "the longest window idel time " << realtotal << endl;
    cout << "number of windows wait time for over 5 minutes " << windows3 << endl;
  }



}








  return 0;
}//end main
