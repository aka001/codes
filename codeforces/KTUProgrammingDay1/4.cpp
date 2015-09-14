/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<bits/stdc++.h>
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
#define F first
#define S second
#define mod (ll)(1e9 + 7)
#define ll long long int
#define MAX 1000006
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
void combinationUtil(int arr[],int n,int r,int index,int data[],int i);
void printCombination(int arr[], int n, int r)
{
	// A temporary array to store all combination one by one
	int data[r];

	// Print all combination using temprary array 'data[]'
	combinationUtil(arr, n, r, 0, data, 0);
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
int ans=0;
map<int,int> mapit;
void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
	// Current cobination is ready, print it
	if (index == r)
	{
		vector<int> vec;
		for (int j=0; j<r; j++)
		{
			vec.pb(data[j]);
		}
		if(vec[0]+vec[1]>vec[2] && vec[1]+vec[2]>vec[0] && vec[0]+vec[2]>vec[1] && mapit[vec[0]]!=0 && mapit[vec[1]]!=0 && mapit[vec[2]]!=0)
		{
			mapit[vec[0]]--; mapit[vec[1]]--; mapit[vec[2]]--;
			ans++;
		}
		return;
	}

	// When no more elements are there to put in data[]
	if (i >= n)
		return;

	// current is included, put next at next location
	data[index] = arr[i];
	combinationUtil(arr, n, r, index+1, data, i+1);

	// current is excluded, replace it with next (Note that
	// i+1 is passed, but index is not changed)
	combinationUtil(arr, n, r, index, data, i+1);
}
int vis[MAX];
int main()
{
	memset(vis, 1, sizeof(vis));
	int n,arr[20],i,flag,j,k;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
		mapit[arr[i]]++;
	}
	sort(arr, arr+n);
	rep(i,n)
	{
		flag=0;
		FOR(j,i+1,n)
		{
			FOR(k,j+1,n)
			{
				if(arr[i]+arr[j]>arr[k] && arr[j]+arr[k]>arr[i] && arr[i]+arr[k]>arr[j] && vis[i] && vis[j] && vis[k])
				{
					vis[i]=vis[j]=vis[k]=0;
					//trace3(i,j,k);
					ans++;
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	//printCombination(arr,n,3);
	pin(ans);
	return 0;
}













