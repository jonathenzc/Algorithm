#include <iostream>
#include <string>

using namespace std;

const int NODESIZE = 26;

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

	TrieNode* getRoot()
	{
		return root;
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
	//方法1：search
	//bool search(string word) {
	//	if (word.size() == 0)
	//		return true;

	//	TrieNode *nextTrie = root;
	//	bool wordInserted = false;
	//	for (int i = 0; i < word.size(); i++)
	//	{
	//		if(word[i] == '.')
	//		{
	//			if (i == word.size() - 1) //最后一位是点
	//			{
	//				for (int j = 0; j < 26; j++)
	//				{
	//					if (nextTrie != NULL && nextTrie->next[j] != NULL)
	//					{
	//						if (nextTrie->next[j]->nodeInserted)
	//							return true;
	//					}

	//					if (j == 25)
	//						return false;
	//				}
	//			}
	//			else
	//			{
	//				bool isFound = false;
	//				string substr = word;

	//				for (int j = 0; j < 26; j++)
	//				{
	//					if (nextTrie != NULL && nextTrie->next[j] != NULL)
	//					{
	//						substr = word;
	//						substr[i] = 'a' + j;
	//						isFound = search(substr);

	//						if (isFound == true)
	//							return true;
	//					}

	//					if (j == 25 && isFound == false)
	//						return false;
	//				}
	//			}
	//		}
	//		else
	//		{
	//			if (nextTrie != NULL && nextTrie->next[word[i] - 'a'] != NULL && nextTrie->next[word[i] - 'a']->letter == word[i])
	//			{
	//				wordInserted = nextTrie->next[word[i] - 'a']->nodeInserted;
	//				nextTrie = nextTrie->next[word[i] - 'a'];
	//			}
	//			else
	//				return false;

	//			if (i == word.size() - 1)
	//			{
	//				if (wordInserted)//处理字典中加入了abb,所有ab时的情况
	//					return true;
	//				else
	//					return false;
	//			}
	//		}
	//	}
	//}

	//方法1：search
	bool search(string word,TrieNode *nextTrieNode) {
		if (word.size() == 0)
			return true;

		TrieNode *nextTrie = nextTrieNode;
		bool wordInserted = false;
		for (int i = 0; i < word.size(); i++)
		{
			if(word[i] == '.')
			{
				if (i == word.size() - 1) //最后一位是点
				{
					for (int j = 0; j < 26; j++)
					{
						if (nextTrie != NULL && nextTrie->next[j] != NULL)
						{
							if (nextTrie->next[j]->nodeInserted)
								return true;
						}

						if (j == 25)
							return false;
					}
				}
				else
				{
					bool isFound = false;
					string substr = word.substr(i+1);

					for (int j = 0; j < 26; j++)
					{
						if (nextTrie != NULL && nextTrie->next[j] != NULL)
						{
							isFound = search(substr, nextTrie->next[j]);

							if (isFound == true)
								return true;
						}

						if (j == 25 && isFound == false)
							return false;
					}
				}
			}
			else
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
	}

private:
	TrieNode* root;
};


class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		trie.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return trie.search(word, trie.getRoot());
	}
private:
	Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

void testPrint(WordDictionary wordDictionary,string s)
{
	if (wordDictionary.search(s))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	WordDictionary wordDictionary;
	wordDictionary.addWord("word");
    
	testPrint(wordDictionary,"word");
	testPrint(wordDictionary, "....");
	testPrint(wordDictionary, ".ord");

	testPrint(wordDictionary,"wor.");
	testPrint(wordDictionary, "wo..");
	testPrint(wordDictionary, "wo.s");

	return 0;
}