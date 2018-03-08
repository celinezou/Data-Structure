#include <iostream>
using namespace std;
struct node
{
	int num1;
	int num2;
	int c;
};
struct node2
{
	node2* par;
	node2* opposite;
	node2() {
		par = NULL;opposite = NULL;
	}

};
node2 partree[20010];
node A[100000];
node2* find(node2* i) {
	if (i->par == NULL)return NULL;
	if (i->par == i) return i;
	i->par = find(i->par);
	return i->par;
};
int partition(int left, int right) {
	int	p = A[left].c;
	node temp = A[left];
	int i = left;
	int j = right;
	while (i != j) {  // no
		while (j > i &&A[j].c <= p) j--;
		if (j > i) { A[i] = A[j];i++; };
		while (i < j&&A[i].c > p) i++;
		if (i < j) { A[j] = A[i];j--; }
	}
	A[i] = temp;
	return i;
}
void Sort(int left, int right) {
	if (left < right) { //no
		int p = partition(left, right);
		Sort(left, p - 1);
		Sort(p + 1, right);
	}
}
int main() {
	int N, M;
	int num1, num2, c;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> A[i].num1 >> A[i].num2 >> A[i].c;
	}
	//SORT
	Sort(0,M-1);
	//no!!!!!!!!!!!!!!!!!!!
	node2*temp1, *temp2;
	int i;
	for ( i = 0; i < M; i++) {
		num1 = A[i].num1;
		num2 = A[i].num2;
		temp1 = find(&partree[num1]);
		temp2 = find(&partree[num2]);
		if (temp1 == NULL&&temp2 == NULL) {
			partree[num1].par = &partree[num1];
			partree[num2].par = &partree[num2];
			partree[num1].opposite = &partree[num2];
			partree[num2].opposite = &partree[num1];
		}
		else if (temp1 == NULL&&temp2 != NULL) {
			partree[num1].par = temp2->opposite;
		}
		else if (temp1 != NULL&&temp2 == NULL) {
			partree[num2].par = temp1->opposite;
		}
		else if (temp1 == temp2) {
			cout << A[i].c << endl;
			break;
		}
		else if (temp1->opposite != temp2) {
			temp2->par = temp1->opposite;
			temp2->opposite->par = temp1;

		}
	}
	if(i==M)
		cout << 0 << endl;
}