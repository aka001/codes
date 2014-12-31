#include <bits/stdc++.h>
#include <deque>
using namespace std;
int arr[1000006];
int main()
{
	int n,k,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	deque<int> Q(k);
	for(i=0;i<k;i++)
	{
		while(!(Q.empty()) && arr[i]>=arr[Q.back()])
		{
			Q.pop_back();
		}
		Q.push_back(i);
	}
	printf("%d ",arr[Q.front()]);
	deque<int>::iterator it;
	for(;i<n;i++)
	{
		while(!(Q.empty()) && (arr[i]>=arr[Q.back()] || (Q.back()<=i-k)))
			Q.pop_back();
		while(!(Q.empty()) && Q.front()<=i-k)
			Q.pop_front();
		/*printf("i=%d\n",i);
		it=Q.begin();
		while(it!=Q.end())
		{
			printf("%d ",*it);
			it++;
		}
		printf("\n");
		if((int)Q.size()==2)
		{
			printf("checking back=%d front=%d\n",Q.back(),Q.front());
		}*/
		Q.push_back(i);
		printf("%d ",arr[Q.front()]);
	}
	printf("\n");
	return 0;
}
