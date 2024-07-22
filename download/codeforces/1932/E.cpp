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

#define N 400007

char s[N];

int sum[N];

inline void work() {
    int n = rd();
    scanf("%s", s + 1);
    int ans = 0, sump = 0;
    rep(i, 1, n) sum[i] = sum[i - 1] + s[i] - '0';
    per(i, n, 2) {sum[i - 1] += sum[i] / 10; sum[i] %= 10;}
    bool fl = false;
    rep(i, 1, n) {
        if (!fl && !sum[i]) continue;
        fl = true; printf("%d", sum[i]);
    } 
    puts("");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}