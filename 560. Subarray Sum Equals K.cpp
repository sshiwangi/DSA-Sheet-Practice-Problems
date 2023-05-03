/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107 */
//code
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //only map

        // int sum = 0;
        // int ans = 0;
        // unordered_map<int,int>mp;
        // mp[0] = 1;
        // for(int i = 0; i<nums.size(); i++){
        //     sum += nums[i];
        //     if(mp.find(sum-k)!=mp.end()){
        //         ans += mp[sum-k];
        //     }
        //     mp[sum]++;
        // }
        // return ans;

        //prefix sum + map
        int n = nums.size();
        //declaring a prefix array
        int pref[n];
        pref[0] = nums[0];
        for(int i = 1; i<n; i++){
            pref[i] = nums[i] + pref[i-1]; 
        }
        unordered_map<int,int>mp;
        int ans= 0;
        for(int i = 0; i<n; i++){
            if(pref[i] == k)ans++;
            if(mp.find(pref[i]-k)!=mp.end()){
                ans += mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        return ans;
    }
};
