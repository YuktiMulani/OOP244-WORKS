
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