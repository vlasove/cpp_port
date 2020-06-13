// a1w1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{	
	int n = 0;
	cin >> n;
	vector<int64_t> temp(n);
	int64_t sum = 0;
	for (auto& t : temp) {
		cin >> t;
		sum += t;
	}
	int64_t avg = sum / static_cast<int64_t>(temp.size());
	vector<int> indexes;

	for (size_t i = 0; i < temp.size(); i++) {
		if (temp[i] > avg) {
			indexes.push_back(i);
		}
	}

	cout << indexes.size() << endl;
	for (const auto& i : indexes) {
		cout << i << " ";
	}
	cout << endl;

	
	return 0;
}

