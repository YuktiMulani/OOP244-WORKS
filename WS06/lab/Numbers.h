#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
    public:
        Numbers();
        Numbers(const char* filename);//copy constructor
        Numbers& operator=(const Numbers&);
        ~Numbers();
        Numbers(const Numbers&);
        double average()const;
        double max()const;
        double min()const;
        bool load();
        void save();
        int numberCount() const;
        Numbers& operator+=(double);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::istream& operator>>(std::istream& istr, Numbers& N);
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
}
#endif // !SDDS_NUMBERS_H_


