/*******************
  Ashish Kumar
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
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
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
#define pil(n) printf("%d\n",n)
#define pll(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
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
int sa[500005];
int pos[500005];
int tmp[500005]={0};
int gram=1,step=1,n;

int cmp(int i,int j)
{
	if(pos[i]!=pos[j])
		return pos[i]<pos[j];
	i+=gram;
	j+=gram;
	if(i<n && j<n)
	{
		return pos[i]<pos[j];
	}
	else
	{
		i>j;
	}
}

int height[500005];
int rank[500005];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		gram=1;
		step=1;
		char s[500005];
		scanf("%s",s);
		int i,j;
		n=strlen(s);
		for(i=0;i<n;i++)
		{
			sa[i]=i;
			pos[i]=s[i];
			tmp[i]=0;
		}
		sort(sa,sa+n,cmp);
for(i=0;i<n-1;i++)
				tmp[i+1]=tmp[i]+cmp(sa[i],sa[i+1]);
			for(i=0;i<n;i++)
				pos[sa[i]]=tmp[i];
		//for(i=0;i<n-1;i++)
		//	tmp[i+1]=tmp[i]+cmp(sa[i],sa[i+1]);
		while(1)
		{
			sort(sa,sa+n,cmp);
			for(i=0;i<n-1;i++)
				tmp[i+1]=tmp[i]+cmp(sa[i],sa[i+1]);
			for(i=0;i<n;i++)
				pos[sa[i]]=tmp[i];
			/*cout<<"step="<<step<<endl;
			for(i=0;i<n;i++)
				cout<<pos[i]<<" ";
			cout<<endl;*/
			if(tmp[n-1]==n-1)
				break;
			gram*=2;
			step++;
		}
		/*for(i=0;i<n;i++)
		{
			cout<<sa[i]<<endl;
		}*/
for (int i=0; i<n; ++i) rank[sa[i]] = i;
	height[0] = 0;
	for (int i=0, h=0; i<n; ++i){
		if (rank[i] > 0){
			int j = sa[rank[i]-1];
			while (i + h < n && j + h < n && s[i+h] == s[j+h]) h++;
			height[rank[i]] = h;
			if (h > 0) h--;
		}
	}

long long ans = 0;
	for (int i=0; i<n; ++i){
		//cout<<sa[i]<<" ";
		ans += n - sa[i] - height[i];
	}
	//cout<<endl;
	cout << ans << endl;

	}
	return 0;
}
