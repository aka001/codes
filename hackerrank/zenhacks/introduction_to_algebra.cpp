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
int arr[300][300];
int freq[2000];
int main()
{
	int t,n,s=0,f1,f2,f3,cit,f4,f5,f6,f7,i,j,k,cnt,str,c1,c2,f11,doit,cnt1;
	si(t);
	while(t--)
	{
		cit=-1;
		f11=f1=f2=f3=f4=f5=f6=f7=1;
		s=0;
		si(n);
		rep(i,n)
			rep(j,n)
			si(arr[i][j]);
		//Quasigroup
		rep(i,n)
		{
			rep(j,n)
			{
				cnt=0;
				cnt1=0;
				rep(k,n)
				{
					if(arr[i][k]==j)
						cnt++;
					if(arr[k][i]==j)
						cnt1++;
				}
				if(cnt!=1)
					f11=0;
				if(cnt!=1 || cnt1!=1)
					f1=0;
			}
		}

		/*rep(i,n)
		  {
		  rep(j,n)
		  freq[j]=0;
		  rep(j,n)
		  {
		  if(freq[arr[i][j]]!=0)
		  {
		  f1=f11=0;
		  break;
		  }
		  freq[arr[i][j]]++;
		  }
		  }
		  rep(i,n)
		  {
		  rep(j,n)
		  freq[j]=0;
		  rep(j,n)
		  {
		  if(freq[arr[j][i]]!=0)
		  {
		  f1=0;
		  break;
		  }
		  freq[arr[i][j]]++;
		  }
		  }*/
		//Finding the loop
		doit=0;
		rep(i,n)
		{
			cnt=0;
			rep(j,n)
			{
				if(arr[i][j]==j && arr[j][i]==j)
				{
					cnt++;
				}
			}
			if(cnt==n)
			{
				cit=i;
				doit++;
			}
		}
		if(doit!=1)
		{
			f2=0;
		}
		//Quasigroup and loop
		if(f1==1)
		{
			s+=1;
			if(f2==1)
			{
				s+=2;
			}
		}
		//Semigroup
		rep(i,n)
		{
			rep(j,n)
			{
				rep(k,n)
				{
					c1=arr[i][j];
					c1=arr[c1][k];
					c2=arr[i][arr[j][k]];
					if(c1!=c2)
					{
						f3=0;
						break;
					}
				}
				if(f3==0)
					break;
			}
			if(f3==0)
				break;
		}
		//Semigroup
		if(f3==1)
		{
			s+=4;
			//Monoid
			if(f2==1)
			{
				s+=8;
				//Group
				rep(i,n)
				{
					cnt=0;
					rep(j,n)
					{
						if(arr[i][j]==arr[j][i] && arr[i][j]==cit)
						{
							cnt=1;
							break;
						}
					}
					if(cnt==0)
					{
						f4=0;
						break;
					}
				}
				//Group
				if(f4)
				{
					//printf("hie\n");
					s+=16;
					//Abelian Group
					rep(i,n)
					{
						rep(j,n)
						{
							if(arr[i][j]!=arr[j][i])
							{
								f5=0;
								break;
							}
						}
						if(f5==0)
							break;
					}
					if(f5==1)
						s+=32;
				}
			}
		}
		//Checking for rack
		rep(i,n)
		{
			rep(j,n)
			{
				rep(k,n)
				{
					c1=arr[i][arr[j][k]];
					c2=arr[arr[i][j]][arr[i][k]];
					if(c1!=c2)
					{
						f6=0;
						break;
					}
				}
				if(f6==0)
					break;
			}
			if(f6==0)
				break;
			if(f11==0)
			{
				f6=0;
				break;
			}
		}
		//Checking for rack
		if(f6)
		{
			s+=64;
			//Checking for quandle
			rep(i,n)
			{
				if(arr[i][i]!=i)
				{
					f7=0;
					break;
				}
			}
			if(f7)
				s+=128;
		}
		pin(s);
	}
	return 0;
}















