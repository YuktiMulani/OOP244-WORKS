
#include <iostream>
#include "Write.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        return c.display(os);
    }
}