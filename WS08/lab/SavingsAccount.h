
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