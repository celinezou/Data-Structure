#pragma once
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
	binarytreenode() { left = NULL;right = NULL; };
	
	binarytreenode(const T& ele) 
	{ info = ele;left = NULL;right = NULL; };

	binarytreenode(const T& ele, binarytreenode<T>*l, binarytreenode<T>*r)
	{info = ele;left = l;right = r;};

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
bool binarytree<T>::isempty()const{
	if (root == NULL)
		return true;
	else
		return false;
}

template <class T>
void binarytree<T>::preorder(binarytreenode<T>* root) {
	if (root != NULL) {
		//Visit(root);
		cout << root->value() << " ";
		preorder(root->leftchild());
		preorder(root->rightchild());
	}
}
template <class T>
void binarytree<T>::inorder(binarytreenode<T>* root) {
	if (root != NULL) {
		inorder(root->leftchild());
		Visit(root);
		inorder(root->rightchild());
	}
}
template <class T>
void binarytree<T>::postorder(binarytreenode<T>* root) {
	if (root != NULL) {
		postorder(root->leftchild());
		postorder(root->rightchild());
		Visit(root);
	}
}
template <class T>
void binarytree<T>::levelorder(binarytreenode<T>*root) {
	queue<binarytreenode<T>*>aQueue;
	binarytreenode<T>*pointer = root;
	if (pointer!=NULL) aQueue.push(pointer);
	while (!aQueue.empty()) {
		pointer = aQueue.front();
		aQueue.pop();
		Visit(pointer);
		if (pointer->leftchild() != NULL)
			aQueue.push(pointer->leftchild());
		if(pointer->rightchild() != NULL)
			aQueue.push(pointer->rightchild());
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