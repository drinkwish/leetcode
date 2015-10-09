//8ms, 100%
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0, end = len;
        int mid = (start + end) >> 1;
        
        while(nums[mid] != target && end - start > 1){
            if(target < nums[mid]) end = mid;
            else start = mid;
            mid = (start+end) >> 1;
        }
        
        if(target <= nums[mid]) return mid;
        else return mid+1;
    }
};