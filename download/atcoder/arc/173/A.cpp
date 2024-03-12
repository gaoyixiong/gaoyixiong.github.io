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

ll pw[16], cnt[16];

inline void work(ll k) {
    per(i, 15, 0) 
        if (k > cnt[i]) {
            k -= cnt[i];
            ll ans = (k - 1) / pw[i] + 1; 
            k = (k - 1) % pw[i] + 1;
            ll lst = ans;
            per(j, i - 1, 0) {
                ans = ans * 10;
                ll c = (k - 1) / pw[j] + 1; 
                k = (k - 1) % pw[j] + 1;
                ans += (lst = (c > lst ? c : c - 1));
            }
            printf("%lld\n", ans); return;
        } 
}

int main() {
    pw[0] = 1;
    rep(i, 1, 15) {
        pw[i] = pw[i - 1] * 9ll;
        cnt[i] = cnt[i - 1] * 9 + 9;
    }
    per(t, rd(), 1) work(rd());    
    return 0;
}