#include <iostream>

using namespace std;
long long exc=0;
long long N;
void Merge(int Array[], int left, int right, int middle) {
	int index1=left, index2=middle+1;
	int*temparray = new int[N];
	for (int i = left;i <= right;i++) {
		temparray[i] = Array[i];
	}

	int arrindex = left, temp=0;//temp记录目前左侧比右侧小的数目
	while (index1 <= middle&&index2 <= right) {
		if (temparray[index1] < temparray[index2]) {
			Array[arrindex++] = temparray[index1++];
			temp++;
		}
		else {
			Array[arrindex++] = temparray[index2++];
			exc = exc + temp;
		}
	}
	while (index1 <= middle) {
		Array[arrindex++] = temparray[index1++];
	}
	while (index2 <= right) {
		Array[arrindex++] = temparray[index2++];
		exc = exc + temp;
	}
	delete[] temparray;
}

void MergeSort(int Array[], int left, int right) {
	int middle = (left + right) / 2;
	
	if (left < right) {
		MergeSort(Array, left, middle);
		MergeSort(Array, middle + 1, right);
		Merge(Array, left, right, middle);
	}
}

int main() {
	cin >> N;
	//input
	int* vel = new int[N];        //speed array
	for (int i = 0;i < N;i++) {
		cin >> vel[i];
	}
	
	//MergeSort
	MergeSort(vel, 0, N - 1);
	delete[] vel;
	//output
	cout << exc << endl;
}
