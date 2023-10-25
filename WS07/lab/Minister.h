

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#define MAX_NAME_LEN 50

#include "MemberParliament.h"
#include <iostream>

namespace sdds {
    class Minister : public MemberParliament {
    private:
        char pm_Name[MAX_NAME_LEN];
        double Y;
    public:
        Minister();
        Minister(const char* id, int age, double Y, const char* _name, const char* district);
        void changePM(const char* ch);
        void assumeOffice(double _year);
        std::ostream& write(std::ostream& ost = std::cout) const;
        std::istream& read(std::istream& ist = std::cin);

        
        void setEmpty();
        void setName(const char* _name);
        void setYear(double _year);
    };
    
    std::ostream& operator<<(std::ostream& ost, const Minister& M);
    std::istream& operator>>(std::istream& ist, Minister& M);
};

#endif //SDDS_MINISTER_H
