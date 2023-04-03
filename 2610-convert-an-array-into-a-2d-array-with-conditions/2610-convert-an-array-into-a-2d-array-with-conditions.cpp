class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Step 1: create unordered map to store element frequencies
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Step 2: sort elements in descending order by frequency
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        return freq[a] > freq[b];
    });
    
    // Step 3: initialize empty matrix
    vector<vector<int>> matrix;
    
    // Step 4: iterate over sorted elements
    for (int num : nums) {
        // Step 5: try to add element to existing row
        bool added = false;
        for (vector<int>& row : matrix) {
            if (find(row.begin(), row.end(), num) == row.end()) {
                row.push_back(num);
                added = true;
                break;
            }
        }
        // Step 6: if element was added to a row, continue to next element
        if (added) {
            continue;
        }
        // Step 7: if element was not added to any row, create new row
        matrix.push_back({num});
    }
    
    return matrix;
    }
};