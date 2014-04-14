/**Author: Akash Agrawall
Institution: IIIT Hyderabad **/
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
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l;
string ans;
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller
int CeilIndex(int A[], int l, int r, int key) {
	int m;

	while( r - l > 1 ) {
		m = l + (r - l)/2;
		(A[m] >= key ? r : l) = m; // ternary expression returns an l-value
	}

	return r;
}

int LongestIncreasingSubsequenceLength(int A[], int size) {
	// Add boundary case, when array size is one

	int *tailTable   = new int[size];
	int len; // always points empty slot

	memset(tailTable, 0, sizeof(tailTable[0])*size);

	tailTable[0] = A[0];
	len = 1;
	for( int i = 1; i < size; i++ ) {
		if( A[i] < tailTable[0] )
			// new smallest value
			tailTable[0] = A[i];
		else if( A[i] > tailTable[len-1] )
			// A[i] wants to extend largest subsequence
			tailTable[len++] = A[i];
		else
			// A[i] wants to be current end candidate of an existing subsequence
			// It will replace ceil value in tailTable
			tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
	}

	delete[] tailTable;

	return len;
}

int A[1000005];
int main() {
	int n;
	si(n);
	rep(i,n)
		si(A[i]);
	printf("%d\n",LongestIncreasingSubsequenceLength(A, n));

	return 0;
}
