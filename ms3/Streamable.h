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
// File  Streamable.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds {
	class Streamable {
		public:virtual std::ostream& write(std::ostream& o)const = 0; 
		virtual std::istream& read(std::istream& i) = 0;
		virtual bool conIO(std::ios& ios)const = 0; 
		virtual operator bool()const = 0; 
		virtual ~Streamable() {};
	};
	std::ostream& operator<<(std::ostream& o, const Streamable& s);
	std::istream& operator>>(std::istream& i, Streamable& s);
}
#endif
