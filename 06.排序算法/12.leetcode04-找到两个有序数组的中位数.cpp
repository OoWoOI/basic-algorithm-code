/*************************************************************************
	> File Name: 12.leetcode04-找到两个有序数组的中位数.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 01:49:16 PM CST
 ************************************************************************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> temp(n + m);
        int pos1 = 0, pos2 = 0, pos3 = 0;
        while (pos1 != n || pos2 != m) {
            if (pos2 == m || (pos1 != n && nums1[pos1] < nums2[pos2])) {
                temp[pos3++] = nums1[pos1++];
            } else {
                temp[pos3++] = nums2[pos2++];
            }
        }
        int ind = (n + m) >> 1;
        double ans = temp[ind];
        if ((n + m) % 2 == 0) {
            ans = (ans + temp[ind - 1]) * 1.0 / 2;
        }
        return ans;
    }
};
