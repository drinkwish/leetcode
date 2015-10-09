class Solution {
public:
    bool isPalindrome(string s) {
        
        int i_=0, j_ =s.length()-1;
        while(i_ < j_){
            if(s[i_] != s[j_]) return false;
            ++i_;
            ++j_;
        }
        
        return true;
    }
};