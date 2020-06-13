// templater.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <utility>
#include <fstream>

using namespace std;

template<typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;

    return make_pair(f, s);
}

template <typename First, typename Second>
ostream& operator << (ostream& stream, const pair<First, Second>& p) {
    stream << "{ " << p.first << " : " << p.second << " }";
    return stream;
}

template <typename T>
T Sqr(T x) {
    return x * x;
}


int main()
{
    pair<int, int> p1 = { 10, 20 };
    pair<double, int> p2 = { 12.5, 4 };

    cout << "Pair<int,int> Sqr: " << Sqr(p1) << endl;
    cout << "Pair<double,int> Sqr: " << Sqr(p2) << endl;

    cout << "Ints : " << Sqr(10) << endl;
    cout << "Doubles : " << Sqr(12.5) << endl;
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
