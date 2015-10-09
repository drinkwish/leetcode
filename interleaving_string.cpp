//8ms, 25.50%
//dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        if(len1 + len2 != len3) return false;
        if(len1 == 0) return s2 == s3;
        if(len2 == 0) return s1 == s3;
        
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        for(int i_ = 1; i_ <= len1; ++i_){
            if(s3[i_-1] == s1[i_-1])
                dp[i_][0] = true;
            else break;
        }
        for(int i_ = 1; i_ <= len2; ++i_){
            if(s3[i_-1] == s2[i_-1])
                dp[0][i_] = true;
            else break;
        }
        
        for(int i_ = 1; i_ <= len1; ++i_){
            for(int j_ = 1; j_ <= len2; ++j_){
                if(s3[i_+j_-1] == s1[i_-1] && dp[i_-1][j_]) 
                    dp[i_][j_] = true;
                else if (s3[i_+j_-1] == s2[j_-1] && dp[i_][j_-1])
                    dp[i_][j_] = true;
                else
                    dp[i_][j_] = false;
            }
        }
        
        return dp[len1][len2];
    }
    
};

//time limit exceeded
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        return isInterleave(s1,s1.length()-1, s2, s2.length()-1, s3, s3.length()-1);
    }
    
    bool isInterleave(const string &s1, int e1, const string &s2, int e2, const string &s3, int e3){
        if(e1 < 0 || e2 < 0 || e3 < 0) return !(e1 >0 && e2 > 0 && e3 >0);
        
        if(s3[e3] == s1[e1] && isInterleave(s1, e1-1, s2, e2, s3, e3-1))
            return true;
        if(s3[e3] == s2[e2] && isInterleave(s1, e1, s2, e2-1, s3, e3-1))
            return true;
        return false;
    }
};