#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 50005;
//TkeyΪ���������븨���Ľṹ��
//key��ʾ������aux��ʾ������index��ʾ������ĵڼ������
struct Tkey {
	string label;
	int pri, index;
} keys[maxn];
//Tnode��BST���Ľṹ�壬key��ʾ������aux��ʾ����
//father��ʾ�����ı�ţ�leftChild��rightChild��ʾ���Ҷ��ӽ��
struct Tnode {
	string label;
	  int pri, father, leftChild, rightChild;
} node[maxn];
int n;

//����ıȽϺ���
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
	//��������
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
		//��key�Խ������
		sort(keys + 1, keys + n + 1, cmp);

		//��key��С���󽫽�����BST
		//father��ʾ��ǰ������ĸ��ڵ㣬leftChild��ʾ��ǰ�����������ӽڵ�  
		//rightMost��ʾÿ�β���ǰBST���ҵĽ��
		int p, father, leftChild, rightMost = 0;
		for (i = 1; i <= n; ++i) {
			//Ѱ�Ҳ�����ĸ����������
			leftChild = 0; father = rightMost;
			while (father != 0 && keys[i].pri > node[father].pri) {
				leftChild = father;
				father = node[father].father;
			}
			//��������BST
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

		//�����
		for (i = 1; i <= n; ++i)
			if (node[i].father == 0) {
				travel(i);
				cout << endl;
				break;
			}
			
	}
}