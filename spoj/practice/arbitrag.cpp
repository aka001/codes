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
double arr[35][35];
ll hashit(char ch[1003])
{
	int i,sz,ans=0,calc=1;
	sz=strlen(ch);
	rep(i,sz)
	{
		ans+=calc*ch[i];
		calc*=26;
		ans%=mod;
		calc%=mod;
	}
	return ans;
}
int main()
{
	int n,i,j,k,p,calc,calc1,m,flag;
	double val,itit;
	char ch[1003],ch1[1003];
	rep(p,5)
	{
		flag=0;
		map<int,int> mapit;
		si(n);
		//printf("n=%d\n",n);
		if(n==0)
		{
			break;
		}
		rep(i,n)
		{
			cin>>ch;
			calc=hashit(ch);
			//mapit[ch]=i+1;
			mapit[calc]=i+1;
		}
		rep(i,n+1)
		{
			rep(j,n+1)
			{
				if(i==j)
					arr[i][j]=1;
				else
					arr[i][j]=0;
			}
		}
		//printf("m=%d\n",m);
		si(m);
		getchar();
		rep(i,m)
		{
			scanf("%s %lf %s\n",ch,&val,ch1);
			/*cin>>ch;
			cin>>val;
			cin>>ch1;*/
			//cout<<ch<<" "<<val<<" "<<ch1<<endl;
			calc=hashit(ch);
			calc=mapit[calc];
			calc1=hashit(ch1);
			calc1=mapit[calc1];
			arr[calc][calc1]=val;
		}
		n++;
		//printf("%lf\n",arr[1][1]);
		FOR(i,1,n)
		{
			FOR(j,1,n)
			{
				FOR(k,1,n)
				{
					itit=arr[j][i]*arr[i][k];
					//printf("j=%d k=%d i=%d arr[j][k]=%lf arr[j][i]=%lf arr[i][k]=%lf\n",j,k,i,arr[j][k],arr[j][i],arr[i][k]);
					arr[j][k]=max(arr[j][k],itit);
					//printf("j=%d k=%d i=%d arr[j][k]=%lf arr[j][i]=%lf arr[i][k]=%lf\n",j,k,i,arr[j][k],arr[j][i],arr[i][k]);
				}
			}
		}
		FOR(i,1,n)
		{
			//printf("i=%d %lf\n",i,arr[i][i]);
			if(arr[i][i]>1)
			{
				flag=1;
				break;
			}
		}
		printf("Case %d: ",p+1);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}















