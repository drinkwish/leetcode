//24ms, O(1) space, fast enough
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k == 0 || nums.size() == 0) return;

        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
    
private:
    void reverse(vector<int> & nums, int start, int end){
        while(start < end){
            std::swap(nums[start++], nums[end--]);
        }
    }
};

//24ms, O(n) space, fast enough
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums_tmp;
        int left = nums.size()-k%nums.size();
        for(int i_=0; i_ < nums.size(); ++i_){
            nums_tmp.push_back(nums[(i_ +left)%nums.size()]);
        }
        
        for(int i_ =0; i_< nums.size(); ++i_){
            nums[i_] = nums_tmp[i_];
        }
    }
};

//limit time exceeded
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int right = k%nums.size();
        
        if(right < (nums.size() >> 1)){
            while(right--){
                rotateOneRight(nums);
            }
        } else {
            while(right++ < nums.size()){
                rotateOneLeft(nums);
            }
        }
    }
    
private:
    void rotateOneRight(vector<int>& nums){
        int tmp = nums[nums.size()-1];
        for(int i_ = nums.size()-1; i_>0; --i_){
            nums[i_] = nums[i_-1];
        }
        
        nums[0] = tmp;
    }
    
    void rotateOneLeft(vector<int>& nums){
        int tmp = nums[0];
        for(int i_ = 0; i_ < nums.size()-1; ++i_){
            nums[i_] = nums[i_+1];
        }
        
        nums[nums.size()-1] = tmp;
    }
};

