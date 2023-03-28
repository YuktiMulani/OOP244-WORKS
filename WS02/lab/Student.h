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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define DATAFILE "simpsons.csv"


namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
    void sort();
    bool load(Student& stu);
    bool load(const char* stufile);
    void display(const Student& student);
    void display();
    void deallocateMemory();
}
#endif // SDDS_STUDENT_H_