class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> nums1, nums2;
        vector<char> chars1, chars2;
        getOrderedCharNum(word1, chars1, nums1);
        getOrderedCharNum(word2, chars2, nums2);
        return nums1 == nums2 && chars1 == chars2;
    }

    void getOrderedCharNum(string word, vector<char>& chars, vector<int>& nums){
        unordered_map<char, int> char_map;
        for(auto p : word)
            char_map[p]++;
        for(auto p : char_map){
            nums.push_back(p.second);
            chars.push_back(p.first);
        }
        sort(chars.begin(), chars.end());
        sort(nums.begin(), nums.end());
    }
};