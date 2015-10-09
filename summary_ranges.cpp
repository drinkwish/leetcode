class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> ret;
        
        if(0 == nums.size()){
            return ret;
        }
        
        int begin;
        int cur;
        int end;
        
        std::vector<int>::iterator iter = nums.begin();
        begin = *iter;
        cur = begin;
        for(iter = iter+1; iter != nums.end();++iter){
            if(*iter - cur != 1){//corner case, don't use >1 since overflow
                end = cur;
                if(begin == end){
                    ret.push_back(std::to_string(begin));
                }
                else{
                    ret.push_back(std::to_string(begin)+"->"+std::to_string(end));
                }
                begin = *iter;
            }
            cur = *iter;
        }
        
        end = cur;
        if(begin == end){
            ret.push_back(std::to_string(begin));
        }
        else{
            ret.push_back(std::to_string(begin)+"->"+std::to_string(end));
        }
        
        return ret;
        
    }
};
