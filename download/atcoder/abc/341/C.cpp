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

#define N 507

char s[N][N], op[N];

int main() {
    int n = rd(), m = rd(), k = rd(), ans = 0;
    scanf("%s", op + 1);
    rep(i, 1, n) scanf("%s", s[i] + 1);  
    rep(i, 1, n) rep(j, 1, m) if (s[i][j] == '.') {
        int x = i, y = j;
        bool fl = true;
        rep(a, 1, k) {
            if (op[a] == 'L') --y;
            if (op[a] == 'R') ++y;
            if (op[a] == 'D') ++x;
            if (op[a] == 'U') --x;
            if (s[x][y] == '#') {fl = false; break;}
        }
        ans += fl;
    }
    printf("%d\n", ans);
    return 0;
}