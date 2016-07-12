//13. Roman to Integer
//Given a roman numeral, convert it to an integer.
//Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
	int romanToInt(string s) {
		if (s == " "){ return 0; }
		int result = 0;
		map<char, int> roman;
		roman['I'] = 1;
		roman['V'] = 5;
		roman['X'] = 10;
		roman['L'] = 50;
		roman['C'] = 100;
		roman['D'] = 500;
		roman['M'] = 1000;
		for (int i = 0; i != s.length(); ++i){
			if (i == 0){
				result = roman[s[i]];
				continue;
			}
			if (roman[s[i]] > roman[s[i - 1]]){
				result = result + roman[s[i]] - 2 * roman[s[i - 1]];
			}
			else{
				result += roman[s[i]];
			}
		}
		return result;
	}
};