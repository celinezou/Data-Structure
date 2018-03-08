#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int SIZE = 200010;
int f[SIZE], nex[SIZE] = { 0 }, cnt[SIZE];
char a[SIZE], b[SIZE];
int n, m, q;

int main()
{
	cin >> n >> m >> q;
	scanf("%s", a + 1); // A[1..n]����A��
	scanf("%s", b + 1); // B[1..m]����B��
	for (int i = 2, j = 0; i <= m; i++) // ��B����ƥ�䣬��next����
	{
		while (j > 0 && b[j + 1] != b[i]) j = nex[j];
		if (b[j + 1] == b[i]) j++;
		nex[i] = j;
	}

	for (int i = 1, j = 0; i <= n;i++) // A����B������ģʽƥ��
	{
		
		while (j>0 && (j == m || a[i] != b[j + 1])) j=nex[j];
		if (a[i] == b[j + 1])j++;
		f[i] = j;
		
	}

	for (int i = 1; i <= n; i++) cnt[f[i]]++;
	for (int i = m; i; i--)  cnt[nex[i]]+= cnt[i];

	// ��ʱcnt[x]�������ƥ�䳤��>=x��λ�ø���

	for (int i = 1; i <= q; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", cnt[x]-cnt[x+1]);
	}
}