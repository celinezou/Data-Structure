#include <iostream>
#include <string>

using namespace std;
template< class T >
class binarytreenode {
private:
	T info;
	binarytreenode* left;
	binarytreenode* right;
public:
	binarytreenode() {};

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

template <class T>
class binarytree {
private:
	binarytreenode<T>* root;
public:
	binarytree() { root = NULL; };
	binarytreenode<T>*Root() { return root; };
	void postorder(binarytreenode<T>* root);
	void deletebinarytree(binarytreenode<T>* root);
	void createtree(binarytreenode<T>* Root) { root = Root; }
	~binarytree()
	{
		deletebinarytree(root);
	}
};
template <class T>
void binarytree<T>::postorder(binarytreenode<T>* root) {
	if (root != NULL) {
		postorder(root->leftchild());
		postorder(root->rightchild());
		//Visit(root);
		cout << root->value();
	}
}
template<class T>
void binarytree<T>::deletebinarytree(binarytreenode<T>*root) {
	if (root != NULL) {
		deletebinarytree(root->leftchild());
		deletebinarytree(root->rightchild());
		delete root;
	}
}
string a, b;
int len;
void restrc(binarytreenode<char>* root,int pl,int pr,int il,int ir );
int main() {
	
	
	while (cin >> a >> b) {
		len = a.length();
		binarytreenode<char>*root = new binarytreenode<char>;
		root->setvalue(a[0]);
		restrc(root,0,len-1,0,len-1);
		binarytree<char>* mytree = new binarytree<char>;
		mytree->createtree(root);
		mytree->postorder(root);
		cout << endl;
		delete mytree;
	}
}
void restrc(binarytreenode<char>* root, int pl, int pr, int il, int ir) {
	int index;
	for (int i = 0;i < len;i++) {
		if (b[i] == root->value())
			index = i;
	}

	if (index == il) {
		root->setleftchild(NULL);
	}
	else {
		binarytreenode<char>*leftchild = new binarytreenode<char>;
		root->setleftchild(leftchild);
		leftchild->setvalue(a[pl + 1]);
		restrc(leftchild, pl + 1, pl + index - il, il, index - 1);
	}
	if (index == ir) {
		root->setrightchild(NULL);
	}
	else {
		binarytreenode<char>*rightchild = new binarytreenode<char>;
		root->setrightchild(rightchild);
		rightchild->setvalue(a[pl + index - il + 1]);
		restrc(rightchild, pl + index - il + 1, pr, index + 1, ir);
	}
}