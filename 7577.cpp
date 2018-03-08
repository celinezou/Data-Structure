#include <iostream>

using namespace std;
void SiftDown(int arr[], int pos,int n) {
	int i = pos;
	int j = 2 * i + 1;
	int temp = arr[pos];
	while (j < n) {
		if (j < n - 1 && arr[j + 1] < arr[j]) j += 1;
		if (arr[j] < temp) {
			arr[i] = arr[j];
			i = j;
			j = 2 * i + 1;
		}
		else break;
	}
	arr[i] = temp;
}

int main() {
	int rlen, heapsize,temp;
	cin >> rlen >> heapsize;
	int *r = new int[rlen];
	int *h = new int[heapsize];
	for (int i = 0;i < rlen;i++) {
		cin >> r[i];
	}
	for (int i = 0;i < heapsize;i++) {
		cin >> h[i];
	}

	//ReplacementSelection
	int read = 0,record,mval;
	for (int last = heapsize - 1;last >= 0;) {
		if (read < rlen) record = r[read++];
		else break;
		mval = h[0];
		cout << mval << " ";
		if (record >= mval) h[0] = record;
		else {
			h[0] = h[last];
			h[last] = record;
			last--;
		}
		if (last > 0) SiftDown(h, 0, last + 1);
	}
	cout << endl;
	for (int i = 0;i < heapsize;i++) {
		cout<< h[i];
	}
	delete[]r;
	delete[]h;
}