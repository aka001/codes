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
char ch[1000006];
ll create_number()
{
	int i,sz;
	ll calc=0;
	sz=strlen(ch);
	rep(i,sz)
	{
		calc=calc*10+ch[i]-'0';
	}
	return calc;
}
int main()
{
	int t,calc,k,i,j,sz;
	ll max,min,temp;
	si(t);
	rep(k,t)
	{
		ss(ch);
		sz=strlen(ch);
		max=create_number();
		min=create_number();
		rep(i,sz)
		{
			FOR(j,i+1,sz)
			{
				if(i==0 && ch[j]=='0')
					continue;
				temp=ch[i];
				ch[i]=ch[j];
				ch[j]=temp;
				calc=create_number();
				if(calc>max)
					max=calc;
				if(calc<min)
					min=calc;
				temp=ch[i];
				ch[i]=ch[j];
				ch[j]=temp;
			}
		}
		printf("Case #%d: %lld %lld\n",k+1,min,max);
	}
	return 0;
}














