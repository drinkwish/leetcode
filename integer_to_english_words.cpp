class Solution {
	public:
		string numberToWords(int num) {
		    if(num == 0) return "Zero";
		    
			int width = 0;
			int tmp = num;
			while (tmp) {
				width++;
				tmp = tmp / 10;
			}

			string ret;
			numberToWords(ret, num, width);

			return ret;
		}

		void numberToWords(string &ret, int num, int width){
			if (width == 1 || (width == 2 && num <= 19)){
				ret += (ret.length() ? " " : "") + digitToString(num);
				return;
			}

			if (width == 2){
				int tens = num - num % 10;
				ret += (ret.length() ? " " : "") + digitToString(tens);
				if(num - tens) numberToWords(ret, num - tens, 1);
				return;
			}

			if (width == 3){
				int hundreds = num / 100;
				if(hundreds) ret += (ret.length() ? " " : "") + digitToString(hundreds) + " Hundred";
				if(num - hundreds * 100) numberToWords(ret, num - hundreds * 100, 2);
				return;
			}

			if (width >3 && width <= 6){
				int thousands = num / 1000;
				if(thousands) {
				    numberToWords(ret, thousands, width - 3);
				    ret += " Thousand";
				}
				if(num - thousands * 1000) numberToWords(ret, num - thousands * 1000, 3);
				return;
			}

			if (width >6 && width <= 9){
				int millions = num / 1000000;
				if(millions) {
				    numberToWords(ret, millions, width - 6);
				    ret += " Million";
				}
				if(num - millions * 1000000) numberToWords(ret, num - millions * 1000000, 6);
				return;
			}

			if (width > 9){
				int billions = num / 1000000000;
				if(billions) {
				    numberToWords(ret, billions, width - 9);
				    ret += " Billion";
				}
				if(num - billions * 1000000000) numberToWords(ret, num - billions * 1000000000, 9);
				return;
			}
		}


		string digitToString(int num){
			switch (num){
			case 0:
				return "Zero";
			case 1:
				return "One";
			case 2:
				return "Two";
			case 3:
				return "Three";
			case 4:
				return "Four";
			case 5:
				return "Five";
			case 6:
				return "Six";
			case 7:
				return "Seven";
			case 8:
				return "Eight";
			case 9:
				return "Nine";
			case 10:
				return "Ten";
			case 11:
				return "Eleven";
			case 12:
				return "Twelve";
			case 13:
				return "Thirteen";
			case 14:
				return "Fourteen";
			case 15:
				return "Fifteen";
			case 16:
				return "Sixteen";
			case 17:
				return "Seventeen";
			case 18:
				return "Eighteen";
			case 19:
				return "Nineteen";
			case 20:
				return "Twenty";
			case 30:
				return "Thirty";
			case 40:
				return "Forty";
			case 50:
				return "Fifty";
			case 60:
				return "Sixty";
			case 70:
				return "Seventy";
			case 80:
				return "Eighty";
			case 90:
				return "Ninety";
			}
		}
	};