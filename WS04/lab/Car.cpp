
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
using namespace std;
namespace sdds {
    void Car::resetInfo() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }
    Car::Car() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        resetInfo();
    }
    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price) {
        if (type != nullptr && brand != nullptr && model != nullptr && year > 0 && code > 0 && price > 0) {
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        else {
            resetInfo();
        }
    }
    Car::~Car() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
    }

    Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        this->resetInfo();
        if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code <= 99 || price <= 0) {
            return *this;
        }
        else {
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        return *this;
    }

    void Car::printInfo()const {

        if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code > 99 && m_price > 0) {
            printf("| %-10s | %-15s  | %-15s  | %-4d | %4d |  %8.2lf |\n", m_type, m_brand, m_model, m_year, m_code, m_price);
        }

    }

    bool Car::isValid()const {

        if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_price > 0) {

            return true;
        }
        else {

            return false;
        }
    }

    bool Car::isSimilarTo(const Car& other)const {
        if (m_type == other.m_type && m_brand == other.m_brand && m_model == other.m_model && m_year == other.m_year) {
            return true;
        }
        else {
            return false;
        }
        return false;
    }

    bool has_similar(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool has_invalid(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            if (!car[i].isValid()) {
                return true;
            }
        }
        return false;
    }

    void print(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            car[i].printInfo();
        }
    }
}
