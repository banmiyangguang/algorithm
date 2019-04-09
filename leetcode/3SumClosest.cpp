class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //考虑绝对值的问题
        //还是可以先排序
        int length = nums.size();
        if (length < 3) //报错
            return -1;
        
        sort(nums.begin(), nums.end());
        
        int index = 0;
        int ret = 0;
        int distance = INT_MAX;
        
        while (index < length - 2) {//预留出来三个数
            int i = index + 1, j = length - 1;
            int value = target - nums[index];
            while (i < j) {
                int number = nums[i] + nums[j] + nums[index];
                
                if (nums[i] + nums[j] == value) {
                    return target;
                } else if (nums[i] + nums[j] > value) {
                    j--;
                } else {
                    i++;
                }
                
                if (distance > abs(number - target)) {
                    ret = number;
                    distance = abs(number - target);
                }
            }
            index++;
        }
        
        return ret;
    }
};