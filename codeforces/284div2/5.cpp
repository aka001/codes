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
int isprime[1000006],arr[1000006];
vector<vector<int> > pit;
vector<int> primeit;
void seive()
{
	ll i,MAX=1000006,j;
	isprime[0]=isprime[1]=1;
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
	for(i=2;i<MAX;i++)
		if(isprime[i]==0)
			primeit.pb(i);
}
vector<int> prit(int n)
{
	int sqit=sqrt(n),i,j,sz;
	vector<int> rit;
	sz=primeit.size();
	rep(i,sz)
	{
		j=primeit[i];
		if(j>sqit)
			break;
		if(n%j==0)
		{
			while(n%j==0)
			{
				rit.pb(j);
				n/=j;
			}
		}
	}
	if(n!=1)
		rit.pb(n);
	return rit;
}
int pre1[1000006],pre2[1000006];
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(vector<int> bpGraph[], int u, bool seen[], int matchR[],int M)
{
	// Try every job one by one
	int v,sz,j;
	sz=bpGraph[u].size();
	//printf("u=%d sz=%d\n",u,sz);
	for (v = 0; v < sz ; v++)
	{
		// If applicant u is interested in job v and v is
		// not visited
		j=bpGraph[u][v];
		if (!seen[j])
		{
			seen[j] = true; // Mark v as visited

			// If job 'v' is not assigned to an applicant OR
			// previously assigned applicant for job v (which is matchR[v]) 
			// has an alternate job available. 
			// Since v is marked as visited in the above line, matchR[v] 
			// in the following recursive call will not get job 'v' again
			//printf("u=%d j=%d match=%d\n",u,j,matchR[j]);
			if (matchR[j] < 0 || bpm(bpGraph, matchR[j], seen, matchR,M))
			{
				matchR[j] = u;
				return true;
			}
		}
	}
	return false;
}

// Returns maximum number of matching from M to N
int maxBPM(vector<int> bpGraph[],int N,int M)
{
	// An array to keep track of the applicants assigned to
	// jobs. The value of matchR[i] is the applicant number
	// assigned to job i, the value -1 indicates nobody is
	// assigned.
	int matchR[M];
	int result = 0,sz,u;
	// Initially all jobs are available
	memset(matchR, -1, sizeof(matchR));

	//printf("n=%d m=%d\n",N,M);
	for (u = 1; u <=N; u++)
	{
		// Mark all jobs as not seen for next applicant.
		bool seen[M];
		memset(seen, 0, sizeof(seen));
		// Find if the applicant 'u' can get a job
		if (bpm(bpGraph, u, seen, matchR,M))
			result++;
	
	}
	return result;
}
int main()
{
	int i,n,m,c1=0,c2=0,v1,v2,j,k,c,d,temp,a,b,cnt;
	seive();
	si(n);
	si(m);
	rep(i,n)
	{
		si(arr[i]);
		pit.pb(prit(arr[i]));
		cnt=pit[i].size();
		//printf("arr[%d]=%d\n",i,arr[i]);
		if(i!=0)
		{
			pre1[i]=pre1[i-1];
			pre2[i]=pre2[i-1];
		}
		if(i%2==0)
		{
			pre1[i]+=cnt;
		}
		else
		{
			pre2[i]+=cnt;
		}
	}
	vector<int> grph[pre1[n-1]+pre2[n-1]+1];
	//printf("M=%d\n",m);
	rep(i,m)
	{
		si(a);
		si(b);
		a--;
		b--;
		if(a%2==1)
		{
			temp=a;
			a=b;
			b=temp;
		}
		c=pit[a].size();
		d=pit[b].size();
		//printf("i=%d\n",i);
		rep(j,c)
		{
			rep(k,d)
			{
				if(pit[a][j]==pit[b][k])
				{
					if(a==0)
						c1=0;
					else
						c1=pre1[a-1];
					if(b==0)
						c2=0;
					else
						c2=pre2[b-1];
					//printf("%d %d %d  %d %d\n",j,k, pit[a][j],c1+j+1,pre1[n-1]+c2+k+1);
					grph[c1+j+1].pb(pre1[n-1]+c2+k+1);
				}
			}
		}
		//printf("i=%d m=%d\n",i,m);
	}
	pin(maxBPM(grph,pre1[n-1],pre1[n-1]+1+pre2[n-1]));
	return 0;
}















