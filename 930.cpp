#include <iostream>
#include <stdlib.h>
using namespace std;
struct pos {
	int i, j;
};
int cases;
int M, N, K;
int Partition(int data[], int left, int right) {
	int i = left;
	int j = right;
	int pivotvalue = data[left];
	while (i != j) {
		while ((data[j]<pivotvalue) && (i<j)) j--;
		if (i<j) { data[i] = data[j];i++; }
		while (data[i] >= pivotvalue&& i<j) i++;
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
int main() {
	cin >> cases;
	for (int i = 0;i < cases;i++) {
		int temp, compindex = 0, time = 1, compnum = 0, sum = 0,lastvalue;
		cin >> M >> N >> K;
		pos* posarr = new pos[3010]; 
		int* comp = new int[M*N];
		for (int m = 0;m < M;m++) {
			for (int n = 0;n < N;n++) {
				cin >> temp;
				if (temp != 0) {
					posarr[temp].i = m;
					posarr[temp].j = n;
					comp[compnum++] = temp;
				}
			}
		}

		QuickSort(comp, 0, compnum - 1);

		if (compnum != 0) {
			// µÚÒ»´Î
			lastvalue = posarr[comp[compindex]].i + 1;
			time += posarr[comp[compindex++]].i  + 1 + lastvalue;
	
			while (time < K&&compindex < compnum) {
				time = time - lastvalue;
				lastvalue = posarr[comp[compindex]].i + 1;
				time += abs(posarr[comp[compindex]].i - posarr[comp[compindex - 1]].i) + abs(posarr[comp[compindex]].j - posarr[comp[compindex - 1]].j) + 1 + lastvalue;
				compindex++;
			}
		}
		if (time > K) 
			for (int j = 0;j < compindex - 1;j++) sum += comp[j];
		else if(time==K)
			for (int j = 0;j < compindex;j++) sum += comp[j];	
		else 
			for (int j = 0;j < compnum;j++) sum += comp[j];
		

		cout << sum << endl;
		delete[] posarr;
		delete[] comp;
		comp = NULL;
		posarr = NULL;
	}
}