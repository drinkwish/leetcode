//8ms, 100%

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        
        int start = 0;
        int end = 0;
        int ret = 0;
        while(end < prices.size()-1){
            if(prices[end] > prices[end+1]){
                ret += prices[end] - prices[start];
                start = end + 1;
            }
            ++end;
        }
        
        if(start != end) ret += prices[end] - prices[start];
        
        return ret;
    }
};