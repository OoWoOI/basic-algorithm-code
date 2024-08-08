/*************************************************************************
	> File Name: 13.leetcode219-存在重复元素II.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 02:16:40 PM CST
 ************************************************************************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //input ind val;
        int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        //sort by ind
        sort(   ind.begin(),
                ind.end(),
                [&](const int i, const int j)->bool{
                    if (nums[i] == nums[j]) return i < j;
                    return nums[i] < nums[j];
        });

        // find key duplicate
        for (int i = 0; i < n - 1; i++) {
            if (nums[ind[i]] - nums[ind[i + 1]]) continue;
            if (abs(ind[i] - ind[i + 1]) <= k) return true;
        }
        return false;
    }
};
