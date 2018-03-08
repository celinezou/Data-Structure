#include <stdio.h>
using namespace std;

struct node
{
	node* par;
	node* opposite;
	node() {
		par = NULL;opposite = NULL;
	}
	
};
//node* partree;
node partree[2010];
node* find(int i);
int main() {
	int num,wormnum,sexnum,worm1,worm2,j;
	bool flag;
	scanf("%d", &num);
	for (int i = 0;i < num;i++) {
		flag = true;
		scanf("%d%d", &wormnum, &sexnum);
		//partree = new node[wormnum];
		for (int k = 1;k <= wormnum;k++) {
			partree[k].par = NULL;
			partree[k].opposite = NULL;
		}
		for (j = 0;j < sexnum;j++) {
			scanf("%d%d", &worm1, &worm2);
			if (flag) {
				node*temp1, *temp2;
				temp1 = find(worm1);
				temp2 = find(worm2);
				if (worm1 == worm2) {
					flag = false;
				}
				else if (temp1 == NULL&&temp2 == NULL) {
					partree[worm1].par = &partree[worm1];
					partree[worm2].par = &partree[worm2];
					partree[worm1].opposite = &partree[worm2];
					partree[worm2].opposite = &partree[worm1];


				}
				else if (temp1 == NULL&&temp2 != NULL) {
					partree[worm1].par = temp2->opposite;


				}
				else if (temp1 != NULL&&temp2 == NULL) {
					partree[worm2].par = temp1->opposite;

				}
				else if (temp1 == temp2) {
					flag = false;
				}
				else if (temp1->opposite != temp2) {
					temp2->par = temp1->opposite;
					temp2->opposite->par = temp1;

				}
			}
		}
		if(flag==false)
			printf("Scenario #%d:\nSuspicious bugs found!\n", i + 1);
		else printf("Scenario #%d:\nNo suspicious bugs found!\n", i + 1);
		printf("\n");
		//delete[]partree;
	}
}
node* find(int i) {
	node* temp;
	temp = &partree[i];
	if (temp->par == NULL)return NULL;
	while (temp->par != temp) {
		temp = temp->par;
	}
	return temp;

}