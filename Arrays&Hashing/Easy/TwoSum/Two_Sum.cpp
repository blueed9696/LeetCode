// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Get the number of elements of array 'nums'
        size_t NumberOfElements = nums.size();
        
        // Define the returning array
        vector<int> return_arr(2);

        for (size_t i = 0; i < NumberOfElements; i++) {
            for (size_t j = i + 1; j < NumberOfElements; j++) {
                if (nums[i] + nums[j] == target) {
                    return_arr[0] = i; // Return the indices
                    return_arr[1] = j;
                    return return_arr;
                }
            }
        }
        return vector<int>(); // Return an empty vector if no pair is found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);

    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
