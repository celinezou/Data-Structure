#include <iostream>
using namespace std;
//shuchuzongshu!!!

int main() {
	long long C[19] = { 0 };
	C[0] = 1;
	C[1] = 1;
	for (int i = 2;i <= 18;i++) {
		for (int j = 0;j <= i - 1;j++) {
			C[i] += C[j] * C[i - 1 - j];
		}
	}

	int n;
	cin >> n;
	cout << C[n] << endl;
}