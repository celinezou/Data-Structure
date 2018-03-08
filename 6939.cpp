#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Minheap {
private:
	T* heaparray;
	int currentsize;
	int maxsize;
	void buildheap();
public:
	Minheap(int n, T arrays[]);
	virtual ~Minheap()
	{
		delete[]heaparray;

	}
	bool isleaf(int pos)const {
		return(pos >= currentsize / 2) && (pos < currentsize);
	}
	int leftchild(int pos)const {
		return 2 * pos + 1;
	}
	int rightchild(int pos)const {
		return 2 * pos + 2;
	}
	int parent(int pos)const {
		return (pos - 1) / 2;
	}
	bool Remove(int pos, T&node);
	bool Insert(const T& newnode);
	T Removemin();
	void Siftup(int pos);
	void Siftdown(int pos);
};
template <class T>
Minheap<T>::Minheap(int n, T arrays[]) {
	currentsize = n;
	if (n <= 0)
		return;
	maxsize = n;
	heaparray = new T[maxsize];
	for (int i = 0;i < n;i++) {
		heaparray[i] = arrays[i];
	}
	buildheap();
}
template <class T>
bool Minheap<T>::Remove(int pos, T&node) {
	if ((pos < 0) || (pos >= currentsize))
		return false;
	T temp = heaparray[pos];
	heaparray[pos] = heaparray[--currentsize];
	Siftup(pos);
	Siftdown(pos);
	node = temp;
	return true;
}
template <class T>
bool Minheap<T>::Insert(const T& newnode) {
	if (currentsize == maxsize) {
		return false;
	}
	else {
		heaparray[currentsize] = newnode;
		Siftup(currentsize);
		currentsize++;
		return true;
	}
}
template <class T>
T Minheap<T>::Removemin() {
	if (currentsize == 0) {
		cout << "can not delete" << endl;
		return 1;
	}
	swap(heaparray[0], heaparray[--currentsize]);
	if (currentsize > 1)
		Siftdown(0);
	return heaparray[currentsize];
}
template<class T>
void Minheap<T>::Siftup(int pos) {
	int temppos = pos;
	T temp = heaparray[pos];
	while (temppos > 0 && heaparray[parent(temppos)] > temp) {
		heaparray[temppos] = heaparray[parent(temppos)];
		temppos = parent(temppos);
	}
	heaparray[temppos] = temp;
}
template<class T>
void Minheap<T>::Siftdown(int pos) {
	int i = pos;
	int j = 2 * i + 1;
	T temp = heaparray[i];
	while (j < currentsize) {
		if (j<currentsize - 1 && heaparray[j]>heaparray[j + 1])
			j++;
		if (temp > heaparray[j]) {
			heaparray[i] = heaparray[j];
			i = j;
			j = 2 * i + 1;
		}
		else break;
	}
	heaparray[i] = temp;
}
template<class T>
void Minheap<T>::buildheap() {
	for (int i = currentsize / 2 - 1;i >= 0;i--) {
		Siftdown(i);
	}
}


template< class T >
class binarytreenode {
private:
	T info;
	binarytreenode* left;
	binarytreenode* right;
public:
	binarytreenode() { left = NULL;right = NULL; };

	binarytreenode(const T& ele)
	{
		info = ele;left = NULL;right = NULL;
	};

	T value() const{ return info; };

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
	bool operator<(const binarytreenode<T> &a)const { return info < a.value(); };
	bool operator>(const binarytreenode<T> &a)const { return info > a.value(); };
	bool isleaf() { if (left == NULL &&right == NULL)return true;else return false; }
};


int WPL(binarytreenode<int>* root);
int main() {
	int n,a;
	cin >> n;
	binarytreenode<int> *arr = new binarytreenode<int>[n];
	
	for (int i = 0;i < n;i++) {

		cin >> a;
		arr[i].setvalue(a);
	}
	Minheap<binarytreenode<int>> myheap(n, arr);
	delete[]arr;
	binarytreenode<int> *arrays = new binarytreenode<int>[2*n];
	for (int i = 0;i < 2*n-2;i=i+2) {
		binarytreenode<int> *parent = new binarytreenode<int>;
		arrays[i] =myheap.Removemin();
		arrays[i+1]=myheap.Removemin();
		parent->setleftchild(&arrays[i]);
		parent->setrightchild(&arrays[i+1]);
		parent->setvalue(arrays[i].value() + arrays[i+1].value());
		myheap.Insert(*parent);
		delete parent;
	}
	binarytreenode<int> *root = &arrays[2*n-1];
	arrays[2 * n - 1] = myheap.Removemin();
	int l=WPL(root);
	cout << l<<endl;
	

}
enum Tags {Left,Right};
typedef struct {
	binarytreenode<int>* pointer;
	Tags tag;
}element;

int WPL(binarytreenode<int>* root) {
	stack<element> astack;
	element ele;
	binarytreenode<int>* node=root;
	int l = 0;
	while (!astack.empty() || node) {
		if (node!=NULL) {
			ele.pointer = node;
			ele.tag = Left;
			astack.push(ele);
			node = node->leftchild();
		}
		else {		
			ele = astack.top();
			astack.pop();
			if (ele.tag == Left) {
				ele.tag = Right;
				astack.push(ele);
				node = ele.pointer->rightchild();
			}
			else {
				if (ele.pointer->isleaf()) {
					l = l + astack.size()*ele.pointer->value();
					//cout << astack.size() << endl;
					//cout << ele.pointer->value() << endl;
				}
				node = NULL;
			}
		}
	}
	return l;
}