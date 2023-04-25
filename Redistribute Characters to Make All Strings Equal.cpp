/* Problem Link: 
solution link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/solutions/3454770/c-easy-solution/ 
You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.

Example 1:

Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.
Example 2:

Input: words = ["ab","a"]
Output: false
Explanation: It is impossible to make all the strings equal using the operation.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.*/
//code
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        vector<int>v(26, 0);
        
        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j<words[i].size(); j++){
                
                v[words[i][j]-'a']++;
            }
        }
        int n = words.size();
        for(int i = 0; i<v.size(); i++){
            if(v[i]%n!=0)return false; //if the number of each character in the words is divided by the size of words then we can distribute it equally
            
            else continue;
        }
        
        return true;
    }
};
