class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        unordered_map<int,int> freq;
        for(auto x : hand){
            freq[x]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto &[key, value]: freq){
            pq.push({key, value});
        }
        while(!pq.empty()){
            int group = groupSize;
            vector<pair<int,int>>temp;
            int prevVal = -1;
            while(group && !pq.empty()){
                auto topi = pq.top(); pq.pop();
                if(topi.second > 1)temp.push_back({topi.first, topi.second-1});
                if(prevVal == -1)prevVal = topi.first;
                else{
                    if(topi.first - prevVal != 1)return false;
                    prevVal = topi.first;
                }
                group--;
            }
            if(group)return false;
            for(auto x : temp){
                pq.push(x);
            }
        }
        return true;
    }
};