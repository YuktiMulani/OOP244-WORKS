
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {
    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;

    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }
    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }
    int Date::daysSince0001_1_1()const {
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }
    Date::Date() :m_CUR_YEAR(systemYear()) {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }
    int Date::errCode()const {
        return m_ErrorCode;
    }
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }

    bool Date::extractChar(std::istream& istr, char ch) {
        if (istr.peek() == ch) {
            istr.get();
            return true;
        }
        else {

            errCode(CIN_FAILED);
            istr.setstate(ios::failbit);
            istr.clear(); //clear bad input flag
            istr.ignore(80, '\n');
            return false;

        }
    }



    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }
    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }



    ////
    //std::istream& Date::read(std::istream& i)
    //{

    //    int year, month, date;
    //    i >> year;

    //    if (extractChar(i, '/'))
    //    {

    //        i >> month;

    //        if (extractChar(i, '/'))
    //        {
    //            i >> date;
    //        }
    //        else
    //        {
    //            return i;
    //        }
    //    }
    //    else
    //    {
    //        return i;
    //    }

    //    if (!i.fail())
    //    {
    //        m_year = year;
    //        m_mon = month;
    //        m_day = date;
    //       /* validate();*/
    //    }
    //    return i;
    //}

    std::istream& Date::read(std::istream& i)
    {
        int y, m, d;
        char ch;
        errCode(NO_ERROR);
        i >> y >> ch >> m >> ch >> d;
        m_year = y;
        m_mon = m;
        m_day = d;
        if (!i.fail())
        {
            validate();
        }
        else
        {
            errCode(CIN_FAILED);
            i.clear();
        }
        /* cin.ignore(1000, '\n');*/
        return i;
    }

    std::ostream& Date::write(std::ostream& o)const
    {

        if (!bad())
        {
            o << m_year << "/" << "0" << m_mon << "/" << m_day;
        }
        else
        {
            o << dateStatus();
        }
        return o;
    }

    bool Date::operator==(const Date& D)const
    {
        if (this->m_year == D.m_year && this->m_mon == D.m_mon && this->m_day == D.m_day) {
            return true;
        }
        return false;
    }

    bool Date::operator!=(const Date& D)const
    {
        return !(*this == D);
    }

    bool Date::operator>=(const Date& D)const
    {
        return (*this > D) || (*this == D);
    }

    bool Date::operator<=(const Date& D)const
    {
        return (*this < D) || (*this == D);
    }

    bool Date::operator<(const Date& D) const {

        if (this->m_year < D.m_year)
        {
            return true;
        }
        else if (this->m_year > D.m_year)
        {
            return false;
        }
        else {

            if (this->m_mon < D.m_mon) {
                return true;
            }
            else if (this->m_mon > D.m_mon)
            {
                return false;
            }
            else {
                if (this->m_day < D.m_day) {
                    return true;
                }
                else if (this->m_day > D.m_day)
                {
                    return false;
                }
                else {
                    return false;
                }
            }
        }
        return false;
    }

    bool Date::operator>(const Date& D)const
    {

        if (this->m_year > D.m_year)
        {
            return true;
        }
        else if (this->m_year < D.m_year)
        {
            return false;
        }
        else {

            if (this->m_mon > D.m_mon) {
                return true;
            }
            else if (this->m_mon < D.m_mon)
            {
                return false;
            }
            else
            {
                if (this->m_day > D.m_day)
                {
                    return true;
                }
                else if (this->m_day < D.m_day)
                {
                    return false;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }

    long int Date::operator-(Date n)const
    {
        return (daysSince0001_1_1() - n.daysSince0001_1_1());
    }

    Date::operator bool() const
    {
        return !bad();
    }
}