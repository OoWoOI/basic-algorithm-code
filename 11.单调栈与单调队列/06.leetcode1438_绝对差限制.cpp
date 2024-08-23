/*************************************************************************
	> File Name: 06.leetcode1438_绝对差限制.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Aug 2024 05:38:18 PM CST
 ************************************************************************/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (limit < 0) return 1;
        deque<int> max_q, min_q;
        int ans = 1, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (!min_q.empty() && nums[r] < nums[min_q.back()]) {
                min_q.pop_back();
            }
            while (!max_q.empty() && nums[r] > nums[max_q.back()]) {
                max_q.pop_back();
            }
            min_q.push_back(r);
            max_q.push_back(r);
            while (nums[max_q.front()] - nums[min_q.front()] > limit) {
                if (l == max_q.front()) max_q.pop_front();
                if (l == min_q.front()) min_q.pop_front();
                l += 1;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
