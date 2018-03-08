#include <iostream>

using namespace std;
struct edge {
	int n1;
	int n2;
	int weight;
};
int A[150];
edge E[10000];
int par(int left, int right) {
	edge p = E[left];
	int pv = E[left].weight;
	int i = left,j = right;
	while (i != j) {
		while (j > i&&E[j].weight > pv)j--;
		if (j > i) {
			E[i] = E[j];i++;
		}
		while (i < j&&E[i].weight <= pv)i++;
		if (i < j) {
			E[j] = E[i];j--;
		}
	}
	E[i] = p;
	return i;
}
void Sort(int left,int right) {
	if (left < right) {
		int p = par(left, right);
		Sort(left, p - 1);
		Sort(p + 1, right);
	}
}
int main() {
	int t,n,m;
	cin >> t;
	for (int i = 0;i < t;i++) {
		cin >> n >> m;
		for (int j = 0;j <= n;j++) A[j] = 0;
		for (int j = 0;j < m;j++) {
			cin >> E[j].n1 >> E[j].n2 >> E[j].weight;
		}

		Sort(0, m - 1);
		int temp = E[0].weight;
		A[E[0].n1] = 1;
		A[E[0].n2] = 1;
		int num = 2;
		int sum = temp;
		int j=0,s;
		for ( j = 1;j < m;j++) {
			if (num >= n) break;
			if (A[E[j].n1] == 1 && A[E[j].n2] == 1&&temp==E[j].weight) {
				cout << "Not Unique!" << endl;
				break;
			}
			else if (A[E[j].n1] == 0 && A[E[j].n2] == 0) {
				num += 2;
				temp = E[j].weight;
				sum += temp;
			}
			else if (A[E[j].n1] == 0 || A[E[j].n2] == 0) { 
				num++;temp = E[j].weight;sum += temp;
				if (A[E[j].n1] == 0) s = E[j].n1;
				else s = E[j].n2;
			}
			A[E[j].n1] = 1;
			A[E[j].n2] = 1;
		}
		if (num >= n) {
			if (j > 0) {
				if (temp == E[j].weight && (E[j].n1 == s || E[j].n2 == s))
					cout << "Not Unique!" << endl;
				else
					cout << sum << endl;
			}
			else
				cout << sum << endl;
		}
	}
}