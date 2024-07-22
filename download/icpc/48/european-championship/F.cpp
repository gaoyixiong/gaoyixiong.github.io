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

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007
#define M 1000007
#define B 3000

int sz[N], tr[N], tag[M];

vector<int> s[N], id[M];

int main() {
    int n = rd(), m = rd();
    rep(i, 1, n) {
        sz[i] = rd(); tr[i] = -1;
        rep(j, 1, sz[i]) {int x = rd(); id[x].eb(i); s[i].eb(x);}
        sort(all(s[i]));
    }

    int cntlarge = 0;
    vector<vector<bool>> re;
    rep(i, 1, n) if (sz[i] >= B) {
        tr[i] = cntlarge++;
        for (auto x : s[i]) tag[x] = i;
        vector<bool> tmp; 
        rep(j, 1, n) {
            if (sz[i] < sz[j]) {tmp.eb(false); continue;}
            if (i == j) {tmp.eb(true); continue;}
            bool fl = true;
            for (auto x : s[j]) if (tag[x] != i) {fl = false; break;}
            tmp.eb(fl);
        }
        re.pb(tmp);
    } 

    rep(i, 1, M - 1) if (id[i].size() > 1) {
        int k = id[i].size() - 1;
        sort(all(id[i]), [&](int a, int b) {return sz[a] < sz[b];});
        rep(j, 1, k) {
            int a = id[i][j - 1], b = id[i][j];
            if (tr[b] == -1) {
                int pos = 0, lim = sz[b];
                for (auto x : s[a]) {
                    while (pos < lim && s[b][pos] < x) ++pos;
                    if (pos == lim || s[b][pos] != x) {
                        puts("YES"); printf("%d %d\n", a, b); return 0;
                    }
                }
            } else if (!re[tr[b]][a - 1]) {
                puts("YES"); printf("%d %d\n", a, b); return 0;
            }
        }
    }

    puts("NO");
    return 0;
}