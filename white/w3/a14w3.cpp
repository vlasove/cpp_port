#include <iostream>
#include <string>
#include <exception>
#include <sstream>

using namespace std;

void EnsureEqual(const string& left, const string& right){
    if (left != right){
        stringstream stream;
        stream << left << " != "<<right;
        throw runtime_error(stream.str());
    }
}

