/*
*****************************************************************************
                            Workshop 2 part 1
Full Name   : Yukti Manoj Mulani
Student ID# : 156809212
Senecamail  : ymulani@myseneca.ca
Date        : May 27, 2022
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char name[]);
   bool read(int& number);
   bool read(char& Grade);
  
}
#endif // !SDDS_FILE_H_
