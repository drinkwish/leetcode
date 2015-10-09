class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ret = 0;
        int s1 = 0, s2 =0, e1 = 0, e2 =0;
        while(ret == 0 && e1 < version1.size() && e2 < version2.size()){
            while(version1[e1] != '.') {
                if(++e1 == version1.size()) break;
            }
            while(version2[e2] != '.') {
                if(++e2 == version2.size()) break;
            }
            if(version1[e1] == '.' && version2[e2] == '.'){
                ret = compareStringNum(version1, s1, e1, version2, s2, e2);
                s1 = e1 + 1;
                e1 = s1;
                s2 = e2 + 1;
                e2 = s2;
            }
        }
        
        if(ret == 0) ret = compareStringNum(version1, s1, e1, version2, s2, e2);
        
        return ret;
        
    }
    
private:
    int compareStringNum(string n1, int s1, int e1, string n2, int s2, int e2){
		while(n1[s1] == '0' && s1<=e1){++s1;}
		while(n2[s2] == '0' && s2<=e2){++s2;}
		
        if(e1 -s1 > e2 - s2) return 1;
        if(e1 -s1 < e2 - s2) return -1;
        
        while(s1 != e1){
            if(n1[s1] > n2[s2]) return 1;
            if(n1[s1] < n2[s2]) return -1;
            ++s1;
            ++s2;
        }
        
        return 0;
    }
};