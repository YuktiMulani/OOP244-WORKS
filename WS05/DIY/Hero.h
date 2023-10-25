

#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>
#include "Power.h"
namespace sdds
{

    class Hero
    {
        char m_name[MAX_NAME_LENGTH + 1]{};
        Power* m_powers{};
        int m_no_powers{};
        int m_power_level{};

    public:
        Hero();
        Hero(const char* name, Power* powers, int no_powers);
        ~Hero();
        std::ostream& display(std::ostream& os = std::cout) const;
        int getPowerLevel() const;
        Hero& operator+=(const Power& P);
        Hero& operator-=(int& value);
    };
    bool operator<(const Hero& h1, const Hero& h2);
    bool operator>(const Hero& h1, const Hero& h2);
    // used the appropriate datatypes for >> and << for the below types to allow cascading effect
    Power& operator>>(Power& p, Hero& h);
    Hero& operator<<(Hero& h, Power& p);
    std::ostream& operator<<(std::ostream& os, const Hero& h);

}

#endif // SDDS_HERO_H