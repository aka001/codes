#include<stdio.h>
int bs(int n)
{
	int l=0,h=298855,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(a[mid]==n)
			return 1;
		else if(n<a[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	return 0;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(bs(n))
			printf("PERFECT\n");
		else
			printf("IMPERFECT\n");
	}
	return 0;
}