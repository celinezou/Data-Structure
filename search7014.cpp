#include <stdio.h> //本题难点竟然在于stdio 比iostream快的多！！！我爱scanf和printf！！
using namespace std;
#define Len 1000000

int A[Len];
int BinSearch(int key,int right,int left) {
	int low = left;
	int high = right;
	int middle;
	while (low <=high) {
		middle = (low + high)/2;
		if (A[middle] > key) {
			high = middle-1;
		}
		else if (A[middle] < key) {
			low = middle + 1;
		}
		else
			return middle;
	}
	if(A[middle]>key)
		return middle*(-1)-1;
	else 
		return (middle+1)*(-1) - 1;
}
int main() {
	int n, m,res,left=0;
	scanf("%d",&n);
	for (int i = 0;i < n;i++) scanf("%d",&A[i]);
	scanf("%d", &m);
	int* B = new int[m];
	for (int i = 0;i < m;i++) scanf("%d", &B[i]);
	int i;
	for (i = 0;i < m;i++) {
		if (left > n - 1) break;
		res = BinSearch(B[i], n - 1, left);
		if (res>=0) {
			for (int j = left;j < res;j++)  printf("%d ",A[j]);
			left = res+1;
		}
		else {
			res = (res + 1)*(-1);
			for (int j = left;j < res;j++)  printf("%d ", A[j]);
			printf("%d ", B[i]);
			left = res;
		}
	}
	while (i < m) {
		printf("%d ", B[i]);
		i++;
	}
	while (left < n) {
		printf("%d ", A[left]);
		left++;
	}

	printf("\n");
}