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
#define mod (int)(1e9 + 7)
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
vector<int> arr;
int track[MAX],cnt[3];
int findval(int a, int b)
{
	if(a==b)
		return 0;
	else if(a>b)
		return 1;
	else
		return 2;
}
int main()
{
	int c1,c2,n,i,flag=1,val;
	si(n);
	rep(i,n)
	{
		si(val);
		arr.pb(val);
	}
	if(n==1 || n==2)
	{
		printf("-1\n");
		return 0;
	}
	FOR(i,1,n)
	{
		if(arr[i]==arr[i-1])
			track[i]=0;
		else if(arr[i]>arr[i-1])
			track[i]=1;
		else
			track[i]=2;
	}
	FOR(i,1,n)
		cnt[track[i]]++;
	//trace3(cnt[0],cnt[1],cnt[2]);
	FOR(i,1,n-1)
	{
		cnt[track[i]]--; cnt[track[i+1]]--;
		if(arr[i]!=arr[i-1])
		{
			c1=findval(arr[i-1],arr[i]);
			c2=findval(arr[i+1],arr[i-1]);
			//trace4(i,c1,c2,"1");
			cnt[c1]++;
			cnt[c2]++;
			if(!(cnt[1]==0 || cnt[2]==0))
			{
				printf("%d %d\n",i+1,i);
				return 0;
			}
			cnt[c1]--; cnt[c2]--;
		}
		if(arr[i]!=arr[i+1])
		{
			c1=findval(arr[i+1],arr[i-1]);
			c2=findval(arr[i],arr[i+1]);
			//trace4(i,c1,c2,"2");
			cnt[c1]++; cnt[c2]++;
			if(!(cnt[1]==0 || cnt[2]==0))
			{
				printf("%d %d\n",i+2,i+1);
				return 0;
			}
			cnt[c1]--; cnt[c2]--;
		}
		cnt[track[i]]++; cnt[track[i+1]]++;
	}
	printf("-1\n");
	return 0;
}













