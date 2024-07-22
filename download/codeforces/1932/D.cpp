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

map<char, int> mp;

char ch[4] = {'C', 'D', 'S', 'H'};

inline void work() {
    int n = rd();
    char c = getchar(); while (!isalpha(c)) c = getchar();
    int sp = mp[c];
    vector<int> s[4];
    rep(i, 1, (n << 1)) {
        c = getchar(); while (!isdigit(c)) c = getchar();
        s[mp[getchar()]].eb(c - '0');
    }
    vector<pair<int, char>> rem;
    vector<tuple<int, char, int, char>> ans;
    rep(i, 0, 3) sort(all(s[i]));
    rep(i, 0, 3) if (i != sp) {
        while (s[i].size() >= 2) { 
            int la = s[i].back(); s[i].pop_back();
            int sm = s[i].back(); s[i].pop_back();
            ans.eb(sm, ch[i], la, ch[i]);
        }  
        if (!s[i].empty()) rem.eb(s[i].back(), ch[i]);
    }
    if (s[sp].size() < rem.size()) {puts("IMPOSSIBLE"); return;}
    for (auto [x, ty] : rem) {
        ans.eb(x, ty, s[sp].back(), ch[sp]);
        s[sp].pop_back();
    }
    while (s[sp].size() >= 2) { 
        int la = s[sp].back(); s[sp].pop_back();
        int sm = s[sp].back(); s[sp].pop_back();
        ans.eb(sm, ch[sp], la, ch[sp]);
    }  
    for (auto [x1, ty1, x2, ty2] : ans) printf("%d%c %d%c\n", x1, ty1, x2, ty2);
}

int main() {
    rep(i, 0, 3) mp[ch[i]] = i;
    per(t, rd(), 1) work();
    return 0;
}