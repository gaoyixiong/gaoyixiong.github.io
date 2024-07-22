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

#define N 2007

bool vis[N];

char A[N], B[N];

int main() {
    int n = rd();
    scanf("%s", A + 1);
    scanf("%s", B + 1);
    int st = 0;
    rep(i, 1, n) {
        if (A[i] == B[i]) vis[i] = true;
        if (!vis[i] && A[i] == '-') st = i;
    }  
    vector<string> ans;
    if (st) ans.eb("DRIVE " + to_string(st));
    while (st) {
        vis[st] = true;
        char cur = B[st];
        if (cur != '-') ans.eb("PICKUP");
        bool fl = false;
        rep(i, 1, n) if (!vis[i] && A[i] == cur) {
            st = i; 
            ans.eb("DRIVE " + to_string(st));
            if (cur != '-') ans.eb("DROPOFF");
            fl = true; break;
        }
        if (!fl) {
            rep(i, 1, n) if (!vis[i] && A[i] == '-') {
                st = i; 
                ans.eb("DRIVE " + to_string(st));
                if (cur != '-') ans.eb("DROPOFF");
                fl = true; break;
            }
        }
        if (!fl) st = 0;
    }   
    cout << ans.size() << endl;
    for (auto s : ans) cout << s << endl;
    return 0;
}