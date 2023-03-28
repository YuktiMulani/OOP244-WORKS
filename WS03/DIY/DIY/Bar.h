#ifndef SDDS_BAR_H // replace with relevant names
#define SDDS_BAR_H
#include <cstring>
namespace sdds
{
    class Bar
    {
        char* gamet;
        Bar* gametn;
        char gametns;
        int  gthn;
        int doit;
        bool working;

    public:
        Bar();
        Bar(const char* title, char symbol, int value);
        ~Bar();
        void set(const char* title, char symbol, int value);
        bool isBarValid() const;
        void draw() const;
    };
}

#endif