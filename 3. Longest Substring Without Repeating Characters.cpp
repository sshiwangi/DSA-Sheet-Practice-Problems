/* Given a string s, find the length of the longest 
substring
 without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces. */

//code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0;
        set<int>st; //to store only unique substrings
        while(j<s.size()){
            if(st.find(s[j])==st.end()){ //if set doesnot contains the char
                st.insert(s[j]);  //we will add that in the set
                if(st.size()>ans)ans = st.size(); //and update the ans
                j++;
            }
            else{
                st.erase(s[i]); // otherwise erase the char at ith index
                i++;
                
            }
        }
        return ans;
    }
};
