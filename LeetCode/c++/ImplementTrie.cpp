#include <iostream>
#include <string>

using namespace std;

const int NODESIZE=26;

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		next = new TrieNode*[NODESIZE];
		for (int i = 0; i < NODESIZE; i++)
			next[i] = NULL;

		nodeInserted = false;
	}

	TrieNode(char theLetter) {
		next = new TrieNode*[NODESIZE];
		for (int i = 0; i < NODESIZE; i++)
			next[i] = NULL;

		letter = theLetter;
		nodeInserted = false;
	}

	TrieNode **next;
	char letter;
	bool nodeInserted;//记录从root节点到当前节点的子串是否插入过字典
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *nextNode = root;

		for (int i = 0; i < word.size(); i++)
		{
			if (nextNode->next[word[i] - 'a'] == NULL)
				nextNode->next[word[i] - 'a'] = new TrieNode(word[i]);

			nextNode = nextNode->next[word[i] - 'a'];

			if (i == word.size() - 1)
				nextNode->nodeInserted = true;
		}
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		if (word.size() == 0)
			return true;

		TrieNode *nextTrie = root;
		bool wordInserted = false;
		for (int i = 0; i < word.size(); i++)
		{
			if (nextTrie != NULL && nextTrie->next[word[i] - 'a'] != NULL && nextTrie->next[word[i] - 'a']->letter == word[i])
			{
				wordInserted = nextTrie->next[word[i] - 'a']->nodeInserted;
				nextTrie = nextTrie->next[word[i] - 'a'];
			}
			else
				return false;

			if (i == word.size() - 1)
			{
				if (wordInserted)//处理字典中加入了abb,所有ab时的情况
					return true;
				else
					return false;
			}
		}
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		if (prefix.size() == 0)
			return true;

		TrieNode *nextTrie = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (nextTrie != NULL && nextTrie->next[prefix[i] - 'a'] != NULL && nextTrie->next[prefix[i] - 'a']->letter == prefix[i])
				nextTrie = nextTrie->next[prefix[i] - 'a'];
			else
				return false;

			if (i == prefix.size() - 1)
				return true;
		}
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	//TrieNode *a = NULL;

	Trie trie;
	trie.insert("abc");
	trie.insert("baa");

	if (trie.search("ab"))
		cout << "Yes\n";
	else
		cout << "No\n";
	
	if (trie.startsWith("ab"))
		cout << "Yes\n";
	else
		cout << "No\n";

	trie.insert("ab");

	if (trie.search("ab"))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}