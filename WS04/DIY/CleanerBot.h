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
#ifndef SDDS_CLEANERBOT_H // replace with relevant names
#define SDDS_CLEANERBOT_H
namespace sdds {
    class CleanerBot {
        char* m_location;
        double m_battery;
        int m_brushes;
        bool m_isactive;
    public:
        CleanerBot();
        CleanerBot(const char* location, double battery, int brush, bool active);
        ~CleanerBot();
        void set(const char* location, double battery, int brush, bool active);
        void setLocation(const char* location);
        void setActive(bool active);
        const char* getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        void display() const;
        
    };
    int report(CleanerBot* bot, const short num_bots);
    void sort(CleanerBot* bot, int num_bots);
}
#endif 