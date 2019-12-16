class Solution {
public:
	vector<string> generateParenthesis(int n) {
		set<string> base;
		base.insert("()");
		for (int i = 1; i<n; i++) {
			set<string> v;
			for (auto s : base) {
				for (int idx = 0; idx <= s.size(); idx++) {
					v.insert(string(s).insert(idx, "()"));
				}
			}
			v.swap(base);
		}
		vector<string> ret;
		for (auto &s : base)
			ret.push_back(s);
		return ret;
	}
};