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
#define ll long long
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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
int arr[MAX], brr[MAX];
vector<pair<int,int> > vec;
int flag[203], temp[203];
int main()
{
	int n,i,j,k,ans=mod,tot=0,sum=0,calc,cnt,c1,s1;
	si(n);
	rep(i,n)
		si(arr[i]);
	rep(i,n)
	{
		si(brr[i]);
		tot+=brr[i];
	}
	rep(i,n)
	{
		vec.pb(mp(arr[i], brr[i]));
	}
	sort(vec.begin(), vec.end());
	i=0;
	while(i<n)
	{
		calc=vec[i].F;
		j=i+1;
		cnt=1;
		sum=0;
		sum+=vec[i].S;
		FOR(k,0,201)
			temp[k]=0;
		temp[vec[i].S]++;
		while(j<n && vec[i].F==vec[j].F)
		{
			sum+=vec[j].S;
			temp[vec[j].S]++;
			cnt++;
			j++;
		}
		i=j;
		cnt--;
		c1=cnt; s1=sum;
		for(k=200; k>=0; k--)
		{
			if(cnt==0)
				break;
			calc = flag[k];
			if(calc>cnt)
			{
				calc=cnt;
				cnt=0;
			}
			else
				cnt-=calc;
			sum+=calc*k;
		}
		//trace6(i, c1, s1, tot, sum, tot-sum);
		rep(k,201)
			flag[k]+=temp[k];
		ans = min(ans, tot-sum);
	}
	pin(ans);
	return 0;
}













