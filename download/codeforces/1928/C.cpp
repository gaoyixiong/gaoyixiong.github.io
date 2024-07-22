#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> s;

inline void work() {
    s.clear();
    int n = rd(), a = rd();
    auto calc = [&](int w) {
        per(i, sqrt(w), 1) 
            if (w % i == 0) {
                if (i % 2 == 0 && i / 2 + 1 >= a) s.eb(i);
                if (w != i * i && (w / i) % 2 == 0 && (w / i) / 2 + 1 >= a) s.eb(w / i); 
            }
    };
    calc(n - a); calc(n + a - 2);
    sort(all(s)); s.erase(unique(all(s)), s.end());
    int ans = 0;
    for (auto x : s) {
        // x = 2 * k - 2
        int k = x / 2 + 1;
        int pos = (n - 1) % x + 1;
        if (pos <= k) ans += (a == pos);
        else ans += (a == x + 2 - pos);
    }
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}