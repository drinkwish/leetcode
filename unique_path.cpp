
//improved dp, 0ms, 100%
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        
        for(int i_ = m-2; i_ >=0; --i_){
            for(int j_ = n-2; j_ >=0; --j_){
                dp[j_] += dp[j_+1];
            }
        }
        
        return dp[0];
    }
};

//4ms, 7.42%
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        
        for(int i_ = m-2; i_ >=0; --i_){
            for(int j_ = n-2; j_ >=0; --j_){
                dp[i_][j_] = dp[i_+1][j_] + dp[i_][j_+1];
            }
        }
        
        return dp[0][0];
    }
};