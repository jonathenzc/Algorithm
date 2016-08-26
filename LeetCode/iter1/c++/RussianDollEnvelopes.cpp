class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	if (envelopes.size() == 0)
		    return 0;
		    
    	sort(envelopes.begin(), envelopes.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.first < p2.first; });
    
    	int *dp = new int[envelopes.size()];
    	for (int i = 0; i < envelopes.size(); i++)
    		dp[i] = 1;
    		
    	int maxCnt = 1;
    
    	for (int i = 1; i < envelopes.size(); i++)
    	{
    		for (int j = 0; j < i; j++)
    		{
    			if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
    			{
    				if (dp[j] + 1 > dp[i])
    					dp[i] = dp[j] + 1;
    			}
    		}
    
    		if (dp[i] > maxCnt)
    			maxCnt = dp[i];
    	}
    
    	return maxCnt;
    }
};