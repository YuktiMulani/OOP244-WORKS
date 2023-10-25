
#include "Student.h"
using namespace sdds;
int main() {
   if (load("students.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}