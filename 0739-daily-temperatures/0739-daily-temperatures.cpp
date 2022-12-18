class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
			
			// Popping all indices with a lower or equal temperature than the current index
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
				
			// If the stack still has elements, then the next warmer temperature exists!
            if(!st.empty())
                ans[i] = st.top() - i;
				
			// Inserting current index in the stack: monotonicity is maintained!
            st.push(i);
        }
        
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> ans(n, 0);
        
//         for(int i = n - 1; i >= 0; i--) {
//             int j = i + 1;
//             while(j < n && arr[j] <= arr[i]) {
//                 j++;
//             }
//             if(j != n) {
//                 ans[i] = j - i;
//             }
//         }
        
//         return ans;
//     }
// };