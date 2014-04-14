#include<stdio.h>
void recursion(int ar[10000],int val,int val1)
{
	if(ar[val1]==-1)
	{
		ar[val1]=val;
		return;
	}
	recursion(ar,val1,ar[val1]);
	ar[val1]=val;
}
int main()
{
	int c,b,t,a,i,temp,cnt;
	scanf("%d",&t);
	while(t--)
	{
		int ar[10000];
		cnt=1;
		scanf("%d %d %d",&a,&b,&c);
		for(i=1;i<=a;i++)
		{
			if(i==b)
			{
				ar[i]=-1;
			}
			else
			{
				scanf("%d",&temp);
				ar[i]=temp;
			}
		}
		recursion(ar,c,ar[c]);
		for(i=1;i<=a;i++)
		{
			if(i!=c)
			{
				if(cnt==a)
					printf("%d\n",ar[i]);
				else
					printf("%d ",ar[i]);
			}
			cnt++;
		}
	}
	return 0;
}
