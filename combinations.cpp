//12ms, 32.59%

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> cur;
        combine(ret, cur, 1, n, k);
        return ret;
    }
    
    void combine(vector<vector<int>> &ret, vector<int> cur, int start, int end, int k){
        if(k == 0){
            ret.push_back(cur);
            return;
        }
        
        if(end - start + 1 < k) return;
        if(end - start + 1 == k){
            for(int i_ = start; i_ <= end; ++i_){
                cur.push_back(i_); 
            }
            ret.push_back(cur);
            return;
        }
        
        combine(ret, cur, start+1, end, k);
        cur.push_back(start);
        combine(ret, cur, start+1, end, k-1);
    }
};