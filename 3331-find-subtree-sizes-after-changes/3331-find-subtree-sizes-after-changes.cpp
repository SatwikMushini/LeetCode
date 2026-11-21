class Solution {
public:
    void dfs(int node, auto& ance, auto& adjList, auto& parent, string& s) {
        int c = s[node] - 'a';
        int last = ance[c];

        if(last != -1)parent[node] = last;
        ance[c] = node;

        for(auto x : adjList[node]) {
            dfs(x, ance, adjList, parent, s);
        }

        ance[c] = last;
    }
    int calc(int node, auto& adjList, auto& ans) {
        ans[node] = 1;
        for(auto x : adjList[node]) {
            ans[node] += calc(x, adjList, ans);
        }
        return ans[node];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>adjList(n);
        for(int i = 1; i < n; i++) {
            adjList[parent[i]].push_back(i);
        }

        vector<int>ance(26, -1); //ance for ancestors
        dfs(0, ance, adjList, parent, s);

        for(auto &x : adjList)x.clear();
        for(int i = 1; i < n; i++) {
            adjList[parent[i]].push_back(i);
        }

        vector<int>ans(n);
        calc(0, adjList, ans);
        return ans;
    }
};