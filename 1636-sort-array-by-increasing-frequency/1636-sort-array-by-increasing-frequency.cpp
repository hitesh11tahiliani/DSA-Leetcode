class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int> output;
        unordered_map<int , int > freq;

        for(int a: nums){
            freq[a]++;
        }

        map<int, vector<int>>temp;

        for(int a: nums){
            temp[freq.find(a)->second].push_back(a);
        }

        for(auto it: temp)
        {
            sort(it.second.rbegin(), it.second.rend());
            for(int a : it.second)
            {
                output.push_back(a);
            }
        }


        return output;
    }
};