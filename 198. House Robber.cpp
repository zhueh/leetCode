You ar/*e a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()){ return NULL; }
		int n = nums.size();
		if (n == 1){ return nums[0]; }
		vector<int> robnums(n, 0);
		robnums[0] = nums[0];
		robnums[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; ++i)
			robnums[i] = max(robnums[i - 2] + nums[i], robnums[i - 1]);
		return robnums[n - 1];
	}
};