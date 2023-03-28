#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}
    Book Book::operator++(int)
    {
        Book copy = *this;
        m_num_chapters++;
        return copy;
    }
    int Book::add_chapter(Chapter* C)
    {
        m_chapters[m_num_chapters] = *C;
        m_num_pages += C->operator int();
        operator++(1);
        return m_num_chapters;
    }
    std::ostream& Book::display(std::ostream& os) const
    {
        os << "Title:'" << m_title << "'" << endl;
        os << "Author: '" << m_author << "'" << endl;

        for (int i = 0; i < m_num_chapters; i++)
        {
            os << m_chapters[i];
        }
        return os;
    }
    Book::operator int() const
    {
        return m_num_chapters;
    }
    Book::operator bool() const
    {
        bool result = false;
        for (int i = 0; i < m_num_chapters && !result; i++)
        {
            if (m_chapters[i].operator int() > 0)
            {
                result = true;
            }
        }
        return result && m_title[0] && m_author[0];
    }
    Book::operator double() const
    {
        return m_price;
    }
    Book::operator const char* () const
    {
        return m_title;
    }
    bool Book::operator!() const
    {
        return !operator bool();
    }
    Book& Book::operator+=(Chapter C)
    {
        add_chapter(&C);
        return *this;
    }
    Book& Book::operator-=(double value)
    {
        m_price -= value;
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Book& B)
    {
        return B.display(os);
    }
}
