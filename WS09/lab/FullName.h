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
#ifndef SDDS_FULLNAME_H_
#define SDDS_FULLNAME_H_
#include<iostream>
#include"Name.h"
using namespace std;
namespace sdds {
    class FullName : public Name {
        char* m_value;
    public:
        FullName();
        FullName(const char* name, const char* lastName);
        // Rule of three goes here:
        FullName(const FullName& obj);
        FullName& operator=(const FullName& other);
        ~FullName();


        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
}
#endif