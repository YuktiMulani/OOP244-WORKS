

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
