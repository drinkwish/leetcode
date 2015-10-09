//not enough test case
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;
        
        vector<int> cur(1,1);
        int i_ = 0, j_ = 0, k_ = 0;
        while(cur.size() < n){
            int a = cur[i_] *2;
            int b = cur[j_] *3;
            int c = cur[k_] *5;
            
            int m = min(a, min(b,c));
            
            if(m == a) ++i_;
            if(m == b) ++j_;
            if(m == c) ++k_;
            
            cur.push_back(m);
        }
        
        return cur[n-1];
    }
};