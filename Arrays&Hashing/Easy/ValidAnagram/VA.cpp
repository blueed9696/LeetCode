// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Strategy:
// Use a hash map that shows letter and its number
// If the hash map matches, return true.
// Else False

// Improvement:
// Use one Hash Table for memory efficiency
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash_word_s;
        unordered_map<char, int> hash_word_t;
        
         // If lengths of strings are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        for(int i = 0; i < s.length(); i++){
            // If exist increment the value of the key
            hash_word_s[s.at(i)]++;
            hash_word_t[t.at(i)]++;
        }
    
        
        return hash_word_s == hash_word_t;

    }
};

int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    if(sol.isAnagram(s, t)){
        cout << "is anagram" << endl;
    }else{
        cout << "is not anagram" << endl;
    }
}