//72ms, can be optimized

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return true;
        
        map<char, char> m0;
        map<char, char> m1;
        for(int i_ = 0; i_< s.size(); ++i_){
            if(m0.find(s[i_]) == m0.end() && m1.find(t[i_]) == m1.end()){
                m0.insert(pair<char, char>(s[i_],t[i_]));
                m1.insert(pair<char, char>(t[i_],s[i_]));
            }
            else{
                if(m0[s[i_]] != t[i_] || m1[t[i_]] != s[i_]) return false;
            }
        }
        
        return true;
    }
};
