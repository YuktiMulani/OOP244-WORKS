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
#ifndef _SDDS_ACCOUNT_H
#define _SDDS_ACCOUNT_H
#include <iostream>
#include "iAccount.h"
namespace sdds {
	class Account :public iAccount {
	public:
		Account();
		Account(double);
		bool credit(double);
		bool debit(double);
		
	protected:
		double balance() const;
		double m_curr_bal;
	};
}

#endif