// Duplicate Integer
// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

// Example 1:

// Input: nums = [1, 2, 3, 3]

// Output: true
// Example 2:

// Input: nums = [1, 2, 3, 4]

// Output: false
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // An array that stores read values
        unordered_set<int> num_set;

        for(int num : nums){
            // Check if num is already in the set
            if(num_set.find(num) != num_set.end()){
                return true;    // Duplicate has found
            }
            num_set.insert(num);
        }
        
        return false; // No duplicate found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 2};
    bool result = sol.hasDuplicate(nums);

    if (result) {
        cout << "Duplicate found." << endl;
    } else {
        cout << "No duplicates." << endl;
    }

    return 0;
}