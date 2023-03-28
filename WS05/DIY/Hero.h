/*
*****************************************************************************
                            Workshop 5 part 2
Full Name   : Yukti Manoj Mulani
Student ID# : 156809212
Seneca email: ymulani@myseneca.ca
Date        : June 20, 2022
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


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