#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// ��ȫ�������⣬���Ҹ������ޣ�����ֻҪ����������
class Solution{
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		vector<int> f(size + 1, -1);
		f[0] = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j + coins[i] <= amount; j++) {
				if (f[j] != -1) {
					f[j + coins[i]] = min(f[j + coins[i]] == -1 ? (1 << 30) : f[j + coins[i], f[j] + 1);
				}
			}
		}
		return f[amount];
	}
};