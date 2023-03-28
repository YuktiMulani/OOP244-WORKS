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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BirthDate.h"
using namespace std;

namespace sdds {
    in* birthdays;
    int findmonth;
    int numofrecord;
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

    bool read(char* stuName) {
        return fscanf(fptr, "%[^,],", stuName) == 1;
    }

    bool read(int& stumonth) {
        return fscanf(fptr, "%d/", &stumonth) == 1;
    }

    bool load(in& birthdays) {
        char sname[128];
        if (read(sname) && read(birthdays.month) && read(birthdays.date) && read(birthdays.year)) {
            birthdays.justname = new char[strlen(sname) + 1];
            strcpy(birthdays.justname, sname);
        }
        return true;
    }
    bool beginSearch(const char* filename) {
        findmonth = 0;
        numofrecord = 0;
        int i = 0, j = 0;
        if (openFile(filename)) {
            numofrecord = noOfRecords();
            birthdays = new in[numofrecord];
            for (j = 0; j < numofrecord; j++) {
                i += load(birthdays[j]);
            }
            if (i != numofrecord) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted.\n";
            }
            closeFile();
        }
        cout << "Birthdate search program\n";
        return true;
    }

    bool readBirthDate(int month) {
        for (int i = 0; i < numofrecord; i++) {
            if (birthdays[i].month == month) {
                findmonth = month;
                return true;
            }
        }
        return false;
    }
    void sort() {
        int i, j;
        in temp;
        for (i = numofrecord - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (birthdays[j].year > birthdays[j + 1].year) {
                    temp = birthdays[j];
                    birthdays[j] = birthdays[j + 1];
                    birthdays[j + 1] = temp;
                }
                else if (birthdays[j].year == birthdays[j + 1].year && birthdays[j].month > birthdays[j + 1].month) {
                    temp = birthdays[j];
                    birthdays[j] = birthdays[j + 1];
                    birthdays[j + 1] = temp;
                }
            }
        }

    }

    void displayBirthdays() {
        int count = 0, ind = 1;
        for (int i = 0; i < numofrecord; i++) {
            if (birthdays[i].month == findmonth) {
                count++;
            }
        }
        cout << count << " birthdates found:\n";
        for (int i = 0; i < numofrecord; i++) {
            if (birthdays[i].month == findmonth) {
                cout << ind << ") ";
                string s;
                for (int j = 1; j < (int)strlen(birthdays[i].justname); j++) {
                    s += birthdays[i].justname[j];
                }
                cout << s << ":" << endl;
                cout << birthdays[i].year << "-" << birthdays[i].month << "-" << birthdays[i].date << endl;
                cout << "===================================\n";
                ind++;
            }
        }
    }
    void deallocate() {
        for (int i = 0; i < numofrecord; i++) {
            delete[] birthdays[i].justname;
        }
        delete[] birthdays;

    }
    void endSearch() {
        cout << "Birthdate Search Program Closed.\n";
    }
}
