class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        queue<string>q;
        q.push("0000");
        unordered_set<string>seen;
        unordered_set<string>dds(deadends.begin(), deadends.end());
        seen.insert("0000");

        if(dds.find("0000") != dds.end())return -1;
        
        int mini = 0;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                string s = q.front(); q.pop();
                if(s == target)return mini;
                for(int i = 0; i < 4; i++){
                    string up = s; string down = s;
                    
                    up[i] = up[i] + 1;
                    if(up[i] > '9')up[i] = '0';
                    if(!seen.count(up) && !dds.count(up)){
                        q.push(up);
                        seen.insert(up);
                    }

                    down[i] = down[i] - 1;
                    if(down[i] < '0')down[i] = '9';
                    if(!seen.count(down) && !dds.count(down)){
                        q.push(down);
                        seen.insert(down);
                    }
                }  
            }
            if(!q.empty())mini++;
        }
        return -1;
    }
};