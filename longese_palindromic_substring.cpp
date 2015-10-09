


//clamping
//O(n^2) time 
//O(1) space
//56ms, 64.5%
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        int start = 0;
        int maxLen = 1;
        
        for(int i_ = 0; i_ < len; ++i_){
            //even
            int low = i_, high = i_ + 1;
            while(low >= 0 && high < len && s[low] == s[high]){
                --low;
                ++high;
            }
            int lenTmp = high - low -1;
            if(lenTmp > maxLen){
                maxLen = lenTmp;
                start = low + 1;
            }
            
            //odd
            low = i_-1;
            high = i_ + 1;
            while(low >= 0 && high < len && s[low] == s[high]){
                --low;
                ++high;
            }
            lenTmp = high - low -1;
            if(lenTmp > maxLen){
                maxLen = lenTmp;
                start = low + 1;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

//improved clamping
//O(n^2) time
//O(1) space
//In the improved algorithm, the first servel same characters are ignored,
//as a result, there is no need to consider the odd/even case.
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        int start = 0;
        int maxLen = 1;
        
        for(int i_ = 0; i_ < len; ++i_){
            int low = i_, high = i_+1;
            //ingore the same charaters from the middle
            while(s[high] == s[low]) ++high;
            --low;
            
            while(low >= 0 && high < len && s[low] == s[high]){
                --low;
                ++high;
            }
            int lenTmp = high - low -1;
            if(lenTmp > maxLen){
                maxLen = lenTmp;
                start = low + 1;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

//dynamic programming
//O(n^2) time
//O(n^2) space
//time limit exceeded
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for(int i_ = 0; i_ <len; ++i_){
            dp[i_][i_] = true;
        }
        
        int start = 0;
        int maxLen = 1;
        
        for(int width = 2; width <= len; ++width){
            for(int i_ = 0; i_ < len - width +1; ++i_){
                int j_ = i_+width-1;
                if(s[i_] == s[j_]){
                    if(width == 2) dp[i_][j_] = true;
                    else if(dp[i_+1][j_-1]) dp[i_][j_] = true;
                    if(dp[i_][j_] && width > maxLen){
                        maxLen = width;
                        start = i_;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};