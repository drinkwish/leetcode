	class Solution {
	public:
		int divide(int dividend, int divisor) {

			int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

			unsigned int a = abs(dividend), b = abs(divisor);
			unsigned int cnt = 1;
			while (a > b){
				cnt = cnt << 1;
				b = b << 1;
			}

			unsigned int ret = positivedivide(a, b, cnt);
			
			if(ret == 0xFFFFFFFF && sign) return 0x7FFFFFFF;
			if(ret == 0xFFFFFFFF && !sign) return 0xFFFFFFFF;

			return sign ? ret : -ret;
		}

		int positivedivide(unsigned int dividend, unsigned int divisor, unsigned int  cnt){
			if (cnt < 1) return 0;
			if (cnt == 1 && dividend == divisor)  return 1;

			while (dividend < divisor){
				divisor = divisor >> 1;
				cnt = cnt >> 1;
			}

			int ret;
			ret = positivedivide(dividend - divisor, divisor, cnt) + cnt;

			return ret;
		}
	};