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
int m,n;
int edit_distance(int* s1, int* s2)
{
	int d;
	int dp[m+1][n+1];
	for (int i = 0; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= n; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i-1] == s2[j-1])
				d = 0;
			else
				d = RC;
			dp[i][j] = minimum(dp[i-1][j-1] + d,    /*replace*/
					dp[i-1][j]+IC,         /*insert*/
					dp[i][j-1]+DC);        /*delete*/
		}
	}

	return dp[m][n];
}
int source[1000],target[1000];
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
		printf("%d\n",edit_distance(source,target));
	}
	return 0;
}
