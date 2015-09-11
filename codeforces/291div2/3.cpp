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
#define mod1 (ll)(1e8 + 7)
#define mod2 (ll)(1e8 + 7)
//#define mod2 (ll)(1e9 + 67)
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
map<pair<ll,ll>, int> mapit;
ll pow261[MAX], pow262[MAX];
char ch[MAX], pre[4];
ll checkit(ll a, ll b)
{
	if(a<0)
	{
		a*=-1;
		a*=(b-1);
	}
	a%=b;
	return a;
}
int main()
{
	int n,m,i,sz,j,k,flag;
	ll c1,c2,v1,v2,val1,val2,or1,or2;
	pre[0]='a'; pre[1]='b'; pre[2]='c';
	si(n);
	si(m);
	rep(i,n)
	{
		ss(ch);
		sz=strlen(ch);
		c1=c2=0;
		rep(j,sz)
		{
			c1=c1*26+ch[j];
			c2=c2*26+ch[j];
			c1%=mod1; c2%=mod2;
		}
		mapit[mp(c1,c2)]=1;
	}
	rep(i,m)
	{
		ss(ch);
		//trace1(ch);
		sz=strlen(ch);
		c1=c2=0;
		rep(j,sz)
		{
			c1=c1*26+ch[j];
			c2=c2*26+ch[j];
			c1%=mod1; c2%=mod2;
		}
		//trace3(c1, c2, sz);
		flag=0;
		rep(j,sz)
		{
			//if(j!=2)
			//	continue;
			v1=modpow(26, sz-j-1, mod1);
			v2=modpow(26, sz-j-1, mod2);
			val1 = c1-(v1*ch[j])%mod1;
			val2 = c2-(v2*ch[j])%mod2;
			val1=checkit(val1, mod1); val2=checkit(val2, mod2);
			//trace2(val1, val2);
			rep(k,3)
			{
				if(pre[k]==ch[j])
					continue;
				//trace4(j, k, ch[j], pre[k]);
				or1=val1; or2=val2;

				val1+=(v1*pre[k])%mod1;
				val2+=(v2*pre[k])%mod2;
				val1%=mod1; val2%=mod2;
				//trace2(val1, val2);
				if(mapit.find(mp(val1,val2))!=mapit.end())
				{
					flag=1;
					break;
				}

				val1=or1; val2=or2;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}













