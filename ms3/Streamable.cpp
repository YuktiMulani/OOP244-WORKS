
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