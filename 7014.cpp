#include <iostream>
using namespace std;
#define Len 1000000

int A[Len];
int main() {
	int n, m;
	cin >> n;
	for (int i = 0;i < n;i++) cin >> A[i];
	cin >> m;
	int* B = new int[m];
	for (int i = 0;i < m;i++) cin >> B[i];

	//output
	int Aindex = 0, Bindex = 0;
	while (Aindex < n && Bindex < m) {
		if (A[Aindex] < B[Bindex]) {
				cout << A[Aindex] << " ";
				Aindex++;
		}
		else if (A[Aindex] > B[Bindex]) {
				cout << B[Bindex] << " ";
				Bindex++;
		}
		else {
			Aindex++;
			Bindex++;
		}
	}
	
	while (Aindex < n) {
		cout << A[Aindex] << " ";
		Aindex++;
	}
	while (Bindex < m) {
		cout << B[Bindex] << " ";
		Bindex++;
	}
		
	cout << endl;
}