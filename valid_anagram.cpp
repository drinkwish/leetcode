class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length()) return false;
        
        std::map<char, int> chMap;
        for(int i_=0; i_<s.length(); ++i_){
            if(chMap.find(s[i_]) != chMap.end()){
                chMap[s[i_]] += 1;
            }
            else{
                chMap.insert(std::pair<char, int>(s[i_], 1));
            }
        }
        
        for(int i_ = 0; i_<t.length(); ++i_){
            if(chMap.find(t[i_]) != chMap.end()){
                chMap[t[i_]] -=1;
                if(chMap[t[i_]] < 0){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
