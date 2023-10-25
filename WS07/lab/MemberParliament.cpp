

#define _CRT_SECURE_NO_WARNINGS
#include "MemberParliament.h"
#include <iomanip>
#include <cstring>

namespace sdds {

    MemberParliament::MemberParliament() {
        setEmpty();
    }

    MemberParliament::MemberParliament(const char* ID, int AGE) {
        strcpy(p_Id, ID);
        mp_Age = AGE;
        strcpy(d_Rep, "Unassigned");
    }

    void MemberParliament::NewDistrict(const char* district) {
        std::cout << "|  " << p_Id << "| |" << std::setw(20) << std::right << d_Rep << " ---> " << std::setw(23) << std::left << district << "|" << std::endl;
        strcpy(d_Rep, district);
    }

    std::ostream& MemberParliament::write(std::ostream& ost) const {
        ost << "| " << p_Id << " | " << mp_Age << " | " << d_Rep;
        return ost;
    }

    std::istream& MemberParliament::read(std::istream& ist) {
        std::cout << "Age: ";
        ist >> mp_Age;
        std::cout << "Id: ";
        ist >> p_Id;
        std::cout << "District: ";
        ist >> d_Rep;

        return ist;
    }

    void MemberParliament::setEmpty() {
        p_Id[0] = '\0';
        d_Rep[0] = '\0';
        mp_Age= 0;
    }

    std::ostream& operator<<(std::ostream& ost, const MemberParliament& M) {
        return M.write(ost);
    }

    std::istream& operator>>(std::istream& ist, MemberParliament& M) {
        return M.read(ist);
    }

    // 
    const char* MemberParliament::getID() const {
        return p_Id;
    }

    const char* MemberParliament::getDistrict() const {
        return d_Rep;
    }

    int MemberParliament::getAge() const {
        return mp_Age;
    }
}