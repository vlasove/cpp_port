#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Date{
    long int day;
    long int month;
    long int year;
    Date() {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(long int d, long int m, long int y){
        day = d;
        month = m;
        year = y;
    }
};

struct Student{
    string name;
    string lastname;
    Date date;
    Student(string n, string l, Date d){
        name = n;
        lastname = l;
        date = d;
    }
};

void PrintFullName(const vector<Student>& students, int number){
    cout << students[number - 1].name << " "<< students[number - 1].lastname<<endl;
}

void PrintDate(const vector<Student>& students, int number){
    cout << students[number - 1].date.day << "." <<
            students[number - 1].date.month << "."<<
            students[number - 1].date.year << endl;
}


int main(){
    int n;
    cin >> n;
    vector<Student> students;
    for (int i = 0; i < n; i++){
        long int day, month, year;
        string name, lastname;
        cin >> name >> lastname >> day >> month >> year;
        Student st = {name, lastname, Date(day, month, year)};
        students.push_back(st);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i ++){
        string command;
        int number;
        cin >> command >> number;
        if (command == "name" && number > 0 && number <= n){
            PrintFullName(students, number);
        } else if (command == "date"  && number > 0 && number <= n){
            PrintDate(students, number);
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}