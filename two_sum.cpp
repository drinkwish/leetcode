//12ms, 98.27%

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> nums1 = nums;
		std::sort(nums1.begin(), nums1.end(), less<int>());

		vector<int> tmp = twoSumSorted(nums1, target);
		vector<int> ret(2, -1);
		bool flag = false;
		for (int i_ = 0; i_ < nums.size(); ++i_){
			if (nums[i_] == tmp[0] && !flag) { ret[0] = i_ + 1; flag = true; }
			else if (nums[i_] == tmp[1]) { ret[1] = i_ + 1; }
		}
		
		if(ret[0] > ret[1]) swap(ret[0], ret[1]);
		return ret;
	}

private:
	vector<int> twoSumSorted(vector<int> nums, int target){
		int i_ = 0, j_ = nums.size() - 1;
		vector<int> ret;
		while (i_ < j_){
			if (nums[i_] + nums[j_] == target) {
				ret.push_back(nums[i_]);
				ret.push_back(nums[j_]);
				return ret;
			}
			if (nums[i_] + nums[j_] > target) --j_;
			else ++i_;
		}
	}
};