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
int M[2000][2000];
int knapsack(int value[], int weight[], int C, int n)
{      
	for(int i = 1; i <= C; i++){
		for(int j = 0; j <n; j++){
			if(j > 0){
				M[j][i] = M[j-1][i];
				if (weight[j] <= i)
					M[j][i] = max(M[j][i], M[j-1][i-weight[j]]+value[j]);
			}
			else{
				M[j][i] = 0;
				if(weight[j] <= i)
					M[j][i] = max(M[j][i], value[j]);
			}
		}
		//    cout << M[i][n-1] << endl;
	}        
	return M[n-1][C];
}  
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int x,y,z,C, N;
		cin >> N >> C;
		int* value = new int[N+1];
		int* weight = new int[N+1];
		for ( int i = 0; i < N; i++) 
		{
			si(x);si(y);si(z);
			weight[i]=z;
			value[i]=x*y;
		}
		//   vector < int >back(N, 0);
		cout<<knapsack(value,weight,C,N)<<endl;
	}
	return 0;
}
