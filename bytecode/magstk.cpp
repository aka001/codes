#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
#include<iterator>
#include<iomanip>
using namespace std;

#define Pi 3.14159265358979323846264338327950288419716939937510582;
typedef long long int lld;
#define MOD 1000000007;
#define pb push_back
#define pf push_front
#define ppb pop_back
lld modpow(lld a,lld n,lld temp){lld res=1;while(n>0){res=(res*res)%temp;if(n&1)res=(res*a)%temp;n/=2;}return res;}
lld gcd(lld a,lld b){if(a==0)return(b);else return(gcd(b%a,a));}
int bsrch(vector <pair <int,int> > &a,int el, int left,int right)
{
	int mid=(left+right)/2;
	if(a[mid].first==el)return mid;
	else if(a[mid].first<el)return bsrch(a,el,mid+1,right);
	else return bsrch(a,el,left,mid-1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		vector <pair <int,int> > a;
		int x[100001];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int t1,t2;
			cin>>t1>>t2;
			a.pb(make_pair(t1,t2));
			x[i]=t1;
		}
		sort(a.begin(),a.end());
		int ans[100001]={0};
		ans[a.size()-1]=1;
		for(int i=a.size()-2;i>=0;i--)
		{
			int j=i,cura=1;
			while(a[j+1].first>a[i].first&&a[j+1].first<a[i].first+a[i].second)//&&j<a.size())
			{
				/*if(j==a.size()-1){
				  cura=j-i+1;
				  break;
				  }*/
				j++;
				if(ans[j]+j-i>cura){
					cura=ans[j]+j-i;
					j=ans[j]+j-1;
					if(j==a.size()-1)
						break;
				}
			}
			ans[i]=cura;
			//		cout<< cura<<" ";
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[bsrch(a,x[i],0,n-1)]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
