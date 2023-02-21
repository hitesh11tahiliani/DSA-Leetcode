class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto num : nums){
            map[num]++;
        }
        for(auto num : map){
            if(num.second == 1) return num.first;
        }
        return -1;
    }
};