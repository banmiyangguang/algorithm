class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        int length = nums.size();
        if (length < 4)
            return vec;//�յ�
        
        sort(nums.begin(), nums.end());
        
        //�о��������ȽϺ�
        int index = length - 1;
        vector<vector<int>> tmp;    //����������ĺ�
        while (index > 2) {//Ԥ���ĸ���
            tmp.clear();    //��ֹ�ظ����죬��ʡʱ��
            int value = nums[index];
            //��ȡ�̶���ֵ���������ĺ�
            threeSum(nums, tmp, index, target - nums[index]);
            //��ӵ��ĸ��������ѽ����ӵ�4������vector��
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
        //nums ���Ѿ��ź����
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