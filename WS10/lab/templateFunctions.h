
#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
#include "Card.h"
#include "Pet.h"
#include "Book.h"
#include "Write.h"

namespace sdds {
    //Find with 3 parameters
    template <typename T1, typename T2>
    bool find(Collection<T1>& obj, int index, T2 key)
    {
        if (obj[index] == key)
        {
            return true;
        }
        return false;
    }

    //Find with 4 parameters
    template <typename T1, typename T2, typename T3>
    int find(Collection<T1>& obj, int size, T2 key1, T3 key2)
    {
        for (int i = 0; i < size; i++)
        {
            if (obj[i] == key1 && obj[i] == key2)
            {
                return i;
            }
        }
        return -1;
    }

    //Insertion operator
    template <typename T>
    std::ostream& operator<<(std::ostream& os, Collection<T>& obj)
    {
        for (int i = 0; i < obj.size(); i++)
        {
            os << obj[i] << std::endl;
        }
        return os;
    }

    //Load Collection
    template <typename T>
    Collection<T> loadCollection(Collection<T>& obj, T element)
    {
        obj += element;
        return obj;
    }

}
#endif // !SDDS_SEARCH_H_
