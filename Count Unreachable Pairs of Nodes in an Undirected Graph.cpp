/* Problem Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Example 1:

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
Example 2:

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

Constraints:

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges. */

/* Total number of unreachable nodes from each node in a component is the total number of nodes outside its component.
Then total number of unreachable pairs will be (total number of unreachable nodes / 2) */
class Solution {
public:
// function to count the size of each component
    void dfs(int node, vector<int>adj[], vector<int>&vis, int&size){
        vis[node] = 1;
        size++;
        for(auto& it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,size);
            }
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //creating adjacency list
        vector<int>adj[n];
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n,0); //visited array
        vector<int>compSize; //to store size of components
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int size = 0;
                dfs(i,adj,vis,size);
                compSize.push_back(size); // pushing size of each component in compSize
            }
        }
        //counting number of unreachable nodes
        long long totalUnreachNodes = 0;
        for(int i = 0; i<compSize.size(); i++){
            int rest = n-compSize[i];
            totalUnreachNodes += (long long)compSize[i] * (long long)rest;
        }
        return totalUnreachNodes/2;
    }
};
