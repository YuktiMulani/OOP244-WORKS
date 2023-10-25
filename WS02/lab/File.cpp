
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