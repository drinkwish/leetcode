//28ms, 99.92%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m){
            int n = grid[0].size();
            vector<int> dp;
            dp.push_back(grid[0][0]);
            for(int i_ = 1; i_ < n; ++i_){
                dp.push_back(dp.back()+grid[0][i_]);
            }
            
            for(int i_ = 1; i_ < m; ++i_){
                dp[0] += grid[i_][0];
                for(int j_ = 1; j_ < n; ++j_){
                    dp[j_] = grid[i_][j_] + std::min(dp[j_-1], dp[j_]);
                }
            }
            return dp[n-1];
        }
        return 0;
    }
};