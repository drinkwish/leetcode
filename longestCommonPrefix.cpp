//8ms, can be optimized

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if(strs.size() == 0) return ret;
        if(strs.size() == 1) return strs[0];
        
        ret = strs[0];
        for(vector<string>::iterator iter = strs.begin() + 1; iter != strs.end() && ret.length() != 0; ++iter){
            ret = CommanPrefix(ret, *iter);
        }
        
        return ret;
    }
    
private:
    string CommanPrefix(const string& s1, const string& s2){
        string ret;
        for(int i_ = 0; i_ <s1.size() && i_ < s2.size(); ++i_){
            if(s1[i_] != s2[i_]) return ret;
            ret.append(1, s1[i_]);
        }
        
        return ret;
    }
};