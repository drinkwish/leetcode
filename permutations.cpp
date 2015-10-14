//12ms, 100%
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        permute(ret, nums, 0, len-1);
        return ret;
    }
    
    void permute(vector<vector<int>> &ret, vector<int>& nums, int start, int end){
        if(start > end) return;
        if(start == end) {
            ret.push_back(nums);
            return;
        }
        
        permute(ret, nums, start+1, end);
        for(int i_ = start + 1; i_ <= end; ++i_){
            swap(nums[i_], nums[start]);
            permute(ret, nums, start+1, end);
            swap(nums[i_], nums[start]);
        }
    }
};