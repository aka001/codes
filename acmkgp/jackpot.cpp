// Name: AKASH AGRAWALL
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<deque>
using namespace std;
typedef struct node{
}node;
typedef node * link;
int fast()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!='\n' && ch!=' ')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
void swap(long long int *x,long long int *y)
{
	long long int a,b;
	a=*x;
	b=*y;
	*x=b;
	*y=a;
}
int main()
{
	long long int i=1,j,k;
	long long int x;
	int t;
	t=fast();
	while(t--)
	{
		vector<long long int> arr;
		long long int x,cnt=1,a=0,b=0,ans=0,min=89,l=0,y,z;
		x=fast();
		while(x!=0)
		{
			if(x&01==1)
			{
				l++;
				arr.push_back(cnt);
			}
			cnt++;
			x>>=1;
		}
		a=arr[l-1];
		if(l==1)
		{
			if(a>1)
				printf("%lld\n",(a-2));
			else
				printf("%lld\n",(a-1));
			continue;
		}
		b=arr[l-2];
		i=l-2;
		while(i>=0)
		{
			a=arr[l-1]-1;
			b=arr[i]-1;
			a+=l-2-i;
			y=l - (l-2 -i) -2;
			if(a<b)
			{
				swap(&a, &b);
			}
			if(a>b)
			{
				while(b!=a&&y!=0)
				{
					b+=1;
					y--;
				}
				if(y%2==0&&b==a)
				{
					ans=a+(y/2);
				}
				else if(y%2==1&&b==a)
				{
					ans=a+(y/2)+1;
				}
				else if(a!=b)
				{
					if(a>b)
						ans=a;
					else
						ans=b;
				}
			}
			if(ans<min)
			{
				min=ans;
			}
			i--;
		}
		printf("%lld\n",(min));
	}
	return 0;	
}

