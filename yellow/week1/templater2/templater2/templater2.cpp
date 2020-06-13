// templater2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

template<typename First, typename Second>
ostream& operator<<(ostream& stream, const pair<First, Second>& p) {
    stream << "(" << p.first << ":" << p.second << ")";
    return stream;
}


template<typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool first = true;
    for (auto elem : c) {
        if (!first) {
            ss << d;
        }
        first = false;
        ss << elem;
    }
    return ss.str();
}



template<typename T>
ostream& operator <<(ostream& stream, const vector<T>& v) {
    stream << "[" << Join(v, ',') << "]";
    return stream;
}

template<typename Key, typename Value>
ostream& operator <<(ostream& stream, const map<Key, Value>& m) {
    stream << "{" << Join(m, ',') << "}";
    return stream;
}

int main()
{
    auto p1 = make_pair(10, 20);
    auto p2 = make_pair(24.5, "sample");
    vector<int> vi = { 1,2,3,4,5,6 };
    vector<double> vd = { 1,2,3,4,5.6, 7.8 };
    vector<string> vs = { "1", "2", "3" };

    map<int, int> mi= { {1,2}, {3,4} };
    map<int, char> mic = { {1,'s'}, {2,'q'} };
    map<string, int> ms = { {"one", 1}, {"two", 2} };

    cout << "Pair : " << p1 << endl;
    cout << "Pait : " << p2 << endl;
    cout << "Vector : " << vi << endl;
    cout << "Vecotr : " << vd << endl;
    cout << "Vector : " << vs << endl;
    cout << "Map : " << mi << endl;
    cout << "Map : " << mic << endl;
    cout << "Map : " << ms << endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
