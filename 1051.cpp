#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#define INFINITY 999999999
using namespace std;
int map[210][210][2];// 0为空气，1为门 ，INFINITY 为墙
int cnt[210][210];
int sum;
int maxx, maxy;
struct node {
	int x, y;
	bool operator<(const node &n1)const {
		return cnt[n1.x][n1.y] < cnt[x][y];
	}
};

void BFS(int f1, int f2) {
	priority_queue<node> Q;
	node nn;
	for (int i = 0;i < 210;i++) {
		for (int j = 0;j < 210;j++)
			cnt[i][j] = INFINITY;
	}
	cnt[0][0] = 0;
	nn.x = 0;
	nn.y =0 ;
	Q.push(nn);
	int x, y;
	while (!Q.empty())
	{
		nn = Q.top();
		Q.pop();
		x = nn.x;
		y = nn.y;
		if (x == f1&&y == f2) {
			sum = cnt[x][y];
			return;
		}
		if (y + 1 <= maxy&& cnt[x][y + 1] > cnt[x][y] + map[x][y + 1][0]) {// 向上走
			cnt[x][y + 1] = cnt[x][y] + map[x][y + 1][0];
			nn.x = x;
			nn.y = y + 1;
			Q.push(nn);
		}
		if (y - 1 >= 0 && cnt[x][y - 1] > cnt[x][y] + map[x][y][0]) {
			cnt[x][y - 1] = cnt[x][y] + map[x][y][0];
			nn.x = x;
			nn.y = y - 1;
			Q.push(nn);
		}
		if (x + 1 <= maxx&& cnt[x + 1][y] > cnt[x][y] + map[x + 1][y][1]) {
			cnt[x + 1][y] = cnt[x][y] + map[x + 1][y][1];
			nn.x = x + 1;
			nn.y = y;
			Q.push(nn);
		}
		if (x - 1 >= 0&& cnt[x - 1][y] > cnt[x][y] + map[x][y][1]) {
			cnt[x - 1][y] = cnt[x][y] + map[x][y][1];
			nn.x = x - 1;
			nn.y = y;
			Q.push(nn);
		}
		
		
	}
	sum = -1;
	return;
		
}
int main() {
	int wall, door;
	while (cin >> wall >> door, wall != -1 || door != -1) {
		int x, y, d, t;
		maxx = -1;
		maxy = -1;
		memset(map, 0, sizeof(map));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0;i < wall;i++) {
			cin >> x >> y >> d >> t;
			for (int j = 0;j < t;j++) {
				map[x][y][d] = INFINITY;
				if (d) y++;else x++;
				maxx = max(maxx, x);
				maxy = max(maxy, y);
			}
		}
		for (int i = 0;i < door;i++) {
			cin >> x >> y >> d;
			map[x][y][d] = 1;
		}
		float f1, f2;
		cin >> f1 >> f2;
		if (f1 > maxx || f2 > maxy) {
			sum = 0;
			cout << sum << endl;
			continue;
		}
		BFS((int)f1, (int)f2);
		cout << sum << endl;
	}

}
