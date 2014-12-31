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

int main()
{
	double n,x,y,low,high,mid,val,calc,calc1,calc2,clc,acc1,acc2,th=0.2,rand;
	int i,flag=0;
	sd(n);
	sd(x);
	sd(y);
	calc=min(1/(x*1.0),1/(y*1.0));
	rand=min(x,y);
	th=calc/(rand*1.0);
	//printf("%lf\n",calc);
	rep(i,n)
	{
		flag=0;
		low=0;
		high=1000000000;
		sd(val);
		while(low<=high)
		{
			mid=(low+high)/2.0;
			calc1=mid*x;
			calc2=mid*y;
			clc=(ll)(calc1+0.01)+(ll)(calc2+0.01);
			//clc=(double)((ll)(calc1+th)+(ll)(calc2+th));
			acc1=(double)((ll)(calc1+th))-calc1;
			acc2=(double)((ll)(calc2+th))-calc2;
			if(acc1<0)
				acc1*=-1;
			if(acc2<0)
				acc2*=-1;
			//printf("clc=%lf mid=%lf calc1=%lf calc2=%lf low=%lf high=%lf\n",clc,mid,calc1,calc2,low,high);
			if(abs(val-clc)<=th)
			{
				calc1=(ll)(calc1+th);
				calc2=(ll)(calc2+th);
				flag=1;
				//printf("acc1=%lf acc2=%lf\n",acc1,acc2);
				if(acc1<=th && acc2<=th)
					printf("Both\n");
				else if(calc1>calc2)
					printf("Vanya\n");
				else
					printf("Vova\n");
				break;
			}
			else if(clc>val)
			{
				high=mid-th;
				if(high<=low)
					high=(mid-low)/2.0;
			}
			else
			{
				low=mid+th;
				if(low>=high)
					low=(mid+high)/2.0;
			}
			mid=(low+high)/2.0;
			//printf("low=%lf high=%lf mid=%lf\n",low,high,mid);
			if(high-mid<0.001)
				break;
		}
		if(flag==0)
			printf("Both\n");
	}
	return 0;
}

















