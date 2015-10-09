//4ms, 96.8%

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.length() == 0) return false;
        
        vector<bool> flag(s.length()+1, false);
        flag[0] = true;
        
        for(int i_= 1; i_<= s.length(); ++i_){
            for(int j_ = i_-1; j_>=0; --j_){
                if(flag[j_] && wordDict.find(s.substr(j_, i_-j_)) != wordDict.end()){
                    flag[i_] = true;
                    break;
                }
            }
        }
        
        return flag[s.length()];
    }
};