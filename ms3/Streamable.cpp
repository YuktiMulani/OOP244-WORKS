
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
// Streamable Module
// File  Streamable.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Streamable.h"
namespace sdds {

	std::ostream& operator<<(std::ostream& o, const Streamable& s) {
		if (s)
		{
			s.write(o);
		}
		return o;
	}
	std::istream& operator>>(std::istream& i, Streamable& s)
	{
		return (s.read(i));
	}
}