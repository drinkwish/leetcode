//

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n <= 0) return 0;
        
        int start = 1, end = n;
        int mid = (start >> 1) + (end >> 1);
        
        while(start != end){
            if(isBadVersion(mid)) 
                end = mid;
            else
                start = mid + 1;
            mid = (start >> 1) + (end >> 1);
        }
        
        return start;
    }
};