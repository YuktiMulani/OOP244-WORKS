
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