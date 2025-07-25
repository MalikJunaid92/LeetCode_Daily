class Solution {
public:
bool topologicalSortChech(  unordered_map<int,vector<int>> &adj, int n,vector<int> &indegree ){
    queue<int>q;
    int count=0;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            count++;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for( int &vec : adj[u]){
            indegree[vec]--;
            if(indegree[vec]==0){
                count++;
                q.push(vec);
            }
        }
    }
    if(count==n) // i was able to push all nodes
    return true;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);  // kahn's algo
        for(auto &v : prerequisites ){
            int a= v[0];
            int b= v[1];
            // b-----> a
            adj[b].push_back(a);
            indegree[a]++;
        }
        // if cycle present 
        return topologicalSortChech(adj,numCourses,indegree);
    }
};