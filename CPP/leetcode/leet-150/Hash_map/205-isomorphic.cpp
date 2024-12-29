#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// 205. Isomorphic Strings
// Solved
// Easy
// Topics
// Companies
// Amazon
// LinkedIn
// Google
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "foo", t = "bar"

// Output: false

// Explanation:

// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

 

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> sm; 
        unordered_map<char, int> tm; 
        for(int i =0 ; i< s.size(); i++){
            if(sm.find(s[i]) == sm.end()){
                sm[s[i]] = i;
            }
            if(tm.find(t[i]) == tm.end()){
                tm[t[i]] = i;
            }
        
            if(sm[s[i]] != tm[t[i]]){
                return false;
            }
        }
        return true;
    }
};
