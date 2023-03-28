/******************************************************
				Workshop-8 Part-1
	NAME          : Yukti Manoj Mulani
	EMAIL         : ymulani@myseneca
	STUDENT ID    : 156809212
	DATE COMPLETED: 21-Jul-2022
	I have done all the coding by myself
	and only copied the code that my professor provided
	to complete my workshops and assignments.
********************************************************
*/
#include <iostream>
#include "Account.h"
#include "iAccount.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {
	Account::Account() {
		m_curr_bal = 0.0;
	}
	Account::Account(double initial_bal) {
		if (initial_bal > 0) {
			m_curr_bal = initial_bal;
		}
		else {
			m_curr_bal = 0;
		}
	}
	bool Account::credit(double credit) {
		bool success;
		if (credit > 0) {
			m_curr_bal +=credit;
			success = true;
		}
		else {
			success = false;
		}
		return success;
	}
	bool Account::debit(double debit) {
		bool success;
		if (debit >= 0) {
			m_curr_bal =m_curr_bal- debit;
			success = true;
		}
		else {
			success = false;
		}
		return success;
	}
	double Account::balance() const {
		return m_curr_bal;
	}

}