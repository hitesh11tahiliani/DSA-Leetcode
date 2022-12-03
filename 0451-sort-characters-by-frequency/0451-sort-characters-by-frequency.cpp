class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }
        vector<pair<int,char>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        
        string ans;
        
        for(auto it:v){
            while(it.first!=0){
                ans.push_back(it.second);
                it.first--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};