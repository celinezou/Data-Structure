#include <map>
#include <iostream>
#include <string>
using namespace std;
int main() {
	map<string, string>mmap;
	char temp;
	string s1, s2;
	while (temp = cin.get(), temp != '\n') {
		cin.putback(temp);
		cin >> s1 >> s2;
		mmap[s2] = s1;
		cin.get();
	}
	while (cin >> s2) {
		
		map<string, string>::iterator it;
		it = mmap.find(s2);
		if (it != mmap.end())
			cout << it->second << endl;
		else
			cout << "eh" << endl;
	}
}