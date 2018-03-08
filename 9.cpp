#include <iostream>
#include <string>
using namespace std;
int n, m;
int arr[2500];
int reversenum(string p,int n) {
	int a = 0,b = 0,c = 0,d = 0;// the number of A,C,G,T
	int sum = 0;
	for (int i = 0;i < n;i++) {
		switch (p[i])
		{
		case 'A':
			sum += b + c + d;
			a++;
			break;
		case'C':
			sum += c + d;
			b++;
			break;
		case'G':
			sum += d;
			c++;
			break;
		default:
			d++;
			break;
		}
	}
	return sum;
}
void InsertSort(int a[], int len) {
	for (int i = 1;i < len;i++) {
		int temp = i - 1;
		int value = a[i];
		while (temp>=0 && value < a[temp]) {
			a[temp + 1] = a[temp];
			temp--;
		}
		a[++temp] = value;
	}
}
int main() {
	int temp;
	char enter;
	cin >> n >> m;
	string* str = new string[m];

	int* sortarr = new int[m];
	for (int i = 0;i < m;i++) {
		cin >> str[i];
		temp = reversenum(str[i], n);
		arr[temp] = i;
		sortarr[i] = temp;
	}

	InsertSort(sortarr, m);

	for (int i = 0;i < m;i++)
		cout << str[arr[sortarr[i]]] << endl;
		
	delete[]str;
	delete[] sortarr;
}