# 350assignment4

Name: Yuki Chen
Email: yingchen@chapman.edu
Student ID: 2320235

purpose: simulate students and windows conditions in the registrar office
         read from a file to get the number of students come in and the time they spend at the windows
         output statistics of window idel and student wait time

source file: doubly1.h
             doubly1.cpp
             doublylinkedlist1.h
             doublylinkedlist1.cpp
             Queue.h
             Queue.cpp
             RegistrarMain1.cpp OR RegistrarMain2.cpp


errors: I have two main programs, one get user input from command line argument, one from standard user input
        because my docker is not working anymore, my command line argument outputs segmentation fault with my current compiler, i think it might not output error if you run it in docker when you grade it  
        please grade RegistrarMain2.cpp (the one with command line argument) if it doesn't output segmentation fault
        other wise please grade RegistrarMain1.cpp (the one with standard user input)
        Also, my program only outputs the correct results when using sample input file (wait.txt), cause it can only take in certain amount of variables when reading from a file 

reference:
https://stackoverflow.com/questions/9235296/how-to-detect-empty-lines-while-reading-from-istream-object-in-c line.empty() function
