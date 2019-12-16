class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		auto s1 = max_element(strs.begin(), strs.end());
		auto s2 = min_element(strs.begin(), strs.end());
		auto pair = mismatch(s1->begin(), s1->end(), s2->begin());
		return string(s1->begin(), pair.first);
	}
};