/******************************************************
				Milestone-3
	NAME          :
	EMAIL         :
	STUDENT ID    :
	DATE COMPLETED:
	I have done all the coding by myself
	and only copied the code that my professor provided
	to complete my workshops and assignments.
********************************************************/

// Final Project Milestone 3
// Publication Module
// File  Publication.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include <iostream>
#include <iomanip>
#include <cstring>
namespace sdds {
	Publication::Publication() {
		setDefault();
	}
	Publication::Publication(const Publication& p) {
		*this = p;
	}
	Publication& Publication::operator=(const Publication& p) {
		set(p.m_membership);
		setRef(p.m_libRef);
		strcpy(m_shelfId, p.m_shelfId);
		m_date = p.m_date;
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		if (p.m_title != nullptr)
		{
			m_title = new char[strlen(p.m_title) + 1];
			strcpy(m_title, p.m_title);
		}
		else {
			m_title = nullptr;
		}
		return *this;
	}
	
	Publication::~Publication() {
		delete[] m_title;
	}
	
	void Publication::setDefault() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	
	void Publication::resetDate() {
		m_date = Date();
	}

	
	char Publication::type() const {
		return 'P';
	}
	
	bool Publication::onLoan() const {
		return (m_membership != 0);
	}
	
	Date Publication::checkoutDate() const {
		return m_date;
	}

	bool Publication::operator==(const char* title) const {
		return strstr(m_title, title) != nullptr;
	}
	
	Publication::operator const char* () const {
		return m_title;
	}
	
	int Publication::getRef() const {
		return m_libRef;
	}


	bool Publication::conIO(std::ios & io) const {
		return &io == &std::cin || &io == &std::cout;
	}
	
	std::ostream& Publication::write(std::ostream& os) const {
		char t[SDDS_TITLE_WIDTH + 1] = { 0 };
		std::strncpy(t, m_title, SDDS_TITLE_WIDTH);
		if (conIO(os)) {
			os << "| " << m_shelfId << " | " << std::setw(30) << std::left <<
				std::setfill('.') << t << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | " << m_date << " |";
		}
		else {
			os << type();
			os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << "\t" << m_date;
		}
		return os;
	}
	
	std::istream& Publication::read(std::istream& istr) {
		
		char title[256]{}, shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int libRef = -1, membership = 0;
		Date date;
		
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		setDefault();
		if (conIO(istr)) {
			std::cout << "Shelf No: ";
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(std::ios::failbit);
			}
			std::cout << "Title: ";
			istr.getline(title, 256);
			std::cout << "Date: ";
			istr >> date;
		}
		else 
		{
			istr >> libRef;
			istr.ignore();
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(title, 256, '\t');
			istr >> membership;
			istr.ignore();
			istr >> date;
		}
		if (!date) {
			istr.setstate(std::ios::failbit);
		}
		if (istr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return istr;
	}
	Publication::operator bool() const {
		bool ans = false;
		if (m_title != nullptr && m_shelfId[0] != '\0') {
			ans = true;
		}
		return ans;
	}

	std::ostream& operator<<(std::ostream& o, const Publication& p) {
		if (p)
		{
			p.write(o);
		}
		return o;
	}
	std::istream& operator>>(std::istream& i, Publication& p)
	{
		return (p.read(i));
	}
}