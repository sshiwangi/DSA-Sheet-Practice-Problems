/* Problem Link: https://leetcode.com/problems/ugly-number-iii/description/
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.

Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
 

Constraints:

1 <= n, a, b, c <= 109
1 <= a * b * c <= 1018
It is guaranteed that the result will be in range [1, 2 * 109]. */

//code
class Solution {
public:
    bool isValid(long mid, long a, long b, long c, int n){
        //finding lcm
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
       long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);

        long count = (mid/a) + (mid/b) + (mid/c) - mid/ab - mid/bc - mid/ac + mid/abc;
        return (count>=n); //if number of ugly numbers at mid is greater than n, then return true otherwise false
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1;
        int high = 2e9;
        long A = long(a);
        long B = long(b);
        long C = long(C);
        while(low<high){
            long mid = low + (high - low)/2;
            if(isValid(mid,A,B,C,n)){ // if at mid, there is a possibility of finding nth ugly number, we will update high
                high = mid;
            }
            else low = mid+1;
        }
        return low;
    }
};
