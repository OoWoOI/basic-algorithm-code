/*************************************************************************
	> File Name: 08.leetcode01-两数之和.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Aug 2024 02:02:46 PM CST
 ************************************************************************/
class Solution {
public:
    typedef pair<int, int> PII;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<PII> nums_ind;
        for (int i = 0; i < nums.size(); i++) {
            nums_ind.push_back({nums[i], i});
        }
        sort(   nums_ind.begin(), 
                nums_ind.end(), 
                [&](const PII &a, const PII &b)->bool{
                    return a.first < b.first;
                });
        int l = 0, r = nums_ind.size() - 1;
        vector<int> ans;
        while (l < r) {
            int tmp = nums_ind[l].first + nums_ind[r].first;
            if (tmp == target) {
                ans.push_back(nums_ind[l].second);
                ans.push_back(nums_ind[r].second);
                break;
            }
            if (tmp > target) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};
