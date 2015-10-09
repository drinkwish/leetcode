//there existed better solution

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
            if(m.find(*iter) == m.end()){
                m.insert(pair<int, int>(*iter, 0));
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};
