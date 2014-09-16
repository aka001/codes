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
#include<fstream>
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
char ch[100006],ch1[100006];
ll arr[100006],arr1[100006];
ll ans[100006];
int main()
{
	ll i,size,size1,cnt=0,val,calc,i1,val1,calc1,dit=0;
	std::ifstream infile("decode.in");
	freopen("decode.out","w",stdout);
	string line;
	while(infile >> ch >> ch1)
	{
		cnt=0;
		size=strlen(ch);
		size1=strlen(ch1);
		rep(i,size)
		{
			if(ch[i]>='0' && ch[i]<='9')
				arr[i]=ch[i]-'0';
			else
				arr[i]=ch[i]-55;
		}
		rep(i,size1)
		{
			if(ch1[i]>='0' && ch1[i]<='9')
				arr1[i]=ch1[i]-'0';
			else
				arr1[i]=ch1[i]-55;
		}
		rep(i,size1/2)
		{
			if(i==0)
			{
				val=arr1[i]*16+arr1[i+1];
				val=val^32;
				ans[cnt++]=val;
			}
			else
			{
				i1=2*i;
				val=arr[i1-2]*16+arr[i1-1];
				//printf("i=%d val=%d ans=%d\n",i,val,ans[cnt-1]);
				val=val^ans[cnt-1];
				val1=arr1[i1]*16+arr1[i1+1];
				//printf("i=%d val=%d val1=%d i1=%d arr1=%d arr1+1=%d\n",i,val,val1,i1,arr1[i1],arr1[i1+1]);
				val=val^val1;
				//printf("i=%d val=%d\n",i,val);
				ans[cnt++]=val;
			}
		}
		rep(i,cnt)
		{
			val=ans[i];
			//printf("%lld\n",val);
			size=0;
			string ans="";
			while(val!=0)
			{
				size++;
				calc=val%16;
				if(calc<=9)
				{
					ans=(char)(calc+'0')+ans;
				}
				else
				{
					ans=(char)(55+calc)+ans;
				}
				val/=16;
			}
			if(size==0)
				ans="00";
			else if(size==1)
				ans="0"+ans;
			cout<<ans;
			//printf("%s",ans);
		}
		cout<<endl;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}













