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
int arr[MAX],sg[MAX],n,vit[MAX];
char ch[MAX];
int query(int,int,int,int,int);
void initialize(int node, int l, int u)
{
	if(l==u)
	{
		arr[node]=vit[l];
	}
	else
	{
		initialize(2*node,l,(l+u)/2);
		initialize(2*node+1, (l+u)/2+1, u);
		arr[node]=arr[2*node]+arr[2*node+1];
	}
}
void update(int node, int p, int q, int a, int b)
{
	if(sg[node])
	{
		arr[node]=q-p+1-arr[node];
		sg[node]=0;
		if(p!=q)
		{
			sg[2*node]^=1;
			sg[2*node+1]^=1;
		}
	}
	if(p>b || q<a || p>q)
		return;
	if(p==q)
	{
		if(p>=a && p<=b)
			arr[node]^=1;
		arr[node]^=sg[node];
		sg[node]=0;
		return;
	}
	if(p>=a && q<=b)
	{
		arr[node]=q-p+1-arr[node];
		sg[2*node]^=1;
		sg[2*node+1]^=1;
		return;
	}
	update(2*node, p, (p+q)/2, a, b);
	update(2*node+1, (p+q)/2+1, q, a, b);
	arr[node]=arr[2*node]+arr[2*node+1];
}
int query(int node, int p, int q, int a, int b)
{
	if(sg[node])
	{
		arr[node]=q-p+1-arr[node];
		sg[node]^=1;
		if(p!=q)
		{
			sg[2*node]^=1;
			sg[2*node+1]^=1;
		}
	}
	if(p>b || q<a || p>q)
		return 0;
	else if(p>=a && q<=b)
		return arr[node];
	else
	{
		int p1,p2;
		p1=query(2*node, p, (p+q)/2, a, b);
		p2=query(2*node+1, (p+q)/2+1, q, a, b);
		return p1+p2;
	}
}
int main()
{
	int q,i,val,val1,val2,calc,sz,flag;
	si(n); si(q);
	ss(ch);
	sz=strlen(ch);
	FOR(i,1,sz+1)
	{
		if(ch[i-1]=='>')
			vit[i]=1;
		else
			vit[i]=0;
	}
	initialize(1,1,sz);
	vector<int> ansit;
	rep(i,q)
	{
		si(val); si(val1); si(val2);
		if(val==1)
		{
			update(1,1,sz,val1,val2-1);
		}
		else
		{
			if(val1==val2)
			{
				pin(0);
				continue;
			}
			flag=0;
			if(val1>val2)
			{
				flag=1;
				int temp;
				temp=val1;
				val1=val2;
				val2=temp;
			}
			calc=query(1,1,sz,val1,val2-1);
			if(!(flag))
				calc=val2-val1-calc;
			pin(calc);
		}
	}
	return 0;
}













