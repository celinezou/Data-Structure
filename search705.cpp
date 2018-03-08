#include <iostream>
using namespace std;

struct node
{
	node* par;
	node* opposite;
	node() {
		par = NULL;opposite = NULL;
	}

};
//node* partree;
node partree[100010];
node* find(node* i) {
	if (i->par == NULL)return NULL;
	if (i->par == i) return i;
	i->par = find(i->par);
	return i->par;
};
int main() {
	int T,N,M,num1,num2;
	char c;
	node*temp1, *temp2;
	cin >> T;
	while (T>0)
	{
		cin >> N >> M;
		for (int k = 1;k <= N;k++) {
				partree[k].par = NULL;
				partree[k].opposite = NULL;
		}
		for (int i = 0; i < M; i++){
			cin >> c >> num1 >> num2;
			temp1 = find(&partree[num1]);
			temp2 = find(&partree[num2]);
			if (c == 'A') {
				if (temp1 == NULL||temp2 == NULL) {
					cout << "Not sure yet." << endl;
				}
				else if (temp1 == temp2) {
					cout << "In the same gang." << endl;
				}
				else if (temp1->opposite == temp2) {
					cout << "In different gangs." << endl;
				}
				else {
					cout << "Not sure yet." << endl;
				}
			}
			if (c == 'D') {
				if (temp1 == NULL&&temp2 == NULL) {
					partree[num1].par = &partree[num1];
					partree[num2].par = &partree[num2];
					partree[num1].opposite = &partree[num2];
					partree[num2].opposite = &partree[num1];
				}
				else if (temp1 == NULL&&temp2 != NULL) {
					partree[num1].par = temp2->opposite;
				}
				else if (temp1 != NULL&&temp2 == NULL) {
					partree[num2].par = temp1->opposite;
				}
				else if (temp1->opposite != temp2) {
					temp2->par = temp1->opposite;
					temp2->opposite->par = temp1;
				}
			}
		}
		T--;
	}

}
