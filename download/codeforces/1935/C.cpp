#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, l, ans = 0; 
        cin >> n >> l;
        vector<pii> s;
        rep(i, 1, n) {int a, b; cin >> a >> b; s.eb(b, a);}
        sort(all(s));
        rep(i, 0, n - 1) {
            int sum = 0;
            priority_queue<int> q;
            rep(j, i, n - 1) {
                int lim = l - (s[j].first - s[i].first);
                if (lim < 0) break;
                q.push(s[j].second); sum += s[j].second;
                while (sum > lim) {sum -= q.top(); q.pop();}
                ans = max(ans, (int)q.size());
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}