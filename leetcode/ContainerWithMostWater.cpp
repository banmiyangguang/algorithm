class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        
        while (i < j) {//不存在等于的情况
            int h = min(height[i], height[j]);
            water = max(water, h * (j - i));
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};