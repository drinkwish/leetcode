class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <=0) return false;
        
        int cnt = 0;
        int mask = 0x1;
        
        while(n){
            cnt += (mask&n);
            if(cnt >1) return false;
            n = n >> 1;
        }
        
        if(cnt ==1) return true;
        else return false;
    }
};
