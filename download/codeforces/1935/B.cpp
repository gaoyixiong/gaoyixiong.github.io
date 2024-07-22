#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007

bool vis[N];

int a[N], L[N], R[N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 0, n) vis[i] = false;
        rep(i, 1, n) {
            vis[a[i]] = true;
            L[i] = L[i - 1];
            while (vis[L[i]]) ++L[i];
        }
        rep(i, 0, n) vis[i] = false;
        int ans = 0;
        bool fl = false;
        per(i, n, 2) {
            vis[a[i]] = true;
            while (vis[ans]) ++ans;
            if (ans == L[i - 1]) {
                printf("2\n1 %d\n%d %d\n", i - 1, i, n);
                fl = true; break;
            }
        }
        if (!fl) puts("-1");
    }
    return 0;
}