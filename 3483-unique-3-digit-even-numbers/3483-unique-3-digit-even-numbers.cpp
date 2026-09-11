class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10, 0);
        for(auto x : digits)freq[x]++;
        
        int cnt = 0;
        for(int i = 1; i < 10; i++){
            if(freq[i] == 0)continue;
            freq[i]--;

            for(int j = 0; j < 10; j++){
                if(!freq[j])continue;
                freq[j]--;

                for(int k = 0; k < 10; k+=2){
                    if(!freq[k])continue;
                    cnt++;
                }
                freq[j]++;
            }
            freq[i]++;
        }

        return cnt;
    }
};