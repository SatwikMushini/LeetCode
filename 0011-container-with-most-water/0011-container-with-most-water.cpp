class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size-1;
        int res_area = 0;
        while(left != right){
            int breadth = min(height[left], height[right]);
            int area = breadth * (right - left);
            res_area = max(res_area, area);
            (height[left] > height[right]) ? right-- : left++;
        }
        return res_area;
    }
};