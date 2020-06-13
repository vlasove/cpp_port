#include <iostream>
#include <vector>
#include <map>
#include <utility>


using namespace std;


template<typename T> vector<T> operator * (const vector<T>& v1, const vector<T>& v2);
template<typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);
template<typename Key, typename Value> map<Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2);
template<typename T> T Sqr(const T& element);


template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2) {
	vector<T> ans(v1.size());
	for (size_t i = 0; i < v1.size(); i++) {
		ans[i] = v1[i] * v1[i];

	}
	return ans;
}

template<typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return make_pair(f, s);
}

template<typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2) {
	map<Key, Value> ans;
	for (auto p : m1) {
		ans[p.first] = p.second * p.second;
	}
	return ans;
}

template<typename T>
T Sqr(const T& element) {
	return element * element;
}





int main() {

	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}