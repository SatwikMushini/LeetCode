class Solution {
public:
    void do_sort(vector<int>& a){
        sort(a.begin(), a.end());
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        do_sort(seats); do_sort(students);
        int ans = 0;
        for(int i = 0; i < seats.size(); i++){
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};