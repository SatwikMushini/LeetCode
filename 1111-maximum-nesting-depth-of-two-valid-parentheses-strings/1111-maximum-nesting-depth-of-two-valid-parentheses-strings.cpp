class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        vector<int>ans(n);
        string stack = "";

        for(int i = 0; i < n; i++){
            if(stack.empty()){
                stack += '0';
                ans[i] = 0;
            }
            else{
                if(seq[i] == '('){
                    ans[i] = (stack.back() == '0' ? 1 : 0);
                    stack += (stack.back() == '0' ? '1' : '0');
                }
                else{
                    ans[i] = (stack.back() == '0' ? 0 : 1);
                    stack.pop_back();
                }
            }
        }

        return ans;
    }
};