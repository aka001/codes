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
#define FOR(i,a,b) for(int i= a ; i < b ; ++i)
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
int cntit[1000006][3];
int main()
{
	int m,i,maxit,minit,val,v1,v2,v3,sizeit,cnt,l,r;
	ss(ch);
	sizeit=strlen(ch);
	rep(i,sizeit)
	{
		if(ch[i]=='x')
		{
			cntit[i][0]=cntit[i-1][0]+1;
			cntit[i][1]=cntit[i-1][1];
			cntit[i][2]=cntit[i-1][2];
		}
		else if(ch[i]=='y')
		{
			cntit[i][0]=cntit[i-1][0];
			cntit[i][1]=cntit[i-1][1]+1;
			cntit[i][2]=cntit[i-1][2];
		}
		else
		{
			cntit[i][0]=cntit[i-1][0];
			cntit[i][1]=cntit[i-1][1];
			cntit[i][2]=cntit[i-1][2]+1;
		}
	}
	si(m);
	rep(i,m)
	{
		si(l);
		si(r);
		l--;
		r--;
		if(l!=-1)
		{
			v1=cntit[r][0]-cntit[l-1][0];
			v2=cntit[r][1]-cntit[l-1][1];
			v3=cntit[r][2]-cntit[l-1][2];
		}
		else
		{
			v1=cntit[r][0];
			v2=cntit[r][1];
			v3=cntit[r][2];
		}
		cnt=v1+v2+v3;
		//printf("cnt=%d\n",cnt);
		if(cnt<3)
		{
			printf("YES\n");
			continue;
		}
		if(cnt%3==0)
		{
			if(v1==cnt/3 && v2==cnt/3 && v3==cnt/3)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(cnt%3==1)
		{
			maxit=v1;
			minit=v1;
			maxit=max(maxit,v2);
			maxit=max(maxit,v3);
			minit=min(minit,v2);
			minit=min(minit,v3);
			val=cnt-minit-maxit;
			if(maxit==(cnt/3+1) && minit==cnt/3 && val==cnt/3)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			maxit=v1;
			minit=v1;
			maxit=max(maxit,v2);
			maxit=max(maxit,v3);
			minit=min(minit,v2);
			minit=min(minit,v3);
			val=cnt-minit-maxit;
			if(maxit==(cnt/3+1) && val==(cnt/3+1) && minit==cnt/3)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}









