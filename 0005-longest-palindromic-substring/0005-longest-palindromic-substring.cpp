class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxlength = 1, start = 0, len = 0;
        for(int i = 0; i < s.length(); i++){
            int low = i-1;
            int high = i+1;
            
            while(high < s.length() && s[i] == s[high])
                high++;
            while(low >= 0 && s[i] == s[low])
                low--;
                
            while(low >= 0 && high < s.length() && s[low] == s[high]){
                low--;
                high++;
            }
            
             len = high-low-1;
            if(len > maxlength){
                maxlength = len;
                start = low+1;
            }
        }
        
        for(int i = start; i <= start+maxlength-1; i++)
            res+=s[i];
        
        return res;
    }
};