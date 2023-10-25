
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
    int noOfStudents;
    Student* students;
    void sort() {
       int i, j;
       Student temp;
       for (i = noOfStudents - 1; i > 0; i--) {
          for (j = 0; j < i; j++) {
             if (students[j].m_grade > students[j + 1].m_grade) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
             }
          }
       }
    }
    bool load(Student& stu) {
        bool ok = false;
        char sname[128];
        int stu_number = 0;
        char stu_grade = 0;
        if (read(sname)) {

            stu.m_name = new char[strlen(sname) + 1];// it is allocation the size of the char array m_name.

            strcpy(stu.m_name, sname);// it is now copying the name to m_name char array.

            if (read(stu_number) && read(stu_grade))
            {
                stu.m_studentNumber = stu_number;
                stu.m_grade = stu_grade;
                ok = true;
            }
        }
        return ok;
    }

    bool load(const char* stufile) {
        bool ok = false;
        int i = 0;
        int count_st = 0;
        if (openFile(DATAFILE)) {
            noOfStudents = noOfRecords();
            students = new Student[noOfStudents];
            for (i = 0; i < noOfStudents; i++)
            {
                load(students[i]);
                count_st++;
            }
            if (sdds::noOfStudents != count_st)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Couldnt open the file" << endl;
        }
        return ok;
    }

    void display(const Student& stu)
    {
        cout << stu.m_name << ", " << stu.m_studentNumber << ": " << stu.m_grade << endl;
    }

    void display()
    {
        int i;
        sort();
        for (i = 0; i < noOfStudents; i++)
        {
            cout << i + 1 << ": ";
            display(students[i]);
        }
    }

    void deallocateMemory()
    {
        int i;

        for (i = 0; i < noOfStudents; i++)
        {
            Student& stu = students[i];//why?
            delete[] stu.m_name;
        }
        delete[] students;
    }
}
