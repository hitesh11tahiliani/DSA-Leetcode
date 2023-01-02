class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCaseLetters = 0, firstLetter = 0, n = word.size();
        if (isupper(word[0])) firstLetter = 1;
        for (int i = 1; i < n; i++) 
            if (isupper(word[i])) 
                upperCaseLetters++;
        return ((firstLetter and upperCaseLetters == n-1) or (upperCaseLetters == 0));
    }
};