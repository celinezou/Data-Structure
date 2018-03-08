#include <queue>
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
	int i;
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
	bool isempty()const;
	binarytreenode<T>*Root() { return root; };
	void preorder(binarytreenode<T>* root);
	void inorder(binarytreenode<T>* root);
	void postorder(binarytreenode<T>* root);
	void levelorder(binarytreenode<T>* root);
	void deletebinarytree(binarytreenode<T>* root);
	void createtree(binarytreenode<T>* Root) { root = Root; }
	~binarytree()
	{
		deletebinarytree(root);
	}
};

template <class T>
void binarytree<T>::preorder(binarytreenode<T>* root) {
	if (root != NULL) {
		//Visit(root);
		cout << root->value();
		preorder(root->leftchild());
		preorder(root->rightchild());
	}
}
template <class T>
void binarytree<T>::inorder(binarytreenode<T>* root) {
	if (root != NULL) {
		inorder(root->leftchild());
		//Visit(root);
		cout << root->value();
		inorder(root->rightchild());
	}
}
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

int getlevel(string s);

int main() {
	int num;
	char r;
	string a;
	cin >> num;
	while (num > 0) {
		binarytreenode<char>*arraytree = new binarytreenode<char>[100];
		cin >> r;
		arraytree[0].setvalue(r);
		arraytree[0].i = 0;
		int k = 1;
		a = "\n";
		getline(cin, a);
		while (getline(cin, a), a.length() != 1) {
			arraytree[k].i = getlevel(a);
			arraytree[k].setvalue(a[arraytree[k].i]);
			arraytree[k].setleftchild(NULL);
			arraytree[k].setrightchild(NULL);
			//find father
			int temp=0;
			for (int j = k - 1;j >= 0;j--) {
				if (arraytree[j].i == arraytree[k].i) {
					temp = 1;
					//cout << "it is right" << endl;
					continue;
				}
				if (arraytree[j].i == arraytree[k].i-1) {
					if (temp == 0 && arraytree[k].value() != '*')
					{
						arraytree[j].setleftchild(&arraytree[k]);
						//cout << arraytree[j].value()<<"set left" << endl;
					}
					if (temp==1 && arraytree[k].value() != '*') 
					{
						arraytree[j].setrightchild(&arraytree[k]);
						//cout << arraytree[j].value() << "set right" << endl;
					}
					break;
				}

			}
			k++;
		}

		
		binarytree<char>*texttree = new binarytree<char>;
		texttree->createtree(&arraytree[0]);
		//output
		texttree->preorder(&arraytree[0]);
		cout << endl;
		texttree->postorder(&arraytree[0]);
		cout << endl;
		texttree->inorder(&arraytree[0]);
		cout << endl;
		cout << endl;
		delete []arraytree;
		num--;
	}
}

int getlevel(string s) {
	for (int i = 0, len = s.length();i < len;i++) {
		if (s[i] != '-')
			return i;
	}
	return 0;
}