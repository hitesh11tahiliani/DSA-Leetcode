class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) 
            return 0;
        
        int i = 0, j = 0, count = 1;
        char prevChar = chars[0];
        
        for (i = 1; i < n; i++) {
            if (chars[i] == prevChar) {
                count++;
            } else {
                chars[j++] = prevChar;
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char ch : countStr) {
                        chars[j++] = ch;
                    }
                }
                prevChar = chars[i];
                count = 1;
            }
        }
        
        chars[j++] = prevChar;
        if (count > 1) {
            string countStr = to_string(count);
            for (char ch : countStr) {
                chars[j++] = ch;
            }
        }
        
        return j;
    }
};