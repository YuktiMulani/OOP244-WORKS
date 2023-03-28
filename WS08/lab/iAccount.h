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
#ifndef _SDDS_IACCOUNT_H
#define _SDDS_IACCOUNT_H
#include <iostream>
namespace sdds {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void  monthEnd() = 0;
		virtual void  display(std::ostream&) const = 0;
		virtual ~iAccount();

	};
	iAccount* CreateAccount(const char*, double);
}

#endif