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
#define mod (ll)(1e9 + 7)
#define ll long long int
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
#define MAX 2000006

ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
typedef struct nodeit
{
	ll lv, rv, l, r, a;
}nodeit;
nodeit arr[MAX];
ll n,vit[MAX],mit;
char ch[MAX];
nodeit query(ll,ll,ll,ll,ll);
void initialize(ll node, ll l, ll u)
{
	if(l==u)
	{
		arr[node].lv=arr[node].rv=vit[l];
		arr[node].l=arr[node].r=arr[node].a=1;
	}
	else
	{
		initialize(2*node,l,(l+u)/2);
		initialize(2*node+1, (l+u)/2+1, u);
		arr[node].r=arr[2*node+1].r; arr[node].l=arr[2*node].l;
		arr[node].a=max(arr[2*node].a, arr[2*node+1].a);
		arr[node].lv=arr[2*node].lv; arr[node].rv=arr[2*node+1].rv;
		if(arr[2*node].rv<arr[2*node+1].lv)
		{
			if(arr[2*node+1].l==arr[2*node+1].r)
				arr[node].r+=arr[2*node].r;
			if(arr[2*node].l==arr[2*node].r)
				arr[node].l+=arr[2*node+1].l;
			arr[node].a=max(arr[node].a, arr[2*node].r+arr[2*node+1].l);
		}
		arr[node].a=max(arr[node].a, max(arr[node].l, arr[node].r));
	}
}
void update(ll node, ll p, ll q, ll a, ll b, ll val)
{
	if(p>b || q<a || p>q)
		return;
	if(p>=a && q<=b)
	{
		arr[node].lv+=val;
		arr[node].rv+=val;
		return;
	}
	update(2*node, p, (p+q)/2, a, b, val);
	update(2*node+1, (p+q)/2+1, q, a, b, val);
	arr[node].r=arr[2*node+1].r; arr[node].l=arr[2*node].l;
	arr[node].a=max(arr[2*node].a, arr[2*node+1].a);
	arr[node].lv=arr[2*node].lv; arr[node].rv=arr[2*node+1].rv;
	if(arr[2*node].rv<arr[2*node+1].lv)
	{
		if(arr[2*node+1].l==arr[2*node+1].r)
			arr[node].r+=arr[2*node].r;
		if(arr[2*node].l==arr[2*node].r)
			arr[node].l+=arr[2*node+1].l;
		arr[node].a=max(arr[node].a, arr[2*node].r+arr[2*node+1].l);
	}
	arr[node].a=max(arr[node].a, max(arr[node].l, arr[node].r));
}
nodeit query(ll node, ll p, ll q, ll a, ll b)
{
	if(p>b || q<a || p>q)
	{
		nodeit temp;
		temp.l=temp.r=0;
		temp.lv=temp.rv=temp.a=-mit;
		return temp;
	}
	else if(p>=a && q<=b)
		return arr[node];
	else
	{
		nodeit p1,p2;
		p1=query(2*node, p, (p+q)/2, a, b);
		p2=query(2*node+1, (p+q)/2+1, q, a, b);
		nodeit temp;
		temp.r=p2.r;
		temp.l=p1.l;
		temp.a=max(p1.a, p2.a);
		temp.lv=p1.lv; temp.rv=p2.rv;
		if(p1.rv<p2.lv)
		{
			if(p2.l==p2.r)
				temp.r+=p1.r;
			if(p1.l==p1.r)
				temp.l+=p2.l;
			temp.a=max(temp.a, p1.r+p2.l);
		}
		temp.a=max(temp.a, max(temp.l, temp.r));
		return temp;
	}
}
int main()
{
	ll q,i,val,val1,val2,sz,flag,t;
	mit=mod*mod;
	sl(t);
	while(t--)
	{
		sl(n); sl(q);
		rep(i,n)
			sl(vit[i]);
		initialize(1,0,n-1);
		rep(i,q)
		{
			sl(val); sl(val1); sl(val2);
			if(val==1)
			{
				update(1,0,n-1,val1-1,val1-1,val2);
			}
			else
			{
				nodeit calc;
				calc=query(1,0,n-1,val1-1,val2-1);
				pln(calc.a);
			}
		}
	}
	return 0;
}
