class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int closenum = nums[0] + nums[1] + nums[2];
		for (int c = nums.size() - 1; c >= 2; ) {
			for (int a = 0, b = c - 1; a<b; ) {
				int tmp_sum = nums[a] + nums[b] + nums[c];
				if (abs(tmp_sum - target)<abs(closenum - target)) {
					closenum = tmp_sum;
				}
				if (tmp_sum<target) {
					++a;
				}
				else if (tmp_sum>target) {
					--b;
				}
				else {
					return target;
				}
			}
			c--;
		}
		return closenum;
	}
};