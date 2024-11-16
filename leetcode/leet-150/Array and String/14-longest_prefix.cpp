// 14. Longest Common Prefix
// Solved
// Easy
// Topics
// Companies
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  
        // can find smallest string to compare for less comparisions inside the while loop 
        // string prefix = *min_element(strs.begin(), strs.end(), [](const string &a, const string &b) {
        //     return a.size() < b.size();
        // });
        string prefix = strs[0]; 
        
        for (const auto& str : strs) {
            while (str.find(prefix) != 0) {  
                prefix.pop_back();  
                if (prefix.empty()) return "";  
            }
        }
        
        return prefix;
    }
};
