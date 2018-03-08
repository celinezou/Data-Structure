#include <iostream>
#include <queue>
using namespace std;

template< class T >
class binarytreenode {
private:
	T info;
	
	binarytreenode* left;
	binarytreenode* right;
public:
	int degree;
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
	void insertfirst(binarytreenode*p);
};
template<class T>
void binarytreenode<T>::insertfirst(binarytreenode*p) {
	if (left == NULL) {
		left = p;
	}else{
		p->setrightchild(left);
		left = p;
	}

}
void inorder(binarytreenode<char>* root);

int main() {
	int treenum,k;
	cin >> treenum;
	char temp;
	temp = getchar();
	queue<binarytreenode<char>*> myq;
	for (int i = 0;i < treenum;i++) {
		binarytreenode<char>* arr = new binarytreenode<char>[30];
		k = 0;
		while (temp = getchar(), temp != '\n') {
			if (temp >= 'A'&& temp <= 'Z') {
				arr[k].setvalue(temp);
			}
			else if (temp >= '0'&& temp <= '9') {
				arr[k].degree = temp - '0';
				k++;
			}
			else continue;
		}
		for (int m = k - 1;m >= 0;m--) {
			if (arr[m].degree != 0){
				binarytreenode<char>* t;
				for (int b = 0;b < arr[m].degree;b++) {
					t = myq.front();
					myq.pop();
					arr[m].insertfirst(t);
				}
			}
			myq.push(&arr[m]);
		}
		binarytreenode<char>* root;
		root = myq.front();
		myq.pop();
		inorder(root);
		delete[]arr;
	}
	cout << endl;
}

void inorder(binarytreenode<char>* root) {
	if (root != NULL) {
		inorder(root->leftchild());
		cout << root->value()<<" ";
		inorder(root->rightchild());
	}
}