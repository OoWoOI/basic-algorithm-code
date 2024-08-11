/*************************************************************************
	> File Name: 05.leetcode01-两数之和.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Aug 2024 12:01:28 PM CST
 ************************************************************************/

class Solution {
public:
    // hash_table
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> h;
        for (int i = 0, I = nums.size(); i < I; i++) {
            if (h.find(target - nums[i]) != h.end()) {
                ret.push_back(h[target - nums[i]]);
                ret.push_back(i);
                break;
            }
            h[nums[i]] = i;
        }
        return ret;
    }
};


class Solution {
public:

    //binary_search

    int binary_search(vector<int> &nums, vector<int> &ind, int b, int target) {
        int l = b, r = ind.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[ind[mid]] == target) return ind[mid];
            if (nums[ind[mid]] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j)->bool{
            if (nums[i] == nums[j]) return i < j;
            return nums[i] < nums[j];
        });
        vector<int> ret(2);
        for (int i = 0; i < n; i++) {
            int index = binary_search(nums, ind, i + 1, target - nums[ind[i]]);
            if (index <0) continue;
            ret[0] = index;
            ret[1] = ind[i];
        }
        return ret;
    }
};
