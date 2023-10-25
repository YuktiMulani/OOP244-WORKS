

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>

#define MAX_IDLENGTH 32
#define MAX_DISTRICTLENGTH 64

namespace sdds {
    class MemberParliament {
    private:
        char p_Id[MAX_IDLENGTH];
        char d_Rep[MAX_DISTRICTLENGTH];
        int mp_Age;
    public:
        MemberParliament();
        MemberParliament(const char* ID, int AGE);
        void NewDistrict(const char* district);
        std::ostream& write(std::ostream& ost = std::cout) const;
        std::istream& read(std::istream& ist = std::cin);

        
        void setEmpty();

        
        const char* getID() const;
        const char* getDistrict() const;
        int getAge() const;
    };
    
    std::ostream& operator<<(std::ostream& ost, const MemberParliament& M);
    std::istream& operator>>(std::istream& ist, MemberParliament& M);
}


#endif // SDDS_MEMBERPARLIAMENT_H