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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(char sname[]) {
       return fscanf(fptr, "%[^,],", sname) == 1;
   }
   bool read(int& snumber) {
       return fscanf(fptr, "%d,", &snumber) == 1;
   }
   bool read(char& sgrade) {
       return fscanf(fptr, "%c\n", &sgrade) == 1;
   }

}