/******************************************************
                Workshop-9 Part-1
    NAME          : Yukti Manoj Mulani
    EMAIL         : ymulani@myseneca
    STUDENT ID    : 156809212
    DATE COMPLETED: 29-Jul-2022
    I have done all the coding by myself
    and only copied the code that my professor provided
    to complete my workshops and assignments.
********************************************************
*/
#ifndef SDDS_NAME_H_
#define SDDS_NAME_H_
#include<iostream>
using namespace std;
namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();
        Name(const char* name);
        // Rule of three goes here:
        Name(const Name& old_obj);
        Name& operator=(const Name& other);
        ~Name();

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    istream& operator>>(istream& in, Name& name);
    ostream& operator<<(ostream& out, Name& name);
}
#endif