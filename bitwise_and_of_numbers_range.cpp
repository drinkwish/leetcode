//64ms, 99.76%

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(m != n && m != 0 && n != 0){
            m = m >> 1;
            n = n >> 1;
            ++cnt;
        }
        
        return m << cnt;
    }
};