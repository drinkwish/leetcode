//8ms, fast enough

class Solution {
public:
    int titleToNumber(string s) {
        int ret =0;
        for(int i_ = 0; i_ <s.size(); ++i_){
            ret = ret*26 + s[i_]-'A' + 1;
        }
        
        return ret;
    }
};