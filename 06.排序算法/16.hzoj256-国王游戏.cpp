/*************************************************************************
	> File Name: 16.hzoj256-国王游戏.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 05:56:34 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BigInt : public vector<int> {
public :
    BigInt(int x){
        this->push_back(x);
        proccess_digit();
    }
    
    void operator*=(const int x) {
        for (int i = 0; i < size(); i++) {
            at(i) *= x;
        }
        proccess_digit();
        return ;
    }


    BigInt operator/(const int x) {
        BigInt ret(*this);
        int y = 0;
        for (int i = size() - 1; i >= 0; i--) {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        ret.proccess_digit();
        return ret; 
    }

    //make digit leagal
    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) this->push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        //del pre zero
        while (size() > 1 && at(size() - 1) == 0) this->pop_back();
        return ;
    }

    bool operator>(const BigInt &a) const {
        if (size() != a.size()) size() > a.size();
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) != a[i]) return at(i) > a[i];
        }
        return false;
    }
};


ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    } 
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 5), b(n + 5);
    int ind[n + 5];
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }

    sort(ind + 1, ind + n + 1, [&](const int i, const int j)->bool {
        return a[i] * b[i] < a[j] * b[j];
    });

    BigInt p = a[0], ans = 0, temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = p / b[ind[i]];
        if (temp > ans) ans = p / b[ind[i]];
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
