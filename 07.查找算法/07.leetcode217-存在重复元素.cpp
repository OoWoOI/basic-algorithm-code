/*************************************************************************
	> File Name: 07.leetcode217-存在重复元素.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Aug 2024 12:19:14 PM CST
 ************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int > h;
        for (int i = 0, I = nums.size(); i < I; i++) {
            if (h.find(nums[i]) != h.end()) return true;
            h[nums[i]] = i;
        }
        return false;
    }
};
