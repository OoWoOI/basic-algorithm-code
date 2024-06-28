class Solution {
public:
    int next_one(int n) {
        int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        if (n == 1) return true;
        int pre = next_one(n), cur = n;

        while (pre != 1 && pre != cur) {
            pre = next_one(pre);
            cur = next_one(cur);
            if (pre != 1) pre = next_one(pre);
        }

        return pre == 1;
    }
};
