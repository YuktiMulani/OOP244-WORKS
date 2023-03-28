/*
*****************************************************************************
							Workshop 2 part 1
Full Name   : Yukti Manoj Mulani
Student ID# : 156809212
Senecamail  : ymulani@myseneca.ca
Date        : May 30, 2022
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
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
