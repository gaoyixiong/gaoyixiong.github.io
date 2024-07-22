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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int l[N], r[N], x[N], a[N];

struct segtree {
    set<pii> c[N << 2];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) / 2)
    void upd(int rt, int l, int r, int L, int R, pii op, bool add) {
        if (L <= l && r <= R) {
            if (add) c[rt].insert(op);
            else c[rt].erase(op);
            return;
        }
        if (L <= mid) upd(ls, l, mid, L, R, op, add);
        if (R > mid) upd(rs, mid + 1, r, L, R, op, add);
    }
    int qmx(int rt, int l, int r, int pos) {
        int cur = (c[rt].empty() ? 0 : (--c[rt].end()) -> first);
        if (l == r) return cur;
        return max(cur, pos <= mid ? qmx(ls, l, mid, pos) : qmx(rs, mid + 1, r, pos)); 
    }
} seg;

int main() {
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    int q = rd();
    rep(i, 1, q) {
        int ty = rd();
        if (ty == 1) {
            l[i] = rd(); r[i] = rd(); x[i] = rd();
            seg.upd(1, 1, n, l[i], r[i], {x[i], i}, true);
        } else if (ty == 2) {
            int id = rd();
            seg.upd(1, 1, n, l[id], r[id], {x[id], id}, false);
        } else {
            int pos = rd();
            printf("%d\n", max(a[pos], seg.qmx(1, 1, n, pos)));
        }
    }
    return 0;
}