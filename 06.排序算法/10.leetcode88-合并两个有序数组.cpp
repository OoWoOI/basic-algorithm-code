/*************************************************************************
	> File Name: 10.leetcode88-合并有序链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Aug 2024 06:49:38 PM CST
 ************************************************************************/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = m - 1, l2 = n - 1, pos = n + m - 1;

        while (l1 >= 0 || l2 >= 0 ) {
            if (l2 < 0 || (l1 >= 0 && nums1[l1] >= nums2[l2])) {
                nums1[pos--] = nums1[l1--];
            } else {
                nums1[pos--] = nums2[l2--];
            }
        }
        return ;
    }
};
