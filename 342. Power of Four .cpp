//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.
//
//Example:
//Given num = 16, return true.Given num = 5, return false.
//
//Follow up : Could you solve it without loops / recursion ?


class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0){ return false; }
		int a = 0;
		while (num > 1){
			if (num % 2 != 0){
				return false;
			}
			a += num % 2 ? 0 : 1;
			num /= 2;
		}
		return a % 2 ? false : true;
	}
};

//recursion
bool isPowerOfFour(int num)
{
	if (num == 1) return true;
	if (num <= 0) return false;
	if (num & 0x03) return false;

	return isPowerOfFour(num / 4);
}
//without loops/recursion1
bool isPowerOfFour(int num)
{
	switch (num)
	{
	case 0x01:
	case 0x04:
	case 0x10:
	case 0x40:
	case 0x100:
	case 0x400:
	case 0x1000:
	case 0x4000:
	case 0x10000:
	case 0x40000:
	case 0x100000:
	case 0x400000:
	case 0x1000000:
	case 0x4000000:
	case 0x10000000:
	case 0x40000000:
		return true;
	default:
		return false;
	}
}
//without loops/recursion2
bool isPowerOfFour(int num)
{
	if (num <= 0) return false;
	if (num & (num - 1)) return false; // 先判断是否是 2 的 N 次方
	if (num & 0x55555555) return true; // 再将不是 4 的 N 次方的数字去掉
	return false;
}