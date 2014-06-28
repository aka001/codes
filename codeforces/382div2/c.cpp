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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
 
long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
				{
					isprime[j] = 1; 
				}
		}
	}
}

vector<int> arr;
vector<int> differenceit;
vector<int> ansit;
map<int,int> flagit;
int main()
{
	int i,n,cnt=0,flag=0,sizeit,calc,diffit,max,min;
	si(n);
	rep(i,n)
	{
		int val;
		si(val);
		arr.pb(val);
	}
	if(n==1)
	{
		printf("-1\n");
		return 0;
	}
	sort(arr.begin(), arr.end());
	calc=arr[0];
	FOR(i,1,n)
	{
		diffit=arr[i]-calc;
		if(flagit[diffit]==0)
		{
			cnt++;
			differenceit.pb(diffit);
			if(cnt>2)
			{
				flag=1;
				flagit[diffit]++;
				break;
			}
		}
		flagit[diffit]++;
		calc=arr[i];
	}
	if(flag)
	{
		printf("0\n");
		return 0;
	}
	sizeit=differenceit.size();
	if(sizeit>2)
	{
		printf("0\n");
		return 0;
	}
	else if(sizeit==1)
	{
		ansit.pb(arr[0]-differenceit[0]);
		if(n==2)
		{
			if(differenceit[0]%2==0)
				ansit.pb(arr[0]+differenceit[0]/2);
		}
		ansit.pb(arr[n-1]+differenceit[0]);
	}
	else if(sizeit==2)
	{
		flag=0;
		max=differenceit[0];
		if(differenceit[1]>max)
			max=differenceit[1];
		min=differenceit[0]+differenceit[1]-max;
		//printf("max=%d min=%d flag=%d\n",max,min,flagit[max]);
		if(max==2*min && flagit[max]==1)
		{
			calc=arr[0];
			FOR(i,1,n)
			{
				diffit=arr[i]-calc;
				//printf("diffit=%d\n",diffit);
				if(diffit==max)
				{
					//printf("i=%d\n",arr[i]);
					ansit.pb(calc+max/2);
					flag=1;
					break;
				}
				calc=arr[i];
			}
		}
		else
		{
			printf("0\n");
			return 0;
		}
		//printf("hello1\n");
	}
	vector<int>::iterator it;
	it=unique(ansit.begin(), ansit.end());
	ansit.resize(distance(ansit.begin(),it));
	sizeit=ansit.size();
	if(sizeit==0)
	{
		printf("0\n");
		return 0;
	}
	pin(sizeit);
	rep(i,sizeit-1)
		printf("%d ",ansit[i]);
	printf("%d\n",ansit[sizeit-1]);
	return 0;
}
