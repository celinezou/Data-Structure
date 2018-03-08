#include "calculator.h"
#include "BITREE.h"
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
binarytreenode<char>* arraytree = new binarytreenode<char>[50];
map<char, int> mymap;
defined_by_me::stack<binarytreenode<char>*>* s = new defined_by_me::stack<binarytreenode<char>*>;
void Merge(binarytreenode<char>* root);
int getheight(binarytreenode<char>* root);
void levelorder(binarytreenode<char>* root);

int main() {
	char a;
	int top = 0;
	char temp;
	// --------------------------------------change to suffix
	char *suffix = new char[50];
	defined_by_me::stack<char> *charstack = new defined_by_me::stack<char>;
	while (a = getchar(), a != '\n') {
		if (a >= 'a'&&a <= 'z') {
			suffix[top] = a;
			top++;
		}
		else if (a == '(') {
			charstack->push(a);
		}
		else if (a == ')') {
			if (charstack->isempty()) {
				cout << "something wrong1" << endl;
				charstack->clear();
				return 1;
			}
			while (1) {
				charstack->pop(temp);
				if (temp != '(') {
					suffix[top] = temp;
					top++;
				}
				else
					break;
				if (charstack->isempty()) {
					cout << "something wrong2" << endl;
					charstack->clear();
					return 1;
				}
			}
		}
		else if (a == '+' || a == '-') {
			if (!charstack->isempty() && charstack->topprint() != '(') {
				do {
					charstack->pop(temp);
					suffix[top] = temp;
					top++;
				} while (!charstack->isempty() && charstack->topprint() != '(');
			}
			charstack->push(a);
		}
		else {
			if (!charstack->isempty() && (charstack->topprint() == '*' || charstack->topprint() == '/')) {
				do {
					charstack->pop(temp);
					suffix[top] = temp;
					top++;
				} while (!charstack->isempty() && (charstack->topprint() == '*' || charstack->topprint() == '/'));
			}
			charstack->push(a);
		}
	}
	while (!charstack->isempty()) {
		charstack->pop(temp);
		if (temp != '('&&temp != ')') {
			suffix[top] = temp;
			top++;

		}
		else {
			cout << "something wrong3" << endl;
			charstack->clear();
			return 1;
		}

	}
	delete charstack;

	/*

	calculator cal;
	cal.run(suffix, top + 1);
	delete[]suffix;
	cout << "end one loop" << endl;*/
	// -----------------------------------------create tree

	suffix[top] = '\n';
	for (int i = 0;i < top;i++) {
		cout << suffix[i];
		arraytree[i].setvalue(suffix[i]);
		if (suffix[i] >= 'a'&& suffix[i] <= 'z') {
			s->push(&arraytree[i]);
		}
		else {
			Merge(&arraytree[i]);
		}
	}
	cout << endl;
	binarytreenode<char>* root = new binarytreenode<char>;
	s->pop(root);
	levelorder(root);

	//calculate
	int num, value, v1, v2;
	char v;
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> v >> value;
		mymap[v] = value;
	}
	defined_by_me::stack<int>* si = new defined_by_me::stack<int>;
	for (int i = 0;i < top;i++) {
		if (suffix[i] >= 'a'&& suffix[i] <= 'z') {
			si->push(mymap[suffix[i]]);
		}
		else {
			si->pop(v1);
			si->pop(v2);
			switch(suffix[i]) {
			case '+': si->push(v2 + v1);break;
			case '-': si->push(v2-v1);break;
			case '*':si->push(v2*v1);break;
			case '/':si->push(v2/v1);break;
			}
		}
	}
	si->pop(value);
	cout << value<<endl;
	delete []arraytree;
	delete s;
	delete si;

}

void Merge(binarytreenode<char>* root){
	binarytreenode<char>*op1,*op2;
	if (s->isempty()) {
		cerr << "Missing operand" << endl;
	}
	s->pop(op1);
	if (s->isempty()) {
		cerr << "Missing operand" << endl;
	}
	s->pop(op2);
	root->setleftchild(op2);
	root->setrightchild(op1);
	s->push(root);
	
}
int getheight(binarytreenode<char>* root) {
	if (root == NULL)
		return 0;
	else {
		int l = getheight(root->leftchild());
		int r = getheight(root->rightchild());
		return max(l, r) + 1;
	}
}
void levelorder(binarytreenode<char>* root) {
	queue<binarytreenode<char>*>aQueue;
	binarytreenode<char>*pointer = root;
	int height = getheight(root);
	int ll = pow(2, height) - 1;
	char* level = new char[ll];
	int temp=0;
	int a=0;
	if (pointer != NULL) aQueue.push(pointer);
	while (a<ll) {
		pointer = aQueue.front();
		aQueue.pop();
		if (pointer == NULL) {
			level[temp] =' ';
			temp++;
			aQueue.push(NULL);
			aQueue.push(NULL);
		}
		else {
			level[temp] = pointer->value();
			temp++;
			aQueue.push(pointer->leftchild());
			aQueue.push(pointer->rightchild());
		}
		a++;
	}

	int nn = pow(2, height - 1);
	int i, j, k,l;
	temp = 0;
	for (i = 0,l = height;i < l;i++) {
		for ( k = 0;k <((nn>>i)- 1);k++) {
			cout << " ";
		}
		cout << level[temp];
		temp++;
		for (j = 0;j < (pow(2, i)-1);j++) {
			for (k = 0;k < ((nn >> (i - 1)) - 1);k++) 
				cout << " ";
			cout << level[temp];
			temp++;
		}
		cout << endl;

		if (i != l - 1) {
			for (k = 0;k < ((nn >> i) - 2);k++)
				cout << " ";
			for (j = 0;j < pow(2, i);j++) {
				if (level[temp] == ' ')
					cout << " ";
				else
					cout << "/";
				cout << " ";
				temp++;
				if (level[temp] == ' ')
					cout << " ";
				else
					cout << "\\";
				temp++;
				if (j != pow(2, i) - 1) {
					for (k = 0;k < ((nn >> (i - 1)) - 3);k++)
						cout << " ";
				}
			}
			temp = temp - 2 * pow(2, i);
			cout << endl;
		}
	}
}