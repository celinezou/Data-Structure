#include <iostream>
using namespace std;
typedef struct treenode{
	int parent;
	int left;
	int right;
	treenode() { parent = -1;left = -1;right = -1; }
}treenode;
void exchange(treenode*arr,int node1,int node2);
void inquire(treenode*arr,int node1);
int main() {
	int num,m,n,temp,node1,node2;
	
	cin >> num;
	while (num > 0) {
		cin >> n >> m;
		treenode*arraytree = new treenode[n];
		for (int i = 0;i < n;i++) {
			cin >> temp>>node1>>node2;
			arraytree[temp].left = node1;
			arraytree[temp].right = node2;
			if (node1 != -1)
				arraytree[node1].parent = temp;
			if (node2 != -1)
				arraytree[node2].parent = temp;
		}

		for (int i = 0;i < m;i++) {
			cin >> temp;
			if (temp == 1) {
				cin >> node1 >> node2;
				exchange(arraytree, node1, node2);
			}
			else if (temp == 2) {
				cin >> node1;
				inquire(arraytree, node1);

			}
		}
		delete arraytree;
		num--;
	}
	return 0;
}

void exchange(treenode*arr,int node1, int node2) {
	int * pos1, *pos2;
	if (arr[arr[node1].parent].left == node1)
		pos1 = &arr[arr[node1].parent].left;
	else
		pos1 = &arr[arr[node1].parent].right;

	if (arr[arr[node2].parent].left == node2)
		pos2=&arr[arr[node2].parent].left;
	else
		pos2= &arr[arr[node2].parent].right;
	*pos1 = node2;
	*pos2 = node1;
	int temp;//不要忘记改反向操作！！！交换时注意思考都有什么发生变化了！
	temp = arr[node1].parent;
	arr[node1].parent = arr[node2].parent;
	arr[node2].parent = temp;

}
void inquire(treenode*arr, int node1) {
	while (arr[node1].left != -1) {
		node1 = arr[node1].left;
	}
	cout << node1 << endl;
}