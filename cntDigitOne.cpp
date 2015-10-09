class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0) return 0;

		if (n<10) return 1;

		int tmp = n;
		int width = 1;
		while (tmp>=10){
			tmp = tmp / 10;
			width++;
		}

		int *array = new int[width+1];
		int offset = 1;
		const int base = 10;
		*array = 0;
		for (int i_ = 1; i_ <= width; ++i_){
			*(array + i_) = offset + base* *(array + i_ - 1);
			offset = base*offset;
		}
		
		tmp = n;
		int ret=0;
		offset = 1;
		for (int i_ = 1; i_ <=width; ++i_){
			int rem = tmp%base;
			tmp = tmp / 10;
			if (rem>1)
				ret += offset + rem**(array + i_ - 1);
			else if (rem == 1)
				ret += n%offset + 1 + rem**(array + i_ - 1);
			offset *= base;
		}
		return ret;
	}
};