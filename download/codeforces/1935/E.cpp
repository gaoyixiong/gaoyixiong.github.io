#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

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

struct segtree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) / 2)

    struct node {
        int w, cnt[30];
        node operator + (const node &obj) const {
            node ret;
            ret.w = w | obj.w;
            rep(i, 0, 29) ret.cnt[i] = cnt[i] + obj.cnt[i];
            return ret;
        }
        inline void make(int x, int y) {
            w = 0; 
            memset(cnt, 0, sizeof(cnt));
            per(i, 29, 0)
                if (((x >> i) & 1) == ((y >> i) & 1)) w |= (x & (1 << i));
                else {per(j, i, 0) cnt[j] = ((y >> j) & 1); break;}
        }
        int calc() {
            int ret = 0;
            per(i, 29, 0) {
                if ((w >> i) & 1) ++cnt[i];
                if (cnt[i] > 1) return ret | ((1ll << (i + 1)) - 1);
                else if (cnt[i] == 1) ret |= (1ll << i);
            }
            return ret;
        }
    } c[N << 2];

    void build(int rt, int l, int r) {
        if (l == r) {
            int x = rd(), y = rd();
            c[rt].make(x, y);
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        c[rt] = c[ls] + c[rs];
    }

    node query(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) return c[rt];
        if (R <= mid) return query(ls, l, mid, L, R);
        if (L > mid) return query(rs, mid + 1, r, L, R);
        return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
    }

} seg;

inline void work() {
    int n = rd();
    seg.build(1, 1, n);
    per(q, rd(), 1) {
        int l = rd(), r = rd();
        printf("%d ", seg.query(1, 1, n, l, r).calc());
    }
    puts("");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}