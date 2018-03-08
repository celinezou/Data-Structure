#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 50005;
//Tkey为输入主键与辅键的结构体
//key表示主键，aux表示辅键，index表示是输入的第几个结点
struct Tkey {
	string label;
	int pri, index;
} keys[maxn];
//Tnode是BST结点的结构体，key表示主键，aux表示辅键
//father表示父结点的编号，leftChild和rightChild表示左右儿子结点
struct Tnode {
	string label;
	  int pri, father, leftChild, rightChild;
} node[maxn];
int n;

//排序的比较函数
bool cmp(const Tkey &a, const Tkey &b) {
	return a.label < b.label;
}
void travel(int i) {
	if (i != 0) {
		cout << "(";
		travel(node[i].leftChild);
		cout<<node[i].label <<"/" <<node[i].pri;
		travel(node[i].rightChild);
		cout << ")";
	}
}
int main() {
	//读入数据
	while (1) {
		int i;
		char  c;
		cin >> n;
		if (n == 0) break;
		getchar();
		for (i = 1; i <= n; ++i) {
			keys[i].label.clear();
			while (c = getchar(), c != '/') 
				keys[i].label += c;
			cin>> keys[i].pri;
			keys[i].index = i;
			getchar();
		}
		//按key对结点排序
		sort(keys + 1, keys + n + 1, cmp);

		//按key从小到大将结点插入BST
		//father表示当前插入结点的父节点，leftChild表示当前插入结点的左儿子节点  
		//rightMost表示每次插入前BST最右的结点
		int p, father, leftChild, rightMost = 0;
		for (i = 1; i <= n; ++i) {
			//寻找插入结点的父亲与左儿子
			leftChild = 0; father = rightMost;
			while (father != 0 && keys[i].pri > node[father].pri) {
				leftChild = father;
				father = node[father].father;
			}
			//将结点插入BST
			p = keys[i].index;
			node[p].label = keys[i].label;
			node[p].pri = keys[i].pri;
			node[p].father = father;
			node[p].leftChild = leftChild;
			node[p].rightChild = 0;
			if (father != 0)
				node[father].rightChild = p;
			if (leftChild != 0)
				node[leftChild].father = p;
			rightMost = p;
		}

		//输出答案
		for (i = 1; i <= n; ++i)
			if (node[i].father == 0) {
				travel(i);
				cout << endl;
				break;
			}
			
	}
}