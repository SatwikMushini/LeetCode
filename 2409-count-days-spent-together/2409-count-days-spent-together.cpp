class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aam = stoi(arriveAlice.substr(0,2));
        int aad = stoi(arriveAlice.substr(3,2));
        int alm = stoi(leaveAlice.substr(0,2));
        int ald = stoi(leaveAlice.substr(3,2));

        int bam = stoi(arriveBob.substr(0,2));
        int bad = stoi(arriveBob.substr(3,2));
        int blm = stoi(leaveBob.substr(0,2));
        int bld = stoi(leaveBob.substr(3,2));

        vector<int>days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int aa = days[aam-1] + aad;
        int la = days[alm-1] + ald;
        int ab = days[bam-1] + bad;
        int lb = days[blm-1] + bld;

        vector<vector<int>>ps = {{aa,la}, {ab,lb}};
        sort(ps.begin(), ps.end());
        
        if(ps[0][1] >= ps[1][0]){
            if(ps[0][1] >= ps[1][1])return ps[1][1] - ps[1][0] + 1;
            return ps[0][1] - ps[1][0] + 1;
        }
        return 0;
    }
};