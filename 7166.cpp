#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template< class T >
class binarytreenode {
private:
	T info;

	binarytreenode* left;
	binarytreenode* right;
public:
	int n;
	binarytreenode() { left = NULL;right = NULL; };

	binarytreenode(const T& ele)
	{
		info = ele;left = NULL;right = NULL;
	};

	binarytreenode(const T& ele, binarytreenode<T>*l, binarytreenode<T>*r)
	{
		info = ele;left = l;right = r;
	};

	T value() { return info; };

	binarytreenode<T>*leftchild()const
	{
		return left;
	};

	binarytreenode<T>*rightchild()const
	{
		return right;
	};
	void setleftchild(binarytreenode*p) { left = p; }
	void setrightchild(binarytreenode*p) { right = p; }
	void setvalue(const T&p) { info = p; }
};

int main() {
	int num,temp=0;
	char a;
	cin >> num;
	a = getchar();

	binarytreenode<char> *mytt=new binarytreenode<char>[num];
	while (temp < num) {
		a = getchar();
		mytt[temp].setvalue(a);
		a = getchar();
		mytt[temp].n = a - '0';
		temp++;
		a = getchar();
	}

	binarytreenode<char>* root,*tp;
	stack<binarytreenode<char>*> astack;
	for (int i = 0;i < num-1;i++) {
		if (mytt[i].n == 0) {
			astack.push(&mytt[i]);
			mytt[i].setleftchild(&mytt[i + 1]);
		}
		else {
			tp =astack.top();
			astack.pop();
			tp->setrightchild(&mytt[i + 1]);
		}
	}
	root = mytt;

	tp = root;
	queue<binarytreenode<char>*> aqueue;
	aqueue.push(tp);
	while (!aqueue.empty()) {
		tp = aqueue.front();
		aqueue.pop();
		
		if (tp->value() != '$') {
			cout << tp->value() << " ";
			tp = tp->leftchild();
			while (tp != NULL) {
				astack.push(tp);
				tp = tp->rightchild();
			}
			while (!astack.empty()) {
				tp = astack.top();
				astack.pop();
				aqueue.push(tp);
			}
		}

	}

	cout << endl;

}
