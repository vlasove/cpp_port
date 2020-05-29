#include <iostream>
#include <string>

using namespace std;

int main(){
    string sample;
    cin >> sample; 

    int count = -2;
    int position;
    for(int i = 0; i < sample.size(); i++){
        if (sample[i] == 'f'){
            count++;
        }
        if (count == 0){
            position = i;
            break;
        }
    }

    if (count == 0){
        cout << position<<endl;
    } else {
        cout << count <<endl;
    }
    return 0;
}
