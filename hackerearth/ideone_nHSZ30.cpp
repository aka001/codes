#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=1;i<=n;i++)
#define ll long long 
#define matrix vector< vector<ll> >
#define MOD 1000000007
const int K=2;

matrix mul(matrix A,matrix B)
{
	matrix C(K+1,vector<ll>(K+1));
	FOR(i,K) FOR(j,K) FOR(k,K)
	C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
	return C;
}

matrix _pow(matrix A, ll p)
{
	if (p == 1)
    return A;
    if (p % 2)
    return mul(A, _pow(A, p-1));
    matrix X = _pow(A, p/2);
    return mul(X, X);
}

ll solve(ll n)
{
	vector<ll> f1(K+1);
	f1[1]=1;
	f1[2]=2;
	matrix T(K+1,vector<ll>(K+1));
	T[1][1]=0;
	T[1][2]=1;
	T[2][1]=1;
	T[2][2]=1;
	
	if(n==1)
	return 1;
	
	T=_pow(T,n-1);
	ll ans=0;
	
	FOR(i,K)
	ans=(ans+T[1][i]*f1[i])%MOD;
	return ans;
	
}

int main()
{
	long long int t;
	long long int N;
	cin>>t;
	while(t--)
	{
		scanf("%lld",&N);
		ll val=solve(N);
		cout<<val<<endl;
	}
}
