#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        // Map each components of nums to hash table
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]] = i;
        }

        // Find a compelment number from nums
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(hash.find(complement) != hash.end() && hash[complement] != i){
                return {i, hash[complement]};
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
