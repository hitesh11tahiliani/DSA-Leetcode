class Solution {
public:
    bool isAnagram(string s, string t) {
//         if (s.size()!=t.size()){
//             return false;
//         }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s==t;
    }
    
   //  bool isAnagram(string s, string t) {
   //      int alp[26]={};
   //      for (int i = 0; i < s.length(); i++) 
   //          alp[s.at(i) - 'a']++;
   //      for (int i = 0; i < t.length(); i++)
   //          alp[t.at(i) - 'a']--;
   //      for (int i=0;i<26;i++)
   //          if (alp[i] != 0) 
   //              return false;
   //          return true;
   // }
};