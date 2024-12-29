#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// 242. Valid Anagram
// Solved
// Easy
// Topics
// Companies
// Given two strings s and t, return true if t is an 
// anagram
//  of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
//1
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        for(int i = 0; i < t.length(); i++) {
            if (m[t[i]] == 0)
                return false;
            m[t[i]]--;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for(char c : s ){
            m[c]++;
        }
        for(char c : t){
            if (m[c] <=0) return false;
            else m[c]--;
        }
        return true;
    }
};

// Same approach but different way of prsenting 