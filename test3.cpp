#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct  node
{
	char c;
	node* leftc;
	node* rightc;
	node() {
		leftc = NULL;rightc = NULL;
	}
};
int str[10000];
void Build(int l,int r,node* root) {
	if (r < l) return;
	if (str[l] == 0) {

		int i = l + 1;
		while (i <= r&&str[i] == 0)i++;
		if (i <= r) root->c = 'F';
		else root->c = 'B';
	}
	else {
	
		int i = l + 1;
		while (i <= r&&str[i] == 1)i++;
		if (i <= r) root->c = 'F';
		else root->c = 'I';
	}
	if (l < r) {
		node* left = new node;
		node* right = new node;
		root->leftc = left;
		root->rightc = right;
		int middle = (r - l + 1) / 2 + l - 1;
		Build(l, middle, left);
		Build(middle+1, r, right);
	}
}
void travel(node* root) {
	if (root != NULL) {
		travel(root->leftc);
		travel(root->rightc);
		cout << root->c;
	}
}
int main() {
	int N;
	cin >> N;
	char a;
	N = pow(2, N);// 2^n!!!!!!!!!!!!!!!!!!
	for (int i = 0;i < N;i++) {
		cin >> a;
		str[i] = a - '0';
	}
	node* root=new node;
	root->leftc = NULL;
	root->rightc = NULL;
	Build(0,N-1,root);

	travel(root);
}