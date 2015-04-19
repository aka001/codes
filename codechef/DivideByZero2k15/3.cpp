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
char ch[1000006],pat[1000006];
ll n,k,arr[1000006],brr[1000006],mem[1000006],powit[1000006];
inline ll checkit(ll val)
{
	ll calc=1;
	while(val<mod)
	{
		val+=calc*mod;
		calc*=2;
	}
	if(val>=mod)
		val%=mod;
	return val;
}
void computeLPSArray(int M, int *lps)
{
	int len = 0;  // lenght of the previous longest prefix suffix
	int i;

	lps[0] = 0; // lps[0] is always 0
	i = 1;

	// the loop calculates lps[i] for i = 1 to M-1
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				// This is tricky. Consider the example AAACAAAA and i = 7.
				len = lps[len-1];

				// Also, note that we do not increment i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
int KMPSearch(int val)
{
	int i;
	rep(i,val)
		pat[i]=ch[i];
	int ans=0;
	int M = val;
	int N = strlen(ch);

	// create lps[] that will hold the longest prefix suffix values for pattern
	int *lps = (int *)malloc(sizeof(int)*M);
	int j  = 0;  // index for pat[]

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(M, lps);
	i=0;
	while (i < N)
	{
		if (pat[j] == ch[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			ans++;
			j = lps[j-1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != ch[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
	free(lps); // to avoid memory leak
	return ans;
}

inline ll find_number(ll val)
{
	ll i,s=0,calc,ans=1,cnt;
	if(val>n)
		return 0;
	calc=arr[val-1];
	s=calc;
	//printf("val=%lld calc=%lld i=%lld\n",val,calc,i);
	cnt=0;
	for(i=val;i<n;i++)
	{
		s=s-powit[val-1]*ch[cnt];
		cnt++;
		s=checkit(s);
		s*=26;
		s=checkit(s);
		s+=ch[i];
		s=checkit(s);
		//printf("i=%lld s=%lld\n",i,s);
		if(calc==s)
			ans++;
	}
	return ans;
}
inline int find_value()
{
	int low=1,high=n-k+1,mid,c1,c2;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(mem[mid]!=-1)
			c1=mem[mid];
		else
		{
			c1=KMPSearch(mid);
			//c1=find_number(mid);
			mem[mid]=c1;
		}
		c2=n-(mid-1)+1;
		if(c2>=k)
		{
			if(mem[mid+1]!=-1)
				c2=mem[mid+1];
			else
			{
				c2=KMPSearch(mid+1);
				//c2=find_number(mid+1);
				mem[mid+1]=c2;
			}
		}
		//printf("mid=%lld c1=%lld c2=%lld k=%lld\n",mid,c1,c2,k);
		if(c1>=k && c2<k)
		{
			return mid;
		}
		else if(c1>=k)
			low=mid+1;
		else
			high=mid-1;
	}
	return 0;
}
int main()
{
	ll ait,i,s=0;
	sl(n);
	ss(ch);
	sl(k);
	rep(i,n)
	{
		s=26*s+ch[i];
		if(s>=mod)
			s%=mod;
		arr[i]=s;
	}
	powit[0]=1;
	FOR(i,1,n+2)
	{
		mem[i]=-1;
		powit[i]=26*powit[i-1];
		if(powit[i]>=mod)
			powit[i]%=mod;
	}
	//printf("Hie\n");
	i=1;
	while(i<=n+1)
	{
		mem[i]=find_number(i);
		i*=3;
	}
	//find_number(1);
	if(k==1)
		ait=n;
	else
		ait=find_value();
	pln(ait);
	rep(i,ait)
		cout<<ch[i];
	cout<<endl;
	return 0;
}

