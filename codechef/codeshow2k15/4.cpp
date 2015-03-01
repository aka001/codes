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
#define ll long long nclude <iostream>
#include <string.h>
using namespace std;

// M is number of applicants and N is number of jobs
ll M,N;
bool available[20];

// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
	// Try every job one by one
	for (int v = 0; v < N; v++)
	{
		// If applicant u is interested in job v and v is
		// not visited
		if (bpGraph[u][v] && !seen[v] && available[v])
		{
			seen[v] = true; // Mark v as visited

			// If job 'v' is not assigned to an applicant OR
			// previously assigned applicant for job v (which is matchR[v]) 
			// has an alternate job available. 
			// Since v is marked as visited in the above line, matchR[v] 
			// in the following recursive call will not get job 'v' again
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
	// An array to keep track of the applicants assigned to
	// jobs. The value of matchR[i] is the applicant number
	// assigned to job i, the value -1 indicates nobody is
	// assigned.
	int matchR[N];

	// Initially all jobs are available
	memset(matchR, -1, sizeof(matchR));

	int result = 0; // Count of jobs assigned to applicants
	for (int u = 0; u < M; u++)
	{
		// Mark all jobs as not seen for next applicant.
		bool seen[N];
		memset(seen, 0, sizeof(seen));

		// Find if the applicant 'u' can get a job
		if (bpm(bpGraph, u, seen, matchR))
			result++;
	}
	return result;
}
bool bpGraph[2002][2002];
// Driver program to test above functions
int main()
{
	// Let us create a bpGraph shown in the above example
	int n;
	si(n);
	N=n;
	M=10;
	rep(i,9)
	{
		si(val);
		available[i]=val;
	}
	rep(i,n)
	{
		si(val);
		rep(j,val)
		{
			si(vit);
			bpGraph[i][vit-1]=1;
		}
	}
	calc=maxBPM(bpGraph);
	if(calc<n)
		printf("It seems MSG\n");
	else
	{
		
	}
	return 0;
}int
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

int main()
{

	return 0;
}
