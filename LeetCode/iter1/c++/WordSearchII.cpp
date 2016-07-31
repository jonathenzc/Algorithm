#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

	TrieNode* getRoot()
	{
		return root;
	}

private:
	TrieNode* root;
};


void searchHelper(vector<vector<char>>& board, TrieNode *trie, string s,int i,int j,vector<string> &v)
{
	char ch = board[i][j];//当前棋盘的字符

	if (ch != '*')
	{
		trie = trie->next[ch - 'a'];
		string newStr = s + ch;
		if (trie != NULL )
		{
			if(trie->nodeInserted)
			{ 
				v.push_back(newStr);
				trie->nodeInserted = false; //已经塞入到容器中
			}

			board[i][j] = '*'; //棋盘该位置已访问过
			if (i - 1 >= 0)//上
				searchHelper(board, trie, newStr, i - 1, j, v);
			if (i + 1 <= board.size() - 1)//下
				searchHelper(board, trie, newStr, i + 1, j, v);

			if (j - 1 >= 0)//左
				searchHelper(board, trie, newStr, i, j - 1, v);

			if (j + 1 <= board[0].size() - 1)//右
				searchHelper(board, trie, newStr, i, j + 1, v);
			board[i][j] = ch;
		}
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	vector<string> resultV;
	
	if (board.size() == 0)
		return resultV;

	//对words构建字典树
	Trie trie = Trie();

	for (int i = 0; i < words.size(); i++)
		trie.insert(words[i]);

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			searchHelper(board, trie.getRoot(), "",i, j, resultV);
		}
	}

	return resultV;
}

int main()
{
	vector<vector<char>> board;
	vector<char> v1;
	v1.push_back('o');
	v1.push_back('a');
	v1.push_back('a');
	v1.push_back('n');

	board.push_back(v1);

	vector<char> v2;
	v2.push_back('e');
	v2.push_back('t');
	v2.push_back('a');
	v2.push_back('e');

	board.push_back(v2);

	vector<char> v3;
	v3.push_back('i');
	v3.push_back('h');
	v3.push_back('k');
	v3.push_back('r');

	board.push_back(v3);

	vector<char> v4;
	v4.push_back('i');
	v4.push_back('f');
	v4.push_back('l');
	v4.push_back('v');

	board.push_back(v4);

	vector<string> para;
	para.push_back("oath");
	para.push_back("pea");
	para.push_back("eat");
	para.push_back("rain");

	vector<string> result = findWords(board, para);
	for (auto s : result)
		cout << s << endl;

	return 0;
}