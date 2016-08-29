#include<vector>
using namespace std;
//该方法在遇到类似[7,2,4,1]这种数据时无法AC

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()){
			return NULL;
		}
		int max = prices[0];
		int min = prices[0];
		int maxindex = 0;
		int minindex = 0;
		int max1, max2;
		for (int i = 0; i < prices.size(); ++i){
			if (prices[i] > max){
				max = prices[i];
				maxindex = i;
			}
			if (prices[i] < min){
				min = prices[i];
				minindex = i;
			}
		}
		if (maxindex > minindex){
			return max - min;
		}
		else{
			min = prices[0];
			for (int j = 0; j = maxindex; ++j){
				if (prices[j] < min){
					min = prices[j];
				}
			}
			max1 = max - min;
			min = prices[minindex];
			max = prices[minindex];
			for (int k = minindex; k < prices.size(); ++k){
				if (prices[k] > max){
					max = prices[k];
				}
			}
			max2 = max - min;
		}
		return (max1 > max2) ? max1 : max2;
	}
};

int main(){
	vector<int> prices = { 3, 2, 6, 5, 0, 3 };
	Solution solution;
	solution.maxProfit(prices);
}

//方法2
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0)
			return 0;
		int i = 0;
		int j = i + 1;
		int small_price = prices[i];
		int profit = 0;
		while (i < prices.size() - 1){
			j = i + 1;
			if (prices[i] < small_price)
				small_price = prices[i];
			int tmp = prices[j] - small_price;
			if (tmp > profit)
				profit = tmp;
			i++;
		}
		if (profit < 0)
			profit = 0;
		return profit;
	}
};
//方法3
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int m = prices.size();
		if (m == 0)
			return 0;

		int curMin = prices[0];
		int ret = 0;
		for (int i = 1; i < m; i++)
		{
			curMin = min(curMin, prices[i]);
			ret = max(ret, prices[i] - curMin);
		}
		return ret;
	}
};