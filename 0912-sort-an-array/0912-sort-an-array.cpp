class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end()); return nums;
    }
};

// void bubbleSort(vector<int>& nums){
//         for(int i = nums.size() - 1; i >= 0; i--)
//             for(int j = 0; j < i; j++)
//                 if(nums[j] > nums[j + 1]) 
//                     swap(nums[j], nums[j + 1]);
//     }