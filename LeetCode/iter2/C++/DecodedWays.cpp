class Solution {
public:
    bool canBeDecoded(char ch1, char ch2)
    {
    	if (ch1 == '0')
    		return false;
    
    	int num = 0;
    	num = 10 * (ch1 - '0') + (ch2-'0');
    
    
    	if (num > 0 && num <= 26)
    		return true;
    	else
    		return false;
    }
    
    int numDecodings(string s) {
    	if (s.size() == 0)
	    	return 0;
	
    	int *dp = new int[s.size()+1];
    	dp[0] = 1;
    
    	if (s[0] == '0')
    		dp[1] = 0;
    	else
    		dp[1] = 1;
    
    	for (int i = 2; i <= s.size(); i++)
    	{
    		int cnt = 0;
    		if (s[i-1] != '0')
    			cnt += dp[i-1];
    
    		if (i>=2 && canBeDecoded(s[i - 2], s[i-1]))
    			cnt += dp[i-2];
    
    		dp[i] = cnt;
    	}
    
    	return dp[s.size()];
    }
};