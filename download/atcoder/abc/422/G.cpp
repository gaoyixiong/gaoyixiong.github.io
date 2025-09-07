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

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int N = 300007;

constexpr int mod = 998244353;
constexpr int maxt = (1ll << 20);

int wn[maxt + 5], A[maxt + 5], B[maxt + 5];

inline int ADD(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int MUL(int x,int y) {return (ll)x*y%mod;}

int Pow(int w,int b) {int s;for (s=1;b;b>>=1,w=MUL(w,w)) if (b&1) s=MUL(s,w);return s;}

__attribute__((constructor)) void NTTPre(){
	int x=Pow(3,(mod-1)/maxt);
	wn[maxt>>1]=1;
	for (int i=(maxt>>1)+1;i<maxt;i++) wn[i]=MUL(wn[i-1],x);
	for (int i=(maxt>>1)-1;i;i--) wn[i]=wn[i<<1];
}

void NTT(int *a,int n,int f){
	if (f>0){
		for (int k=n>>1;k;k>>=1)
			for (int i=0;i<n;i+=k<<1)
				for (int j=0;j<k;j++){
					int x=a[i+j],y=a[i+j+k];
					a[i+j+k]=MUL(x+mod-y,wn[k+j]);
					a[i+j]=ADD(x,y);
				}
	} else {
		for (int k=1;k<n;k<<=1)
			for (int i=0;i<n;i+=k<<1)
				for (int j=0;j<k;j++){
					int x=a[i+j],y=MUL(a[i+j+k],wn[k+j]);
					a[i+j+k]=ADD(x,mod-y);
					a[i+j]=ADD(x,y);
				}
		for (int i=0,INV=mod-(mod-1)/n;i<n;i++) a[i]=MUL(a[i],INV);
		reverse(a+1,a+n);
	}
}

int f[N], fac[N], ifac[N];

int main() {
	int n = rd(), a = rd(), b = rd(), c = rd();
	f[0] = 1;
	rep(i, a, n) f[i] = (f[i] + f[i - a]) % mod;
	rep(i, b, n) f[i] = (f[i] + f[i - b]) % mod;
	rep(i, c, n) f[i] = (f[i] + f[i - c]) % mod;
	printf("%d\n", f[n]);
	fac[0] = ifac[0] = 1;
	rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[n] = Pow(fac[n],mod-2);
	per(i, n - 1, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	

	int k = 0;
	while ((1 << k) <= n) ++k;

	rep(i, 0, n) A[i] = (i % a == 0) * ifac[i] % mod;
	rep(i, 0, n) B[i] = (i % b == 0) * ifac[i] % mod;


	NTT(A, (1 << (k + 1)), 1);
	NTT(B, (1 << (k + 1)), 1);
	rep(i, 0, (1 << (k + 1)) - 1) A[i] = MUL(A[i], B[i]);
	memset(B, 0, sizeof(B));
	rep(i, 0, n) B[i] = (i % c == 0) * ifac[i] % mod;
	NTT(B, (1 << (k + 1)), 1);
	rep(i, 0, (1 << (k + 1)) - 1) A[i] = MUL(A[i], B[i]);
	NTT(A, (1 << (k + 1)), -1);

	printf("%d\n", MUL(A[n], fac[n]));
	return 0;
}