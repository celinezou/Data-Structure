#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int HI[100000] = { 0 };
int n;
int a[2];
int Search() {
	int i = a[0];
	while (i <= n - 1 && HI[i] == 0) i++;
	if (i == n) a[0] = -1;
	else a[0] = i;
	int p=i;
	int j = i + 1;
	while (j <= n - 1 && HI[j] != 0) {
		if (HI[j] < HI[p]) p = j;
		j++;
	}
	if (j == n) a[1] = n - 1;
	else a[1] = j - 1;
	
	return HI[p];
}
int main() {
	int minnum = 0;
	int minus;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &HI[i]);
	}
	while (1) {
		minus=Search();
		//cout << a[0] << " " << a[1] << endl;
		if (a[0] == -1) break;
		for (int i = a[0];i <= a[1];i++) {
			HI[i]-=minus;
		}
		minnum+=minus;
	}
	printf("%d\n", minnum);
}