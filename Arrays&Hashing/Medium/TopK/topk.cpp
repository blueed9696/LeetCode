// Given an integer array nums and an integer k, return the k most frequent elements. 
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool compare_num_to_sort(pair<int, int> num1, pair<int, int> num2){
    return num1.second > num2.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        vector<int> v;

        int nums_size = nums.size();

        // 1. Increment value for each key 
        for(auto num : nums){
            hash_map[num]++;
        }

        vector<pair<int,int>> p(hash_map.begin(), hash_map.end());

        // 2. Compare and sort
        sort(p.begin(), p.end(), compare_num_to_sort);
        
        // 3. v.push_back(hash_map) for k times
        for(int i = 0; i < k; i++){
            v.push_back(p[i].first);
        }

        // 4. return v
        return v;
    }
};

int main() {
    Solution solution;
    vector<int> test_data = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> top_k = solution.topKFrequent(test_data, k);

    cout << "Top " << k << " Frequent Elements:" << endl;
    for (int num : top_k) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}