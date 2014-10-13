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
char ch[1000006],ch1[1000006],ch2[1000006];
int main()
{
	int t,cnt,i,pnt,n,j,lenit,len1,i1,flag=0;
	t=1;
	{
		si(n);
		ss(ch);
		rep(i,n)
		{
			lenit=strlen(ch);
			ss(ch1);
			cnt=0;
			len1=strlen(ch1);
			//printf("%s %d\n",ch1,len1);
			pnt=0;
			j=0;
			cnt=0;
			while(j<lenit)
			{
				//printf("j=%d\n",j);
				i1=j;
				pnt=0;
				flag=0;
				if(ch[i1]==ch1[pnt])
				{
					while(ch[i1]==ch1[pnt])
					{
						i1++;pnt++;
						if(i1==lenit || pnt==len1)
							break;
					}
					//printf("j=%d pnt=%d len1=%d i1=%d\n",j,pnt,len1,i1);
					if(pnt!=len1)
					{
						//printf("j=%d pnt=%d cnt=%d\n",j,pnt,cnt);
						ch2[cnt++]=ch[j];
					}
					else
					{
						//printf("j=%d i1=%d\n",j,i1);
						j=i1;
						flag=1;
					}
				}
				else
					ch2[cnt++]=ch[i1];
				if(flag==0)
					j++;
			}
			rep(j,cnt)
			{
				//printf("%c",ch[j]);
				ch[j]=ch2[j];
			}
			//printf("\n");
			ch[cnt]='\0';
		}
		lenit=strlen(ch);
		if(lenit==0)
		{
			printf("0\n");
			return 0;
		}
		rep(i,lenit)
			printf("%c",ch[i]);
		printf("\n");
	}
	return 0;
}















