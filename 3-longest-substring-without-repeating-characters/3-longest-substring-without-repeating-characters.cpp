class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;
        
        int max =0;
        
        int start=0, end=0;
        
        while (start < s.size()){
            auto it = Set.find(s[start]);     //checking if the char has occured for the first time or not, if not it should already be presnt in set 
            
            if (it==Set.end()){               //reaching the end of the set means char is not present in the set 
                if (start-end+1>max){
                    max=start-end+1;
                }
                Set.insert(s[start]);
                start++;
            }
            else {
                Set.erase(s[end]);
                end++;
            }
        }
        return max;
    }
};