#include <cstdio>
using namespace std;
int A[1000000];
int M[1000000];
int m[1000000];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++) {
		scanf("%d", &A[i]);
	}

	int min=-9999999, max=9999999,posmin=-1,posmax=-1;
	int temp;

	for (int i = 0;i <= n - k;i++) {
		
		if (posmin == i - 1) {
			temp = min;
			min = A[i + k - 1];
			posmin = i + k - 1;
			if (A[i + k - 1] > temp) {
			//	printf("yes");
				for (int j = i + k - 1;j >= i;j--) {
					if (A[j] < min) {
						min = A[j];
						posmin = j;
					}
				}
			}
		}
		else {
			if (A[i + k - 1] < min) {
				min = A[i + k - 1];
				posmin = i + k - 1;
				
			}
		}
		if (posmax == i - 1) {
			temp = max;
			max = A[i + k - 1];
			posmax = i + k - 1;
			if (A[i + k - 1] < temp){
				for (int j = i+k-1;j >=i ;j--) {
					if (A[j] > max) {
						max = A[j];
						posmax = j;
					}
				}
			}
		}
		else
		{
			if (A[i + k - 1] > max) {
				max = A[i + k - 1];
				posmax = i + k - 1;
			}
		}
		m[i] = min;
		M[i] = max;
	}
	for (int i = 0;i <= n - k;i++) {
		printf("%d ", m[i]);
	}
	printf("\n");
	for (int i = 0;i <= n - k;i++) {
		printf("%d ", M[i]);
	}
	printf("\n");

}