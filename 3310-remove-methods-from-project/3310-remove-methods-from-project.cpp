class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, unordered_set<int>& sus){
        sus.insert(node);
        for(auto &nbr : adjList[node]){
            if(!sus.count(nbr))dfs(nbr, adjList, sus);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adjList(n);

        for(auto &vec : invocations){            //O(n)
            adjList[vec[0]].push_back(vec[1]);
        }

        unordered_set<int>sus;
        dfs(k, adjList, sus);       //O(n)

        vector<int>ans;
        bool flag = true;

        for(int i = 0; i < n; i++){ //O(n)
            if(!sus.count(i)){
                for(auto nbr : adjList[i]){
                    if(sus.count(nbr)){ // doubt..
                        flag = false; break;
                    }
                }
                if(!flag)break;
                else ans.push_back(i);
            }
        }
        
        if(flag)return ans;
        ans.clear();
        for(int i = 0; i < n; i++)ans.push_back(i); //O(n)
        return ans;
    }
};