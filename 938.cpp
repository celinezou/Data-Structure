#include <string>
#include <iostream>
using namespace std;

void subsequence(string s, string t);

int main() {
	string s,t;

	while (cin >> s >> t) {
		subsequence(s, t);
		s.clear();
		t.clear();
	}
		return 0;

}
void subsequence(string s, string t) {
	int i = 0,j = 0;
	int n = s.length();
	int m = t.length();
	while (i < n && j < m) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	if (i >= n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}