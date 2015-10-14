//pass
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};

//LTE
class Solution {
public:
    bool canWinNim(int n) {
        if(n <= 3) return true;
        
        deque<bool> dp(3, true);
        int cnt = 3;
        while(cnt++ < n){
            canWinNim(dp, cnt);
        }
        return dp.back();
    }
    
    void canWinNim(deque<bool> &dp, int n){
        bool tmp = true;
        for(deque<bool>::iterator iter = dp.begin(); iter != dp.end(); ++iter){
            tmp = tmp || !(*iter);
        }
        dp.pop_front();
        dp.push_back(tmp);
    }
};