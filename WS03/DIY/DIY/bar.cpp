#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Bar.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
    Bar::Bar()
    {
        gamet = nullptr;
        gametn = nullptr;
        gametns = ' ';
        gthn = 0;
        doit = 0;
        working = false;
    }
    Bar::Bar(const char* title, char symbol, int value)
    {
        gamet = new char[strlen(title) + 1];
        strcpy(gamet, title);
        gametns = symbol;
        gthn = value;
        doit = 0;
        working = true;
    }
    Bar::~Bar()
    {
        delete[] gamet;
        gamet = nullptr;
        gametn = nullptr;
    }
    void Bar::set(const char* title, char symbol, int value)
    {
        if (value <= 0 || value > 100) {
            working = false;
            return;
        }
        value /= 2;
        gamet = new char[strlen(title) + 1];
        strcpy(gamet, title);
        gametns = symbol;
        gthn = value;
        doit = 0;
        working = true;
    }
    bool Bar::isBarValid() const
    {
        return working;
    }
    void Bar::draw() const
    {
        if (working)
        {
            int ind = 0;
            for (ind = 0; gamet[ind] != '\0'; ind++) {
                cout << gamet[ind];
            }
            while (ind < 20) {
                cout << ".";
                ind++;
            }
            cout << "|";
            for (int i = 0; i < gthn; i++)
            {
                cout << gametns;
            }
            cout << endl;
        }
    }
}
