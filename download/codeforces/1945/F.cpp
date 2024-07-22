#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
    int x = 0;
    bool f = 0; 
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c== '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int a[N], b[N];

multiset<int> B, S;

inline void work() {   
    B.clear();
    S.clear();
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) S.insert(b[i] = a[rd()]);

    ll ans = 0;
    int ansk = 0;
    rep(i, 1, n) {
        if (S.size() + B.size() < i) break;
        while (B.size() < i) {
            B.insert(*--S.end()); S.erase(--S.end());
        }
        ll nw = 1ll * (*B.begin()) * i;
        if (nw > ans) {ans = nw; ansk = i;}
        if (S.find(b[i]) != S.end()) S.erase(S.find(b[i]));
        else B.erase(B.find(b[i]));
    }
    printf("%lld %d\n", ans, ansk);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}