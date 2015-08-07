#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int NODESIZE = 26;

struct backTrackEle
{
	TrieNode *fatherNode;
	int index;
	backTrackEle(TrieNode *node, int theIndex) :fatherNode(node), index(theIndex){}
};

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		next = new TrieNode*[NODESIZE];
		for (int i = 0; i < NODESIZE; i++)
			next[i] = NULL;

		nodeInserted = false;
		hasChildren = false;
	}

	TrieNode(char theLetter) {
		next = new TrieNode*[NODESIZE];
		for (int i = 0; i < NODESIZE; i++)
			next[i] = NULL;

		letter = theLetter;
		nodeInserted = false;
		hasChildren = false;
	}

	TrieNode **next;
	char letter;
	bool nodeInserted; //记录从root节点到当前节点的子串是否插入过字典
	bool hasChildren; //记录该节点下是否有孩子
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
			{
				nextNode->next[word[i] - 'a'] = new TrieNode(word[i]);
				nextNode->hasChildren = true;
			}

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
		stack<backTrackEle> s;
		
		int i = 0;
		while (i<s.size())
		{
			if (word[i] == '.')
			{
				//检查当前节点是否有孩子
				if(nextTrie->hasChildren)
				{
					//从'a'找到不为NULL的节点压栈
					TrieNode *temp = nextTrie->next[0];
					int index = 0;
					while (temp == NULL)
					{
						index++;
						temp = nextTrie->next[index];
					}
					
					s.push(backTrackEle(nextTrie,index));

					nextTrie = temp;
					i++;
				}
				else
					return false;
			}
			else
			{
				if (nextTrie != NULL)
				{
					if (nextTrie->next[word[i] - 'a'] != NULL /*&&
						nextTrie->next[word[i] - 'a']->letter == word[i]*/)
					{
						wordInserted = nextTrie->next[word[i] - 'a']->nodeInserted;
						nextTrie = nextTrie->next[word[i] - 'a'];
						i++;
					}
					else//该字符没有word[i]这个孩子,回溯到上一个字符的下一个
					{
						if (!s.empty())
						{
							backTrackEle ele = s.top();
							if (ele.index == 25)//26个字母已经都检查过时，需要回溯到上一层
							{

							}

							TrieNode *temp = nextTrie->next[0];
							int index = 0;
							while (temp == NULL)
							{
								index++;
								temp = nextTrie->next[index];
							}

							nextTrie = ele.fatherNode->next[++ele.index]; //比如'a'不行，就试'b'
							s.pop();
							s.push(ele);
						}
					}

				}
				else//当前结点为空,说明不存在
					return false;

		

				if (i == word.size())
				{
					if (wordInserted)//处理字典中加入了abb,所有ab时的情况
						return true;
					else
						return false;
				}
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

class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		trie.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {

	}

	Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
	//TrieNode *a = NULL;

	Trie trie;
	trie.insert("abc");
	trie.insert("baa");

	if (trie.search("ab."))
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