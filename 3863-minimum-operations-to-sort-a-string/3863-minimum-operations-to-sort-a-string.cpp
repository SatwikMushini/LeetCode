class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string sorted = s; sort(sorted.begin(), sorted.end()); //nlogn
        if(n == 2 && s != sorted)return -1; //n
        if(s == sorted)return 0; // n
        if(s[0] == sorted[0] || s[n-1] == sorted[n-1])return 1;
        string s1 = s, s2 = s;
        sort(s1.begin()+1, s1.end()); //nlogn
        sort(s1.begin(), s1.end()-1); //nlogn

        sort(s2.begin(), s2.end()-1); //nlogn
        sort(s2.begin()+1, s2.end()); //nlogn
        if(sorted == s1 || sorted == s2)return 2; //2n
        return 3;
    }
};