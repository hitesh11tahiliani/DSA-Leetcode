class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        long long nums[10000];
        int idx = 0;
        for (string &s : tokens) {
            if(s.length() == 1 && s[0] == '+') {
                nums[idx-2] += nums[idx - 1];
                --idx;
            }
            else if(s.length() == 1 && s[0] == '-') {
                nums[idx-2] -= nums[idx - 1];
                --idx;
            }
            else if(s.length() == 1 && s[0] == '*') {
                nums[idx-2] *= nums[idx - 1];
                --idx;
            }
            else if(s.length() == 1 && s[0] == '/') {
                nums[idx-2] /= nums[idx - 1];
                --idx;
            }
            else {
                int buho = 1;
                int loc = 0;
                int num = 0;
                if(s[0] == '-') {
                    buho = -1;
                    loc = 1;
                }
                
                for (; loc < s.length(); ++loc) {
                    num *= 10;
                    num += s[loc] - '0';
                }

                nums[idx++] = buho*num;
            }
        }

        return nums[0];
    }
};