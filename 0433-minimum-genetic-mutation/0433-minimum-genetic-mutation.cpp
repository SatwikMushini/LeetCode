class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char>choices = {'A', 'C', 'G', 'T'};
        unordered_set<string>seen(bank.begin(), bank.end());
        unordered_set<string>checked;

        queue<string>q;
        q.push(startGene); seen.insert(startGene); checked.insert(startGene);

        int mutations = 0;
        while(!q.empty()){
            
            int qs = q.size();
            while(qs--){

                string s = q.front(); q.pop();
                if(s == endGene)return mutations;

                for(int i = 0; i < 8; i++){
                    char ori = s[i];
                    for(auto &c: choices){
                        s[i] = c;
                        if(seen.count(s) && !checked.count(s)){
                            q.push(s); checked.insert(s);
                        }
                    }
                    s[i] = ori;
                }
            }
            if(!q.empty())mutations++;
        }

        return -1;
    }
};