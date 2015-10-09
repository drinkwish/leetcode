//8ms, 100%

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        
        int min = prices[0];
        int ret =0;
        for(int i_ = 0; i_ < prices.size(); ++i_){
            if(prices[i_] < min) min = prices[i_];
            int tmp = prices[i_] - min;
            if(tmp > ret) ret = tmp;
            
        }
        
        return ret;
    }
};