class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > vec;
        if (nums.size() < 3)
            return vec;
        
        sort(nums.begin(), nums.end());
        
        //避免产生同一符号的情况
        int length = nums.size();
        if ((nums[0] > 0 && nums[length - 1] > 0) || (nums[0] < 0 && nums[length - 1] < 0))
            return vec;
        
        int index = length - 1;
        int front_record, last_record;
        vector<int> ret;
        ret.reserve(3);
        while (index > 1) {
            int i = 0, j = index - 1;
            int preValue = nums[index];
            int value = 0 - nums[index];
            while (i < j) {
                front_record = nums[i];
                last_record  = nums[j];
                if (nums[i] + nums[j] == value) {
                    ret.clear();
                    //add elements
                    ret.push_back(nums[i]);
                    ret.push_back(nums[j]);
                    ret.push_back(nums[index]);
                    
                    vec.push_back(ret);
                    
                    while (++i < j && nums[i] == front_record);
                    while (--j > i && nums[j] == last_record);
                } else if (nums[i] + nums[j] > value) {
                    while (--j > i && nums[j] == last_record);
                } else {
                    while (++i < j && nums[i] == front_record);
                }
            }
            //去重
            while (--index > 0 && nums[index] == preValue);
        }
        
        return vec;
    }
};