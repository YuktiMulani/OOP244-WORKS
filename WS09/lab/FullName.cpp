
#define _CRT_SECURE_NO_WARNINGS
#include "FullName.h"
#include"FullName.h"
#include<iostream>
#include<string.h>
using namespace std;
namespace sdds {
	FullName::FullName() :Name() {
		this->m_value = nullptr;
	}
	FullName::FullName(const char* name, const char* lastName) :
		Name(name)
	{
		this->m_value = new char[strlen(lastName) + 1];
		strcpy(m_value, lastName);
	}
	FullName::FullName(const FullName& obj) :Name(obj.Name::operator const char* ()) {
		this->m_value = new char[strlen(obj.m_value) + 1];
		strcpy(m_value, obj.m_value);
	}
	FullName& FullName::operator=(const FullName& other)
	{
		//	this->~FullName();
		this->Name::operator =(other);
		if (m_value != nullptr) {
			delete[] m_value;
		}
		this->m_value = new char[strlen(other.m_value) + 1];
		strcpy(m_value, other.m_value);
		return *this;

	}
	FullName::~FullName() {
		if (m_value != nullptr) {
			delete[] m_value;
		}
	}
	FullName::operator const char* () const {
		return m_value;
	}
	FullName::operator bool() const {
		return (Name::operator bool() == true) && (this->m_value != nullptr);
	}
	std::ostream& FullName::display(std::ostream& ostr) const
	{
		if ((bool)this) {
			Name::display(ostr);
			ostr << " " << m_value;
		}
		return ostr;

	}
	std::istream& FullName::read(std::istream& istr)
	{
		Name::read(istr);
		char c[100];
		istr.getline(c, 100);
		if (!istr.fail()) {
			if (m_value != nullptr) {
				delete[]m_value;
			}
			m_value = new char[strlen(c) + 1];
			strcpy(m_value, c);
		}
		return istr;
		// // O: insert return statement here
	}
}
