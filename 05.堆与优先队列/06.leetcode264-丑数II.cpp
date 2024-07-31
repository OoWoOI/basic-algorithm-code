class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        long long ans = 1, flag = 0;
        s.insert(1);
        while (n--) {
            ans = *s.begin();
            s.erase(s.begin());
            if (ans % 5 == 0) flag = 0;
            if (ans % 3 == 0) flag = 1;
            if (ans % 2 == 0) flag = 2;
            switch (flag) {
                case 0: s.insert(ans * 5);
                case 1: s.insert(ans * 3);
                case 2: s.insert(ans * 2);
            }
        }
        return ans;
    }
};
