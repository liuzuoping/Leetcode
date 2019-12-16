class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0) return false;
		if (x<10) return true;
		std::vector<int> v;
		while (x>0) {
			int m = x % 10;
			x = x / 10;
			v.push_back(m);
		}
		int len = v.size();
		for (int i = 0; i<len / 2; i++) {
			if (v[i] != v[len - i - 1]) return false;
		}
		return true;
	}
};