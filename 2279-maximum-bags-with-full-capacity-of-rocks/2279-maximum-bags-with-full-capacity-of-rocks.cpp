class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
         vector<int> vv ; 
         for(int i = 0 ; i < capacity.size(); i ++ ) {
              vv.push_back(capacity[i] - rocks[i]); 
         }
         sort(vv.begin(), vv.end()); 
         int  cnt = 0 ; 
         for(auto a : vv ) {
              if(a == 0) {
                   cnt ++ ; 
              }else if(additionalRocks - a >= 0){
                  cnt ++; 
                  additionalRocks -= a ; 
              }
         }
        return cnt ; 
}
};