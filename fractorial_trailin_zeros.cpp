//4ms, fast enough
class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 0) return 0;
        int ret = 0;
        int cnt = 1;
        while(n >=5){
            ret += (n/5);
            n /=5;
        }
        
        return ret;
    }
};