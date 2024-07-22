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
    int n = rd(), m = rd(), ans = 0;
    rep(i, 1, n) {
        bool fl = false;
        int w = rd(), len = 0;
        while (w) {
            if (w % 10) fl = true;
            fl ? ++ans : ++len; w /= 10;
        }
        s.eb(len);
    }
    sort(all(s)); reverse(all(s));
    bool fl = true;
    for (auto x : s) {
        fl ^= 1;
        if (fl) ans += x;
    }
    puts(ans >= m + 1 ? "Sasha" : "Anna");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}