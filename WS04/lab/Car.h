/*
*****************************************************************************
                            Workshop 4 part 1
Full Name   : Yukti Manoj Mulani
Student ID# : 156809212
Senecamail  : ymulani@myseneca.ca
Date        : June 10, 2022
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
using namespace std;
namespace sdds {
    class Car {
    private:
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;
    public:
        Car();
        Car(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
        ~Car();
        void resetInfo();
        Car& setInfo(const char* type, const char* brand, const char* model, int yera, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car& car) const;
    };
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
}
#endif