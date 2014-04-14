#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define IC 1 /*cost to insert*/
#define RC 1 /*cost to replace*/
#define DC 1 /*cost to delete*/

int minimum(int a, int b, int c)
{
	int min = c;

	if( a < b )
	{
		if( a < c )
		{
			min = a;
		}
	}
	else
	{
		if( b < c )
		{
			min = b;
		}
	}

	return min;
}

/*
   red- recursive edit distance

 */
int m,n;
int red(int x[], int y[])
{
	int d,e,f;

	/* Base cases */

	if(*x==0)return n;
	if(*y== 0)return m;

	/* Recurse */

	if(*x==*y)
		d=red(x+1,y+1);
	else
		d=RC+red(x+1,y+1); /*replace*/
	e=IC+red(x,y+1); /*insert*/
	f=DC+red(x+1,y); /*delete*/

	return minimum(d,e,f);
}

int source[1000];
int target[1000];
int main()
{
	int t,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&source[i]);
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&target[i]);
		}
		x=red(source,target);
		printf("%d\n",x);
	}
	return 0;
}
