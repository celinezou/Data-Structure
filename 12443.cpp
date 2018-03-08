#include <iostream>
using namespace std;
int A[100000];
int T[100000];
int sum = 0;
void Merge(int l,int r,int m) {
	for (int i = l; i <= r;i++)
		T[i] = A[i];
	int i = l;
	int index1 = l, index2 =m+1;
	while (index1 <= m&&index2 <= r) {
		if (T[index1] < T[index2]) {
			A[i++] = T[index2++];
			sum+=m-index1+1;
		}
		else {
			A[i++] = T[index1++];
		}
	}
	while (index1 <= m) {
		A[i++] = T[index1++];
	}
	while (index2 <= r) {
		A[i++] = T[index2++];
	}

}
void MergeSort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		MergeSort(l, m);
		MergeSort(m+1,r);
		Merge(l, r, m);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	MergeSort(0, N - 1);
	cout << sum << endl;
}
