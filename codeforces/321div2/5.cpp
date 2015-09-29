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
char ch[MAX];
ll arr[MAX],sg[MAX],pref[MAX],n,m,k,hashit[10][MAX];
ll query(ll,ll,ll,ll,ll);
void initialize(ll node, ll l, ll u)
{
	if(l==u)
	{
		arr[node]=ch[l]-'0';
	}
	else
	{
		initialize(2*node,l,(l+u)/2);
		initialize(2*node+1, (l+u)/2+1, u);
		ll lit=u-((l+u)/2+1)+1, calc;
		calc=modpow(11,lit,mod);
		arr[node]=calc*arr[2*node]+arr[2*node+1];
		arr[node]%=mod;
	}
}
ll assignit(ll node1, ll node2)
{
	if(pref[node2]<=pref[node1])
	{
		pref[node2]=pref[node1];
		sg[node2]=sg[node1];
	}
}
void update(ll node, ll p, ll q, ll a, ll b, ll val, ll toup)
{
	if(pref[node]) //If the node is lazy affected
	{
		ll lit=q-p+1;
		arr[node]=hashit[sg[node]][lit]; //Updating the value of the node
		if(p!=q)
		{
			assignit(node, 2*node);
			assignit(node, 2*node+1);
		}
		sg[node]=0;
		pref[node]=0;
	}
	if(p>b || q<a || p>q)
		return;
	if(p>=a && q<=b)
	{
		//trace4(p,q,a,b);
		ll lit=q-p;
		//trace4(p,q,a,b);
		arr[node]=hashit[toup][lit];
		//trace4(toup, lit, hashit[toup][lit], arr[node]);
		pref[node]=val;
		if(p!=q)
		{
			assignit(node,2*node);
			assignit(node,2*node+1);
		}
		pref[node]=0;
		return;
	}
	update(2*node, p, (p+q)/2, a, b, val, toup);
	update(2*node+1, (p+q)/2+1, q, a, b, val, toup);
	ll lit=q-((p+q)/2+1)+1;
	arr[node]=modpow(11,lit,mod)*arr[2*node]+arr[2*node+1];
	arr[node]%=mod;
}
ll query(ll node, ll p, ll q, ll a, ll b)
{
	if(pref[node]) //If the node is lazy affected
	{
		ll lit=q-p+1;
		arr[node]=hashit[sg[node]][lit]; //Updating the value of the node
		if(p!=q)
		{
			assignit(node, 2*node);
			assignit(node, 2*node+1);
		}
		sg[node]=0;
		pref[node]=0;
	}
	if(p>b || q<a || p>q)
		return -1;
	else if(p>=a && q<=b)
		return arr[node];
	else
	{
		ll p1,p2,lit;
		p1=query(2*node, p, (p+q)/2, a, b);
		p2=query(2*node+1, (p+q)/2+1, q, a, b);
		ll calc;
		if(p2==-1)
			calc=p1;
		else if(p1==-1)
			calc=p2;
		else
		{
			ll l=(p+q)/2+1, h=q;
			l=max(l,a); h=min(h, b);
			lit=h-l+1;
			calc=modpow(11,lit,mod)*p1+p2;
		}
		//trace5(p,q,a,b,calc);
		calc%=mod;
		return calc;
	}
}
int main()
{
	ll q,i,val,calc,sz,cnd,c1,c2,j,v1,v2,v3;
	sl(n); sl(m); sl(k);
	ss(ch);
	initialize(1,0,n-1);
	//cin>>q;
	//si(q);
	rep(i,10)
	{
		calc=0;
		rep(j,MAX)
		{
			calc=calc*11+i;
			calc%=mod;
			hashit[i][j]=calc;
		}
	}
	rep(i,m+k)
	{
		sl(cnd); sl(v1); sl(v2); sl(v3);
		v1--; v2--;
		if(cnd==1)
		{
			update(1, 0, n-1, v1, v2, i+1, v3);
		}
		else
		{
			c1=query(1,0,n-1,v1,v2-v3);
			c2=query(1,0,n-1,v1+v3,v2);
			//trace2(c1,c2);
			if(c1==c2)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}













