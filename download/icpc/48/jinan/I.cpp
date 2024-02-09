#include <bits/stdc++.h>
using namespace std;
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int a[101];

vector<pii> ans;

inline void work() {
    ans.clear();
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) if (a[i] != i) {
        per(j, n, i) if (a[j] < a[i]) {
            sort(a + i, a + j + 1); 
            ans.eb(i, j); break;
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto [l, r] : ans) printf("%d %d\n", l, r);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}