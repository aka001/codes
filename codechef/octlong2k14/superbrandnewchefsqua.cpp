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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll arr[2002][2002];
vector<pair<ll,ll> > str,str1;
vector<pair<ll,ll> > dist[2002];
vector<ll> ondist[200005],from[200005];
int main()
{
	ll n,i,j,val,val1,dt,k,sz,ans,low,mid,high,lb,hb,j1,lb1,hb1,calcit,ans1,dt2;
	sl(n);
	rep(i,n)
	{
		sl(val);
		sl(val1);
		str1.pb(mp(val,val1));
		str.pb(mp(val,val1));
	}
	/*sort(str1.begin(),str1.end());
	rep(i,n)
	{
		//printf("%lld %lld\n",str1[i].F,str1[i].S);
		if(i==n-1 || (str1[i].F!=str1[i+1].F || str1[i].S!=str1[i+1].S))
			str.pb(str1[i]);
	}*/
	ans=4;
//	if(n==0)
//		ans=4;
//	else if(n==1)
//		ans=3;
//	else
//		ans=2;
	rep(i,n)
	{
		//printf("i=%lld x=%lld y=%lld\n",i,str[i].F,str[i].S);
		FOR(j,i+1,n)
		//FOR(j,i+1,n)
		{
			dt=(str[j].S-str[i].S)*(str[j].S-str[i].S)+(str[j].F-str[i].F)*(str[j].F-str[i].F);
			arr[i][j]=dt;
			arr[j][i]=dt;
			dist[i].pb(mp(dt,j));
			dist[j].pb(mp(dt,i));
		}
	}	
	rep(i,n)
	{
		sort(dist[i].begin(),dist[i].end());
		sz=dist[i].size();
		rep(j,sz)
		{
			ondist[i].pb(dist[i][j].F);
			from[i].pb(dist[i][j].S);
		}
	}
	rep(i,n)
	{
		FOR(j,i+1,n)
		{
			dt=arr[i][j];
			dt2=dt/2.0;
			sz=dist[i].size();
			lb=lower_bound(ondist[i].begin(),ondist[i].end(),dt2)-ondist[i].begin();
			hb=upper_bound(ondist[i].begin(),ondist[i].end(),dt2)-ondist[i].begin();
			//m1=findslope(str[i].F,str[i].S,str[j].F,str[j].S);
			//printf("i=%lld j=%lld dt=%lld sz=%lld\n",i,j,dt,sz);
			/*low=0;
			high=sz-1;
			lb=-1;
			hb=-1;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(dist[j][mid].F==dt2 && (mid==sz-1 || dist[j][mid+1].F>dt2))
				{
					hb=mid;
					break;
				}
				else if(dt2>=dist[j][mid].F)
					low=mid+1;
				else
					high=mid-1;
			}
			low=0;
			high=sz-1;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(dist[j][mid].F==dt2 && (mid==0 || dist[j][mid-1].F<dt2))
				{
					lb=mid;
					break;
				}
				else if(dt2>dist[j][mid].F)
					low=mid+1;
				else
					high=mid-1;
			}*/
			//printf("i=%lld j=%lld dist=%lld lb=%lld hb=%lld\n",i,j,dt,lb,hb);
			/*if(hb!=-1)
			  printf("value=%lld\n",dist[j][hb].F);*/
			ans1=2;
	//		if(lb==hb)
	//			continue;
			while(lb<hb)
			{
				val=from[i][lb];
				val1=(str[val].S-str[j].S)*(str[val].S-str[j].S)+(str[val].F-str[j].F)*(str[val].F-str[j].F);
				//printf("i=%lld j=%lld val=%lld val1=%lld\n",i,j,val,val1);
				if(val1==dt2) //&& val!=i && val!=j)
				{
					ans1--;
				}
				if(ans1==0)
					break;
				lb++;
			}
			ans=min(ans,ans1);
			if(ans==0)
				break;
		}
		if(ans==0)
			break;
	}
	if(n==0)
		printf("4\n");
	else if(n==1)
		printf("3\n");
	else
		pln(ans);
	return 0;
}

















