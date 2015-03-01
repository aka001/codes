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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<pair<int,int> > ans;
int vis[1000006],xit[1000006],nit[1000006];
vector<int> grph[1000006];
struct comp
{
	bool operator()(std::pair<int,int> s1, std::pair<int,int> s2)
	{
		return s1.F < s2.F && s1.S == s2.S;
	}
};
set<pair<int,int> > vec;
int main()
{
	int n,cnt=0,a,b,calc,i,c1,cnt1;
	pair<int,int> itit;
	si(n);
	cnt=0;
	rep(i,n)
	{
		si(a);
		si(b);
		if(a==0)
			continue;
		vec.insert(mp(a,i));
		cnt+=a;
		nit[i]=a;
		xit[i]=b;
	}
	cnt1=cnt;
	//make_heap(vec.begin(),vec.end(),comp());
	/*while(!vec.empty())
	  {
	  itit=*(vec.begin());
	  printf("itit.S %d deg=%d\n",itit.S,itit.F);
	  vec.erase(vec.begin());
	  }*/
	cnt1=0;
	while(1)
	{
		if(cnt==0)
		{
			break;
		}
		itit=*(vec.begin());
		vec.erase(vec.begin());
		calc=itit.S;
		c1=xit[calc];
		vec.erase(vec.find(mp(nit[c1],c1)));
		ans.pb(mp(itit.S,xit[itit.S]));
		cnt1++;
		cnt-=2;
		nit[xit[calc]]--;
		xit[c1]=xit[c1]^calc;
		if(nit[c1]>0)
			vec.insert(mp(nit[c1],c1));
		//printf("%d %d  %d %d cnt=%d\n",itit.S,xit[itit.S],nit[xit[itit.S]],xit[xit[itit.S]],cnt);
	}
	printf("%d\n",cnt1);
	rep(i,cnt1)
	{
		printf("%d %d\n",ans[i].F,ans[i].S);
	}
	return 0;
}








