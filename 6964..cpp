#include <iostream>
#include <map>
#include <string>
#define INFINITY 999999999
using namespace std;
struct Dist
{
	int length;
	int pre;
};

int main() {
	int pos, direc, m, n;
	cin >> pos;

	map<string, int> mmap;
	string ss;
	for (int i = 0;i < pos;i++) {
		cin >> ss;
		mmap[ss] = i;
	}
	//≥ı ºªØæÿ’Û
	Dist** D = new Dist*[pos];
	for (int i = 0;i < pos;i++)
		D[i] = new Dist[pos];
	for (int i = 0;i < pos;i++) {
		for (int j = 0;j < pos;j++) {
			if (i == j) {
				D[i][j].length = 0;
				D[i][j].pre = i;
			}
			else {
				D[i][j].length = INFINITY;
				D[i][j].pre = -1;
			}
		}
	}
	cin >> direc;
	for (int i = 0; i < direc; i++)
	{
		int length;
		cin >> ss;
		m = mmap[ss];
		cin >> ss;
		n = mmap[ss];
		cin >> length;
		if (D[m][n].length > length) {
			D[m][n].length = length;
			D[m][n].pre = m;
			D[n][m].length = length;
			D[n][m].pre = n;
		}
	}


	//iterate
	for (int v = 0;v < pos;v++) {
		for (int i = 0;i < pos;i++) {
			for (int j = 0;j < pos;j++) {
				if (D[i][v].length + D[v][j].length < D[i][j].length) {
					D[i][j].length = D[i][v].length + D[v][j].length;
					D[i][j].pre = D[v][j].pre;
				}
			}
		}
	}

	int output;
	cin >> output;
	int trace[30];
	for (int i = 0;i < output;i++) {
		int first, last;
		cin >> ss;
		first = mmap[ss];
		cout << ss;
		cin >> ss;
		last = mmap[ss];

		int k = 0;
		m = first;
		n = last;
		while (D[m][n].pre != m)
		{
			trace[k++] = D[m][n].pre;
			n = D[m][n].pre;

		}
		map<string, int>::iterator itr;
		for (int j = k - 1;j >= 0;j--) {
			cout << "->(" << D[m][trace[j]].length << ")->";
			for (itr = mmap.begin();itr != mmap.end();itr++) {
				if (itr->second == trace[j]) {
					cout << itr->first;
					break;
				}
			}
			m = trace[j];
		}
		if (first != last) {
			if (D[first][last].pre == first)
				cout << "->(" << D[first][last].length << ")->" << ss;
			else
				cout << "->(" << D[trace[0]][last].length << ")->" << ss;
		}
		cout << endl;
	}
	delete[]D;
}