class Solution {
public:
    int countBinarySubstrings(string& s) {
      // we start from first character - so curConsecutive = 1
      int curConsecutive = 1, prevConsecutive = 0, ans = 0;
      for(int i = 1; i < size(s); i++) {
        if(s[i] != s[i - 1]) // whenever current & previous don't match
            ans += min(prevConsecutive, curConsecutive), // number of substring formed is minimum of cur & prev count
            prevConsecutive = curConsecutive,            // previous consecutive streak will become current consecutive and,
            curConsecutive = 1;                          // current streak will be resetted
        else 
            curConsecutive++; 
      }
      // required to include count from last two groups of consecutive characters.
      ans += min(prevConsecutive, curConsecutive); 
      return ans;
    }
};