#include <stdio.h>
#include <math.h>
#include <queue>
int A[5050][8];
int pos[8];
int n, K,t,m;
struct node
{
	double v;
	int index;
	bool operator < (const node b)const  {
		return this->v < b.v;
	}
};
node N[5050];
int MM[15];
std::priority_queue<node> myq;
double dis(int p) {
	double s = 0.0;
	for (int i = 0;i < K;i++) {
		s += pow((double)(A[p][i] - pos[i]), 2.0);
	}
	return s;
}

int main() {
	while (scanf("%d%d", &n, &K) != EOF) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < K;j++) {
				scanf("%d", &A[i][j]);
			}
		}

		scanf("%d", &t);
		for (int i = 0;i < t;i++) {
			for (int j = 0;j < K;j++)
				scanf("%d", &pos[j]);
			scanf("%d", &m);
			printf("the closest %d points are:\n", m);
			for (int j = 0;j < m;j++) {
				N[j].v = dis(j);
				N[j].index = j;
				myq.push(N[j]);
			}
			for (int j = m;j < n;j++) {
				N[j].v = dis(j);
				N[j].index = j;
				if (N[j].v < myq.top().v) {
					myq.pop();
					myq.push(N[j]);
				}
			}
			//Êä³ö
			int z = 0;
			while (!myq.empty()) {
				MM[z++] = myq.top().index;
				myq.pop();
			}
			for (int j = m - 1;j >= 0;j--) {
				for (int k = 0;k < K;k++)
					printf("%d ", A[MM[j]][k]);
				printf("\n");
			}
		}
	}
}