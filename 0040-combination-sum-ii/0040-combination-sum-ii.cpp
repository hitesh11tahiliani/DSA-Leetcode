class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& output, int index) {
        // No need to sort output at every call, as it is already sorted in the previous calls
        if (target == 0) {
            ans.push_back(output);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates to avoid redundant combinations
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break; // No need to explore further since candidates are sorted
            }

            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, output, i + 1); // Use i + 1 for the next index to avoid using the same element again
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates properly
        solve(candidates, target, ans, output, 0);
        return ans;
    }
};
