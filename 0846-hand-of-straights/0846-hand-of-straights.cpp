class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        map<int,int> freq;
        for(auto x : hand){
            freq[x]++;
        }
        while(!freq.empty()){
            int key = freq.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(freq.find(key + i) == freq.end())return false;

                freq[key + i]--;
                if(freq[key + i] == 0)freq.erase(key+i);
            }
        }
        return true;
    }
};