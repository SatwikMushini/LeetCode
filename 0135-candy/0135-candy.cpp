class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1)return 1;

        vector<int>candies(n, 0);
        int cnt = 0;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                cnt++;
                candies[i-1] = cnt;
            }
            else{
                if(cnt > 0)candies[i-1] = cnt + 1;
                cnt = 0;
            }
        }
        
        cnt = 0;
        for(int i = ratings.size()-1; i >= 1; i--){
            if(ratings[i-1] > ratings[i]){
                cnt++;
                candies[i] = cnt;
            }
            else{
                if(cnt > 0){
                    if(candies[i])candies[i] = max(candies[i], cnt+1);
                    else candies[i] = cnt+1;
                }
                cnt = 0;
            }
        }

        if(!candies[0]){
            if(ratings[0] > ratings[1])candies[0] = candies[1] + 1;
            else candies[0] = 1;
        }
        if(!candies[n-1]){
            if(ratings[n-1] > ratings[n-2])candies[n-1] = candies[n-2]+1;
            else candies[n-1] = 1;
        }

        int minCandies = 0;
        
        for(auto x : candies){
            minCandies += x > 0 ? x : 1;
        }
        return minCandies;

    }
};