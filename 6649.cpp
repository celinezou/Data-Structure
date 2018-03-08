#include <iostream>
#include <queue>
using namespace std;
int out[1000001] = { 0 };
struct node {
	int v;
	int index;
};
struct cmpmax {
	bool operator ()( node &a, node &b) {
		return a.v < b.v;
	}
};
struct cmpmin {
	bool operator ()(node &a, node &b) {
		return a.v > b.v;
	}
};
priority_queue<node,vector<node>,cmpmax> maxq;
priority_queue<node, vector<node>,cmpmin> minq;

int main() {
	int n,k;
	int ind = 0;
	long long sum=0;
	long long ma, mi;
	node p,temp;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> k;
		for (int j = 0;j < k;j++) {
			cin >> p.v;
			p.index = ind;
			maxq.push(p);
			minq.push(p);
			ind++;
		}
		ma = 0;
		mi = 0;
		while (!maxq.empty()) {
			temp = maxq.top();
			maxq.pop();
			if (out[temp.index] == 0) {
				ma = temp.v;
				out[temp.index] = 1;
				//cout << temp.index << endl;
				break;
			}
		}
		while (!minq.empty()) {
			temp = minq.top();
			minq.pop();
			if (out[temp.index] == 0) {
				mi = temp.v;
				out[temp.index] = 1;
				//cout << temp.index << endl;
				break;
			}
		}
		sum += ma - mi;
	}
	cout << sum << endl;
}