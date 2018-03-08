#include <iostream>
#include <string>
using namespace std;
struct dicnode {
	string s;
	int num;
};
dicnode dictionary[16][10000];
dicnode indexarr[10000];
int length[16];
int len=0;
void Insert(string s,int n) {
	dictionary[s.length()][length[s.length()]].s = s;
	dictionary[s.length()][length[s.length()]].num = n;
	length[s.length()]++;
}
bool issimilar(string str,string s) {
	int i=0, j=0;
	string longs, shorts;
	int fault=0; //容错一次
	if (str.length() == s.length()) {
		for (int m = 0;m < s.length();m++) {
			if (str[m] != s[m]) fault++;
		}
		if (fault > 1) return false;
		else return true;
	}
	if (str.length() < s.length()) {
		shorts = str;
		longs = s;
	}
	else {
		shorts = s;
		longs = str;
	}
	while (i < shorts.length()&&j<longs.length()) {
		if (shorts[i] != longs[j]) {
			fault++;
			j++;
		}
		else {
			i++;j++;
		}
	}
	if (fault > 1) return false;
	else return true;

}

int main() {
	string s,temps;
	//length 初始化
	for (int i = 0;i < 16;i++) length[i] = 0;
	while (1) {
		cin >> s;
		if (s[0] == '#') break;
		else Insert(s, len);
		len++;
	}

	while (1) {
		int r = 0;
		bool flag=false;
		cin >> s;
		if (s[0] == '#') break;
		for (int i = 0;i < length[s.length()];i++) {
			if (dictionary[s.length()][i].s == s) {
				cout << s << " is correct" << endl;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << s << ":";
			//less1//equal//more1
			for (int j = s.length() - 1;j <= s.length() + 1;j++) {
				if (j > 15) break;
				for (int i = 0;i < length[j]; i++) {
					temps = dictionary[j][i].s;
					if(issimilar(temps, s)) indexarr[r++] = dictionary[j][i];
				}
			}
			//sort
			dicnode temp;
			for (int i = 1;i < r;i++) {
				temp.num = indexarr[i].num;
				temp.s = indexarr[i].s;
				int j = i;
				while (j - 1 >= 0 & temp.num < indexarr[j - 1].num) {
					indexarr[j] = indexarr[j - 1];
					j--;
				}
				indexarr[j] = temp;
			}
			for (int i = 0;i < r;i++)
				cout << " " << indexarr[i].s;
			cout << endl;
		}
	}
}
	
