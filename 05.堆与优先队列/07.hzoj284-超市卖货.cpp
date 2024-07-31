#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int d, p, n;
    cin >> n;
    vector<PII> vec;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        vec.push_back({d, p});
    }
   
    // 按照 d 升序，如果 d 相同则按 p 降序排序
    sort(vec.begin(), vec.end(), [](const PII &a, const PII &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    // 优先队列，最小堆
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < vec.size(); i++) {
        if (pq.size() < vec[i].first) {
            pq.push(vec[i].second);
        } else if (!pq.empty() && pq.top() < vec[i].second) {
            pq.pop();
            pq.push(vec[i].second);
        }
    }

    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
    return 0;
}
