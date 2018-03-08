#include <iostream>
using namespace std;
class  edge
{
public:
	int from, to, weight;
	edge() { from = -1;to = -1;weight = 0; };
	edge(int f, int t, int w) { from = f;to = t;weight = w; }
	bool operator>(edge oneedge) { return weight > oneedge.weight; }
	bool operator<(edge oneedge) { return weight < oneedge.weight; }
};
struct node {
	node* n;
};
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
node* find(node*p);
node mark[26];

int main() {
	int numVertex,num;
	cin >> numVertex;
	char point;

	edge* graphedge=new edge[75];
	//read
	int m = 0, row, column, w;
	for (int i = 0;i < numVertex - 1;i++) {
		cin >> point>>num;
		row = point - 'A';
		for (int j = 0;j < num;j++) {
			cin >> point >> w;
			column = point - 'A';
			graphedge[m++]=edge(row, column, w);
		}
	}
	//放入堆中
	edge* graphedges = new edge[m];
	for (int i = 0;i < m;i++) {
		graphedges[i] = graphedge[i];
	
	}
	delete graphedge;
	Minheap<edge> H(m, graphedges);
	//合并
	edge* MST = new edge[numVertex - 1];
	for (int i = 0;i < 26;i++) mark[i].n = &mark[i];
	int n=0,sum=0;
	while (n<numVertex-1) {
		edge e = H.Removemin();
		if (find(&mark[e.from]) != find(&mark[e.to])) {
			MST[n++] = e;
			find(&mark[e.from])->n = find(&mark[e.to]);
		}
	}
	for (int i = 0;i < n;i++) {
		sum += MST[i].weight;
	}
	cout << sum << endl;
}

node* find(node*p) {
	if (p->n == p) return p;
	p->n = find(p->n);
	return p->n;
}