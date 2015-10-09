//simple solution 
//56ms, 83.19%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int len = nums.size();
        
        vector<vector<int>> ret;
        for(int i_ = 0; i_ < len; ++i_){
            twoSum(nums, i_, -nums[i_], ret);
            while(i_ < len && nums[i_] == nums[i_+1]) ++i_;
        }
        
        return ret;
        
    }
    
    void twoSum(vector<int> &nums, int start, int target, vector<vector<int>> &ret){
        int len = nums.size();
        int right = len - 1;
        int left = start + 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target) {
                vector<int> tmp(3);
                tmp[0] = nums[start];
                tmp[1] = nums[left];
                tmp[2] = nums[right];
                ret.push_back(tmp);
                while(left < len && nums[left] == nums[left+1]) ++left;
                while(right > start && nums[right] == nums[right-1]) --right;
                ++left;
                --right;
            }
            else if(sum > target) --right;
            else ++left;
        }
    }
};


//hash solution
//72ms, 20.41%
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(), nums.end(), less<int>());
			unordered_map<int, int> hash;
			int len = nums.size();
			for (int i_ = 0; i_ < len; ++i_){
				if (hash.find(nums[i_]) == hash.end()) hash.insert(pair<int, int>(nums[i_], 1));
				else ++hash[nums[i_]];
			}

			vector<vector<int>> ret;
			for (int i_ = 0; i_ < len; ++i_){
				--hash[nums[i_]];
				for (int j_ = i_ + 1; j_ < len; ++j_){
					int target = -nums[i_] - nums[j_];
					if (target < nums[j_]) break;
					--hash[nums[j_]];
					if (hash.find(target) != hash.end() && hash[target]){
						vector<int> tmp(3);
						tmp[0] = nums[i_];
						tmp[1] = nums[j_];
						tmp[2] = target;
						ret.push_back(tmp);
					}
					++hash[nums[j_]];
					while (j_ != len - 1 && nums[j_] == nums[j_ + 1]) ++j_;
				}
				++hash[nums[i_]];
				while (i_ != len - 1 && nums[i_] == nums[i_ + 1]) ++i_;
			}

			return ret;

		}
	};