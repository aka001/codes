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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<map<ll,ll> > strit;
ll arr[100005],brr[1000006],crr[1000006],cnt=0;
map<ll,ll> mapit;
vector< pair<ll,ll> > pairit;
int compare(pair<ll,ll> s1, pair<ll,ll> s2)
{
	return s1.first<s2.first;
}
void merge_them(vector< pair<ll,ll> > pairit,ll m)
{
	ll fir,sec,i,val1,val2;
	fir=pairit[0].first;
	sec=pairit[0].second;
	//printf("fir=%d sec=%d\n",fir,sec);
	brr[0]=fir;
	crr[0]=sec;
	cnt++;
	//printf("m=%d\n",m);
	FOR(i,1,m)
	{
		fir=pairit[i].first;
		sec=pairit[i].second;
		val1=brr[cnt-1];
		val2=crr[cnt-1];
		//printf("val1=%d val2=%d fir=%d sec=%d\n",val1,val2,fir,sec);
		if(val2<fir)
		{
			//printf("fir=%d sec=%d\n",fir,sec);
			brr[cnt]=fir;
			crr[cnt]=sec;
			cnt++;
		}
		else if(val2<sec)
		{
			brr[cnt]=fir;
			crr[cnt]=sec;
			cnt++;
		}
	}
}
int main()
{
	ll sz,i,n,d,val,val1,ans=0,gap;
	sl(n);
	sl(d);
	FOR(i,1,n+1)
	{
		sl(arr[i]);
		mapit[arr[i]]=i;
	}
	FOR(i,1,n)
	{
		val=arr[i];
		val1=val+d;
		if(mapit[val1]!=0)
		{
			val1=mapit[val1];
			pairit.pb(mp(i,val1));
		}
	}
	sort(pairit.begin(),pairit.end(),compare);
	sz=pairit.size();
	/*rep(i,sz)
		printf("%lld %lld\n",pairit[i].first,pairit[i].second);*/
	//printf("%d %d\n",pairit[0].first,pairit[0].second);
	merge_them(pairit,sz);
	/*rep(i,sz)
	{
		brr[i]=pairit[i].first;
		crr[i]=pairit[i].second;
	}*/
	ans+=brr[0]+n-crr[0];
	//printf("%lld\n",ans);
	val=crr[0];
	//printf("%lld\n",ans);
	gap=0;
	FOR(i,1,cnt)
	{
		ans+=brr[i]+n-crr[i]-i;
		//ans+=gap;
		//gap+=brr[i]-crr[i-1];
		val=crr[i];
		//printf("%lld\n",ans);
	}
	pln(ans);
	return 0;
}















