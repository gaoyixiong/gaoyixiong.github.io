#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y){
    if (!b) {x = 1; y = 0; return a;}
    ll r = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

int main(){
    ll a, b, x, y; 
    cin >> a >> b;
    ll g = exgcd(abs(a), abs(b), x, y);
    if (g > 2) {puts("-1"); return 0;}
    ll ansx = y * -2 / g;
    ll ansy = x * 2 / g;
    if (a < 0) ansx = -ansx;
    if (b < 0) ansy = -ansy;
    printf("%lld %lld\n", ansx, ansy);
    return 0;
}