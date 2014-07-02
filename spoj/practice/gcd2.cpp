#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;
#define ll long long int
#define mod 1e9+7
inline ll gcd(ll a,ll b)
{
	ll c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}
char arr[10000];
int main()
{
	int t,sizeit,i;
	ll ans,calc,val,final,n;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%s",&n,arr);
		val=0;
		if(n==0)
		{
			printf("%s\n",arr);
			continue;
		}
		ans=0;
		for(i=0;arr[i];i++)
		{
			ans=ans*10+(arr[i]-48);
			ans=ans%n;
		}
		final=gcd(n,ans);
		printf("%lld\n",final);
	}
	return 0;
}
