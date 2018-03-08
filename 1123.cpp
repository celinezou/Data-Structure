#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {

	map<string, int> mapnumber;
	mapnumber["negative"] = -1;
	mapnumber["zero"] = 0;
	mapnumber["one"] = 1;
	mapnumber["two"] = 2;
	mapnumber["three"] = 3;
	mapnumber["four"] = 4;
	mapnumber["five"] = 5;
	mapnumber["six"] = 6;
	mapnumber["seven"] = 7;
	mapnumber["eight"] = 8;
	mapnumber["nine"] = 9;
	mapnumber["ten"] = 10;
	mapnumber["eleven"] = 11;
	mapnumber["twelve"] = 12;
	mapnumber["thirteen"] = 13;
	mapnumber["fourteen"] = 14;
	mapnumber["fifteen"] = 15;
	mapnumber["sixteen"] = 16;
	mapnumber["seventeen"] = 17;
	mapnumber["eighteen"] = 18;
	mapnumber["nineteen"] = 19;
	mapnumber["twenty"] = 20;
	mapnumber["thirty"] = 30;
	mapnumber["forty"] = 40;
	mapnumber["fifty"] = 50;
	mapnumber["sixty"] = 60;
	mapnumber["seventy"] = 70;
	mapnumber["eighty"] = 80;
	mapnumber["ninety"] = 90;
	mapnumber["hundred"] =100;
	mapnumber["thousand"] =1000;
	mapnumber["million"] = 1000000;


	string a;
	char ch=' ';
	while (1) {
		int num = 0,pre = -1,sign = 1,mi=0;
		while (ch != '\n') {
			while (ch = cin.get(), ch != ' '&& ch != '\n') {
				a += ch;//a.append(&ch,1)
			}
			if (a == "negative") {
				sign = -1;
			}
			else if (a != "thousand"&&a != "hundred"&&a != "million") {
				if (pre == -1) {
					pre = mapnumber[a];
				}
				else {
					num = num + pre + mapnumber[a];
					pre = -1;
				}
			}
			else if (a == "hundred") {
				num = num + pre * 100;
				pre = -1;
			}
			else if(a=="million"){
				if (pre != -1) num = num + pre;
				num = num*1000000;
				pre = -1;
				mi = num;
			}
			else {
				if (pre != -1) num = num + pre;
				num = (num-mi)*1000+mi;
				pre = -1;
			}
			a.clear();
		}

		if (pre != -1) num = num + pre;
		num = num*sign;
		cout << num << endl;
		if (ch = cin.get(), ch == '\n') break;
		else cin.putback(ch);
	}

}