#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

vector<int> s[N], id;

inline void work() {
    id.clear();
    int n = rd(), k = rd();
    rep(i, 1, k) {
        int cur = rd(); 
        id.eb(cur); s[cur].clear();
        rep(j, 1, n - 1) s[cur].eb(rd()); 
    }
    if (k == 1) {puts("YES"); return;}
    
    vector<int> ans;
    
    auto check = [&]() {
        for (auto cur : id) {
            int ptr = 0;
            for (auto x : s[cur]) {
                if (ans[ptr] == cur) ++ptr;
                if (ans[ptr] != x) return false;
                ++ptr;
            }
        }
        return true;
    };

    ans.clear(); ans.eb(id[0]);
    for (auto x : s[id[0]]) ans.eb(x);
    if (check()) {puts("YES"); return;}
    
    int pre = id[1];
    for (auto x : s[id[1]]) {if (x == id[0]) break; pre = x;}
    ans.clear(); 
    for (auto x : s[id[0]]) {ans.eb(x); if (x == pre) ans.eb(id[0]);}
    if (check()) {puts("YES"); return;}
    
    ans.clear();    
    for (auto x : s[id[0]]) {ans.eb(x); if (x == id[1]) ans.eb(id[0]);}
    if (check()) {puts("YES"); return;}

    puts("NO");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}