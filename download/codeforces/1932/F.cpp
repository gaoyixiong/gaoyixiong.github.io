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

#define N 1000007

int f[N], L[N], cont[N], mx[N];

inline void work() {
    int n = rd(), m = rd();
    rep(i, 1, n) L[i] = i, cont[i] = 0;
    rep(i, 1, m) {
        int l = rd(), r = rd(); 
        L[r] = min(L[r], l); 
        ++cont[l]; --cont[r + 1];
    }
    per(i, n - 1, 1) L[i] = min(L[i], L[i + 1]);
    rep(i, 1, n) {
        cont[i] += cont[i - 1];
        f[i] = max(f[i - 1], mx[L[i] - 1] + cont[i]);
        mx[i] = max(mx[i - 1], f[i]);
    }
    printf("%d\n", mx[n]);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}