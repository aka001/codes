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
int freq[200];
int main()
{
	int t,i,n,i1,i2,flag;
	char ch[100],ch1[100];
	si(t);
	while(t--)
	{
		string str="";
		si(n);
		ss(ch);
		rep(i,n)
		{
			freq[ch[i]]=i;
			ch1[i]=ch[i];
		}
		sort(ch1,ch1+n);
		flag=0;
		rep(i,n)
		{
			if(ch[i]!=ch1[i])
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			i1=i;
			//pin(i1);
			rep(i,i1)
				str+=ch[i];
			str+=ch1[i1];
			//cout<<ch[i1]<<endl;
			i2=freq[ch1[i1]];
			//pin(i2);
			FOR(i,i1,i2)
				str+=ch[i];
			FOR(i,i2+1,n)
				str+=ch[i];
		}
		else
			rep(i,n)
				str+=ch[i];
		cout<<str<<endl;
	}
	return 0;
}













