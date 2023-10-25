
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
