#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
private:
	void help(string s, set<string> &tmp, string str, int left, int right, int pair, int i, int n)
	{
		if (i == n)
		{
			if (left == 0 && right == 0 && pair == 0) {
				tmp.insert(str);
			}
			return;
		}

		if (s[i] != '(' && s[i] != ')')
			help(s, tmp, str + s[i], left, right, pair, i + 1, n);
		else
		{
			if (s[i] == '(')
			{
				if (left>0)
					help(s, tmp, str, left - 1, right, pair, i + 1, n);
				help(s, tmp, str + s[i], left, right, pair + 1, i + 1, n);
			}
			if (s[i] == ')')
			{
				if (right>0)
					help(s, tmp, str, left, right - 1, pair, i + 1, n);
				if (pair>0)
					help(s, tmp, str + s[i], left, right, pair - 1, i + 1, n);
			}
		}
	}

public:
	vector<string> removeInvalidParentheses(string s) {
		int n = s.size();
		if (n == 0)
			return { "" };

		set<string> tmp;
		int left = 0;
		int right = 0;

		for (int i = 0; i<n; i++)
		{
			if (s[i] == '(')
				left++;
			if (s[i] == ')')
			{
				if (left>0)
					left--;
				else
					right++;
			}
		}

		help(s, tmp, "", left, right, 0, 0, n);
		return vector<string>(tmp.begin(), tmp.end());
	}
};

void main()
{
	Solution s;
	s.removeInvalidParentheses("(");
}
