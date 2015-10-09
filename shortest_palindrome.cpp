//8ms, 31.37%
//not orginal
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len <= 1) return s;
     
        string r = s;
        reverse(r.begin(), r.end());
        string t = s+'#'+r;
        vector<int> p(t.size(),0);
        
        for(int i_ = 1; i_ < t.size(); ++i_){
            int j_ = p[i_-1];
            while(j_ > 0 && t[j_]!= t[i_]) j_ = p[j_-1];
            p[i_] = j_ + (t[i_] == t[j_]);
        }
        
        return r.substr(0, s.size()-p[t.size()-1]) + s;
    }
};