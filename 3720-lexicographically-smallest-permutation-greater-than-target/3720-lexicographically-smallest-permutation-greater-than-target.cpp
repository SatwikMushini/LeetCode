class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char,int>mpp;
        for(auto x : s)mpp[x]++;

        //putting chars from target which are present in s.
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
                    ans += c;           //putting the just greatest char if found
                    mpp[c]--;
                    if(mpp[c] == 0)mpp.erase(c);
                }
                break;
            }
        }

        string remaining = "";
        for(auto &[key, val]: mpp){
            while(val--){
                remaining += key;
            }
        }
        sort(remaining.begin(), remaining.end());
        if(!ans.empty() && ans.back() > target[ans.size()-1]){ //if just greater char found
           ans += remaining; return ans;
        }

        int matchedSize = ans.size();
        ans += remaining;
        for(int i = matchedSize-1; i >= 0; i--){ //else loop back to front and find the just greater
            char c = 'z'+1;
            int minIdx = -1;
            for(int j = i+1; j < ans.size(); j++){
                if(ans[i] < ans[j] && c > ans[j]){
                    c = ans[j];
                    minIdx = j;
                }
            }
            if(minIdx != -1){           //if found 
                swap(ans[i], ans[minIdx]);
                sort(ans.begin()+i+1, ans.end());
                return ans;
            }
        }
        return "";
    }
};