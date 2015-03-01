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
map<string,int> mapit;
map<int,string> mit;
int arr[1000006],vis[1000006];
string fir[100000],sec[100000],a1[100000],a2[100000];
int find_bapu(int val)
{
	while(val!=arr[val])
	{
		val=arr[val];
		vis[val]=1;
	}
	//printf("here val=%d\n",val);
	return val;
}
int main()
{
	int n,cnt=1,c1,c2,i,val,calc;
	string ch1,ch2;
	si(n);
	rep(i,2*n+2)
		arr[i]=i;
	rep(i,n)
	{
		cin>>ch1>>ch2;
		if(mapit[ch1]==0)
		{
			mapit[ch1]=cnt++;
		}
		if(mapit[ch2]==0)
		{
			mapit[ch2]=cnt++;
		}
		c1=mapit[ch1];
		c2=mapit[ch2];
		mit[c1]=ch1;
		mit[c2]=ch2;

		arr[c1]=c2;
		fir[i]=ch1;
		sec[i]=ch2;
	}
	/*FOR(i,1,n+1)
	{
		printf("i=%d %d\n",i,arr[i]);
	}*/
	cnt=0;
	rep(i,n)
	{
		c1=mapit[fir[i]];
		c2=mapit[sec[i]];
		//cout<<fir[i]<<" "<<sec[i]<<endl;
		//cout<<c1<<" "<<c2<<endl;
		calc=vis[c1];
		if(calc==0)
		{
			val=find_bapu(c1);
			//cout<<c1<<" "<<val<<endl;
			a1[cnt]=fir[i];
			a2[cnt]=mit[val];
			cnt++;
			//cout<<fir[i]<<" "<<mit[val]<<endl;
		}
	}
	cout<<cnt<<endl;
	rep(i,cnt)
	{
		cout<<a1[i]<<" "<<a2[i]<<endl;
	}
	return 0;
}












