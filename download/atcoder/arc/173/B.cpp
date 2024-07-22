#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline ll rd() {
    ll x = 0;
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

#define N 307

ll x[N], y[N];

// solution1 : BM Voting O(n)

int main() {
    int n = rd();
    auto check = [&](int i, int j, int k) {
        return (x[j] - x[i]) * (y[k] - y[i]) == (x[k] - x[i]) * (y[j] - y[i]);
    };
    vector<int> s;
    rep(i, 1, n) {
        x[i] = rd(); y[i] = rd();
        if (s.size() < 2) s.eb(i);
        else {
            if (check(s[0], s[1], i)) s.eb(i);
            else {s.pop_back(); s.pop_back();}
        }
    }
    if (s.size() < 3) {printf("%d\n", n / 3); return 0;}
    int cnt = 0;
    rep(i, 1, n) cnt += check(s[0], s[1], i);
    printf("%d\n", min(n / 3, n - cnt));
    return 0;
}

/*

// solution2 : O(n^3)

int main() {
    int n = rd();
    rep(i, 1, n) {x[i] = rd(); y[i] = rd();}
    int ans = 0;
    rep(i, 1, n) rep(j, i + 1, n) {
        int tmp = 2;
        // ijk on the same line : ij cross ik = 0
        rep(k, 1, n) if (k != i && k != j) tmp += ((x[j] - x[i]) * (y[k] - y[i]) == (x[k] - x[i]) * (y[j] - y[i]));   
        ans = max(ans, tmp);
    } 
    printf("%d\n", min(n / 3, n - ans));
    return 0;
}

*/