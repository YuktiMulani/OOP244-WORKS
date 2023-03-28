#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {


    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }
    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }


    Numbers& Numbers::operator=(const Numbers& src) {
        delete[] m_numbers;
        m_numbers = new double[src.m_numCount];
        m_numCount = src.m_numCount;
        for (int i = 0; i < src.m_numCount; i++) {
            m_numbers[i] = src.m_numbers[i];
        }
        sort();
        return *this;
    }

    Numbers::Numbers(const Numbers& src) {
        setEmpty();
        m_isOriginal = false;
        *this = src;
    }

    bool Numbers::load() {
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream File;
            File.open(m_filename);
            for (int x = 0; x < m_numCount; x++) {
                File >> m_numbers[x];
            }
            File.close();
            return true;
        }
        else return
            false;
    }

    int Numbers::numberCount() const {
        fstream File;
        File.open(m_filename, ios::in);
        string number;
        int counting = 0;
        while (getline(File, number)) {
            counting++;
        }
        File.close();
        return  counting;
    }

    Numbers& Numbers::operator+=(double numbers) {
        double* tem = m_numbers;
        m_numbers = new double[m_numCount + 1];
        m_numCount++;
        for (int y = 0; y < m_numCount; y++) {
            if (y != m_numCount - 1) {
                m_numbers[y] = tem[y];
            }
            else m_numbers[y] = numbers;
        }
        delete[] tem;
        sort();
        return *this;
    }

    void Numbers::save() {
        if (this->m_isOriginal && !isEmpty()) {
            ofstream File;
            File.open(m_filename);
            for (int i = 0; i < m_numCount; i++) {
                File << m_numbers[i] << endl;
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const Numbers& N) {
        return N.display(os);
    }

    std::ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << "=========================\n";
            if (m_isOriginal) {
                ostr << m_filename << endl;
            }
            else {
                ostr << "*** COPY ***\n";
            }
            for (int z = 0; z < m_numCount; z++) {
                if (z != m_numCount - 1) {
                    ostr << m_numbers[z] << ", ";
                }
                else ostr << m_numbers[z];
            }
            ostr << endl;
            ostr << "-------------------------\n";
            ostr << "Total of " << m_numCount << " number(s)\n";
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average :        " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }



    std::istream& operator>>(std::istream& istr, Numbers& N) {
        double number;
        istr >> number;
        N += number;
        return istr;
    }
}
