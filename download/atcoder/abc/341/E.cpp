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

#define N 500007

char s[N];

struct segtree {
    #define mid ((l + r) / 2)
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    struct node {
        bool ok; int bg, ed;
        void flip() {bg ^= 1; ed ^= 1;}
        node operator + (const node &obj) const {
            node ret;
            ret.bg = bg; ret.ed = obj.ed;
            ret.ok = (ok && obj.ok && ed != obj.bg);
            return ret;
        }
    } c[N << 2];
    bool flip[N << 2];

    void pushdown(int rt) {
        if (flip[rt]) {
            c[ls].flip(); c[rs].flip();
            flip[ls] ^= 1; flip[rs] ^= 1;
            flip[rt] = false;
        }
    }
    void build(int rt, int l, int r) {
        if (l == r) {
            c[rt].bg = c[rt].ed = s[l] - '0';
            c[rt].ok = true; return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        c[rt] = c[ls] + c[rs];
    }
    void upd(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) {flip[rt] ^= 1; c[rt].flip(); return;}
        pushdown(rt);
        if (L <= mid) upd(ls, l, mid, L, R);
        if (R > mid) upd(rs, mid + 1, r, L, R);
        c[rt] = c[ls] + c[rs];
    }
    node query(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) return c[rt];
        pushdown(rt);
        if (R <= mid) return query(ls, l, mid, L, R);
        if (L > mid) return query(rs, mid + 1, r, L, R);
        return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
    }

} seg;

int main() {
    int n = rd(), q = rd();
    scanf("%s", s + 1);
    seg.build(1, 1, n);
    rep(i, 1, q) {
        int op = rd(), l = rd(), r = rd();
        if (op == 1) seg.upd(1, 1, n, l, r);
        else puts(seg.query(1, 1, n, l, r).ok ? "Yes" : "No");
    }
    return 0;
}