class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int sum = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] == val) {
				nums.erase(nums.begin() + i);
				i = i - 1;
			}
			else {
				sum++;
			}
		}
		return sum;
	}
};