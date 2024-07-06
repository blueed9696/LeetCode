// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Strategy
// 1. Map to hash table each iteration
// 2. If saved, remove those letters from the iteration
// 3. Reppeate until no letters left.

// 'Move' can improve memory usage.

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Use an unordered_map to store grouped anagrams
        unordered_map<string, vector<string>> anagram_groups;

        for(auto s : strs){
            string word = s;

            // Sort characters in ascending order
            sort(word.begin(), word.end());

            anagram_groups[word].push_back(move(s));
        }

        vector<vector<string>> result;
        for(auto a : anagram_groups){
            result.push_back(move(a.second));
        }
        return result;

    }
};

int main() {
    Solution solution;
    vector<string> test_data = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> grouped_anagrams = solution.groupAnagrams(test_data);

    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : grouped_anagrams) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}