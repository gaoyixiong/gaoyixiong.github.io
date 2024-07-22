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

ll sum[N];

double ans[N];

vector<int> s;

int main() {
    int n = rd();
    rep(i, 1, n) sum[i] = sum[i - 1] + rd();
    per(i, n, 1) {
        while (s.size() > 1) {
            int y = s.back(); s.pop_back();
            int x = s.back();
            if ((sum[x] - sum[y]) * (x - i) < (sum[x] - sum[i]) * (x - y)) {s.eb(y); break;}
        }
        s.eb(i);
        int l = 0, r = s.size() - 1;
        while (r - l > 5) {
            int mid = (l + r) / 2;
            int lmid = s[mid - 1], rmid = s[mid + 1];
            if ((sum[lmid] - sum[i - 1]) * (rmid - i + 1) > (sum[rmid] - sum[i - 1]) * (lmid - i + 1)) r = rmid + 1;
            else l = mid - 1;
        }
        rep(j, l, r) ans[i] = max(ans[i], 1.0 * (sum[s[j]] - sum[i - 1]) / (s[j] - i + 1));
    }
    rep(i, 1, n) printf("%.10lf\n", ans[i]);
    return 0;
}