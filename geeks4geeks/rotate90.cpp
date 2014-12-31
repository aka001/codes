
#include<cstdio>
#include<iostream>
using namespace std;
int arr[1001][1001],rot[1001][1001];
int main()
{
	int i,j,n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			rot[j][n-i-1]=arr[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",rot[i][j]);
		printf("\n");
	}
}







