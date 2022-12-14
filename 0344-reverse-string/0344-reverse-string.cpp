// APPROCH 1 
//     Start a loop from end and store char in new vector.
    
// APPROCH 2   
//     Make start and end pointer swap them until they pass each other.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j){
            swap(s[i++], s[j--]);
        }
    }
};