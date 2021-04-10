#ifndef SCONVERT_H
#define SCONVERT_H

#if __cplusplus < 201103L
#include <string>
#include <sstream>
#include <iostream>

namespace std
{
    int stoi(const string& str)
    {
        std::stringstream degree(str);
        int x;
        degree >> x;
        return x;
    }
}

#endif

#endif //Sconvert_H