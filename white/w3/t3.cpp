#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Duration{
    int hour;
    int min;

    Duration(int h = 0, int m = 0){
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

istream& operator >> (istream& stream, Duration& dur){
    stream >> dur.hour;
    stream.ignore(1);
    stream >> dur.min;
    return stream;
}


ostream& operator << (ostream& stream, const Duration& dur){
    stream << setfill('0') ;
    stream << setw(2) << dur.hour << ':' << setw(2) << dur.min;
    return stream;
}

Duration operator + (const Duration& lhs, const Duration& rhs){
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator < (const Duration& lhs, const Duration& rhs){
    return (lhs.hour*60 + lhs.min) < (rhs.hour*60 + rhs.min);
}

ostream& operator << (ostream& stream, const vector<Duration>& durs){
    for(const auto& d : durs){
        stream << d << " ";
    }
    return stream;
}

int main(){
    Duration dur = {1, 20};
    Duration dur2 = {2, 4};
    Duration dur3;
    cin >> dur3;
    cout << dur << endl;
    cout << dur2 << endl;
    cout << dur3<<endl;
    cout << dur3 + dur2 << endl;

    vector<Duration> v = {dur, dur2, dur3, dur + dur2, dur2 + dur3};
    sort(begin(v), end(v));
    cout << v << endl;

    return 0;
}