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
int arr[1000006];
stack<int> stk;
int main()
{
	int i,len,flg=1,c=0,cnt=0,flag,val,sz,j;
	ss(ch);
	len=strlen(ch);
	rep(i,len)
	{
		if(ch[i]=='#')
			cnt++;
	}
	rep(i,len)
	{
		if(ch[i]=='(')
			stk.push(1);
		else if(ch[i]=='#')
		{
			stk.push(2);
		}
		else
		{
			flag=1;
			c=0;
			//printf("1. size=%d\n",(int)stk.size());
			while(!(stk.empty()))
			{
				val=stk.top();
				stk.pop();
				//printf("val=%d\n",val);
				if(val==1)
				{
					flag=0;
					break;
				}
				else if(val==2)
				{
					c++;
				}
			}
			//cout<<i<<" "<<ch[i]<<endl;
			if(flag==1)
			{
				flg=0;
				break;
			}
			else
			{
				rep(j,c)
				{
					stk.push(2);
				}
			}
			//printf("2. size=%d\n",(int)stk.size());
		}
	}
	//printf("cnt=%d\n",cnt);
	if(flg==0)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		sz=stk.size();
		c=0;
		rep(i,sz)
		{
			arr[i]=stk.top();
			stk.pop();
			if(arr[i]==2)
				c++;
		}
		if(c!=cnt)
		{
			return 1;
		}
		if(arr[0]!=2)
		{
			printf("-1\n");
			return 0;
		}
		cnt=0;
		flag=0;
		for(i=sz-1;i>=0;i--)
		{
			if(arr[i]==1)
			{
				cnt++;
			}
			else
			{
				if(cnt==0)
				{
					flag=1;
					break;
				}
				cnt--;
			}
		}
		if(flag)
		{
			printf("-1\n");
			return 0;
		}
		cnt=0;
		for(i=sz-1;i>0;i--)
		{
			if(arr[i]==1)
			{
				cnt++;
			}
			else
			{
				printf("1\n");
				//pin(cnt);
				cnt--;
			}
		}
		if(cnt==0)
			printf("-1\n");
		else
			printf("%d\n",cnt);
	}
	return 0;
}









