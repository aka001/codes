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
int val[MAX],vis[MAX];
char c1[MAX], c2[MAX], aka;
int main()
{
	int t,n,t1,t2,i,j,cnt=0,tit,calc;
	si(n); si(t);
	tit=t;
	ss(c1);
	ss(c2);
	rep(i,n)
	{
		if(c1[i]!=c2[i])
			cnt++;
		val[i]=c1[i]-'a';
	}
	int flag=0;
	if(t<cnt)
	{
		rep(i,n)
		{
			if(c1[i]!=c2[i])
			{
				if(flag%2==0)
					val[i]=c1[i]-'a';
				else
					val[i]=c2[i]-'a';
				flag=1-flag;
				vis[i]=1;
			}
		}
		calc = cnt/2;
		t-=calc;
		rep(i,n)
		{
			if(t==0)
			{
				break;
			}
			if(vis[i]!=1)
			{
			FOR(j,0,26)
			{
				t1 = c1[i] - 'a';
				t2 = c2[i] - 'a';
				//trace3(i,t1,t2);
				if(j!=t1 && j!=t2)
				{
					val[i]=j;
					t--;
					break;
				}
			}
			vis[i]=1;
			}	
		}
		trace1(t);
		if(t!=0)
		{
			printf("-1\n");
			return 0;
		}
	}
	else
	{
	rep(i,n)
	{
		if(c1[i]!=c2[i])
		{
			FOR(j,0,26)
			{
				t1 = c1[i] - 'a';
				t2 = c2[i] - 'a';
				//trace3(i,t1,t2);
				if(j!=t1 && j!=t2)
				{
					val[i]=j;
					break;
				}
			}
		}
	}
	t-=cnt;
	rep(i,n)
	{
		if(t==0)
			break;
		//trace2(i, t);
		if(c1[i]==c2[i])
		{
			FOR(j,0,26)
			{
				t1=c1[i]-'a';
				if(t1!=j)
				{
					val[i]=j;
					t--;
					break;
				}
			}
		}
	}
	}
	if(t!=0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	string fin="";
	int cnt1, cnt2;
	cnt1=cnt2=0;
	rep(i,n)
	{
		aka = val[i]+'a';
		fin+=aka;
		if(aka!=c1[i])
			cnt1++;
		if(aka!=c2[i])
			cnt2++;
	}
	if(cnt1==tit && cnt2==tit)
		cout<<fin<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}













