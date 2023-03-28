#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include "Basket.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds {
	Basket::Basket() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}
	Basket::Basket(Fruit* fruit, int cnt, double price) {
		if (cnt > 0 && price > 0 && fruit!=nullptr){
			m_cnt = cnt;
			m_price = price;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; m_fruits[i] = fruit[i], i++) {
				;
			}
			
		}

	}
	Basket::Basket(const Basket& src) {
		*this = src;
	}
	Basket&Basket::operator=(const Basket& src) {
		if (this != &src)
		{

			delete[] m_fruits;
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
			if (src.m_fruits && src.m_cnt > 0)
			{
				m_cnt = src.m_cnt;
				m_price = src.m_price;
				m_fruits = new Fruit[m_cnt];
				for (int i = 0; i < m_cnt; m_fruits[i] = src.m_fruits[i], i++)
					;
			}
		}
		return *this;
	}
	Basket::~Basket() {
		delete[] m_fruits;
	}
	void Basket::setPrice(double price) {
		m_price += price;
	}
	Basket::operator bool()const {
		return m_cnt>0;
	}
	Basket&Basket:: operator+=(Fruit F) {
		Fruit* temp_array = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; temp_array[i] = m_fruits[i], i++)
			;
		temp_array[m_cnt] = F;
		delete[] m_fruits;
		m_fruits = temp_array;
		m_cnt++;
		return *this;
	}
	std::ostream& Basket::display(std::ostream& os) const {
		
		if(operator bool()) {
			os << "Basket Content:" << endl;
			for (int i = 0; i < m_cnt; i++) {
				os.setf(std::ios::right);
				os.width(10);
				os << m_fruits[i].m_name << ": ";
				os.unsetf(std::ios::right);
				os.setf(std::ios::fixed);
				os.precision(2);
				os << m_fruits[i].m_qty << "kg" << endl;
				os.unsetf(std::ios::fixed);

			}
			os << "Price: ";
			os.setf(std::ios::fixed);
			os.precision(2);
			os<< m_price<<endl ;
			os.unsetf(std::ios::fixed);

		}
		else {
			os << "The basket is empty!" << endl;
		}
		return os;
	}
	std::ostream& operator<<(std::ostream& os, Basket& B) {
		return B.display(os);
	}
}