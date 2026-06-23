class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int i = 0, n = ast.size();
        vector<int>ans;
        while(i < n && ast[i] < 0){
            ans.push_back(ast[i]);
            i++;
        }
        if(i == n)return ans;
        stack<int> stk;
        for(; i < n; i++){
            if(ast[i] < 0){
                while(!stk.empty() && stk.top() < abs(ast[i]))stk.pop();
                if(stk.empty())ans.push_back(ast[i]);
                else if(!stk.empty() && stk.top() == abs(ast[i])){
                    stk.pop();
                }
            }
            else stk.push(ast[i]);
        }
        int size = ans.size();
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin()+size, ans.end());
        return ans;
    }
};