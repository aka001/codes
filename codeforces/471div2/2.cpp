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
vector<pair<int,int> > arr;
vector<pair<int,int> > brr[2009];
int flg[100006];
int main()
{
	int n,fl=0,cnt,i,val,cn=0,sz,j,flag=1;
	si(n);
	rep(i,n)
	{
		si(val);
		arr.pb(mp(val,i+1));
	}
	sort(arr.begin(),arr.end());
	cnt=0;
	rep(i,n)
	{
		if(i==n-1 || arr[i].F!=arr[i+1].F)
		{
			brr[cnt].pb(arr[i]);
			cnt++;
		}
		else
		{
			brr[cnt].pb(arr[i]);
		}
	}
	rep(i,cnt)
	{
		flg[brr[i].size()]++;
	}
	FOR(i,3,20004)
	{
		if(flg[i]>0)
		{
			fl=1;
			break;
		}
	}
	if(fl==1 || flg[2]>=2)
	{
		printf("YES\n");
		cn=0;
		i=0;
		vector<int> prnt,prnt1,prnt2;
		if(flg[2]>=2)
		{
			rep(i,cnt)
			{
				if(brr[i].size()==2)
				{
					if(flag==1)
					{
						prnt.pb(brr[i][0].S);
						prnt.pb(brr[i][1].S);
						prnt1.pb(brr[i][1].S);
						prnt1.pb(brr[i][0].S);
						prnt2.pb(brr[i][0].S);
						prnt2.pb(brr[i][1].S);
						flag=0;
					}
					else
					{
						prnt.pb(brr[i][0].S);
						prnt.pb(brr[i][1].S);
						prnt2.pb(brr[i][1].S);
						prnt2.pb(brr[i][0].S);
						prnt1.pb(brr[i][0].S);
						prnt1.pb(brr[i][1].S);
						flag=2;
					}
				}
				else
				{
					sz=brr[i].size();
					rep(j,sz)
					{
						prnt.pb(brr[i][j].S);
						prnt1.pb(brr[i][j].S);
						prnt2.pb(brr[i][j].S);
					}
				}
			}
			rep(i,n)
			{
				printf("%d",prnt[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n");
			}
			rep(i,n)
			{
				printf("%d",prnt1[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n");
			}
			rep(i,n)
			{
				printf("%d",prnt2[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n");
			}
		}
		else
		{
			vector<int> prnt,prnt1,prnt2;
			flag=1;
			rep(i,cnt)
			{
				if(brr[i].size()>=3 && flag==1)
				{
					prnt.pb(brr[i][0].S);
					prnt.pb(brr[i][1].S);
					prnt.pb(brr[i][2].S);
					prnt1.pb(brr[i][0].S);
					prnt1.pb(brr[i][2].S);
					prnt1.pb(brr[i][1].S);
					prnt2.pb(brr[i][1].S);
					prnt2.pb(brr[i][0].S);
					prnt2.pb(brr[i][2].S);
					sz=brr[i].size();
					FOR(j,3,sz)
					{
						prnt.pb(brr[i][j].S);
						prnt1.pb(brr[i][j].S);
						prnt2.pb(brr[i][j].S);
					}
					flag=0;
				}
				else
				{
					sz=brr[i].size();
					rep(j,sz)
					{
						prnt.pb(brr[i][j].S);
						prnt1.pb(brr[i][j].S);
						prnt2.pb(brr[i][j].S);
					}
				}
			}
			rep(i,n)
			{
				printf("%d",prnt[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n");
			}
			rep(i,n)
			{
				printf("%d",prnt1[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n");
			}
			rep(i,n)
			{
				printf("%d",prnt2[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
	else
		printf("NO\n");
	return 0;
}











