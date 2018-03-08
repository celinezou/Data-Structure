#include <iostream>

using namespace std;
int *A, *B;
int LowExt, offset;
int loser(int arr[], int l, int r) {
	if (arr[l] <= arr[r])
		return r;
	else
		return l;
}
int winner(int arr[], int l, int r) {
	if (arr[l] <= arr[r])
		return l;
	else
		return r;
}
void Play(int p, int lc, int rc) {
	B[p] = loser(A, lc, rc);
	int temp1, temp2;
	temp1 = winner(A, lc, rc);
	while (p > 1 && p % 2) {
		temp2 = winner(A, temp1, B[p / 2]);
		B[p / 2] = loser(A, temp1, B[p / 2]);
		temp1 = temp2;
		p /= 2;
	}
	B[p / 2] = temp1;
}
void Initialize(int n) {
	int i, s;
	for (s = 1;2 * s <= n - 1;s += s);
	LowExt = 2 * (n - s);
	offset = 2 * s - 1;
	for (i = 2;i <= LowExt;i += 2)
		Play((offset + i) / 2, i - 1, i);
	if (n % 2) {
		Play(n / 2, B[(n - 1) / 2], LowExt + 1);
		i = LowExt + 3;
	}
	else i = LowExt + 2;
	for (;i <= n;i += 2)
		Play((i - LowExt + n - 1) / 2, i - 1, i);
}
void Replay(int i, int n) {
	int p;
	if (i <= LowExt)
		p = (i + offset) / 2;
	else p = (i - LowExt + n - 1) / 2;
	B[0] = winner(A, i, B[p]);
	B[p] = loser(A, i, B[p]);
	for (;(p / 2) >= 1;p /= 2) {
		int temp;
		temp = winner(A, B[p / 2], B[0]);
		B[p / 2] = loser(A, B[p / 2], B[0]);
		B[0] = temp;
	}
}
int main() {
	int len, changetime;
	cin >> len >> changetime;
	A= new int[len+1];
	B= new int[len];
	for (int i = 1;i <= len;i++) cin >> A[i];
	//initial
	Initialize(len);
	for (int i = 0;i < len;i++) {
		cout << A[B[i]] << " ";
	}
	cout << endl;
	//change
	for (int i = 0;i < changetime;i++) {
		int mark, value;
		cin >> mark >> value;
		A[mark + 1] = value;
		Replay(mark + 1,len);
		for (int i = 0;i < len;i++) {
			cout << A[B[i]] << " ";
		}
		cout << endl;
	}
	delete[]A;
	delete[]B;
}