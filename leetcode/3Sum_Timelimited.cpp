class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//����ô�ж��Ƿ�����ͬ���ǣ�
		//vectorӦ�����������ظ�
		//�ȷŽ�ȥ��������ж�
		vector<vector<int> > vec;
		if (nums.size() < 3)
			return vec;

		//���Կ������������Ͳ���������
		sort(nums.begin(), nums.end());
		int i = 0, j = nums.size() - 1;
        
		if ((nums[i] < 0 && nums[j] < 0) || (nums[i] > 0 && nums[j] > 0))
			return vec;

		int ret;
		vector<int> v;

		for (int index = j; index > 0 && nums[index] >= 0;) {
			int preValue2 = nums[index];
			for (int i = 0; nums[i] <= 0 && i < j;) {
				int preValue = nums[i];
				int value = 0 - nums[i] - nums[index];
				if (value < nums[i] || value > nums[index]) {
					while (nums[++i] == preValue);
					continue;
				}
				ret = search(nums, i, index, value);
				if (ret != -1) {//û�ҵ��Ļ�����ͬ����ֵ��ֱ��ȥ��
					v.clear();
					v.push_back(nums[i]);
					v.push_back(nums[ret]);
					v.push_back(nums[index]);
					vec.push_back(v);
				}
				while ((nums[++i] == preValue) && i < j);

			}
			while (--index > 0 && (nums[index] == preValue2));
		}

		return vec;
	}
private:
	int search(vector<int>& nums, int i, int j, int value) {
		if ((j - i == 1) || j <= i)
			return -1;
		for (int index = i + 1; index < j; index++) {
			if (nums[index] == value)
				return index;
		}
		return -1;
	}
};