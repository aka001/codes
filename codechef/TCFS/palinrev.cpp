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
int palin(string str)
{
	int sz=str.size(),i;
	int flag=1;
	rep(i,sz/2)
	{
		if(str[i]!=str[sz-i-1])
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int sz,i,j,pnt,lenit,flagit=0,pntit=-1,calcit;
	string ch,str1,str2;
	cin>>ch;
	sz=ch.size();
	str1="";
	rep(i,sz/2)
	{
		if(ch[i]!=ch[sz-i-1])
		{
			pntit=i;
			break;
		}
	}
	if(pntit==-1)
	{
		printf("Yes\n");
		return 0;
	}
	flagit=1;
	str1+=ch[sz-i-1];
	pnt=sz-i-2;
	while(pnt>i)
	{
		str2="";
		if(ch[pnt]==ch[sz-i-1])
		{
			for(j=i;j<=pnt;j++)
				str2=ch[j]+str2;
			str2+=str1;
			//printf("pnt=%d sz-i-1=%d\n",pnt,sz-i-1);
			sz=str2.size();
			flagit=1;
			rep(j,sz/2)
			{
				if(str2[j]!=str2[sz-j-1])
				{
					flagit=0;
					break;
				}
			}
			//cout<<str1<<endl<<str2<<endl;
			if(flagit)
			{
				printf("Yes\n");
				return 0;
			}
		}
		str1+=ch[pnt];
		pnt--;
	}
	str1="";
	flagit=1;
	pnt=pntit;
	str1+=ch[pnt];
	pnt=i+1;
	while(pnt<sz-i-1)
	{
		str2="";
		if(ch[pnt]==ch[i])
		{
			lenit=sz-i-1-pnt;
			//printf("pnt=%d\n",pnt);
			for(j=pnt;j<=sz-i-1;j++)
			{
				str2=ch[j]+str2;
			}
			str2=str1+str2;
			//cout<<str1<<endl;
			//cout<<str2<<endl;
			//printf("pnt=%d sz-i-1=%d\n",pnt,sz-i-1);
			sz=str2.size();
			flagit=1;
			rep(j,sz/2)
			{
				if(str2[j]!=str2[sz-j-1])
				{
					flagit=0;
					break;
				}
			}
			//cout<<str1<<endl<<str2<<endl;
			if(flagit)
			{
				printf("Yes\n");
				return 0;
			}
		}
		str1+=ch[pnt];
		pnt++;
	}
	printf("No\n");
	return 0;
}









