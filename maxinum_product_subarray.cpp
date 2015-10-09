//4ms, 75.52%

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];
        int maxhere = nums[0];
        int minhere = nums[0];
        int maxsofar = nums[0];
        
        int len = nums.size();
        for(int i_ = 1; i_ < len; ++i_){
            int tmp1 = max*nums[i_];
            int tmp2 = min*nums[i_];
            
            maxhere = std::max(nums[i_], std::max(tmp1, tmp2));
            minhere = std::min(nums[i_], std::min(tmp1, tmp2));
            maxsofar = std::max(maxhere, maxsofar);
            max = maxhere;
            min = minhere;
        }
        
        return maxsofar;
    }
};