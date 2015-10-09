//leetcode
//test-justification 
//https://leetcode.com/problems/text-justification/
//drinkwish

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		if (words.size() == 0 || maxWidth == 0) return words;

		unsigned int start = 0;
		vector<string> ret;
		while (start < words.size()){
			int curLen = 0;
			int curCnt = 0;
			int i_;
			for (i_ = start; i_ < words.size(); ++i_){
				curLen += words[i_].size();
				curCnt++;
				if (curLen + curCnt - 1 > maxWidth){
					break;
				}
			}

			string tmpStr;
			if (i_ == words.size()){
				tmpStr = leftJustify(words, maxWidth, start, i_);
			}
			else{
				tmpStr = evenlyJustify(words, maxWidth, start, i_);
			}
			ret.push_back(tmpStr);

			start = i_;
		}
		return ret;
	}

private:
	//corner1: the last line should be left alligned
	string leftJustify(vector<string>& words, int maxWidth, int start, int end)
	{
		string ret;
		for (int i_ = start; i_ < end-1; ++i_){
			ret += words[i_];
			ret += " ";
		}
		ret += words[end-1];
		int lastCnt = maxWidth - ret.size();
		ret.append(lastCnt, ' ');

		return ret;
	}

	string evenlyJustify(vector<string>& words, int maxWidth, int start, int end)
	{
		string ret;

		int curLen = 0;
		for (int i_ = start; i_ < end; ++i_)
			curLen += words[i_].size();

		int leftCnt = maxWidth - curLen;

		//corner2: if a line is occupied by one line, it should be left alligned.
		if (end - start == 1){
			return ret.append(words[start]).append(leftCnt, ' ');
		}
		else{
			int aveSpace = leftCnt / (end - start - 1);
			int extraCnt = leftCnt % (end - start - 1);
			for (int i_ = start; i_ < end - 1; ++i_){
				ret += words[i_];
				ret.append(aveSpace, ' ');
				if (i_ - start +1<= extraCnt){
					ret.append(1, ' ');
				}
			}
			ret += words[end - 1];
			return ret;
		}
	}

};