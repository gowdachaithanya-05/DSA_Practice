// 383. Ransom Note
// Solved
// Easy
// Topics
// Companies
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 


 class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // first approach using hash map
        //      unordered_map<char, int> m;
        //      for(char c : magazine){
        //         m[c]++;
        //      }
        //      for(char c : ransomNote){
        //         if (m[c] <=0) return false;
        //          else m[c]--;
        //      }
        // return true;  

        //Second approach better in runtime   
        int cnt[128] = {0};
        for(char c : magazine){
            cnt[c]++;
        }
        for(char c : ransomNote){
            if(cnt[c]< 1){
                return false;
            }
            else{
                cnt[c]--;
            }
        }
        return true;
    }
};