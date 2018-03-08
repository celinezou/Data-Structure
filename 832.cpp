

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//��2ȡģ��01������
const int MAXN = 40;
//��equ�����̣�var����Ԫ�������������Ϊequ,����Ϊvar+1,�ֱ�Ϊ0��var
int equ, var;
int a[MAXN][MAXN]; //�������
int x[MAXN]; //�⼯
int free_x[MAXN];//�����洢���ɱ�Ԫ�����ö�����ɱ�Ԫ����ʹ�ã�
int free_num;//���ɱ�Ԫ�ĸ���

			 //����ֵΪ-1��ʾ�޽⣬Ϊ0��Ψһ�⣬���򷵻����ɱ�Ԫ����
int Gauss()
{
	int max_r, col, k;
	free_num = 0;
	for (k = 0, col = 0; k < equ && col < var; k++, col++)
	{
		max_r = k;
		for (int i = k + 1;i < equ;i++)
		{
			if (abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		}
		if (a[max_r][col] == 0)
		{
			k--;
			free_x[free_num++] = col;//��������ɱ�Ԫ
			continue;
		}
		if (max_r != k)
		{
			for (int j = col; j < var + 1; j++)
				swap(a[k][j], a[max_r][j]);
		}
		for (int i = k + 1;i < equ;i++)
		{
			if (a[i][col] != 0)
			{
				for (int j = col;j < var + 1;j++)
					a[i][j] ^= a[k][j];
			}
		}
	}
	for (int i = k;i < equ;i++)
		if (a[i][col] != 0)
			return -1;//�޽�
	if (k < var) return var - k;//���ɱ�Ԫ����
								//Ψһ�⣬�ش�
	for (int i = var - 1; i >= 0;i--)
	{
		x[i] = a[i][var];
		for (int j = i + 1;j < var;j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}
void init()
{
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
}
int start[MAXN], endd[MAXN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0;i < n;i++)
			scanf("%d", &start[i]);
		for (int i = 0;i < n;i++)
			scanf("%d", &endd[i]);
		init();
		equ = var = n;
		for (int i = 0;i < n;i++)
			a[i][i] = 1;
		int u, v;
		while (scanf("%d%d", &u, &v) == 2)
		{
			if (u == 0 && v == 0)break;
			a[v - 1][u - 1] = 1;
		}
		for (int i = 0;i < n;i++)
			a[i][n] = (start[i] ^ endd[i]);
		int ans = Gauss();
		if (ans == -1)
			printf("Oh,it's impossible~!!\n");
		else printf("%d\n", (1 << ans));
	}
	return 0;
}