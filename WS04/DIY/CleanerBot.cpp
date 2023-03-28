/*
*****************************************************************************
                            Workshop 4 part 2
Full Name   : Yukti Manoj Mulani
Student ID# : 156809212
Senecamail  : ymulani@myseneca.ca
Date        : June 13, 2022
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <string>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "CleanerBot.h"
using namespace std;
namespace sdds
{
    CleanerBot::CleanerBot()
    {
        m_location = nullptr;
        m_battery = 0;
        m_brushes = 0;
        m_isactive = false;
    }

    CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active)
    {
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
        m_battery = battery;
        m_brushes = brush;
        m_isactive = active;
    }

    CleanerBot::~CleanerBot()
    {
        delete[] m_location;
        m_battery = 0;
        m_location = nullptr;
    }

    void CleanerBot::set(const char* location, double battery, int brush, bool active)
    {
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
        m_battery = battery;
        m_brushes = brush;
        m_isactive = active;
    }

    void CleanerBot::setLocation(const char* location)
    {
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
    }

    void CleanerBot::setActive(bool active)
    {
        m_isactive = active;
    }

    const char* CleanerBot::getLocation() const
    {
        return m_location;
    }

    double CleanerBot::getBattery() const
    {
        return m_battery;
    }

    int CleanerBot::getBrush() const
    {
        return m_brushes;
    }

    bool CleanerBot::isActive() const
    {
        if (m_isactive == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool CleanerBot::isValid() const
    {
        return m_battery > 0 && m_brushes > 0;
    }

    int report(CleanerBot* bot, const short num_bots)
    {
        cout << "         ------ Cleaner Bots Report -----\n";
        cout << "     ---------------------------------------\n";
        printf("| Location   | Battery |  Number of Brushes | Active |\n");
        printf("|------------+---------+--------------------+--------|\n");
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                printf("| %-10s | %7.1lf | %18d | %-6s |\n", bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), bot[i].isActive() ? "YES" : "NO");
            }
        }

        cout << "\n";
        cout << "|====================================================|\n";
        cout << "| LOW BATTERY WARNING:                               |\n";
        cout << "|====================================================|\n";
        int low_battery = 0;
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid() && bot[i].getBattery() < 30)
            {
                low_battery++;
            }
        }
        cout << "| Number of robots to be charged: " << low_battery << "                  |\n";
        cout << "| Sorting robots based on their available power:     |\n";
        cout << "| Location   | Battery |  Number of Brushes | Active |\n";
        cout << "|------------+---------+--------------------+--------|\n";


        CleanerBot abc;
        for (int i = 0; i < num_bots - 1; i++) {
            for (int j = i + 1; j < num_bots; j++) {
                if (bot[i].isValid() && bot[j].isValid()) {
                    if (bot[i].getBattery() < bot[j].getBattery()) {
                        abc = bot[i];
                        bot[i] = bot[j];
                        bot[j] = abc;
                    }
                }
            }
        }

        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                printf("| %-10s | %7.1lf | %18d | %-6s |\n", bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), bot[i].isActive() ? "YES" : "NO");
            }
        }
        cout << "|====================================================|\n";

        return 1;
    }
}
