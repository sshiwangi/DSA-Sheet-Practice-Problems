/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1  */
//code
class Solution {
public:
    int solve(int n){
        //if the number is a single digit number then return the number
        if(n>=1 && n<=9){
           return n;
        }
        //otherwise perform the following operation
        int sum = 0;
        while(n>0){
            int rem = n%10;
            sum += rem*rem;
            n = n/10;
        }
        int ans = solve(sum);
        return ans;
        
    }
    bool isHappy(int n) {
        int res = solve(n);
        if(res == 1 || res ==7)return true; //only 1 and 7 are happy numbers from digits 1 to 9
        return false;
    }
};
