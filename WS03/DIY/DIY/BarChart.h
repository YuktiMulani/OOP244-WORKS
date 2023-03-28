#ifndef SDDS_BARCHART_H // replace with relevant names
#define SDDS_BARCHART_H
#include "Bar.h"
namespace sdds{
    class BarChart
    {
    public:
        BarChart();
        ~BarChart();
        bool validBars();
        void init(const char* title, int noOfSamples, char f);
        void add(const char* bar_title, int value);
        void draw() const;
        void deallocate();
    private:
        const char* charttitle;
        Bar* bars;
        char symbol;
        int barsize;
        int samples;
        bool Umbrella;
    };
}
#endif
