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
struct Comp
{
	bool operator()(const pair<int,int> s1, const pair<int,int> s2)
	{
		return s1.S<s2.S;
	}
};
int latest[1000006],flag[1000006];
int xit[1000006];
vector<int> arr[500006];
int main()
{
	int t,i,n,m,j,x,start,end,val,chck,curr,cnt,el,k,kit;
	si(t);
	while(t--)
	{
		cnt=0;
		pair<int,int> calc,akash;
		set<pair<int,int> > vec;
		//make_heap(vec.begin(),vec.end(),Comp());
		si(n);
		si(m);
		rep(i,m+1)
		{
			flag[i]=0;
		}
		start=-1;
		end=-1;
		curr=-1;
		rep(i,n)
		{
			arr[i].clear();
			si(xit[i]);
			rep(j,xit[i])
			{
				si(val);
				arr[i].pb(val);
			}
		}
		rep(i,n)
		{
			rep(j,xit[i])
			{
				val=arr[i][j];
				if(flag[val]==0)
					cnt++;
				flag[val]=1;
				latest[val]=i;
			}
			if(cnt==m)
			{
				start=0;
				end=i;
				curr=end-start;
				break;
			}
		}
		FOR(i,1,m+1)
		{
			vec.insert(mp(latest[i],i));
		}
		rep(i,n)
		{
			calc=*(vec.begin());
			if(calc.F>=i)
			{
				//printf("%d %d\n",i+1,end+1);
				start=i;
			}
			else
			{
				el=curr-1;
				el+=end;
				if(el>=n-1)
				{
					el=n-1;
				}
				j=min(end+1,n-1);
				while(1)
				{
					kit=arr[j].size();
					//printf("i=%d %d %d j=%d kit=%d\n",i,akash.F,start,j,kit);
					rep(k,kit)
					{
						//printf("j=%d k=%d latest=%d arr[j][k]=%d\n",j,k,latest[arr[j][k]],arr[j][k]);
						vec.erase(vec.find(mp(latest[arr[j][k]],arr[j][k])));
						latest[arr[j][k]]=j;
						vec.insert(mp(latest[arr[j][k]],arr[j][k]));
					}
					akash=*(vec.begin());
					if(akash.F>start)
					{
						start=akash.F;
						curr=end-start+1;
						printf("%d %d\n",min(i,start)+1,end+1);
						break;
					}
					else
					{
						printf("%d %d\n",start+1,end+1);
						break;
					}
					j++;
					if(j>el)
					{
						break;
					}
				}
			}
			if(start==-1)
				printf("-1\n");
		}
	}
	return 0;
}











