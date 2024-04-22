#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

#define N 20

int f[N];

int find(int x) {return f[x] == x ? x : (f[x] = find(f[x]));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, c; 
    cin >> n >> c;
    vector<tii> e;
    rep(i, 0, n) rep(j, 0, n) {
        int w; cin >> w;
        if (w && i < j) e.eb(w, i, j);
    }
    int ans = INT_MAX;
    sort(all(e));
    rep(s, 1, (1 << n)) {
        int sum = 0, cnt = 0;
        rep(i, 0, n) f[i] = i;
        for (auto [w, u, v] : e) 
            if (((1 << u) & s) || ((1 << v) & s)) 
                if (find(u) != find(v)) {++cnt; sum += w; f[find(u)] = find(v);}
        if (cnt == n - 1) ans = min(ans, c * __builtin_popcount(s) + sum);
    }   
    printf("%d\n", ans);

    return 0;
}