/*Author : Akash Agrawall
Institution: IIIT Hyderabad*/

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

#define FOR(i,a,b) 	for(i= a ; i < b ; ++i)
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
#define lli		long long int
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int getint()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!=' ')
	{
		s=s<<1 + s<<3 + ch-'0';
		ch=getchar();
	}
	return s;
}
long long int arr[1000000];
char ch[10000];
typedef unsigned long long u64;
u64 multiply(u64 a, u64 b, u64 c)
{
	u64 result = 0;
	a %= c;
	b %= c;
	while(b) {
		if(b & 0x1) {
			result += a;
			result %= c;
		}
		b >>= 1;
		a <<= 1;
		a %= c;
	}
	return result;
}
int str[1001][1003];
int main()
{
	long long int calc,a,b,c,temp;
	int val,leftit,rightit,k,i,t,n,pos,x,n1,j,l,n2;
	si(t);
	while(t--)
	{
		rep(i,1001)
		{
			str[i][0]=-1;
			str[i][1]=0;
		}
		si(n);
		rep(i,n)
			sl(arr[i]);
		sl(a);
		sl(b);
		sl(c);
		scanf("%s",ch);
		if(ch[0]=='A')
		{
			arr[0]=arr[0]+a;
			if(arr[0]>c)
				arr[0]%=c;
			str[0][1]=1;
			str[0][0]=0;
		}
		else if(ch[0]=='M')
		{
			arr[0]=multiply(arr[0],b,c);
			//arr[0]=((arr[0]%c)*(b%c))%c;
			str[0][1]=1;
			str[0][0]=1;
		}
		else
		{
			n1=n>>1-1;
			rep(i,n1)
				arr[i]=arr[n-i-1];
			str[0][0]=2;
			str[0][1]=1;
			str[0][2]=0;
		}
		l=1;
		/*rep(i,n)
			printf("%lld ",arr[i]);
		printf("\n");
		rep(i,l)
			printf("%d %d\n",str[i][0],str[i][1]);
		printf("\n");*/
		FOR(i,1,n)
		{
			x=2;
			if(ch[i]=='A')
				x=0;
			else if(ch[i]=='M')
				x=1;
			if(str[l-1][0]==x)
			{
				str[l-1][1]++;
				if(x==2)
					str[l-1][1+str[l-1][1]]=i;
			}
			else
			{
				str[l][0]=x;
				str[l][1]=1;
				l++;
			}
			calc=arr[i];
			rep(j,l)
			{
				if(str[j][0]==0)
				{
					calc+=str[j][1]*a;
					arr[i]=calc;
				}
				else if(str[j][0]==1)
				{
					calc=multiply(calc,str[j][1]*b,c);
					arr[i]=calc;
				}
				else
				{
					val=str[j][1];
					//printf("val=%d\n",val);
					rep(k,val)
					{
						pos=str[j][2+k];
						n2=(pos+n);
						n1=n2>>1;
						leftit=n1-i;
						rightit=n1+leftit;
						if(n2&01)
							rightit--;
						temp=arr[i];
						arr[i]=arr[rightit];
						arr[rightit]=temp;
						//printf("interchanged pos=%d rightit=%d\n",i,rightit);
					}
				}
				//calc=(calc*(str[j][1]*(b%c))%c)%c;
				//if(calc>c)
				//	calc%=c;
			}
			/*rep(j,n)
				printf("%lld ",arr[j]);
			printf("\n");
			rep(j,l)
			{
				printf("%d %d\n",str[j][0],str[j][1]);
			}
			printf("\n");*/
		}
		rep(i,n-1)
			printf("%lld ",arr[i]%c);
		printf("%lld\n",arr[n-1]%c);
	}
	return 0;
}










