#include <iostream>
#include <stdlib.h>
using namespace std;
void QuickSort(int data[], int left, int right);
int main() {
	int N, T;
	cin >> N >> T;
	int* data = new int[N];
	for (int i = 0;i < N;i++) {
		cin >> data[i];
	}
	QuickSort(data, 0, N - 1);
	int num = 0,value1,value2;
	int i = 0,j = 1;
	while (1) {
		while ((j < N) && (data[j] - data[i]) < abs(T)) j++;
		value1 = data[i];
		value2 = data[j];
		if (j < N) {
			if ((data[j] - data[i]) == abs(T)) {
				num++;
				i++;
				j++;
				while ((i < N) && data[i] == value1) i++;
				while (j < N && data[j] == value2) j++;
				if (i == j) j++;
			}
			else {
				while ((i < N) && data[i] == value1) i++;
				if (i>=j) j=i+1;
			}
		}
		else break;
	}

	cout << num << endl;
}
int Partition(int data[], int left, int right) {
	int i = left;
	int j = right;
	int pivotvalue = data[left];
	while (i != j) {
		while ((data[j]>pivotvalue) && (i<j)) j--;
		if (i<j) { data[i] = data[j];i++; }
		while (data[i] <= pivotvalue&& i<j) i++;
		if (i<j) { data[j] = data[i];j--; }
	}
	data[i] = pivotvalue;
	return i;
}
void QuickSort(int data[], int left, int right) {
	if (left<right) {
		int pivot = Partition(data, left, right);
		QuickSort(data, left, pivot - 1);
		QuickSort(data, pivot + 1, right);
	}
}