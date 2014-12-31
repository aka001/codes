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
char ch[3001][3001],ch1[3001][3001],chit[3001];
vector<pair<int,int> > vit;
int main()
{
	int n,m,i,a,b,j;
	si(n);
	si(m);
	rep(i,m)
	{
		cin>>ch[i]>>ch1[i];
		a=strlen(ch[i]);
		b=strlen(ch1[i]);
		vit.pb(mp(a,b));
	}
	rep(i,n)
	{
		cin>>chit;
		for(j=0;j<m;j++)
		{
			if(strcmp(ch[j],chit)==0)
			{
				//cout<<j<<endl;
				//printf("i=%d j=%d %d %d\n",i,j,vit[j].F,vit[j].S);
				if(vit[j].S<vit[j].F)
					cout<<ch1[j];
				else
					cout<<ch[j];
				break;
			}
		}
		if(i!=n-1)
			cout<<" ";
		else
			cout<<endl;
	}
	return 0;
}









