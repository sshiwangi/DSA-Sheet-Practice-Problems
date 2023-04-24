//Link: https://leetcode.com/problems/daily-temperatures/description/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int>ans(n,0); //initializing the ans vector with 0
      stack<int>st; //stack to store the indices of the temperatures items
      //since we have to find out next warmer temperature, we will iterate from the end
      for(int i = n-1; i>=0; i--){
        while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
          // we will pop out the elements
          st.pop();
        }
        // if we found a greater element to the right and if the stack is not empty then we will calculate the distance of the current element from the next greater element and put in the ans vector
        if(!st.empty()){
          ans[i] = st.top() - i;
        }
        st.push(i);//pushing the index of element in the stack
      }
        return ans;
    }
};
