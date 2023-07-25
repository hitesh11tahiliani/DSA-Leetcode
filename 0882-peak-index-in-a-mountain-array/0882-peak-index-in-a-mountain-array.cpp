class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int maxElement = 0;
        int maxElementIndex = 0;

        for(int i=0; i<n; i++){
            maxElement = max(maxElement, arr[i]);
            if(maxElement == arr[i]){
                maxElementIndex = i;
            }
        }

        return maxElementIndex;
    }
};