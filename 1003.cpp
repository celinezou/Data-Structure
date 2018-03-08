#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define Size 26
typedef struct Trie_node {
	int count; //记录该结点为前缀的单词个数
	Trie_node* next[Size];
}*trie;
Trie_node* creat_trie_node() {
	Trie_node* pnode = new Trie_node;
	pnode->count = 0;
	for (int i = 0;i < Size;i++) {
		pnode->next[i] = NULL;
	}
	return pnode;
}
// insert
void T_insert(trie root, string key) {
	Trie_node* node = root;
	char* p = new char[key.length()+1];
	strcpy(p,key.c_str());
	node->count += 1;

	for (int i = 0;i < key.length();i++) {
		if (node->next[p[i] - 'a'] == NULL) {
			node->next[p[i] - 'a'] = creat_trie_node();
		}
		node = node->next[p[i] - 'a'];
		node->count +=1;
	}
	delete p;
}
/**
* 查询：不存在返回0，存在返回出现的次数
*/
int T_search(trie root, string key) {
	Trie_node* node = root;
	char* p = new char[key.length() + 1];
	strcpy(p, key.c_str());
	string ss;
	for (int i = 0;i < key.length();i++) {
		ss += p[i];
		if (node->next[p[i] - 'a']->count == 1) break;
		node = node->next[p[i]-'a'];
	}
		cout << ss;
		delete p;
		return node->count;
		
}
int main(){
	string s[1001];
	Trie_node* root = creat_trie_node();
	int l = 0;
	while (cin >> s[l]) {
		T_insert(root, s[l]);
		l++;
	}

	for (int i = 0;i < l;i++) {
		cout << s[i] << " ";
		T_search(root, s[i]);
		cout << endl;
	}
}