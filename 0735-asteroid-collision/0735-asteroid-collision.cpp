class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        stack<int> stk;
        for(int i = 0; i < ast.size(); i++){
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