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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<int> arr;
vector<int> split[10];
int main()
{
	int ans=mod,buf=0,t,d,cnt=0,cas=0,i,mx,calc,fl,mxit,smx;
	split[1].pb(1);
	split[2].pb(1); split[2].pb(1);
	split[3].pb(2); split[3].pb(1);
	split[4].pb(2); split[4].pb(2);
	split[5].pb(2); split[5].pb(3);
	split[6].pb(3); split[6].pb(3);
	split[7].pb(3); split[7].pb(4);
	split[8].pb(4); split[8].pb(4);
	split[9].pb(3); split[9].pb(6);
	si(t);
	while(t--)
	{
		arr.clear();
		cas++;
		ans=mod;
		buf=0;
		cnt=0;
		si(d);
		rep(i,d)
		{
			si(calc);
			arr.pb(calc);
		}
		cnt=d;
		while(1)
		{
			sort(arr.begin(), arr.end());
			mx=arr[cnt-1];
			smx=mx;
			i=cnt-2;
			while(i>=0 && arr[i]==mx)
			{
			//	printf("%d ",arr[i]);
				i--;
			}
			//printf("\n");
			if(i!=-1)
				smx=arr[i];
			ans=min(ans, mx+buf);
			//trace6(mx, smx, ans, buf, fl, cnt)
			if(mx==1)
				break;
			rep(i,cnt)
			{
				if(arr[i]==mx)
				{
					buf++;
					if(smx==mx || smx==1)
					{
						arr.pb(split[arr[i]][0]);
						arr[i]=split[arr[i]][1];
					}
					else
					{
						arr.pb(smx);
						arr[i]=mx-smx;
					}
					cnt++;
					//arr[cnt++]=split[arr[i]][0];
					//arr[i]=split[arr[i]][1];
					//calc=arr[i]/2;
					//arr[cnt++]=arr[i]-calc;
					//arr[i]=calc;
					//break;
				}
			}
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}













