//there exist better solution

class Solution {
public:
////thie method exceed time limits
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        if(nums.size() < 2 || k <=0) return false;
//        
//        for(int i_ = 0; i_< nums.size()-1; ++i_){
//            for(int j_ = i_+1; j_-i_ <=k && j_ < nums.size(); ++j_){
//                if(nums[j_] == nums[i_]) return true;
//            }
//        }
//        
//        return false;
//    }
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int cnt = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
            if(m.find(*iter) == m.end()){
                m.insert(pair<int, int>(*iter, cnt));
            }
            else if(cnt - m[*iter] <= k) {
                return true;
            } else{
                m[*iter] = cnt;
            }
            ++cnt;
        }
        
        return false;
    }
};
