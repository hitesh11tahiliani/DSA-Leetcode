class Solution {
public:
    bool isValid(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>& ans, vector<string> output, int index){
        if(index == s.size()){
            ans.push_back(output);
            return;
        }
    
        for(int i=index; i<s.size(); i++ ){
            if(isValid(s, index, i)==true){
                output.push_back(s.substr(index, i-index+1));
                solve(s, ans, output, i+1);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s, ans, output, 0);
        return ans;
    }
};