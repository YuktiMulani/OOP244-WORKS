#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "BarChart.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{

    BarChart::BarChart()
    {
        samples = 0;
        Umbrella = false;
    }
    BarChart::~BarChart()
    {

    }
    bool BarChart::validBars()
    {
        return Umbrella;
    }
    void BarChart::init(const char* title, int noOfSamples, char f)
    {
        bars = new Bar[noOfSamples];
        barsize = noOfSamples;
        symbol = f;
        charttitle = title;
    }
    void BarChart::add(const char* bar_title, int value)
    {
        Bar* b = (Bar*)malloc(sizeof(Bar) * 5);
        if (samples <= barsize)
        {
            b->set(bar_title, symbol, value);
            bars[samples] = *b;
            samples += 1;
        }
        if (samples == barsize)
        {
            Umbrella = true;
        }
        else
        {
            Umbrella = false;
        }
        free(b);
    }
    void BarChart::draw() const
    {
        if (Umbrella)
        {
            bool validateBars = false;
            for (int i = 0; i < barsize; i++)
            {
                if (bars[i].isBarValid())
                {
                    validateBars = true;
                }
                else
                {
                    validateBars = false;
                }
            }
            if (validateBars)
            {
                cout << charttitle << endl;
                for (int d = 0; d < 71; d++)
                {
                    cout << "-";
                }
                cout << endl;
                for (int b = 0; b < barsize; b++)
                {
                    bars[b].draw();
                }
                for (int d = 0; d < 71; d++)
                {
                    cout << "-";
                }
                cout << endl;
            }

        }
        else
        {
            cout << "Invalid Chart!" << endl;
        }
    }
    void BarChart::deallocate()
    {
        delete[] bars;
    }
}