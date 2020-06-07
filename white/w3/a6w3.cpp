#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString{
public:
    ReversibleString() {
        message = "";
    }
    ReversibleString(string s){
        message = s;
    }

    string ToString() const {
        return message;
    }

    void Reverse(){
        string temp;
        for(int i = message.length() -1; i > -1; i--){
            temp += message[i];
        }
        message = temp;
    }
private:
    string message;
};

