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

char s[N];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    rep(i, 2, n - 1) if (s[i] != s[i - 1] && s[i] != s[i + 1]) {printf("%d", i); return 0;}
    printf("%d", s[1] == s[2] ? n : 1); 
    return 0;
}