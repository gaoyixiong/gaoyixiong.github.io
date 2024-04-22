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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 5007

int a[N], b[N];

inline void work() {
    int n = rd();
    rep(i, 1, n) a[i] = rd(); sort(a + 1, a + n + 1);
    rep(i, 1, n) b[i] = rd(); sort(b + 1, b + n + 1);
    int ans = 0;
    rep(i, 1, n) {
        int mng = 1e9;
        rep(j, 1, i) mng = min(mng, abs(a[j] - b[n - i + j]));
        rep(j, i + 1, n) mng = min(mng, abs(a[j] - b[j - i]));
        ans = max(ans, mng);
    }
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}