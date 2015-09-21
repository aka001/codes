/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define F first
#define S second
#define mod (ll)(1e9 + 7)
#define ll long long int
#define MAX 1006
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll arr[MAX][MAX],dp1[MAX][MAX],p1[MAX][MAX],dp2[MAX][MAX],p2[MAX][MAX],minit,ans,m,n,mp1[1000005],mp2[1000006];
ll copymat(ll dit[MAX][MAX], ll pit[MAX][MAX], ll todo[MAX][MAX], ll mp[1000006])
{
	ll i,j;
	dit[0][0]=todo[0][0];
	pit[0][0]=0;
	FOR(i,1,m)
	{
		dit[0][i]=dit[0][i-1]+todo[0][i];
		pit[0][i]=1;
	}
	FOR(i,1,n)
	{
		dit[i][0]=dit[i-1][0]+todo[i][0];
		pit[i][0]=2;
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(dit[i-1][j]>dit[i][j-1])
				pit[i][j]=2;
			else
				pit[i][j]=1;
			dit[i][j]=todo[i][j]+max(dit[i-1][j], dit[i][j-1]);
		}
	}
	ll v1=n-1, v2=m-1;
	minit=todo[v1][v2];
	ans=todo[v1][v2];
	while(pit[v1][v2]!=0)
	{
		if(pit[v1][v2]==1)
			v2--;
		else
			v1--;
		mp[todo[v1][v2]]=1;
		ans+=todo[v1][v2];
		//trace3(v1,v2,pit[v1][v2]);
	}
	trace1(dit[n-1][m-1]);
}
ll copymat1(ll dit[MAX][MAX], ll pit[MAX][MAX], ll todo[MAX][MAX], ll mp[1000006])
{
	ll i,j;
	dit[n-1][0]=todo[n-1][0];
	pit[n-1][0]=0;
	FOR(i,1,m)
	{
		dit[n-1][i]=dit[n-1][i-1]+todo[n-1][i];
		pit[n-1][i]=1;
	}
	for(i=n-2;i>=0;i--)
	{
		dit[i][0]=dit[i+1][0]+todo[i][0];
		pit[i][0]=2;
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=1;j<m;j++)
		{
			if(dit[i+1][j]>dit[i][j-1])
				pit[i][j]=2;
			else
				pit[i][j]=1;
			dit[i][j]=todo[i][j]+max(dit[i+1][j], dit[i][j-1]);
		}
	}
	ll v1=0, v2=m-1;
	minit=todo[v1][v2];
	ans=todo[v1][v2];
	while(pit[v1][v2]!=0)
	{
		if(pit[v1][v2]==1)
			v2--;
		else
			v1++;
		mp[todo[v1][v2]]=1;
		ans+=todo[v1][v2];
		//trace3(v1,v2,pit[v1][v2]);
	}
}
int main()
{
	ll i,j,val,fin,temp;
	sl(n); sl(m);
	rep(i,n)
		rep(j,m)
			sl(arr[i][j]);
	copymat(dp1, p1, arr, mp1);
	fin = ans;
	trace1(ans);
	copymat1(dp1, p1, arr, mp2);
	trace1(ans);
	fin+=ans;
	FOR(i,0,1000006)
	{
		if(mp1[i]!=0 && mp2[i]!=0)
		{
			trace1(i);
			fin-=2*i;
			break;
		}
	}
	pln(fin);
	return 0;
}













