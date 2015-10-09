class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        
        int ret = 1;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end() -1; ++iter){
            if(*iter != *(iter + 1)) ret++;
        }
        
        if(ret == nums.size()) return ret;
        
        int cur = nums[nums.size() - 1];
        for(vector<int>::reverse_iterator iter = nums.rbegin(); iter != nums.rend() - ret; ++iter){
            if(cur != *(iter + 1)) {
                cur = *(iter + 1);
                int tmp = *iter;
                *iter = *(iter + 1);
                *(iter + 1) = tmp;
            }
        }
        
        return ret;
        
    }
};