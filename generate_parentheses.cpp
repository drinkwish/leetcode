//0ms, 100%
class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> ret;
			generateParenthesis(ret, 0, 0, "", n);
			return ret;
		}

		void generateParenthesis(vector<string> &ret, int left, int right, string s, int n){
			if (left < right) return;
			if (left == n && right == n) {
				ret.push_back(s);
				return;
			}

			if (left == n){
				while (right != n){
					s.append(1, ')');
					++right;
				}
				ret.push_back(s);
				return;
			}

			generateParenthesis(ret, left + 1, right, s + "(", n);
			generateParenthesis(ret, left, right + 1, s + ")", n);
		}
};

//4ms, 27.05%
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> seq;

		for(int i_ = 0; i_ <= n; ++i_){
			generateParenthesis(seq, i_);
		}

		return seq[n];
	}

	void generateParenthesis(vector<vector<string>> &seq, int n){
	    vector<string> ret;
		if (n == 0){
			ret.push_back("");
			seq.push_back(ret);
			return;
		}
		if (n == 1) {
			ret.push_back("()");
			seq.push_back(ret);
			return;
		}

		for (int left = 1; left <= n; ++left){
			int right = n - left;
			
			for (int i_ = 0; i_ < seq[left-1].size(); ++i_){
				for (int j_ = 0; j_ < seq[right].size(); ++j_){
					ret.push_back("(" + seq[left - 1][i_] + ")" + seq[right][j_]);
				}
			}
		}
		seq.push_back(ret);
	}
};