// Time Complexity O(n^2)

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
#include <vector>
#include <iostream>

using namespace std;

// Function Definition

// Input : vector nums
// Output : multiplied elements (int)
int getMultipliedElements(vector<int> nums, int iteration){
    int numsSize = nums.size();
    int multResult = 1;
    nums.erase(nums.begin() + iteration);

    for(int i = 0; i < numsSize; i++){
        multResult *= nums[i];
    }

    return multResult;
}

// Input : vector nums
// Output : a multiplication vector 
vector<int> getMultipliedNumsArray(vector<int> nums){
    int multElements = 0;

    vector<int> multiplicationResult;
    
    for(int iteration = 0; iteration < nums.size(); iteration++){
        multElements = getMultipliedElements(nums, iteration);
        multiplicationResult.push_back(multElements);
    }

    return multiplicationResult;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int numsSize = nums.size();
        vector<int> resultArray;

        resultArray = getMultipliedNumsArray(nums);

        return resultArray;
    }
};

int main() {
    Solution solution;
    vector<int> test_data = {1, 2, 3, 4};
    
    vector<int> result = solution.productExceptSelf(test_data);

    cout << "Product of array except self: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}