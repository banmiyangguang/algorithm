class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        int length = nums.size();
        if (length < 4)
            return vec;//空的
        
        sort(nums.begin(), nums.end());
        
        //感觉倒着来比较好
        int index = length - 1;
        vector<vector<int>> tmp;    //存放三个数的和
        while (index > 2) {//预留四个数
            tmp.clear();    //防止重复构造，节省时间
            int value = nums[index];
            //获取固定数值的三个数的和
            threeSum(nums, tmp, index, target - nums[index]);
            //添加第四个数，并把结果添加到4个数的vector中
            for (auto beg = tmp.begin(); beg != tmp.end(); beg++) {
                (*beg).push_back(nums[index]);
                vec.push_back(*beg);
            }
            while (--index > 2 && nums[index] == value);
        }
        
        return vec;
    }
public:
    void threeSum(const vector<int>& nums, vector<vector<int>>& vec, const int length, const int target) {
        //nums 是已经排好序的
        vector<int> v;
        int index = 0;
        int front_record, last_record;
        
        while (index < length - 2) {
            int preValue = nums[index];
            int i = index + 1, j = length - 1;
            int value = target - nums[index];
            
            while (i < j) {
                front_record = nums[i];
                last_record = nums[j];
                
                if (nums[i] + nums[j] == value) {
                    v.clear();
                    v.push_back(nums[index]);
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    vec.push_back(v);
                    
                    while (++i < j && nums[i] == front_record);
                    while (--j > i && nums[j] == last_record);
                } else if (nums[i] + nums[j] > value) {
                    while (--j > i && nums[j] == last_record);
                } else {
                    while (++i < j && nums[i] == front_record);
                }
            }
            while (++index < length - 2 && nums[index] == preValue);
        }
    }
};