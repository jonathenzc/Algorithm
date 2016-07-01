#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//方法1：
//struct twitterInfo {
//	int tweetId;
//	bool isValid;
//
//	twitterInfo(int _tweetId, bool _isValid)
//	{
//		tweetId = _tweetId;
//		isValid = _isValid;
//	}
//};
//
//class Twitter {
//public:
//	/** Initialize your data structure here. */
//	Twitter() {
//		twitterCnt = 0;
//	}
//	/** Compose a new tweet. */
//	void postTweet(int userId, int tweetId) {
//		//先将自己的tweetmap塞入并更新自己发布的twittermap
//		twitterInfo info(tweetId, true);
//		twitterMap[userId].push_back(info);
//		myTwitterMap[userId].push_back(tweetId);
//		
//		//遍历所有关注userId
//		for (auto iter = followedMap.begin(); iter != followedMap.end(); iter++)
//		{
//			if (iter->second[userId] == 1)
//				twitterMap[iter->first].push_back(info);
//		}
//
//		//维护全局的推特
//		twitterCnt++;
//		globalTwitterMap[tweetId] = twitterCnt;
//	}
//
//	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//	vector<int> getNewsFeed(int userId) {
//		vector<twitterInfo> st = twitterMap[userId];
//
//		vector<int> v;
//
//		int cnt = 0;
//		int i = st.size() - 1;
//		while (i >= 0 && cnt < 10)
//		{
//			if (st[i].isValid)
//			{		
//				v.push_back(st[i].tweetId);
//
//				cnt++;
//			}
//
//			i--;
//		}
//
//		return v;
//	}
//
//	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
//	//需要考虑那种follow了，再unfollow的情况，再follow的情况
//	void follow(int followerId, int followeeId) {
//		if (followerId == followeeId)
//			return;
//
//		if (followedMap[followerId][followeeId] == 0)
//		{
//			followedMap[followerId][followeeId] = 1;
//
//			//更新follower的vector
//			vector<twitterInfo> followerV = twitterMap[followerId];
//			vector<int> followeeV = myTwitterMap[followeeId];
//
//			//处理之前关注了，然后取消关注仍保留在twitter vector里的twitter
//			int followeeIndex = 0;
//
//			bool firstFollow = true;
//
//			while (followeeIndex < followeeV.size())
//			{
//				bool isEnd = false;
//				for (int i = 0; i < followerV.size(); i++)
//				{
//					if (followerV[i].tweetId == followeeV[followeeIndex])
//					{
//						followerV[i].isValid = true;
//						firstFollow = false;
//						break;
//					}
//
//					if (i == followerV.size() - 1)
//					{
//						isEnd = true;
//						break;
//					}
//				}
//
//				if (isEnd)
//					break;
//
//				followeeIndex++;
//			}
//
//			if (firstFollow)
//				followeeIndex = 0;
//
//			if (followeeIndex < followeeV.size())
//			{
//				int followerIndex = followerV.size() - 1;
//
//				for (followeeIndex; followeeIndex < followeeV.size(); followeeIndex++)
//				{
//					//先在followerV后压入该元素，然后冒泡找到合适的位置
//					int target = followeeV[followeeIndex];
//					int targetGlobalPos = globalTwitterMap[target];
//
//					twitterInfo targetInfo(target, true);
//
//					followerV.push_back(targetInfo);
//
//					int i = followerV.size() - 2;
//
//					while (i >= 0)
//					{
//						twitterInfo info = followerV[i];
//
//						if (globalTwitterMap[info.tweetId] < targetGlobalPos)
//							break;
//						else
//						{
//							followerV[i + 1] = followerV[i];
//							followerV[i] = targetInfo;
//						}
//
//						i--;
//					}
//				}
//
//				twitterMap[followerId] = followerV;
//			}
//		}
//	}
//
//	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
//	void unfollow(int followerId, int followeeId) {
//		if (followerId == followeeId)
//			return;
//
//		if (followedMap[followerId][followeeId] == 1)
//		{
//			followedMap[followerId][followeeId] = 0;
//			//更新follower的vector
//			vector<twitterInfo> followerV = twitterMap[followerId];
//			vector<int> followeeV = myTwitterMap[followeeId];
//
//			int followerIndex = followerV.size() - 1;
//
//			for (int i = followeeV.size() - 1; i >= 0; i--)
//			{
//				followerIndex = followerV.size() - 1;
//
//				while (followerIndex >= 0)
//				{
//					if (followerV[followerIndex].tweetId == followeeV[i])
//						twitterMap[followerId][followerIndex].isValid = false;
//
//					followerIndex--;
//				}
//			}
//		}
//	}
//
//private:
//	unordered_map<int, unordered_map<int, int>> followedMap; //键是urserId，值是一个follow的map，该map的值是是否follow
//	unordered_map<int,vector<twitterInfo>> twitterMap; //键是urserId，值是他的twitter列表
//	unordered_map<int, vector<int>> myTwitterMap; //键是urserId，值是发布的twitter列表
//	unordered_map<int, int> globalTwitterMap; //记录发推的总时间顺序
//	int twitterCnt; //记录已经发过的推特的数量
//};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/

//方法2：
struct twitterPair {
	int userId;
	int tweetId;
	twitterPair(int _userId, int _tweetId)
	{
		userId = _userId;
		tweetId = _tweetId;
	}
};

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {
		
	}
	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		twitterPair tPair(userId,tweetId);

		twitterVec.push_back(tPair);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		unordered_set<int> followPeopleSet = followMap[userId];

		vector<int> v;

		followPeopleSet.insert(userId);

		int cnt = 0;

		for (int i = twitterVec.size()-1; i >= 0;i--)
		{
			twitterPair tPair = twitterVec[i];

			int twitterAuthorId = tPair.userId;

			if (followPeopleSet.find(twitterAuthorId) != followPeopleSet.end())
			{
				v.push_back(tPair.tweetId);
				cnt++;
			}

			if (cnt == 10)
				break;
		}

		return v;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	//需要考虑那种follow了，再unfollow的情况，再follow的情况
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
			followMap[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId != followeeId)
			followMap[followerId].erase(followeeId);
	}

private:
	unordered_map<int,unordered_set<int>> followMap;
	vector<twitterPair> twitterVec;
};


void testPrint(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
}

int main()
{
	Twitter twitter;

	// User 1 posts a new tweet (id = 5).
	twitter.postTweet(1, 5);

	// User 1's news feed should return a list with 1 tweet id -> [5].
	vector<int> v1 = twitter.getNewsFeed(1);
	testPrint(v1);

	// User 1 follows user 2.
	twitter.follow(1, 2);

	// User 2 posts a new tweet (id = 6).
	twitter.postTweet(2, 6);

	// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
	// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
	vector<int> v2 = twitter.getNewsFeed(1);
	testPrint(v2);

	// User 1 unfollows user 2.
	twitter.unfollow(1, 2);

	// User 1's news feed should return a list with 1 tweet id -> [5],
	// since user 1 is no longer following user 2.
	vector<int> v3 = twitter.getNewsFeed(1);
	testPrint(v3);

	twitter.postTweet(1, 7);
	twitter.postTweet(1, 8);
	twitter.postTweet(1, 9);
	twitter.postTweet(1, 10);

	twitter.postTweet(2, 11);


	twitter.follow(1, 2);

	vector<int> v4 = twitter.getNewsFeed(1);
	testPrint(v4);


	twitter.unfollow(1, 2);

	vector<int> v5 = twitter.getNewsFeed(1);
	testPrint(v5);

	twitter.postTweet(1, 12);

	twitter.postTweet(2, 13);
	vector<int> v6 = twitter.getNewsFeed(1);
	testPrint(v6);

	twitter.follow(1, 2);

	vector<int> v7 = twitter.getNewsFeed(1);
	testPrint(v7);


	//*********************
	//twitter.postTweet(1,1);

	//vector<int> v1 = twitter.getNewsFeed(1);
	//testPrint(v1);

	//twitter.follow(2,1);

	//vector<int> v2 = twitter.getNewsFeed(2);
	//testPrint(v2);

	//twitter.unfollow(2, 1);

	//vector<int> v3 = twitter.getNewsFeed(2);
	//testPrint(v3);

	return 0;
}