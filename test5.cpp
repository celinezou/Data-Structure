#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//双线程动态规划，两个纸条同时从11出发传递，用4维数组表示状态,并给出
//递推公式，每个下一步都是用前一步的结果得到，为了避免重合，重合点只算一次
int DP[60][60][60][60] = {0};
int M[50][50] = {0};
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <=n;j++) {
			cin >> M[i][j];
		}
	}

	//DP
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			for (int ii = 1;ii <= m;ii++) {
				int jj = i + j - ii;
				if (jj <= 0 || jj > n) continue;
				DP[i][j][ii][jj] = max(max(DP[i - 1][j][ii - 1][jj], DP[i - 1][j][ii][jj - 1]), max(DP[i][j - 1][ii - 1][jj], DP[i][j - 1][ii][jj - 1]));
				if (ii == i &&jj == j) DP[i][j][ii][jj] += M[i][j];
				else DP[i][j][ii][jj] += M[i][j] + M[ii][jj];
			}
		}
	}
	cout << DP[m][n][m][n] << endl;
}