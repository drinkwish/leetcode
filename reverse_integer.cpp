//check other solution though this is the best
class Solution {
public:
    int reverse(int x) {
        if(x == -2147483648) return 0;
        
        int sign = x >0;
        x= abs(x);
        
        queue<int> q;
        while(x){
            int tmp = x%10;
            q.push(tmp);
            x = x/10;
        }
        
        int ret = 0;
        int tenthMax = 0x7FFFFFFF/10;
        while(!q.empty()){
            if(ret > tenthMax) return 0;
            ret = ret*10 + q.front();
            q.pop();
        }
        
        return sign>0 ? ret : -ret;
    }
};
