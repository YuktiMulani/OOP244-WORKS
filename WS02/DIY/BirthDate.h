
#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

#include <iostream>
#include <string>
using namespace std;
namespace sdds {

    struct in {
        char* justname;
        int month;
        int date;
        int year;
    };
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    bool load(in& birthdays);
    bool read(char* stuName);
    bool read(int& stumonth);
    bool beginSearch(const char* filename);
    bool readBirthDate(int month);
    void sort();
    void displayBirthdays();
    void deallocate();
    void endSearch();
}
#endif
