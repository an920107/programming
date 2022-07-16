#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		map<int, int> mp;
		for (int i = 0; i < nums.size(); ++ i) {
			auto iter = mp.find(target - nums[i]);
			if (iter != mp.end()) {
				ans.emplace_back(iter->second);
				ans.emplace_back(i);
				break;
			}
			mp.insert(pair<int, int>(nums[i], i));
		}
		return ans;
	}
};

int main() {
	
	vector<int> nums = {3, 2, 4};
	Solution sol;
	nums = sol.twoSum(nums,6);
	for (auto x : nums) {
		cout << x << endl;
	}

	return 0;
}
