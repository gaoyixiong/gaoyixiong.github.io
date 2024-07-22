#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

struct segtree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) / 2)

    ll c[N << 2];

    void build(int rt, int l, int r) {
        if (l == r) {c[rt] = rd(); return;}
        build(ls, l, mid); build(rs, mid + 1, r);
    }

    ll query(int rt, int l, int r, int p) {
        if (l == r) return c[rt];
        return c[rt] + (p <= mid ? query(ls, l, mid, p) : query(rs, mid + 1, r, p));
    }

    void upd(int rt, int l, int r, int L, int R, ll w) {
        if (L <= l && r <= R) {c[rt] += w; return;}
        if (L <= mid) upd(ls, l, mid, L, R, w);
        if (R > mid) upd(rs, mid + 1, r, L, R, w);
    }

    void print(int rt, int l, int r) {
        if (l == r) {printf("%lld ", c[rt]); return;}
        c[ls] += c[rt]; c[rs] += c[rt];
        print(ls, l, mid); print(rs, mid + 1, r);
    }

} seg;

int main() {
    int n = rd(), m = rd();
    seg.build(1, 1, n);
    rep(i, 1, m) {
        int id = rd() + 1;
        ll w = seg.query(1, 1, n, id);
        seg.upd(1, 1, n, id, id, -w);
        int R = min(1ll * n, id + w);
        seg.upd(1, 1, n, id + 1, R, 1);
        if (R == n) {
            w -= n - id;
            if (w / n) seg.upd(1, 1, n, 1, n, w / n);
            w = w % n;
            if (w) seg.upd(1, 1, n, 1, w, 1);
        } 
    }
    seg.print(1, 1, n);
    return 0;
}