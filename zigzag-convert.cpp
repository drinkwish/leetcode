//leetcode
//zigzag-conversion/
//https://leetcode.com/problems/zigzag-conversion/
//drinkwish

class Solution {
public:
	string convert(string s, int numRows) {
		//int len = s.length();
		//if (len == 0 || numRows <= 1) return s;

		//string *ret = new string[numRows];
		//int row = 0, delta = 1;
		//for (int i = 0; i < len; i++) {
		//	ret[row] += s.at(i);
		//	row += delta;
		//	if (row >= numRows) {
		//		row = numRows - 2;
		//		delta = -1;
		//	}
		//	if (row < 0) {
		//		row = 1;
		//		delta = 1;
		//	}
		//}

		//string ret = "";
		//for (int i = 0; i < numRows; i++) {
		//	ret += ret[i];
		//}
		//return ret;

		int length = s.length();
		if (0 == length || numRows < 2)
			return s;
		
		string ret = "";
		int blockSize = 2 * numRows - 2;
		for (int i_ = 0; i_ < numRows; ++i_){
			for (int j_ = i_; j_ < length; j_ += blockSize){
				ret += s.at(j_);
				if (i_ >0 && i_ < numRows-1){
					int t = j_ + blockSize - 2 * i_;
					if (t < length){
						ret += s.at(j_ + blockSize - 2 * i_);
					}
				}
			}
		}

		return ret;
	}
};