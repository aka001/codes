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
vector<string> ch;
int findminimum1()
{
	int i,j,ans,flag,k;
	ans = mod;
	rep(i,8)
	{
		rep(j,8)
		{
			if(ch[i][j] == 'B')
			{
				flag=1;
				FOR(k,i+1,8)
				{
					if(ch[k][j]!='.')
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					ans = min(ans, 7-i);
				}
			}
		}
	}
	return ans;
}
int findminimum2()
{
	int i,j,ans,flag,k;
	ans = mod;
	rep(i,8)
	{
		rep(j,8)
		{
			if(ch[i][j] == 'W')
			{
				flag=1;
				for(k=i-1; k>=0; k--)
				{
					if(ch[k][j]!='.')
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					ans = min(ans, i);
				}
			}
		}
	}
	return ans;
}
int main()
{
	int i,j,c1,c2;
	rep(i,8)
	{
		string temp;
		cin>>temp;
		ch.pb(temp);
	}
	c1 = findminimum1();
	c2 = findminimum2();
	trace2(c1, c2);
	if(c2<=c1)
		cout<<"A"<<endl;
	else
		cout<<"B"<<endl;
	return 0;
}

