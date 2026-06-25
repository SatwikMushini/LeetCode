class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(auto x : text){
            if(x == 'b' || x == 'a' || x == 'l' || x == 'o' || x == 'n'){
                freq[x]++;
            }
        }
        if(freq.size() < 5)return 0;
        int mini = min(freq['l'], freq['o']) / 2;
        for(auto &[key,value]: freq){
            mini = min(value, mini);
        }
        return mini;
    }
};