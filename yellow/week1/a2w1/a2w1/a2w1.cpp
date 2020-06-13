#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int amount, density;
	cin >> amount >> density;
	uint64_t mass = 0;
	for (size_t i = 0; i < static_cast<size_t>(amount); i++) {
		uint64_t w, h, d;
		cin >> w >> h >> d;
		mass += w * h * d * static_cast<uint64_t>(density);
	}

	cout << mass << endl;
	return 0;
}


