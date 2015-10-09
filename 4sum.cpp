//hash solution
//TLE
	class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end(), less<int>());
			unordered_map<int, int> hash;
			int len = nums.size();
			for (int i_ = 0; i_ < len; ++i_){
				if (hash.find(nums[i_]) == hash.end()) hash.insert(pair<int, int>(nums[i_], 1));
				else ++hash[nums[i_]];
			}

			vector<vector<int>> ret;
			vector<int> tmp;
			kSum(4, nums, -1, target, ret, len, tmp, hash);

			return ret;
		}

		void kSum(int k, vector<int> &nums, int start, int target, vector<vector<int>> &ret, int len, vector<int> &tmp, unordered_map<int, int> & hash){
			int left = start + 1;
			if (left >= len) return;
			if (target < k*nums[left]) return;

			if (k == 2){
				while (left < len){
					target -= nums[left];
					if (target < nums[left]) {
						target += nums[left];
						return;
					}
					--hash[nums[left]];
					if (hash.find(target) != hash.end() && hash[target]){
						tmp.push_back(nums[left]);
						tmp.push_back(target);
						ret.push_back(tmp);
						tmp.pop_back();
						tmp.pop_back();
					}
					target += nums[left];
					left += ++hash[nums[left]];
				}
				return;
			}

			while (left < len){
				--hash[nums[left]];
				tmp.push_back(nums[left]);
				kSum(k - 1, nums, left, target - nums[left], ret, len, tmp, hash);
				tmp.pop_back();
				left += ++hash[nums[left]];
			}
		}
	};

//simple solution
//80ms, 77.8%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        int len = nums.size();
        
        vector<vector<int>> ret;
        vector<int> tmp;
        kSum(4,nums, -1, target, ret, len,tmp);
        
        return ret;
    }
    
    void kSum(int k, vector<int> &nums, int start, int target, vector<vector<int>> &ret, int len, vector<int> &tmp){
        int left = start + 1;
        
        if(k == 2){
            int right = len -1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ret.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                    while(left < len && nums[left] == nums[left+1]) ++left;
                    while(right > start && nums[right] == nums[right-1]) --right;
                    ++left;
                    --right;
                }
                else if(sum > target) --right;
                else ++left;
            }
            return;
        }
        
        for(; left < len; ++left){
            tmp.push_back(nums[left]);
            kSum(k-1, nums, left, target-nums[left], ret, len, tmp);
            tmp.pop_back();
            while(left < len-1 && nums[left] == nums[left+1]) ++left;
        }
            
    }
};