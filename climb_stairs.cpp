//0ms, fast enough

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        vector<int> steps(n+1);
        steps[0] = 1;
        steps[1] = 1;
        for(int i_ = 2; i_ <= n; ++i_){
            steps[i_] = steps[i_-1] + steps[i_-2];
        }
        
        return steps[n];
    }
};