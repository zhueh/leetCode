//Write a function that takes a string as input and reverse only the vowels of a string.
//
//Example 1:
//Given s = "hello", return "holle".
//
//Example 2 :
//Given s = "leetcode", return "leotcede".
//
//Note :
//	 The vowels does not include the letter "y".

class Solution {
public:
	string reverseVowels(string s) {
		if (s.empty()){ return s; }
		vector<int> vec;
		set<char> vow = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		for (int i = 0; i != s.size(); ++i){
			if (vow.count(s[i])){
				vec.push_back(i);
			}
		}
		for (int j = 0; j != vec.size() / 2; ++j){
			exchange(s[vec[j]], s[vec[vec.size() - j - 1]]);
		}
		return s;
	}
	void exchange(char &a, char &b){
		char temp;
		temp = a;
		a = b;
		b = temp;
	}
};
//faster
[cpp] view plain copy 在CODE上查看代码片派生到我的代码片
class Solution {
public:
	string reverseVowels(string s) {
		if (s.length() == 0) return "";
		int left = 0, right = s.length() - 1;
		set<char> hash{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		while (left < right)
		{
			if (hash.count(s[left]) == 0)
				left++;
			if (hash.count(s[right]) == 0)
				right--;
			if (hash.count(s[left]) != 0 && hash.count(s[right]) != 0)
			{
				swap(s[left], s[right]);
				left++, right--;
			}
		}
		return s;
	}
};