#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;
void QuickSort(int data[], int left, int right);
int main(){      
	int N,T;
	cin >> N >> T;
	int* data = new int[N];
	for (int i = 0;i < N;i++) {
		cin >> data[i];
	}
	QuickSort(data, 0, N - 1);
	list<int> datas(data, data + N);
	delete[]data;
	//
	int num = 0, value1,value2;
	list<int>::iterator itr1 = datas.begin(), itr2 = datas.begin();
	advance(itr2, 1);
	while (itr1 != datas.end()) {
		while ((itr2 != datas.end()) && (*itr2 - *itr1 != abs(T)))  itr2++;
		if (itr2 != datas.end()) {
			num++;
			value1 = *itr1;
			value2 = *itr2;
			//cout << *itr1 << "," << *itr2 << endl;
			itr2 = datas.erase(itr2);
			itr1 = datas.erase(itr1);
			while ((itr1 != datas.end()) && (*itr1 == value1)) itr1++;
			while ((itr2 != datas.end()) && (*itr2 == value2)) itr2++;
			if (itr2 == datas.end()) break;
			else if (itr1!= datas.end()&&itr1==itr2) {
				itr2 = ++itr1;
				--itr1;
				if (itr2 == datas.end()) break;


			}
		}
		else {
			++itr1;
			if (itr1 == datas.end()) break;
			itr2 = ++itr1;
			--itr1;
			if (itr2 == datas.end()) break;
		}
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