#include <iostream>
#include <string>
#include <vector>

using namespace std;

//返回用于分割单词的空格集
vector<string> spaceSeperate(int candidateSize, int maxWidth, int strLength)
{
	vector<string> spaceCntV; //记录空格的个数
	int rest = maxWidth - strLength; //多余的空格
	int eachAddSpaceCnt = rest / (candidateSize - 1);
	int mod = rest % (candidateSize - 1);

	for (int j = 0; j < candidateSize - 1; j++)
	{
		int spaceCnt = 1 + eachAddSpaceCnt;
		if (mod > 0)
		{
			spaceCnt++;
			mod--;
		}

		string spaceStr = "";
		for (int k = 0; k < spaceCnt; k++)
			spaceStr += ' ';

		spaceCntV.push_back(spaceStr);
	}

	return spaceCntV;
}

//不需要考虑塞不进的情况
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> result;

	int strLength = 0;
	vector<string> candidateV; //储存候选的单词

	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];

		if (strLength == 0)
			strLength = s.size();
		else
			strLength += s.size() + 1; //1是空格

		if (strLength <= maxWidth)
			candidateV.push_back(s);
		else //一行装不下了
		{
			//将多出来的候选单词去掉，并从该单词计数
			strLength = strLength - s.size() - 1;
			i--;

			if (candidateV.size() == 1) //单词只有一个，对单词后补全空格
			{
				string pushS = candidateV[0];
				int restSpaceCnt = maxWidth - pushS.size();
				for (int j = 0; j < restSpaceCnt; j++)
					pushS += ' ';

				result.push_back(pushS);
			}
			else
			{
				//获取用于分隔单词空格的容器
				vector<string> spaceCntV = spaceSeperate(candidateV.size(), maxWidth, strLength);

				string pushS = "";
				for (int j = 0; j < candidateV.size(); j++)
				{
					if (j > 0)
						pushS += spaceCntV[j - 1];

					pushS += candidateV[j];
				}

				result.push_back(pushS);
			}

			//重置比较的状态
			strLength = 0;
			candidateV.clear();
		}

		//最后一行
		if (i == words.size() - 1)
		{
			string pushS = candidateV[0];

			for (int j = 1; j < candidateV.size(); j++)
				pushS += " "+candidateV[j];

			//补充剩下的空格
			int restSpaceCnt = maxWidth - pushS.size();
			for (int j = 0; j < restSpaceCnt; j++)
				pushS += ' ';

			result.push_back(pushS);
		}
	}

	return result;
}

void testPrint(vector<string> v, int n)
{
	vector<string> resultV = fullJustify(v, n);
	for (int i = 0; i < resultV.size(); i++)
		cout << resultV[i] << endl;
}

int main()
{
	//vector<string> v;
	//v.push_back("This");
	//v.push_back("is");
	//v.push_back("an");
	//v.push_back("example");
	//v.push_back("of");
	//v.push_back("text");
	//v.push_back("justification.");

	//testPrint(v,17);

	//vector<string> v;
	//v.push_back("a");
	//v.push_back("b");
	//v.push_back("c");
	//v.push_back("d");
	//v.push_back("e");
	//v.push_back("f");
	//v.push_back("g");

	//testPrint(v,1);


	vector<string> v;
	v.push_back("What");
	v.push_back("must");
	v.push_back("be");
	v.push_back("shall");
	v.push_back("be.");

	testPrint(v, 12);

	return 0;
}
