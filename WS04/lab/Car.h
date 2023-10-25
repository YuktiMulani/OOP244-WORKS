
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