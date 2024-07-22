#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; 
    cin >> t;
    while (t--) {
        int n, c, o = 0, e = 0; 
        cin >> n >> c;
        ll ans = 1ll * (c + 1) * (c + 2) / 2;
        rep(i, 1, n) {
            int x; cin >> x;
            ans -= (x / 2 + 1) + (c - x + 1);
            (x & 1) ? ++o : ++e;
        }
        ans += 1ll * o * (o + 1) / 2 + 1ll * e * (e + 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}