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
#ifndef  _SDDS_CHEQUINGACCOUNT_H
#define  _SDDS_CHEQUINGACCOUNT_H
#include <iostream>
#include "iAccount.h"
#include "Account.h"
namespace sdds {
	class ChequingAccount :public Account {
		double m_trans_fee;
		double m_month_fee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};

	
}
#endif