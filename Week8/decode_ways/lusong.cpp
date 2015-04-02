class Solution {
public:
    int numDecodings(string s) {
        //动态规划
		if (s.empty())
			return 0;
		int *ret = new int[s.size()];
		for (int i = 0; i < s.size(); i++)
			ret[i] = 0;
		if (s[0] != '0')
			ret[0] = 1;
		else
			return 0;

		if (s.size() >= 2) {
			if (s[1] != '0')
				ret[1] += ret[0];
			if (combinable(s[0], s[1]))
				ret[1] += 1;
		}

		for (int i = 2; i < s.size(); i++) {
			if (s[i] == '0' && s[i - 1] == '0')
				return 0;
			if (s[i] != '0')
				ret[i] += ret[i - 1];
			if (combinable(s[i - 1], s[i])) {
				ret[i] += ret[i - 2];
			}
		}
		return ret[s.size() - 1];
	}
private:
	bool combinable(char a, char b) {
		if (a == '1' || (a == '2' && b >= '0' && b <= '6'))
			return true;
		else
			return false;
    }
};
