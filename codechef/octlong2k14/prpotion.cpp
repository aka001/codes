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
int arr[3][1000006];
int main()
{
	int t,rit,git,bit,ans,val,m,i,j,sz,grp,grp1;
	si(t);
	while(t--)
	{
		vector<int> sizeit;
		vector<pair<int,int> > S;
		pair<int,int> temp,temp1;
		si(rit);
		si(git);
		si(bit);
		sizeit.pb(rit);
		sizeit.pb(git);
		sizeit.pb(bit);
		si(m);
		rep(i,rit)
		{
			si(arr[0][i]);
		}
		rep(i,git)
		{
			si(arr[1][i]);
		}
		rep(i,bit)
		{
			si(arr[2][i]);
		}
		sort(arr[0],arr[0]+sizeit[0]);
		sort(arr[1],arr[1]+sizeit[1]);
		sort(arr[2],arr[2]+sizeit[2]);
		S.pb(mp(arr[0][rit-1],0));
		S.pb(mp(arr[1][git-1],1));
		S.pb(mp(arr[2][bit-1],2));
		sort(S.begin(),S.end());
		rep(i,m)
		{
			sz=S.size();
			temp=S[sz-1];
			grp=temp.S;
			val=temp.F;
			//printf("val=%d grp=%d\n",val,grp);
			S.erase(S.end());
			sz=sizeit[grp];
			rep(j,sz)
			{
				arr[grp][j]/=2;
			}
			S.pb(mp(arr[grp][sz-1],grp));
			sort(S.begin(),S.end());
		}
		ans=-mod;
		rep(i,3)
		{
			sz=sizeit[i];
			rep(j,sz)
			{
				ans=max(ans,arr[i][j]);
			}
		}
		pin(ans);
	}
	return 0;
}
















