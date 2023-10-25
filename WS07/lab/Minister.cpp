

#define _CRT_SECURE_NO_WARNINGS
#include "Minister.h"
#include <iomanip>
#include <cstring>

namespace sdds {
    Minister::Minister() {
        setEmpty();
    }

    Minister::Minister(const char* id, int age, double Y, const char* _name, const char* district) : MemberParliament(id, age) {
        MemberParliament::NewDistrict(district);
        strcpy(pm_Name, _name);
        this->Y = Y;
    }

    void Minister::changePM(const char* ch) {
        strcpy(pm_Name, ch);
    }

    void Minister::assumeOffice(double _year) {
        this->Y = _year;
    }

    std::ostream& Minister::write(std::ostream& ost) const {
        ost << "| " << getID() << " | " << getAge() << " | " << getDistrict() << " | " << pm_Name << "/" << Y;
        return ost;
    }

    std::istream& Minister::read(std::istream& ist) {
        char ref_To[MAX_NAME_LEN];
        double off_Year;

        MemberParliament::read(ist);
        std::cout << "Reports TO: ";
        ist >> ref_To;
        std::cout << "Year Assumed Office: ";
        ist >> off_Year;
        setName(ref_To);
        setYear(off_Year);

        return ist;
    }

    std::ostream& operator<<(std::ostream& ost, const Minister& M) {
        return M.write(ost);
    }
    std::istream& operator>>(std::istream& ist, Minister& M) {
        return M.read(ist);
    }

    void Minister::setEmpty() {
        MemberParliament::setEmpty();
        pm_Name[0] = '\0';
        Y = 0;
    }

    void Minister::setName(const char* _name) {
        strcpy(pm_Name, _name);
    }
    void Minister::setYear(double _year) {
        this->Y = _year;
    }
}