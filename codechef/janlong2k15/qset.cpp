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
#include<cassert>
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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
char ch[1000006];
ll seg[1000006][3],sg[1000006],brr[4];
vector<ll> arr,crr;
void initialize(ll node, ll a, ll b)
{
	if(a==b)
	{
		seg[node][arr[a]%3]++;
	//	printf("a=%lld arr[a]=%lld val=%lld\n",a,arr[a],seg[node][arr[a]%3]);
	}
	else
	{
		ll i;
		initialize(2*node,a,(a+b)/2);
		initialize(2*node+1,(a+b)/2+1,b);
		//printf("a=%d b=%d\n",a,b);
		rep(i,3)
		{
			seg[node][i]=seg[2*node][i]+seg[2*node+1][i];
			//printf("i=%d %d\n",i,seg[node][i]);
		}
	}
}
void update(ll node,ll p,ll q,ll a,ll b,ll doit)
{
	if(sg[node])
	{
		ll i,calc,val;
		rep(i,3)
		{
			calc=seg[node][i];
			val=(i+sg[node])%3;
			brr[val]=calc;
		}
		rep(i,3)
			seg[node][i]=brr[i];
		if(p!=q)
		{
			sg[2*node]+=sg[node];
			sg[2*node+1]+=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a || p>q)
	{
		return;
	}
	if(p==q)
	{
		if(p>=a && q<=b)
		{
			//printf("p=q=%lld a=%lld b=%lld doit=%lld\n",p,a,b,doit);
			ll i,calc,val;
			//printf("p=%lld q=%lld doit=%lld\n",p,q,doit);
			//printf("old=======\n");
			rep(i,3)
			{
				//printf("i=%lld %lld\n",i,seg[node][i]);
				calc=seg[node][i];
				val=(i+doit)%3;
				brr[val]=calc;
			}
			//printf("new=========\n");
			rep(i,3)
			{
				//printf("i=%lld %lld\n",i,brr[i]);
				seg[node][i]=brr[i];
			}
		}
		return;
	}
	if(p>=a && q<=b)
	{
		ll i,calc,val;
		rep(i,3)
		{
			calc=seg[node][i];
			val=(i+doit)%3;
			brr[val]=calc;
		}
		rep(i,3)
			seg[node][i]=brr[i];
		sg[2*node]+=doit;
		sg[2*node+1]+=doit;
		//printf("p=%lld q=%lld doit=%lld  %lld %lld\n",p,q,doit,sg[2*node],sg[2*node+1]);
		return;
	}
	update(2*node,p,(p+q)/2,a,b,doit);
	update(2*node+1,(p+q)/2+1,q,a,b,doit);
	ll i;
	rep(i,3)
	{
		seg[node][i]=seg[2*node][i]+seg[2*node+1][i];
	}
}
typedef struct need
{
	ll a[3];
}need;
need query(ll node,ll p,ll q,ll a,ll b)
{
	if(sg[node])
	{
		//intf("sg[node]=%lld p=%lld q=%lld\n",sg[node],p,q);
		ll calc,val,i;
		//intf("old============\n");
		rep(i,3)
		{
			//printf("i=%lld %lld\n",i,seg[node][i]);
			calc=seg[node][i];
			val=(i+sg[node])%3;
			brr[val]=calc;
		}
		rep(i,3)
		{
			seg[node][i]=brr[i];
		}
		if(p!=q)
		{
			sg[2*node]+=sg[node];
			sg[2*node+1]+=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a || p>q)
	{
		need stud;
		ll i;
		rep(i,3)
		{
			stud.a[i]=0;
		}
		return stud;
	}
	else if(p>=a && q<=b)
	{
		need stud;
		ll i;
		//printf("p=%d q=%d\n",p,q);
		rep(i,3)
		{
			//printf("i=%d  %d\n",i,seg[node][i]);
			stud.a[i]=seg[node][i];
		}
		return stud;
	}
	else
	{
		need c1,c2,c;
		ll i;
		c1=query(2*node,p,(p+q)/2,a,b);
		c2=query(2*node+1,(p+q)/2+1,q,a,b);
		rep(i,3)
			c.a[i]=c1.a[i]+c2.a[i];
		return c;
	}
}
inline ll checkit(ll calc)
{
	while(calc<0)
		calc+=3;
	return calc%3;
}
int main()
{
	ll n,m,i,sz,j;
	ll ans=0,calc,val,v1,v2,c;
	sl(n);
	sl(m);
	ss(ch);
	sz=strlen(ch);
	arr.pb(0);
	rep(i,sz)
	{
		arr.pb(ch[i]-'0');
	}
	FOR(i,0,sz+1)
	{
		if(i==0)
			arr[i]=arr[i]%3;
		else
			arr[i]=(arr[i-1]*10+arr[i])%3;
		//printf("i=%d arr[i]=%d\n",i,arr[i]);
	}
	crr.pb(0);
	rep(i,sz)
	{
		crr.pb((ch[i]-'0')%3);
		//printf("i=%lld %lld %d\n",i+1,crr[i+1],ch[i]-'0');
	}
	initialize(1,0,sz);
	rep(i,m)
	{
		sl(val);
		sl(v1);
		sl(v2);
		//printf("===============%lld %lld %lld================\n",val,v1,v2);
		if(val==1)
		{
			need it;
			it=query(1,0,sz,v1,v1);
			rep(j,3)
			{
				if(it.a[j]!=0)
				{
					calc=j;
					break;
				}
			}
			c=calc;
			//calc=v2-(ch[v1-1]-'0');
			calc=v2-crr[v1];
			crr[v1]=v2%3;
			calc=checkit(calc);
			//printf("calc=%lld v1=%lld v2=%lld crr[v1]=%lld\n",calc,v1,v2,crr[v1]);
			//printf("val=%lld v1=%lld c=%lld calc=%lld v2=%lld sz=%lld\n",val,v1,c,calc,v2,sz);
			update(1,0,sz,v1,sz,calc);
		}
		else
		{
			v1--;
			need it;
			ans=0;
			it=query(1,0,sz,v1,v2);
			//printf("v1=%lld v2=%lld\n",v1,v2); 
			rep(j,3)
			{
				calc=it.a[j];
				//printf("j=%lld calc=%lld\n",j,calc);
				calc=(calc*(calc-1))/2;
				ans+=calc;
			}
			/*if(ans<0)
				assert(-1>0);*/
			pln(ans);
		}
	}
	return 0;
}















