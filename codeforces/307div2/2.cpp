/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
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
#define mod (int)(1e9 + 7)
#define ll long long
#define MAX 1000006
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
char c[3][MAX];
int s[3],arr[3][26],f[26];
int val(int i1, int i2)
{
	int flag=1,cnt=0,i,val;
	while(1)
	{
		flag=1;
		rep(i,26)
		{
			val=arr[i1][i]-arr[i2][i];
			if(val<0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			rep(i,26)
				arr[i1][i]-=arr[i2][i];
		}
		else
			break;
		cnt++;
	}
	return cnt;
}
int main()
{
	int i,s1,s2,s3,a1,a2,j,c1,c2,c3,c4,sz,cnt,fl=0;
	string ans="";
	ss(c[0]);
	ss(c[1]);
	ss(c[2]);
	rep(i,3)
	{
		s[i]=strlen(c[i]);
		rep(j,s[i])
			arr[i][c[i][j]-'a']++;
	}
	//Method 1
	rep(i,26)
		f[i]=arr[0][i];
	c1=val(0,1); c2=val(0,2);
	a1 = c1+c2;
	rep(i,26)
		arr[0][i]=f[i];
	c3=val(0,2); c4=val(0,1);
	a2 = c3+c4;
	rep(i,26)
		arr[0][i]=f[i];
	if(a1<a2)
	{
		c1=c4;
		c2=c3;
		fl=1;
	}
	rep(i,c1)
	{
		sz=strlen(c[1]);
		rep(j,sz)
			ans+=c[1][j];
	}
	rep(i,c2)
	{
		sz=strlen(c[2]);
		rep(j,sz)
			ans+=c[2][j];
	}
	if(fl==0)
		cnt = val(0,1) + val(0,2);
	else
		cnt = val(0,2) + val(0,1);
	rep(i,26)
	{
		rep(j,arr[0][i])
			ans+=('a'+i);
	}
	cout<<ans<<endl;
	return 0;
}













