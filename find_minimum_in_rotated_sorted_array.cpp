//4ms, 100%
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len){
            int start = 0;
            int end = len-1;
            int mid = (start + end) >> 1;
            while(start != end){
                if(nums[start] < nums[end]) return nums[start];//not rotated
                
                if(nums[mid] > nums[end]) start = mid + 1;
                else end = mid;
                mid = (start+end) >> 1;
            }
            return nums[mid];
        }
    }
};