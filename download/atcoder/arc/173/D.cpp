#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline ll rd() {
    ll x = 0;
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

#define N 4007

int n;

bool inq[N];

int cnt[N], dis[N];

vector<pii> e[N];

int main() {
    int n = rd(), m = rd();
    rep(i, 1, m) {
        int u = rd(), v = rd();
        char c = getchar(); while (c != '(' && c != ')') c = getchar();
        e[u].eb(v, (c == '(' ? 1 : -1));
    }
    
    auto spfa = [&](int s) {
        static queue<int> q;
        while (!q.empty()) q.pop();
        rep(i, 1, n) dis[i] = n + 1, cnt[i] = 0, inq[i] = 0;
        dis[s] = 0; cnt[s] = 1; inq[s] = true; q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            inq[u] = false; q.pop();
            for (auto [v, w] : e[u])
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (!inq[v]) {
                        ++cnt[v]; if (cnt[v] > n) return true;
                        inq[v] = true; q.push(v);
                    }
                }
        }
        return false;
    };

    bool f1 = spfa(1);
    rep(u, 1, n) for (auto &[v, w] : e[u]) w = -w;
    bool f2 = spfa(1);
    puts(f1 == f2 ? "Yes" : "No");
    return 0;
}