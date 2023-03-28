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
#ifndef _SDDS_SAVINGSACCOUNT_H
#define _SDDS_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"
namespace sdds {
	class SavingsAccount : public Account {
	private:
		double m_interestRate;
	public:
		SavingsAccount(double, double);
		void  monthEnd();
		void  display(std::ostream&) const;
	};
}

#endif