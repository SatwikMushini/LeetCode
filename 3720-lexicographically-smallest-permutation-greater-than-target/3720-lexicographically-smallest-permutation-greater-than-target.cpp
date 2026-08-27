class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char,int>mpp;
        for(auto x : s)mpp[x]++;

        string ans = "";
        for(auto x : target){
            if(mpp.count(x)){
                ans += x;
                mpp[x]--;
                if(mpp[x] == 0)mpp.erase(x);
            }
            else{
                char c = 'z' + 1;
                for(auto &[key, val]: mpp){
                    if(key > x)c = min(c, key);
                }
                if(c != 'z'+1){
                    ans += c;
                    mpp[c]--;
                    if(mpp[c] == 0)mpp.erase(c);
                }
                break;
            }
        }
        if(ans.empty()){
            sort(s.begin(),s.end());
            return (s > target) ?  s : "";
        }

        string remaining = "";
        for(auto &[key, val]: mpp){
            while(val--){
                remaining += key;
            }
        }
        sort(remaining.begin(), remaining.end());
        if(ans.back() > target[ans.size()-1]){
           ans += remaining; return ans;
        }

        int matchedSize = ans.size();
        ans += remaining;
        for(int i = matchedSize-1; i >= 0; i--){
            char c = 'z'+1;
            int minIdx = -1;
            for(int j = i+1; j < ans.size(); j++){
                if(ans[i] < ans[j] && c > ans[j]){
                    c = ans[j];
                    minIdx = j;
                }
            }
            if(minIdx != -1){
                swap(ans[i], ans[minIdx]);
                sort(ans.begin()+i+1, ans.end());
                return ans;
            }
        }
        return "";

        // if(ans <= target){
        //     for(int i = ans.size()-1; i >= 1; i--){
        //         if(ans[i] > ans[i-1]){
        //             int mini = i;
        //             for(int j = i; j < ans.size(); j++){
        //                 if(ans[i-1] < ans[j] && ans[mini] > ans[j])mini = j;
        //             }
        //             swap(ans[i-1], ans[mini]); 
        //             sort(ans.begin()+i, ans.end());
        //             break;
        //         }
        //     }
        // }
        // if(ans <= target)return "";
        // return ans;
    }
};