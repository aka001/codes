#include<bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin >> test;
	for(int t=0;t<test;++t)
	{
		vector <long long int> a;
		long long int n,k,x;
		cin >> n;
		cin >> k;
		long long int sum=0;
		for(long long int i=0;i<n;++i)
		{
			cin >> x;
			sum+=x;
			a.push_back(x);
		}
		if(sum%k!=0)
			cout << "no" << endl;
		else
		{
			long long int val=sum/k;
			sort(a.rbegin(),a.rend());
			long long int ans=1,ctr=0;
			while(ctr!=k)
			{
				int flag=0;
				for(long long int i=0;i<(1<<a.size());++i)
				{
					long long int temp=val;
					for(long long int j=0;j<a.size();++j)
					{
						if(i & (1<<j))
						{
							temp-=a[j];
						}
					}
					if(temp==0)
					{
						vector<long long int>tempvec;
						for(long long int j=0;j<a.size();++j)
						{
							if(i & (1<<j))
								continue;
							else
							{
								tempvec.push_back(a[j]);
								//  cout << a[j] << " ";
							}
						}
						a=tempvec;
						//cout << endl;
						ctr++;
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					ans=0;
					break;
				}
			}
			if(ans==1)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}
