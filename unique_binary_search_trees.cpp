//0ms, 100%
class Solution {
public:
    int numTrees(int n) {
        vector<int> seq;
        int cnt = 0;
        while(cnt <= n){
            numTrees(seq, cnt);
            ++cnt;
        }
        return seq.back();
    }
    
    void numTrees(vector<int> &seq, int n){
        if(n == 0) {
            seq.push_back(1) ;
            return;
        }
        if(n == 1) {
            seq.push_back(1);
            return;
        }
        
        int ret = 0;
        for(int i_ = 0; i_ <= n - 1; ++i_){
            ret += seq[i_] * seq[n-i_-1];
        }
        seq.push_back(ret);
    }
};