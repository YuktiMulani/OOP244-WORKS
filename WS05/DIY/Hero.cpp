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


#include <iostream>
#include <cstring>
#include "Hero.h"
#include <string>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
namespace sdds
{
    Hero::Hero()
    {
        m_name[0] = '\0';
        m_powers = nullptr;
        m_no_powers = '\0';
        m_power_level = '\0';
    }
    Hero::Hero(const char* name, Power* powers, int no_powers)
    {
        strcpy(m_name, name);
        m_powers = new Power[no_powers];
        int sum{};
        for (int i = 0; i < no_powers; i++)
        {
            m_powers[i] = powers[i];
            sum += m_powers[i].checkRarity();
        }
        m_no_powers = no_powers;
        m_power_level = no_powers * sum;
    }
    Hero::~Hero()
    {
        delete[] m_powers;
    }
    std::ostream& Hero::display(std::ostream& os) const
    {
        os << "Name: " << m_name << std::endl;
        displayDetails(m_powers, m_no_powers);
        os << "Power Level: " << m_power_level;
        return os;
    }
    int Hero::getPowerLevel() const
    {
        return m_power_level;
    }
    Hero& Hero::operator+=(const Power& P)
    {

        Power* temp = new Power[m_no_powers + 1];
        int sum{};
        for (int i = 0; i < m_no_powers; i++)
        {
            temp[i] = m_powers[i];
            sum += m_powers[i].checkRarity();
        }
        temp[m_no_powers] = P;
        sum += temp[m_no_powers].checkRarity();
        m_no_powers = m_no_powers + 1;
        delete[] m_powers;
        m_powers = temp;
        m_power_level = sum * m_no_powers;
        return *this;
    }
    Hero& Hero::operator-=(int& value)
    {
        m_power_level -= value;
        return *this;
    }
    bool operator<(const Hero& h1, const Hero& h2)
    {
        return h1.getPowerLevel() < h2.getPowerLevel();
    }
    bool operator>(const Hero& h1, const Hero& h2)
    {
        return h1.getPowerLevel() > h2.getPowerLevel();
    }
    Power& operator>>(Power& p, Hero& h)//cascading effect for Power  eg : p>>h1>>h2>>h3 will also work
    {
        h += p;
        return p;
    }
    Hero& operator<<(Hero& h, Power& p)//cascading effect for Power  eg : h<<p1<<p2<<p3 will also work
    {
        h += p;
        return h;
    }
    std::ostream& operator<<(std::ostream& os, const Hero& h)
    {
        return h.display(os);
    }

};