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
vector<int> arr[1002];
int isprime[MAX];
vector<int> ans, primeit;
void seive()
{
	ll i,j;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	FOR(i,2,MAX)
		if(isprime[i]==0)
			primeit.pb(i);
}
int check(int val)
{
	int i,sz,s1,j,flag;
	sz=arr[val].size();
	/*if(val==6)
		trace1(val);
	if(val==6)
	rep(j,sz)
	{
				printf("%d", arr[val][j]);
				if(j!=sz-1)
					printf(" ");
				else
					printf("\n");
		
	}*/
	FOR(i,1,val)
	{
		flag=0;
		rep(j,sz)
		{
			if(arr[val][j]!=arr[i][j])
			{
				flag=1;
			}
		}
		if(flag==0)
			return 0;
	}
	return 1;
}
vector<int> vit;
int main()
{
	seive();
	int n,i,i1,sqit,ait,cnt,sz,j;
	si(n);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	arr[1].pb(0);
	arr[2].pb(1);
	ans.pb(2);
	FOR(i,3,n+1)
	{
		sqit=sqrt(i);
		cnt=0;
		arr[i].clear();
		sz=ans.size();
		//trace2(i, sz);
		rep(j,sz)
		{
			if(i%ans[j]==0)
				arr[i].pb(1);
			else
				arr[i].pb(0);
		}
		//trace2(i, arr[i].size());
		vit.clear();
		vit.pb(1);
		i1=i;
		while(primeit[cnt]<=sqit)
		{
			if(i1%primeit[cnt]==0)
			{
				while(i1%primeit[cnt]==0)
					i1/=primeit[cnt];
				vit.pb(primeit[cnt]);
			}
			cnt++;
		}
		if(i1!=i && i1!=1)
			vit.pb(i1);

		ait=check(i);
		//trace2(i, ait);

		/*sz=vit.size();
		trace1(sz);
		rep(j,sz)
			trace2(j, vit[j]);
		sz=arr[i].size();
		rep(j,sz)
		{
			printf("%d",arr[1][j]);
			if(j!=sz-1)
				printf(" ");
			else
				printf("\n");
		}*/
		if(ait==0)
		{
			ans.pb(i);
			FOR(j,1,1001)
			{
				if(arr[j].size()==0)
					continue;
				if(j%i==0)
					arr[j].pb(1);
				else
					arr[j].pb(0);
			}
		}
	}
	sz=ans.size();
	pin(sz);
	rep(i,sz)
	{
		printf("%d", ans[i]);
		if(i!=sz-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}













