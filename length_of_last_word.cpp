class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        const char*  chStr= s.data();
        int ret = 0;
        bool flag = false;
        int i_ = length-1;
        
        while(chStr[i_] == ' ') {--i_;}
        for(; i_>-1; --i_){
            if(*(chStr+i_) == ' '){
                break;
            }
            ++ret;
        }
        
        return ret;
    }
};