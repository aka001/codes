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
vector<string> finit;
map<ll,int> mapit;
inline ll hashit(char ch[10])
{
	int sz,i;
	ll calc=0;
	sz=strlen(ch);
	rep(i,sz)
	{
		calc+=modpow(26,i,mod)*ch[i];
		if(calc>mod)
			calc%=mod;
	}
	return calc;
}
int main()
{
	int n,i,sz,sz1=0,j;
	char ch,chit[10],valit[10];
	ll val;
	si(n);
	ch=getchar();
	rep(i,n)
	{
		ss(valit);
		/*ss(chit);
		valit="";
		sz=strlen(chit);
		rep(j,sz)
			valit+=chit[j];*/
		//ss(valit);
		val=hashit(valit);
	//	val=i+1;
		//printf("valit=%s mapit=%d\n",valit,mapit[val]);
		if(mapit[val]==0)
		{
			finit.pb(valit);
			sz1++;
		}
		mapit[val]=1;
	}
	sz=finit.size();
	sort(finit.begin(),finit.end());
	printf("%d\n",sz);
	//cout<<sz<<endl;
	rep(i,sz)
	{
		//cout<<finit[i]<<endl;
		printf("%s\n",finit[i].c_str());
	}
	return 0;
}










