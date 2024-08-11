/*************************************************************************
	> File Name: 08.leetcode349-两个数组的交集.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Aug 2024 12:38:54 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_set<int> hash;
        for (int i = 0, I = nums1.size(); i < I; i++) {
            hash.insert(nums1[i]);
        }
        //find intersection
        for (int i = 0, I = nums2.size(); i < I; i++) {
            auto it = hash.find(nums2[i]);
            if (it != hash.end()) {
                ret.push_back(nums2[i]);
                hash.erase(*it);
            }
        }
        return ret;
    }
};
