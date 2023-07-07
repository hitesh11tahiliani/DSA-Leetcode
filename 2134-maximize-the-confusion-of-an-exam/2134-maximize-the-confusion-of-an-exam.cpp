class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int left=0, ans=0, cnt=0;

        for(int i=0; i<n; i++){
            if(answerKey[i]=='F') cnt++;
            while (cnt>k){
                if(answerKey[left]=='F')
                    cnt--;
                left++;
            }
            ans = max(i-left+1, ans);
        }

        cnt=0, left=0;

        for(int i=0; i<n; i++){
            if(answerKey[i]=='T')
                cnt++;
            while(cnt>k){
                if(answerKey[left] == 'T')cnt--;
                left++;
            }
            ans = max(i-left+1, ans);
        }
        return ans;
    }
};


// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
//         while (r < n) {
//             sum += nums[r++];
//             while (sum >= s) {
//                 len = min(len, r - l);
//                 sum -= nums[l++];
//             }
//         }
//         return len == INT_MAX ? 0 : len;
//     }
// };