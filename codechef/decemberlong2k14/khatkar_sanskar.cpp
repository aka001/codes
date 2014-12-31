/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
void solve_subtask1_subtask2(vector<ll> v, int k, ll cnt)
{
	if(cnt == 0 && v.size() >= k-1)
	{
		cout<<"yes\n";
		return;
	}
	if(cnt % k != 0 || v.size() < k)
	{
		cout<<"no\n";
		return;
	}
	int n = v.size();
	ll eq = cnt / k, sm;
	vector<ll> masks;
	for(int i = 1; i < (1 << n); ++i)
	{
		sm = 0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				sm += v[j];
		if(sm == eq)
			masks.push_back(i);
	}
	if(masks.size() < k)
	{
		cout<<"no\n";
		return;
	}
	else
	{
		int sz,i;
		sz=masks.size();
		/*for(i=0;i<sz;i++)
		{
			printf("%lld\n",masks[i]);
		}*/
	}
	vector<ll> submasks;
	bool flag[n];
	int i;
	for(int i = (1 << k) - 1; i < (1 << masks.size()); ++i)
	{
		if(__builtin_popcount(i) != k)
			continue;
		submasks.clear();
		memset(flag, false, sizeof(flag));
		for(int j = 0; j < masks.size(); ++j)
			if(i & (1 << j))
				submasks.push_back(masks[j]);
		bool found = true;
		for(int j = 0; j < submasks.size() && found; ++j)
		{
			for(int l = 0; l < n; ++l)
			{
				if(submasks[j] & (1 << l))
				{
					if(flag[l]==true)
					{
						found=false;
						break;
					}
					flag[l] = true;
				}
			}
			/*for(int l = j+1; l < submasks.size(); ++l)
			{
				if(submasks[j] & submasks[l])
				{
					found = false;
					break;
				}
			}*/
		}
		//printf("\n");
		if(found)
		{
			bool fnd = true;
			for(int j = 0; j < n; ++j)
			{
				if(!flag[j])
				{
					fnd = false;
					break;
				}
			}
			if(fnd)
			{
				cout<<"yes\n";
				return;
			}
		}
	}
	cout<<"no\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		vector<ll> v;
		ll tmp, cnt = 0;
		for(int i = 0; i < n; ++i)
		{
			cin>>tmp;
			cnt += tmp;
			v.push_back(tmp);
		}
		solve_subtask1_subtask2(v, k, cnt);
	}
	return 0;
}
