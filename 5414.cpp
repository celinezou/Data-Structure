#include  "BITREE.h"
#include <iostream>
#include <map>
using namespace std;
map<int, int> inorder;
map<int, int> postorder;
void restruct(binarytreenode<int> *root, int pl, int pr, int il, int ir);
int main() {
	
	int n=0,temp;
	char c;
	do {
		cin >> temp;
		inorder[temp]=n;
		n++;
	} while (c = cin.get(), c == ' ');
	n = 0;
	do {
		cin >> postorder[n];
		n++;
	} while (c = cin.get(), c == ' ');

	binarytreenode<int> *root = new binarytreenode<int>;
	binarytree<int> mytree;
	mytree.createtree(root);
	root->setvalue(postorder[n - 1]);
	
	restruct(root,0,n-1,0,n-1);
	mytree.preorder(root);
//	mytree.deletebinarytree(root);
}

void restruct(binarytreenode<int> *root,int pl,int pr, int il, int ir) {
	
	int index = inorder[root->value()];
	if (index == il)
		root->setleftchild(NULL);
	else {
		binarytreenode<int> *left = new binarytreenode<int>;
		left->setvalue(postorder[index-il+pl-1]);
		root->setleftchild(left);
		restruct(left,pl, index - il + pl-1,il,index-1);
	}
	if (index == ir)
		root->setrightchild(NULL);
	else{
		binarytreenode<int> *right = new binarytreenode<int>;
		right->setvalue(postorder[pr-1]);
		root->setrightchild(right);
		restruct(right,index - il + pl,pr-1,index+1,ir);
	}
	
}