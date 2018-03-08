#include <iostream>
#include <string>

using namespace std;
#define Size 26
typedef struct Trie_node {
	int count; //记录该结点代表的单词个数
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
	const char* p = key.c_str();
	while (*p) {
		if (node->next[*p - 'a'] == NULL) {
			node->next[*p - 'a'] = creat_trie_node();
		}
		node = node->next[*p - 'a'];
		p++;
	}
	node->count +=1;
}
/**
* 查询：不存在返回0，存在返回出现的次数
*/
int T_search(trie root, string key) {
	Trie_node* node = root;
	const char* p = key.c_str();
	while (*p) {
		if (node->next[*p - 'a'] == NULL)
			return 0;
		node = node->next[*p - 'a'];
		p++;
	}
	return node->count;
}
int main() {
	string s[1001];
	Trie_node* root = creat_trie_node();
	int l = 0;
	while (cin >> s[l++]) {
		T_insert(root, s[l]);
	}
	for (int i = 0;i < l;i++) {

	}
}