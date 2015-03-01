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
#define MAX 2002
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
double t1[1000006],t2[1000006];
long long int triangle[MAX + 1][MAX + 1];

void makeTriangle() {
	int i, j;

	// initialize the first row
	triangle[0][0] = 1; // C(0, 0) = 1

	for(i = 1; i < MAX; i++) {
		triangle[i][0] = 1; // C(i, 0) = 1
		for(j = 1; j <= i; j++) {
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
	}
}
int main()
{
	int n,t,i,j,c1,c2;
	double p,ans=0,calc;
	makeTriangle();
	si(n);
	sd(p);
	si(t);
	FOR(i,1,1000006)
	{
		if(i==1)
		{
			t1[i]=p;
			t2[i]=1-p;
		}
		else
		{
			t1[i]=p*t1[i-1];
			t2[i]=(1-p)*t2[i-1];
		}
	}
	t1[0]=t2[0]=1;
	FOR(i,1,n+1)
	{
		calc=p;
		for(j=t-1;j>=0;j--)
		{
			c1=i-1;
			c2=j-c1;
			if(c1<0 || c2<0)
				continue;
			//printf("c1=%d c2=%d %lf\n",c1,c2,p*t1[c1]*t2[c2]);
			calc=p*t1[c1]*t2[c2]*triangle[c1+c2][c1];
			ans+=calc;
		}
	}
	printf("%lf\n",ans);
	return 0;
}











