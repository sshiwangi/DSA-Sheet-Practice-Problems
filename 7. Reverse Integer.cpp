/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1 */
//code
class Solution {
public:
// find out the reversed Number
//if it is out of the 32 bit range then return 0
    int reverse(int x) {
        // we know that The highest bit is often called the "sign bit" because if it's 0, the number is positive, and if it's 1, the value is negative (for signed values).
        //so take a variable sign and initialize it with 1
        int sign = 1;
        if(x<0){
            sign = -1 ;//if the number is negative we will make the sign value -1
            x = -1ll * x;
        }
         long long reversedNum = 0;
         while(x>0){
             int rem = x%10; //finding the last digit
             reversedNum = reversedNum*10 + rem; 
             x = x/10;
         }
         reversedNum = reversedNum * sign;
         if(reversedNum <INT_MIN || reversedNum >INT_MAX)return 0;
         return int(reversedNum);

    }
};
